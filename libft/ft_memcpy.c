/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:56:45 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 19:29:33 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t n) 
{
	char        *ptr_dest = (char *)dest;
	const char  *ptr_src = (const char *)src;
	size_t      i = 0;

	while (i < n)
        {
		ptr_dest[i] = ptr_src[i];
		i++;
	}

	return (dest);
}

/**
 * @file
 * @brief      Copie les n premiers octets d'un bloc de mémoire source vers un bloc de mémoire destination.
 *
 * @param[out] dest  Pointeur vers le bloc de mémoire de destination.
 * @param[in]  src   Pointeur vers le bloc de mémoire source.
 * @param[in]  n     Nombre d'octets à copier.
 *
 * @return     Un pointeur vers le bloc de mémoire de destination.
 *
 * @details    La fonction ft_memcpy procède comme suit :
 *             1. Si n est égal à 0, retourne le pointeur dest (pas de copie).
 *             2. Crée deux pointeurs de caractères pour parcourir les blocs de mémoire.
 *             3. Copie les octets correspondants du bloc de mémoire source vers le bloc de mémoire destination.
 *             4. Si les octets ont été copiés et qu'il reste des octets à copier, passe aux octets suivants.
 *             5. Une fois que tous les octets ont été copiés, retourne le pointeur vers le bloc de mémoire de destination.
 */
