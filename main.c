/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 02:12:55 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/14 02:13:31 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			free_db(t_filler *filler)
{
	int			i;

	i = 0;
	if (filler->map == NULL)
		return ;
	while (i < filler->map_size_y)
	{
		if (filler->map[i] != NULL)
			free(filler->map[i]);
		i++;
	}
	free(filler->map);
	filler->map = NULL;
}

void			free_piece(t_piece *p)
{
	int			i;

	i = 0;
	if (p->piece != NULL)
	{
		while (i < p->size_y)
			free(p->piece[i++]);
		free(p->piece);
	}
	p->piece = NULL;
}

void			*ft_malloc(size_t size)
{
	void		*ret;

	ret = malloc(size);
	if (!ret)
		exit(0);
	return (ret);
}

int				main(void)
{
	t_filler	*filler;
	t_piece		*p;

	filler = (t_filler *)ft_malloc(sizeof(t_filler));
	p = (t_piece *)ft_malloc(sizeof(t_piece));
	ft_init_struct(filler, p);
	ft_get_player(filler);
	while (1)
	{
		free_db(filler);
		free_piece(p);
		ft_get_the_ret(filler, p);
		if (ft_play(filler, p) == 1)
		{
			if (ft_last_try(filler, p) == 1)
			{
				ft_print_result(p, filler);
				exit(1);
			}
		}
	}
	return (0);
}
