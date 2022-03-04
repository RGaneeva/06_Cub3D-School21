/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:59:04 by cliza             #+#    #+#             */
/*   Updated: 2022/01/27 10:59:05 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_include/cub3d.h"

void	wallx_work(t_cube *cube, t_ray *ray, t_door	*new_door)
{
	double	wallx;

	if (ray->side)
		wallx = cube->posx + ray->perpwalldist * ray->raydirx;
	else
		wallx = cube->posy + ray->perpwalldist * ray->raydiry;
	wallx -= floor(wallx);
	new_door->texx = (int)(wallx * (double)TEX);
}

t_door	*new_door(t_cube *cube, t_ray *ray, int type)
{
	t_door	*new_door;

	new_door = malloc(sizeof(t_door));
	new_door->next = NULL;
	new_door->type = type;
	if (ray->side)
		ray->perpwalldist = ray->sidedisty - ray->deltadisty;
	else
		ray->perpwalldist = ray->sidedistx - ray->deltadistx;
	ray->lineheight = (int)(HEIGHT / ray->perpwalldist);
	new_door->drawstart = -ray->lineheight / 2 + HEIGHT / 2;
	if (new_door->drawstart < 0)
		new_door->drawstart = 0;
	new_door->drawend = ray->lineheight / 2 + HEIGHT / 2;
	if (new_door->drawend >= HEIGHT)
		new_door->drawend = HEIGHT - 1;
	wallx_work(cube, ray, new_door);
	if (!ray->side && ray->raydirx > 0)
		new_door->texx = TEX - new_door->texx;
	if (ray->side && ray->raydiry < 0)
		new_door->texx = TEX - new_door->texx;
	new_door->step = (double) TEX / ray->lineheight;
	new_door->texpos = (new_door->drawstart - HEIGHT / 2 + ray->lineheight / 2);
	new_door->texpos *= new_door->step;
	return (new_door);
}

void	add_door_front(t_door **doors, t_door *new_door)
{
	if (!(*doors))
		*doors = new_door;
	else
	{
		new_door->next = *doors;
		*doors = new_door;
	}
}

void	free_doors(t_door **doors)
{
	t_door	*temp;
	t_door	*temp2;

	temp = *doors;
	*doors = NULL;
	while (temp)
	{
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
}

void	draw_doors(t_cube *cube, t_door *doors, int x)
{
	int	color;
	int	y;

	while (doors)
	{
		y = doors->drawstart;
		while (y < doors->drawend)
		{
			doors->texy = (int)doors->texpos;
			doors->texpos += doors->step;
			if (doors->type == 2)
				color = get_color(&cube->tex[4], doors->texx, doors->texy);
			if (doors->type == 3)
				color = get_color(&cube->tex[5], doors->texx, doors->texy);
			if (color != 0)
				apply_pixel(cube->img, x, y, color);
			y++;
		}
		doors = doors->next;
	}
}
