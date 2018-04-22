/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:35:28 by nmizin            #+#    #+#             */
/*   Updated: 2017/12/04 20:41:37 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 50000

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# define RED "\x1B[31m"
# define RES "\x1B[0m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define MAG  "\x1B[35m"
# define CYN  "\x1B[36m"

typedef struct		s_list
{
	char			*content;
	int				num;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_bzero(void *s, size_t n);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strrchr(const char *s, int c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				my_ft_setyourchar(char *s, int c);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
int					f_valid(char *str);
int					get_next_line(const int fd, char **line);
int					ft_atoi(const char *str);
int					f_w_e_l(char c, int length);
void				print_board(t_list *list);
int					find_num(t_list *str_match);
t_list				*make_struct(char *str, t_list *list);
int					check_answer(char *str);
void				print_try_again(void);
void				print_angry(void);
void				print_super_angry(void);
void				print_mistake();
void				print_result(int move_number);
void				ft_putnbr(int nb);
int					who_first(void);
int					ask(t_list *str_match);
int					bot(t_list *str_match);
t_list				*update_board(t_list *str_match, int count);
int					sum_matches(t_list *str_match);
t_list				*game_process(t_list *str_match, int move_num, int players);
#endif
