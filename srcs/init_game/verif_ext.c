/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:21:29 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/25 18:01:53 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

int	verif_ext(char *str)
{
	char	*ext;
	int		i;

	ext = ".ber";
	str++;
	while (*str != '.')
	{
		str++;
	}
	i = ft_strncmp(str, ext, 5);
	return (i);
}
