/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:55:07 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 15:36:38 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (src[len])
		len++;
	if (dstsize == 0)
		return (len);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (len);
}

/**
 * @file
 * @brief      Copie une chaîne de caractères vers une autre chaîne, avec une taille maximale spécifiée.
 *
 * @param[out] dst      Chaîne de caractères de destination.
 * @param[in]  src      Chaîne de caractères source à copier.
 * @param[in]  dstsize  Taille maximale de la chaîne de caractères de destination.
 *
 * @return     La longueur totale de la chaîne de caractères source.
 *
 * @details    La fonction ft_strlcpy procède comme suit :
 *             1. Calcule la longueur de la chaîne de caractères source.
 *             2. Si la taille de destination (dstsize) est égale à 0, retourne la longueur de la chaîne source.
 *             3. Copie la chaîne de caractères source dans la chaîne de caractères de destination, en respectant la taille maximale (dstsize - 1).
 *             4. Ajoute un caractère de fin de chaîne ('\0') à la fin de la chaîne de caractères de destination.
 *             5. Retourne la longueur totale de la chaîne de caractères source.
 */
