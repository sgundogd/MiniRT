#include "../inc/minirt.h"


void	mlx_stuffs( t_data * );
void	my_mlx_pixel_put( t_mlx *, int, int, int );
void	render_background( t_mlx *, int );

t_roots	r_intersects_sphere( const t_vec3 *, const t_sphere *, const t_data *);

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

int handle_key(int keycode, t_data *genel)
{
	if ( keycode == KEY_ESC || keycode == KEY_Q ) free_exit( genel );	//printf( "%d\n", keycode );

	cam_move( genel, keycode );

	render_background( genel->mlx, 0x1818AA * keycode / 100 );
	mlx_put_image_to_window( genel->mlx->mlx_p, genel->mlx->win_p, genel->mlx->img_p, 0, 0 );
	return (0);
}


// t_vec3 canvas_to_viewport(int *x, int *y) // V_D represents the distance between the camera and the projection plane.
// {
//     return ((t_vec3){(*x)*WIDTH / C_W , (*y)*HEIGHT/C_H , V_D});
// }




// t_color	trace_ray(t_data *genel, t_vec3 *d, double t_min, double t_max) // O the origin of the ray,
// {
// 	t_vec3 *o = &genel->cam->origin;
// 	double closest_t = INF;
// 	t_sphere *closest_sp = NULL;
// 	t_sphere *iter = genel->objs->sp;
// 	t_roots r;
// 	while (iter)
// 	{
// 		r = r_intersects_sphere(d, iter, genel);
// 		if ((r.t1 <= t_max && r.t1 >= t_min) && r.t1 < closest_t)
// 		{
// 			closest_t = r.t1;
// 			closest_sp = iter;
// 		}
// 		if ((r.t2 <= t_max && r.t2 >= t_min) && r.t2 < closest_t)
// 		{
// 			closest_t = r.t2;
// 			closest_sp = iter;
// 		}
// 		iter = iter->next;
// 	}
// 	if (!closest_sp)
// 		return ((t_color){.r = 155, .g = 155, .b = 155});
// 	return ((t_color){.r = closest_sp->color.r, .g = closest_sp->color.g, .b = closest_sp->color.b});
// }


int rgb_to_int(t_color *rgb)
{
	int	c;

	c = rgb->r;
	c = (c << 8) | rgb->g;
	c = (c << 8) | rgb->b;
	return (c);
}


// void render(t_data *genel)
// {
// 	t_vec3	d;
// 	t_color color;

// 	int y = -1;
// 	int x;

// 	while (++y < HEIGHT)
// 	{
// 		x = -1;
// 		while (++x > WIDTH)
// 		{
// 			// d = canvas_to_viewport(&x, &y);
// 			// color = trace_ray(genel, &d, 1, INF);


// 			my_mlx_pixel_put( genel->mlx, d.x, d.y, rgb_to_int(&color) );
// 		}
// 	}
// }




void	new_mlx(t_data *d) {
	if (!d->mlx)
		free_exit(d);
	d->mlx->mlx_p = mlx_init();
	if (!d->mlx->mlx_p)
		free_exit(d);
	d->mlx->win_p = mlx_new_window( d->mlx->mlx_p, WIDTH, HEIGHT, "tnoyan's team" );
	if (!d->mlx->win_p)
		free_exit(d);
	d->mlx->img_p = mlx_new_image( d->mlx->mlx_p, WIDTH, HEIGHT );
	if (!d->mlx->img_p)
		free_exit(d);
	d->mlx->addr = mlx_get_data_addr( d->mlx->img_p, &d->mlx->bpp, &d->mlx->line_len, &d->mlx->endian );
	if (!d->mlx->addr)
		free_exit(d);
}

void	init_screen(t_data *d) {
	if (!d->screen)
		free_exit(d);
	d->screen->aspect_ratio = WIDTH / HEIGHT;
	d->screen->half_width = WIDTH / 2;
	d->screen->half_height = HEIGHT / 2;
	d->screen->viewport_width = 1 / tan(d->cam->fov / 2);
	d->screen->viewport_height = d->screen->viewport_width / d->screen->aspect_ratio;
}

void	set_sphere(t_data *d, t_sphere *s, int i) {
	d->obj_set[i].type = SPHERE;
	d->obj_set[i].obj = s;
	d->obj_set[i].idx = i;
}

void	set_light(t_data *d, t_light *l, int i) {
	d->obj_set[i].obj = l;
	d->obj_set[i].idx = i;
}

void	set_stuffs(t_data *d) {
	//init_cam(d);
	init_screen(d);
	//set_obj(d, obj);
	//set_light(d, light);
}



void	main_loop(t_data *d) {
	mlx_hook( d->mlx->win_p, 17, 1, &free_exit, d);
	mlx_hook( d->mlx->win_p, EVENT_KEY_PRESS, 1, &handle_key, d );
	mlx_loop( d->mlx->mlx_p );

}


t_roots	r_intersects_sphere(const t_vec3 *d, const t_sphere *s, const t_data *genel)
{
	const t_vec3 *o = &genel->cam->origin;
	t_vec3	co = v_substract(o, &s->center);

	double	a = v_dot(d, d);
	double 	b = 2 * v_dot(&co, d);
	double	c = v_dot(&co, &co) - (s->r * s->r);

	double	discriminant = b * b - 4 * a * c;
	if (discriminant < TOL)
		return ((t_roots){INF, INF});
	double t1 = (-b + sqrt(discriminant)) / (2 * a);
	double t2 = (-b - sqrt(discriminant)) / (2 * a);
	return ((t_roots){t1, t2});
}

// void __attribute__((destructor)) a(){
// 	system("leaks test.out");
// }
