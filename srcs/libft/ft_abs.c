/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:39:28 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/23 17:29:43 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Computes the absolute value of an integer */
int	ft_abs(int n)
{
	if (n < 0)
	{
		if (n == INT_MIN)
			return (INT_MAX);
		return (-n);
	}
	return (n);
}
