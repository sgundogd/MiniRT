/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:44:02 by sgundogd          #+#    #+#             */
/*   Updated: 2024/02/26 02:34:35 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/keys.h"
#include "../inc/minirt.h"

void	my_mlx_pixel_put(t_mlx *m, int x, int y, int color)
{
	char	*dst;

	dst = m->addr + (y * m->line_len + x * (m->bpp / 8));
	*(unsigned int*)dst = color;
}

// int rgb_to_int(t_color *rgb);

// void	render_background2( t_mlx *m ) {
//     int	x;
//     int	y;
//     t_color c;

//     y = -1;
//     while ( ++y < HEIGHT ) {
//         x = -1;
//         while ( ++x < WIDTH ) {
//             c = (t_color){.r = ((float)x/(float)WIDTH * 255), .g = ((float)y/(float)HEIGHT * 255), .b = ((float)(x+2) * 255)};
            
//             my_mlx_pixel_put( m, x, y, rgb_to_int(&c)  );
//         }
//     }
// }
