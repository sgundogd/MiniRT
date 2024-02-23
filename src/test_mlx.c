/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:44:02 by sgundogd          #+#    #+#             */
/*   Updated: 2024/02/23 21:44:25 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/keys.h"
#include "../inc/rt.h"

void	my_mlx_pixel_put(t_mlx *m, int x, int y, int color)
{
	char	*dst;

	dst = m->addr + (y * m->line_len + x * (m->bpp / 8));
	*(unsigned int*)dst = color;
}

void	render_background( t_mlx *m, int color ) {
    int	x;
    int	y;

    y = -1;
    while ( ++y < V_HEIGHT ) {
        x = -1;
        while ( ++x < V_WIDTH ) {
            my_mlx_pixel_put( m, x, y, color );
        }
    }
}
