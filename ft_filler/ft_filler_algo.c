/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 02:10:10 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/14 02:10:43 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_algo_end(int nbr_contact, t_piece *p, t_filler *filler)
{
	if (nbr_contact == -1)
		return (0);
	p->final_x = p->tmp_x;
	p->final_y = p->tmp_y;
	ft_print_result(p, filler);
	return (1);
}

int		ft_algo(t_filler *filler, t_piece *p)
{
	int	i;
	int	i2;
	int	nbr_contact_tmp;
	int	nbr_contact;

	nbr_contact = -1;
	i = filler->map_size_y - (p->size_y - p->end_y);
	p->tmp_x = 0;
	p->tmp_y = 0;
	while (--i >= 0)
	{
		i2 = filler->map_size_x - (p->size_x - p->end_x);
		while (--i2 >= 0)
			if (ft_is_placable(i, i2, filler, p) == 0)
			{
				nbr_contact_tmp = ft_count_contact(filler, p, i, i2);
				if (nbr_contact_tmp > nbr_contact)
				{
					nbr_contact = nbr_contact_tmp;
					p->tmp_x = i2;
					p->tmp_y = i;
				}
			}
	}
	return (ft_algo_end(nbr_contact, p, filler));
}

void	ft_get_contact(t_piece *p, t_filler *filler)
{
	int	i;
	int	i2;

	i = 2;
	while (++i < filler->map_size_y - 3)
	{
		i2 = 2;
		while (++i2 < filler->map_size_x - 3)
		{
			if (filler->map[i][i2] == filler->me[0] ||
				filler->map[i][i2] == filler->me[1])
				if (filler->map[i][i2 + 3] == filler->en[0] ||
					filler->map[i][i2 - 3] == filler->en[0] ||
					filler->map[i + 3][i2] == filler->en[0] ||
					filler->map[i - 3][i2] == filler->en[0] ||
					filler->map[i][i2 + 3] == filler->en[1] ||
					filler->map[i][i2 - 3] == filler->en[1] ||
					filler->map[i + 3][i2] == filler->en[1] ||
					filler->map[i - 3][i2] == filler->en[1])
				{
					p->contact = 1;
					return ;
				}
		}
	}
}

int		ft_count_contact(t_filler *filler, t_piece *p, int y, int x)
{
	int	i;
	int	i2;
	int o;

	i = -1;
	p->nbr_contact = 0;
	while (++i < p->size_y)
	{
		i2 = -1;
		while (++i2 < p->size_x)
			if (p->piece[i][i2] == '*')
			{
				o = 0;
				while (++o < 4)
					if ((i2 + x + o) < filler->map_size_x && (i2 + x - o) > 0 &&
						(i + y + o) < filler->map_size_y && (i + y - o) > 0)
						if (filler->map[i + y][i2 + x + o] == filler->en[0] ||
							filler->map[i + y][i2 + x - o] == filler->en[0] ||
							filler->map[i + y + o][i2 + x] == filler->en[0] ||
							filler->map[i + y - o][i2 + x] == filler->en[0])
							p->nbr_contact += (4 - o);
			}
	}
	return (p->nbr_contact);
}
