/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_libft.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 12:36:29 by arsciand          #+#    #+#             */
/*   Updated: 2020/05/07 14:12:59 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_LIBFT_H
# define SHARED_LIBFT_H

# define BUFF_SZ	4096
# define FD_MAXSET	4864
# define SUCCESS	0
# define FAILURE	-1
# define FALSE		0
# define TRUE		1

# include <sys/types.h>
# include "ft_printf.h"
# include <stdint.h>
# include <stddef.h>

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
size_t				ft_decade(int32_t nbr);
u_int64_t			ft_get_options(int argc, char **argv, char *allowed);
int					get_next_line(int fd, char **line);
void				remove_invalid_char(char *buff);
int32_t				ft_getnextline(const int fd, char **line);
int8_t				ft_is_number(const char *s);
u_int8_t			ft_is_print(int16_t c);
int8_t				ft_isalnum(int16_t c);
int16_t				ft_isalpha(int16_t c);
int16_t				ft_isblank(int16_t c);
int16_t				ft_isdigit(int16_t c);
u_int8_t			ft_isnum(char *str);
u_int8_t			ft_isstart(const char *s1, const char *s2);
char				*ft_itoa_base(int32_t nbr, int32_t base);
char				*ft_itoa_base_custom(u_int64_t nbr, int32_t base);
char				*ft_itoa(int32_t n);
int8_t				ft_itoabuf(int32_t number, char *buffer);
t_lst				*ft_lstappend(t_lst **alst, t_lst *new);
size_t				ft_lstlen(t_lst *lst);
t_lst				*ft_lstnew(const void *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dst, const void *s, size_t n);
void				ft_memdel(void **ap);
void				*ft_memset(void *s, int16_t c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putnbr_fd(int32_t n, int fd);
void				ft_putnbr(int32_t n);
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
size_t				ft_strisdigit(const char *str);
u_int8_t			ft_str_isprint(const char *str);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strjoinf(char *s1, char *s2, u_int8_t vars);
size_t				ft_strlen_to(const char *s, char c);
size_t				ft_strlen(const char *s);
void				*ft_strlower(char *s);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int32_t				ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
u_int8_t			ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strrchr(const char *s, int16_t c);
char				**ft_strsplit(const char *s, char *charset);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strsub_free
						(char const *s, unsigned int start, size_t len);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
void				ft_swap_int(int32_t *nb1, int32_t *nb2);
char				**ft_tabchr(char **tab_src, char *str);
char				**ft_tabcopy(char **tab_dest, char **tab_copy);
void				ft_tabdel(char ***array);
void				ft_tabfree(char **array);
size_t				ft_tablen(char **array);
int16_t				ft_tolower(int16_t c);
size_t				skip_opt(char **argv);
char				*ft_realloc(char *ptr, size_t size);
void				ft_lstsort(t_lst **lst, int (*cmp)(void *, void *));
int					ft_lstcmp(void *data1, void *data2);
void				ft_lstdel(t_lst **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_lst **alst, void (*del)(void *, size_t));

#endif
