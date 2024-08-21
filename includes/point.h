/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:22:39 by welee             #+#    #+#             */
/*   Updated: 2024/08/21 17:58:14 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

typedef struct s_point2d
{
	int	x;
	int	y;
}	t_point2d;

t_point2d	create_point2d(int x, int y);
t_point2d	add_points2d(t_point2d p1, t_point2d p2);
t_point2d	subtract_points2d(t_point2d p1, t_point2d p2);
float		distance_between_points2d(t_point2d p1, t_point2d p2);
t_point2d	scale_point2d(t_point2d p, int scalar);
int			dot_product2d(t_point2d p1, t_point2d p2);
void		print_point2d(t_point2d p);

typedef struct s_point3d
{
	int	x;
	int	y;
	int	z;
}	t_point3d;

t_point3d	create_point3d(int x, int y, int z);
t_point3d	add_points3d(t_point3d p1, t_point3d p2);
t_point3d	subtract_points3d(t_point3d p1, t_point3d p2);
float		distance_between_points3d(t_point3d p1, t_point3d p2);
t_point3d	scale_point3d(t_point3d p, int scalar);
int			dot_product3d(t_point3d p1, t_point3d p2);
t_point3d	cross_product3d(t_point3d p1, t_point3d p2);
void		print_point3d(t_point3d p);

#endif
