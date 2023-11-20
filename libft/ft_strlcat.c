/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:05:53 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 16:19:35 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	if (dstsize < dst_len)
		return (src_len + dstsize);
	while (dst[i])
		i++;
	ft_strlcpy(dst + i, src, dstsize - dst_len);
	return (dst_len + src_len);
}

/**
 * @file
 * @brief      Concatène deux chaînes de caractères en une seule chaîne de caractères, en vérifiant la taille maximale autorisée pour la chaîne de destination.
 *
 * @param[out] dst        La chaîne de caractères de destination.
 * @param[in]  src        La chaîne de caractères source.
 * @param[in]  dstsize    La taille maximale autorisée pour la chaîne de caractères de destination.
 *
 * @return     La longueur totale de la chaîne qui aurait été créée si la taille maximale de destination avait été suffisante, sans tenir compte du caractère nul de fin.
 *
 * @details    La fonction ft_strlcat procède comme suit :
 *             1. Calcule la longueur totale de la chaîne de caractères source et de la chaîne de destination.
 *             2. Vérifie si la taille maximale autorisée pour la chaîne de destination est inférieure à la longueur de la chaîne de destination. Si c'est le cas, retourne la longueur de la chaîne source plus la taille maximale autorisée pour la chaîne de destination.
 *             3. Utilise ft_strlcpy pour copier la chaîne de caractères source à la fin de la chaîne de caractères de destination, en prenant soin de ne pas dépasser la taille maximale autorisée pour la chaîne de destination.
 *             4. Retourne la longueur totale de la chaîne qui aurait été créée si la taille maximale de destination avait été suffisante, sans tenir compte du caractère nul de fin.
 */
