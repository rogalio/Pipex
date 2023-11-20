/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:26:05 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 19:14:15 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *str, int c, size_t size)
{
	unsigned char	*ptr;
	unsigned char	chr;
	size_t		i;

	ptr = (unsigned char *)str;
	chr = (unsigned char)c;
	i = 0;
	while (i < size)
	{
		if (ptr[i] == chr)
			return (ptr + i);
		i++;
	}
	return (NULL);
}

/**
 * @file
 * @brief      Recherche un octet dans une zone mémoire.
 *
 * @param[in]  str   Pointeur vers la zone mémoire à analyser.
 * @param[in]  c     L'octet à rechercher (converti en `unsigned char`).
 * @param[in]  size  La taille de la zone mémoire à analyser.
 *
 * @return     Un pointeur vers l'octet recherché s'il est trouvé, sinon NULL.
 *
 * @details    La fonction ft_memchr procède comme suit :
 *             1. Convertit les pointeurs et les octets en `unsigned char`.
 *             2. Parcourt la zone mémoire à partir de l'adresse pointée par le pointeur converti.
 *             3. Compare chaque octet de la zone mémoire avec l'octet recherché.
 *             4. Si l'octet recherché est trouvé, retourne un pointeur vers cet octet.
 *             5. Si l'octet recherché n'est pas trouvé après avoir parcouru toute la zone mémoire, retourne NULL.
 */
