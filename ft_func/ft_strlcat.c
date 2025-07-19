/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bann <oel-bann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 04:17:40 by oel-bann          #+#    #+#             */
/*   Updated: 2025/07/16 04:20:36 by oel-bann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_func.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dst_len == dstsize)
		return (dst_len + src_len);
	if (dst_len > dstsize)
		return (dstsize + src_len);
	if (dstsize == 0)
		return (src_len);
	while ((i + dst_len < dstsize - 1) && src[i])
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i + dst_len] = 0;
	return (src_len + dst_len);
}