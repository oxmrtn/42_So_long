/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:39:56 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/26 13:19:31 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs_bonus/so_long_bonus.h"

int	is_cutted(char *tmpmap)
{
	int	i;
	int	is_space;
	int	is_before;
	int	is_after;

	i = 0;
	is_space = 0;
	is_before = 0;
	is_after = 0;
	while (tmpmap[i])
	{
		if (tmpmap[i] != '\n' && is_before == 0)
			is_before = 1;
		if (tmpmap[i + 1] && tmpmap[i] == '\n' && tmpmap[i + 1] == '\n'
			&& is_before == 1)
			is_space = 1;
		if (tmpmap[i] != '\n' && is_before == 1 && is_space == 1)
			is_after = 1;
		i++;
	}
	if (is_space == 1 && is_before == 1 && is_after == 1)
		return (1);
	return (0);
}

void	ft_parser(int fd, char ***map)
{
	char	*str;
	char	*buffer;

	str = get_next_line(fd);
	if (!str)
	{
		*map = NULL;
		return ;
	}
	buffer = NULL;
	while (str)
	{	
		buffer = ft_strjoin(buffer, str);
		free(str);
		str = get_next_line(fd);
	}
	if (is_cutted(buffer))
	{
		free(buffer);
		*map = NULL;
		return ;
	}
	*map = ft_split(buffer, '\n');
	free(buffer);
}

void	ft_print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}
