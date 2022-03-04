/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <pcarmeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:12:25 by pcarmeli          #+#    #+#             */
/*   Updated: 2022/01/26 17:42:52 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	file_checking(char *file_name)
{
	int	fd;
	int	len;

	fd = open(file_name, O_RDONLY, 0);
	if (fd <= 0)
		ft_error("file does not exist\n");
	len = ft_strlen(file_name);
	if (ft_strncmp(".cub", file_name + len - 4, 5) != 0)
		ft_error("file extension should be .cub\n");
	close(fd);
	return (0);
}
