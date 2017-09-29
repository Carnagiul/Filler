/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 02:13:46 by piquerue          #+#    #+#             */
/*   Updated: 2017/05/19 05:28:06 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

typedef struct		s_filler
{
	char			**map;
	int				player;
	int				map_size_x;
	int				map_size_y;
	char			*en;
	int				pos_enemy_x;
	int				pos_enemy_y;
	int				my_pos_x;
	int				my_pos_y;
	int				first_x;
	int				first_y;
	char			*me;
	char			*ret;
}					t_filler;

typedef struct		s_piece
{
	int				tmp_x;
	int				tmp_y;
	int				nbr_contact;
	int				contact;
	int				final_x;
	int				final_y;
	char			**piece;
	int				size_x;
	int				size_y;
	int				real_size_x;
	int				real_size_y;
	int				start_x;
	int				end_x;
	int				start_y;
	int				end_y;
}					t_piece;

void				ft_get_player(t_filler *filler);
void				ft_get_strat_pos(t_filler *filler);
void				ft_get_filler(t_filler *filler);
void				ft_get_filler_size(char *line, t_filler *filler);
int					ft_get_the_ret(t_filler *filler, t_piece *p);
void				ft_get_real_piece_size(t_piece *p);
void				ft_get_piece(t_piece *p);
void				ft_get_piece_size(char *line, t_piece *p);
void				ft_init_struct(t_filler *filler, t_piece *p);
int					ft_go_contact1(t_filler *filler, t_piece *p);
int					ft_go_contact2(t_filler *filler, t_piece *p);
int					ft_big_map(t_filler *filler, t_piece *p);
int					ft_play(t_filler *filler, t_piece *p);
void				ft_get_contact(t_piece *p, t_filler *filler);
int					ft_count_contact(t_filler *filler, t_piece *p, int y,
		int x);
int					ft_algo(t_filler *filler, t_piece *p);
void				ft_wich_player(t_filler *filler);
int					ft_is_placable(int i, int i2, t_filler *filler, t_piece *p);
void				ft_print_result(t_piece *p, t_filler *filler);
int					ft_last_try(t_filler *filler, t_piece *p);
int					ft_is_placable2(t_piece *p, int count, int y, int x);
int					ft_algo_end(int nbr_contact, t_piece *p, t_filler *filler);

#endif
