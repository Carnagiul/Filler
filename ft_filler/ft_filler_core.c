/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 02:10:18 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/14 02:11:13 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_wich_player(t_filler *filler)
{
	if (filler->player == 1)
	{
		filler->en = "Xx";
		filler->me = "Oo";
	}
	if (filler->player == 2)
	{
		filler->en = "Oo";
		filler->me = "Xx";
	}
}

void	ft_print_result(t_piece *p, t_filler *filler)
{
	ft_printf("%d %d\n", p->final_y, p->final_x);
	filler->my_pos_x = p->final_x;
	filler->my_pos_y = p->final_y;
}

void	ft_init_struct(t_filler *filler, t_piece *p)
{
	filler->map = NULL;
	filler->player = 0;
	filler->map_size_x = 0;
	filler->map_size_y = 0;
	p->final_x = 0;
	p->final_y = 0;
	p->size_x = 0;
	p->size_y = 0;
	filler->pos_enemy_x = 0;
	filler->pos_enemy_y = 0;
	filler->my_pos_x = 0;
	filler->my_pos_y = 0;
	p->start_x = 0;
	p->end_x = 0;
	p->start_y = 0;
	p->end_y = 0;
	p->contact = 0;
}

int		ft_big_map(t_filler *filler, t_piece *p)
{
	int	ret;

	ft_get_contact(p, filler);
	if (p->contact == 0)
	{
		if (filler->my_pos_y < filler->pos_enemy_y)
		{
			if (ft_go_contact1(filler, p) == 1)
				return (1);
		}
		else if (filler->my_pos_y >= filler->pos_enemy_y)
		{
			if (ft_go_contact2(filler, p) == 1)
				return (1);
		}
	}
	else
	{
		ret = ft_algo(filler, p);
		if (ret == 0)
			return (1);
	}
	return (0);
}

int		ft_play(t_filler *filler, t_piece *p)
{
	return (ft_big_map(filler, p));
}
