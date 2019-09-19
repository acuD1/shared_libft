/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:51:25 by arsciand          #+#    #+#             */
/*   Updated: 2019/07/09 10:51:37 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;

	i = 0;
	if (!s)
		return (NULL);
	if (!(dst = ft_memalloc(len + 1)))
		return (NULL);
	while (i < len)
		dst[i++] = s[start++];
	dst[i] = '\0';
	return (dst);
}

char        *ft_wstrsub(wchar_t *ws, unsigned int start, size_t len)
{
    int     real_len;
    int     i;
    char    *fresh;

    real_len = 0;
    i = 0;
    while (ws[i] != '\0' && (int)len >= ft_wcharlen(ws[i]))
    {
        len -= ft_wcharlen(ws[i]);
        real_len += ft_wcharlen(ws[i]);
        i++;
    }
    fresh = ft_transform_wchar_in_char(ws);
    return (ft_strsub_with_free(fresh, start, real_len));
}

char        *ft_strsub_with_free(char const *s, unsigned int start, size_t len)
{
    char    *fresh;
    char    *tmp;
    int     i;

    tmp = NULL;
    if (!s)
        return (NULL);
    tmp = (char*)s;
    if (!(fresh = malloc((len + 1) * sizeof(char))))
        return (NULL);
    i = 0;
    if (!fresh)
        return (NULL);
    fresh[len] = '\0';
    while (len > 0)
    {
        fresh[i] = s[start];
        i++;
        start++;
        len--;
    }
    free(tmp);
    return (fresh);
}