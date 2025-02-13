/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:38:45 by anebbou           #+#    #+#             */
/*   Updated: 2025/02/13 16:48:22 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	append_number(char *dest, int pos, int n)
{
	char	*temp;
	int		i;
	int		len;

	temp = ft_itoa(n);
	if (!temp)
		return (0);
	i = 0;
	while (temp[i] != '\0')
	{
		dest[pos] = temp[i];
		pos++;
		i++;
	}
	len = i;
	free(temp);
	return (len);
}

static int	append_string(char *dest, int pos, char *str)
{
	while (*str != '\0')
	{
		dest[pos] = *str;
		pos++;
		str++;
	}
	return (pos);
}

static int	handle_format(char *dest, int pos, va_list args, char fmt)
{
	if (fmt == 's')
		return (append_string(dest, pos, va_arg(args, char *)));
	else if (fmt == 'd')
		return (pos + append_number(dest, pos, va_arg(args, int)));
	return (pos);
}

int	ft_sprintf(char *dest, const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	va_start(args, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%' && (fmt[i + 1] == 's' || fmt[i + 1] == 'd'))
		{
			pos = handle_format(dest, pos, args, fmt[i + 1]);
			i += 2;
		}
		else
		{
			dest[pos] = fmt[i];
			pos++;
			i++;
		}
	}
	dest[pos] = '\0';
	va_end(args);
	return (pos);
}
