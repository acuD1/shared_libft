/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_libft.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 12:36:29 by arsciand          #+#    #+#             */
/*   Updated: 2019/07/17 11:05:44 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_LIBFT_H
# define SHARED_LIBFT_H

# define BUFF_SIZE 4096
# define FD_MAXSET 4864

# include <string.h>
# include <stdlib.h>

/*
**		Structures
*/

typedef struct		s_lst
{
	void			*content;
	size_t			content_size;
	struct s_lst	*next;
}					t_lst;

/*
**		Fonctions
*/

int32_t				ft_atoi(const char *s);
void				ft_bzero(void *s, size_t n);
void				ft_tabdel(char ***tab);
char				*ft_itoa(int32_t n);
size_t				ft_lstlen(t_lst *lst);
t_lst				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstappend(t_lst **alst, t_lst *new);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dst, const void *s, size_t n);
void				*ft_memset(void *s, int32_t c, size_t len);
char				*ft_strcat(char *dst, const char *s);
size_t				ft_strclen(const char *s, int32_t c);
char				*ft_strchr(const char *s, int32_t c);
int32_t				ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *s);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s);
uint8_t				ft_strequ(const char *s1, const char *s2);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strjoinf(char *s1, char *s2, uint8_t vars);
size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t size);
char				**ft_strsplit(const char *s, char *charset);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
int32_t				ft_getnextline(const int fd, char **line);

#endif
