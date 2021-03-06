/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralverta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:37:52 by ralverta          #+#    #+#             */
/*   Updated: 2020/11/07 16:26:54 by ralverta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strlcpy(char *dst, char *src, int len)
{
	int	i;

	i = 0;
	while (len)
	{
		dst[i] = src[i];
		i++;
		len--;
	}
}
