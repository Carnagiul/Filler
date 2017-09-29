/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 02:09:15 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/14 02:09:30 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void			ft_get_player(t_filler *filler)
{
	char		*line;

	get_next_line(0, &line);
	if (ft_strncmp(line, "$$$", 2) == 0 && filler->player == 0)
	{
		if (ft_strstr(line, "p2"))
			filler->player = 2;
		if (ft_strstr(line, "p1"))
			filler->player = 1;
		ft_wich_player(filler);
	}
	ft_strdel(&line);
}

void			ft_get_strat_pos(t_filler *filler)
{
	int			x;
	int			y;

	y = 0;
	if (y == filler->map_size_y)
		return ;
	while (++y < (filler->map_size_y))
	{
		x = 0;
		while (++x < (filler->map_size_x))
		{
			if ((filler->map[y][x] == filler->en[0] ||
						filler->map[y][x] == filler->en[1]))
			{
				filler->pos_enemy_x = x;
				filler->pos_enemy_y = y;
			}
			if ((filler->map[y][x] == filler->me[0] ||
						filler->map[y][x] == filler->me[1]))
			{
				filler->my_pos_x = x;
				filler->my_pos_y = y;
			}
		}
	}
}

char			*ft_get_filler_line(char *line)
{
	char		**data;
	char		*ret;

	data = ft_strsplit(line, ' ');
	ret = NULL;
	if (data[1])
		ret = ft_strdup(data[1]);
	if (data[0])
		free(data[0]);
	if (data[1])
		free(data[1]);
	if (data)
		free(data);
	return (ret);
}

void			ft_get_filler(t_filler *filler)
{
	int			i;
	char		*line;

	get_next_line(0, &line);
	ft_strdel(&line);
	i = -1;
	filler->map = (char **)malloc(sizeof(char *) * (filler->map_size_y + 1));
	if (!filler->map)
		exit(0);
	while (++i <= (filler->map_size_y - 1))
	{
		get_next_line(0, &line);
		filler->map[i] = ft_get_filler_line(line);
		ft_strdel(&line);
	}
	ft_get_strat_pos(filler);
}

void			ft_get_filler_size(char *line, t_filler *filler)
{
	int			i;
	int			tmp;

	i = 0;
	filler->map_size_x = 0;
	filler->map_size_y = 0;
	while (line[i])
	{
		tmp = 0;
		while (ft_isdigit(line[i]) == 1 && line[i])
		{
			tmp += line[i] - 48;
			if (ft_isdigit(line[i + 1]) == 1)
				tmp *= 10;
			i++;
		}
		if (filler->map_size_y == 0)
			filler->map_size_y = tmp;
		else if (filler->map_size_x == 0)
			filler->map_size_x = tmp;
		i++;
	}
	ft_get_filler(filler);
}

int				ft_get_the_ret(t_filler *filler, t_piece *p)
{
	char		*line;

	p->piece = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau", 6) == 0)
		{
			ft_get_filler_size(line, filler);
			ft_strdel(&line);
		}
		else if (ft_strncmp(line, "Piece", 4) == 0)
		{
			ft_get_piece_size(line, p);
			return (1);
		}
		else
			ft_strdel(&line);
	}
	return (0);
}
