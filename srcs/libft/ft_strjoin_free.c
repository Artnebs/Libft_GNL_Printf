/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:34:14 by anebbou           #+#    #+#             */
/*   Updated: 2025/02/09 17:34:19 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin_free(char *s1, const char *s2)
{
	char *joined_str;
	size_t len1;
	size_t len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined_str = malloc(len1 + len2 + 1);
	if (!joined_str)
		return (NULL);
	ft_strlcpy(joined_str, s1, len1 + 1);
	ft_strlcat(joined_str, s2, len1 + len2 + 1);
	free(s1);
	return (joined_str);
}
