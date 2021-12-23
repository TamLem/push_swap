/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:21:41 by tlemma            #+#    #+#             */
/*   Updated: 2021/10/12 18:31:30 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	char	*cp_ret;
	char	*cp_s;

	if (s2 == NULL)
		return (s1);
	if (s1 == NULL)
		return (s2);
	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	cp_ret = ret;
	cp_s = s1;
	while (*cp_s)
		*cp_ret++ = *cp_s++;
	cp_s = s2;
	while (*cp_s)
		*cp_ret++ = *cp_s++;
	*cp_ret = '\0';
	ft_free(&s1);
	ft_free(&s2);
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		j;
	char	*subs;
	size_t	src_len;

	j = 0;
	src_len = ft_strlen(s);
	subs = malloc(sizeof(char) * (len + 1));
	if (subs != NULL)
	{
		while ((j < (int)len) && (start < src_len))
		{
			subs[j] = s[start];
			start++;
			j++;
		}
		subs[j] = '\0';
	}
	return (subs);
}
