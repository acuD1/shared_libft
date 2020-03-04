/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_libft.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 12:36:29 by arsciand          #+#    #+#             */
/*   Updated: 2020/03/04 23:16:41 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_LIBFT_H
# define SHARED_LIBFT_H

# define BUFF_SZ	4096
# define FD_MAXSET	4864

# include "ft_printf.h"

typedef struct		s_lst
{
	void			*content;
	size_t			content_size;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

/*
**		Fonctions
*/

int32_t				ft_atoi(const char *s);
int8_t				ft_atol(const char *s, int64_t *result);
void				ft_bzero(void *s, size_t n);
int					ft_decade(int nbr);
u_int64_t			ft_get_options(int argc, char **argv, char *allowed);
int					get_next_line(int fd, char **line);
void				remove_invalid_char(char *buff);
int32_t				ft_getnextline(const int fd, char **line);
int8_t				ft_is_number(const char *s);
int					ft_is_print(int c);
int8_t				ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isblank(int c);
int					ft_isdigit(int c);
u_int8_t			ft_isnum(char *str);
int					ft_isstart(const char *s1, const char *s2);
char				*ft_itoa_base(int32_t nbr, int32_t base);
char				*ft_itoa_base_custom(u_int64_t nbr, int32_t base);
char				*ft_itoa(int32_t n);
int8_t				ft_itoabuf(int number, char *buffer);
t_lst				*ft_lstappend(t_lst **alst, t_lst *new);
size_t				ft_lstlen(t_lst *lst);
t_lst				*ft_lstnew(const void *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dst, const void *s, size_t n);
void				ft_memdel(void **ap);
void				*ft_memset(void *s, int32_t c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
char				*ft_strcat(char *dst, const char *s);
char				*ft_strchr(const char *s, int32_t c);
size_t				ft_strclen(const char *s, int32_t c);
int32_t				ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *s);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s);
u_int8_t			ft_strequ(const char *s1, const char *s2);
int					ft_strisdigit(const char *str);
int8_t				ft_str_isprint(const char *str);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strjoinf(char *s1, char *s2, u_int8_t vars);
size_t				ft_strlen_to(const char *s, char c);
size_t				ft_strlen(const char *s);
void				*ft_strlower(char *s);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(const char *s, char *charset);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strsub_free
						(char const *s, unsigned int start, size_t len);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
void				ft_swap_int(int *nb1, int *nb2);
char				**ft_tabchr(char **tab_src, char *str);
char				**ft_tabcopy(char **tab_dest, char **tab_copy);
void				ft_tabdel(char ***array);
void				ft_tabfree(char **array);
size_t				ft_tablen(char **array);
int					ft_tolower(int c);
int					skip_opt(char **argv);
char				*ft_realloc(char *ptr, size_t size);

#endif
