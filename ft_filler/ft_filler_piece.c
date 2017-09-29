/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 02:10:24 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/14 02:10:27 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_get_real_piece_size(t_piece *p)
{
	int		i;
	int		i2;

	i = -1;
	p->start_x = p->size_x;
	p->start_y = p->size_y;
	while (++i < p->size_y)
	{
		i2 = -1;
		while (++i2 < p->size_x)
			if (p->piece[i][i2] == '*')
			{
				if (i2 < p->start_x)
					p->start_x = i2;
				if (i2 > p->end_x)
					p->end_x = i2;
				if (i < p->start_y)
					p->start_y = i;
				if (i > p->end_y)
					p->end_y = i;
			}
	}
	p->real_size_x = (p->end_x - p->start_x) + 1;
	p->real_size_y = (p->end_y - p->start_y) + 1;
}

void		ft_get_piece(t_piece *p)
{
	int		i;
	char	*line;

	i = 0;
	p->piece = (char **)malloc(sizeof(char *) * (p->size_y + 1));
	while (i < p->size_y)
	{
		get_next_line(0, &line);
		p->piece[i++] = ft_strdup(line);
		ft_strdel(&line);
	}
	ft_get_real_piece_size(p);
}

void		ft_get_piece_size(char *line, t_piece *p)
{
	int		i;
	int		tmp;

	i = 0;
	p->size_x = 0;
	p->size_y = 0;
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
		if (p->size_y == 0)
			p->size_y = tmp;
		else if (p->size_x == 0)
			p->size_x = tmp;
		i++;
	}
	ft_strdel(&line);
	ft_get_piece(p);
}
