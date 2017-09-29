/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 02:10:14 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/14 02:11:49 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_go_contact1(t_filler *filler, t_piece *p)
{
	int	i;
	int	i2;
	int	ret;

	i = filler->map_size_y - 1;
	p->final_x = 0;
	p->final_y = 0;
	ret = 0;
	while (i > 0)
	{
		i2 = filler->map_size_x - 1;
		while (i2 > 0)
		{
			ret = ft_is_placable(i, i2, filler, p);
			if (ret == 0)
			{
				ft_print_result(p, filler);
				return (0);
			}
			i2--;
		}
		i--;
	}
	return (1);
}

int		ft_go_contact2(t_filler *filler, t_piece *p)
{
	int	i;
	int	i2;
	int	ret;

	i = -1;
	p->final_x = 0;
	p->final_y = 0;
	ret = 0;
	while (++i < filler->map_size_y - 1)
	{
		i2 = -1;
		while (++i2 < filler->map_size_x - 1)
		{
			ret = ft_is_placable(i, i2, filler, p);
			if (ret == 0)
			{
				ft_print_result(p, filler);
				return (0);
			}
		}
	}
	return (1);
}

int		ft_is_placable(int i, int i2, t_filler *f, t_piece *p)
{
	int	j;
	int	j2;
	int	count;

	j = -1;
	count = 0;
	if (i + p->size_y > f->map_size_y || i2 + p->size_x > f->map_size_x)
		return (1);
	while (++j <= (p->size_y - 1))
	{
		j2 = -1;
		while (++j2 <= (p->size_x - 1))
		{
			if (p->piece[j][j2] == '*' && (f->map[i + j][i2 + j2] ==
				f->en[0] || f->map[i + j][i2 + j2] ==
				f->en[0] - 32))
				return (1);
			if (p->piece[j][j2] == '*' && (f->map[i + j][i2 + j2] ==
				f->me[0] || f->map[i + j][i2 + j2] == f->me[0] - 32))
				count++;
		}
	}
	if (ft_is_placable2(p, count, i, i2) == 0)
		return (0);
	return (1);
}

int		ft_is_placable2(t_piece *p, int count, int y, int x)
{
	if (count == 1)
	{
		p->final_x = x;
		p->final_y = y;
		return (0);
	}
	return (1);
}

int		ft_last_try(t_filler *filler, t_piece *p)
{
	int	i;
	int	i2;
	int	ret;

	i = -1;
	p->final_x = 0;
	p->final_y = 0;
	ret = 0;
	while (++i < filler->map_size_y - 1)
	{
		i2 = -1;
		while (++i2 < filler->map_size_x - 1)
		{
			ret = ft_is_placable(i, i2, filler, p);
			if (ret == 0)
			{
				ft_print_result(p, filler);
				return (0);
			}
		}
	}
	return (1);
}
