#include "../inc/minirt.h"
#include <stdio.h>

void	mlx_stuffs(t_data * );
void	my_mlx_pixel_put( t_mlx *, int, int, int );
void	render_background( t_mlx *, int );


void	free_objects( t_data *genel) {
	int i = -1;

	 while (++i < (int) genel->obj_count) {
	 	if (genel->obj_set[i].obj)
	 		free(genel->obj_set[i].obj);
	 }
	 if (genel->obj_set)
	 	free(genel->obj_set);

}

int	free_exit( t_data *genel) {
	//(void)genel;
	if (genel)
	{
		if (genel->mlx->img_p)
		{
			mlx_destroy_image( genel->mlx->mlx_p, genel->mlx->img_p );
			if (genel->mlx->win_p)
				mlx_destroy_window( genel->mlx->mlx_p, genel->mlx->win_p );
		}
		free_objects(genel);
		if (genel->cam)
			free(genel->cam);
		if (genel->screen)
			free(genel->screen);
		if (genel->mlx)
			free(genel->mlx);
	}
	exit( 0 );
}


void	cam_move( t_data *genel, int keycode ) {
	if ( keycode == KEY_A ) genel->cam->origin.x += SHIFT_VAL;
	else if ( keycode == KEY_D ) genel->cam->origin.x -= SHIFT_VAL;
	else if ( keycode == KEY_W ) genel->cam->origin.z += SHIFT_VAL;
	else if ( keycode == KEY_S ) genel->cam->origin.z -= SHIFT_VAL;
	else if ( keycode == KEY_UP ) genel->cam->origin.y += SHIFT_VAL;
	else if ( keycode == KEY_DOWN ) genel->cam->origin.y -= SHIFT_VAL;
}

void render(t_data *data);

int rgb_to_int(const t_color *rgb);

int handle_key(int keycode, t_data *genel)
{
	if ( keycode == KEY_ESC || keycode == KEY_Q ) free_exit( genel );	//printf( "%d\n", keycode );
	cam_move( genel, keycode );

	render( genel );
	printf("cam->z: %f\n", genel->cam->origin.z);

	mlx_put_image_to_window( genel->mlx->mlx_p, genel->mlx->win_p, genel->mlx->img_p, 0, 0 );
	return (0);
}

t_color	trace_ray(t_data *data, const t_ray *ray)
{
	t_color color = {155, 155, 115};
	const t_obj *obj;
	double distance;
	double min_distance;
	int i;

	i = -1;
	min_distance = INF;
	while (++i < data->obj_count)
	{
		obj = &data->obj_set[i];
		distance = obj->f_intersects(ray, obj);
		if (distance > 0 && distance < min_distance)
		{
			min_distance = distance;
			color = obj->f_get_color(obj);
		}
	}
	return (color);
}

int rgb_to_int(const t_color *rgb)
{
	int	c;

	c = rgb->r;
	c = (c << 8) | rgb->g;
	c = (c << 8) | rgb->b;
	return (c);
}

void	pixel_to_virtual(t_screen *s, int *x, int *y, t_vec3 *iter_coords)
{
	iter_coords->x = -1 + (2 * (*x + 0.5) / WIDTH) ;
	iter_coords->y = 1 - 2.0 * ((*y + 0.5 - s->y_pix_min) / HEIGHT);
	iter_coords->z = s->focal_length;
}

void render(t_data *data)
{
	t_ray ray;
	ray.origin = data->cam->origin;

	t_color color;// = (t_color){0, 0, 0};
	t_vec3 mapped_coords = {0, 0, 0};

	int pix_vertical_margin = (double)HEIGHT * (1 - (1 / data->screen->aspect_ratio)) / 2;

	int pix_y;
	int pix_x;

	pix_y = pix_vertical_margin - 1;
	while (++pix_y < data->screen->y_pix_max)
	{
		pix_x = -1;
		while (++pix_x < WIDTH)
		{
			pixel_to_virtual(data->screen, &pix_x, &pix_y, &mapped_coords);

			ray.dir = v_normalize(&mapped_coords);

			color = trace_ray(data, &ray);

			my_mlx_pixel_put( data->mlx, pix_x, pix_y, rgb_to_int(&color) );

			pix_x++;
		}
		pix_y++;
	}

}

void	new_mlx(t_data *d) {
	if (!d->mlx)
		free_exit(d);
	d->mlx->mlx_p = mlx_init();
	if (!d->mlx->mlx_p)
		free_exit(d);
	d->mlx->win_p = mlx_new_window( d->mlx->mlx_p, WIDTH, WIDTH, "tnoyan's team" );
	if (!d->mlx->win_p)
		free_exit(d);
	d->mlx->img_p = mlx_new_image( d->mlx->mlx_p, WIDTH, WIDTH );
	if (!d->mlx->img_p)
		free_exit(d);
	d->mlx->addr = mlx_get_data_addr( d->mlx->img_p, &d->mlx->bpp, &d->mlx->line_len, &d->mlx->endian );
	if (!d->mlx->addr)
		free_exit(d);
}

void	init_camera_up_right(t_data *d) {
	d->screen->up = (t_vec3){0, 1, 0};
	d->screen->right = v_cross(&d->cam->dir, &d->screen->up);
	d->screen->up = v_cross(&d->screen->right, &d->cam->dir);
	d->screen->up = v_normalize(&d->screen->up);
	d->screen->right = v_normalize(&d->screen->right);
}

void	init_screen(t_data *d) {
	if (!d->screen)
		free_exit(d);
	d->screen->aspect_ratio = (double)ASPECT_RATIO_X / (double)ASPECT_RATIO_Y;
	d->screen->focal_length = 1 / tan((d->cam->fov / 2) * (M_PI / 180));
	d->screen->y_pix_min = ((double)HEIGHT - (WIDTH / d->screen->aspect_ratio)) / 2;
	d->screen->y_pix_max = (WIDTH / d->screen->aspect_ratio) + d->screen->y_pix_min;
}

		void print_intersection_points(t_data *d, t_ray ray){
			double distance;
			t_vec3 point;

			for (int i = 0; i < d->obj_count; i++)
			{
			distance = d->obj_set[i].f_intersects(&ray, &(d->obj_set[i]));
			point = v_multiply(&ray.dir, distance);
			point = v_add(&ray.origin, &point);
			printf("Distance for object %d: %.2f\n", i, point.z);
			printf("\tIntersection point:\tx:%.3f y:%.3f z:%.3f\n", point.x, point.y, point.z);
			}
		}


void	main_loop(t_data *d) {

	print_intersection_points(d, (t_ray){.origin = d->cam->origin, .dir = d->cam->dir});

	init_screen(d);
	init_camera_up_right(d);

	render( d );
	mlx_put_image_to_window( d->mlx->mlx_p, d->mlx->win_p, d->mlx->img_p, 0, 0 );

	mlx_hook( d->mlx->win_p, 17, 1, &free_exit, d);
	mlx_hook( d->mlx->win_p, EVENT_KEY_PRESS, 1, &handle_key, d );
	mlx_loop( d->mlx->mlx_p );

}




// void __attribute__((destructor)) a(){
// 	system("leaks test.out");
// }
