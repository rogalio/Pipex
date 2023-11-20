/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:15:56 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 19:00:03 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *) s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/**
 * @file
 * @brief      Remplit une zone mémoire avec des octets nuls (0).
 *
 * @param[out] s  Pointeur vers la zone mémoire à remplir avec des octets nuls.
 * @param[in]  n  Nombre d'octets à remplir.
 *
 * @details    La fonction ft_bzero procède comme suit :
 *             1. Convertit le pointeur `void *` en un pointeur `char *`.
 *             2. Parcourt la zone mémoire à partir de l'adresse pointée par le pointeur converti.
 *             3. Remplit chaque octet de la zone mémoire avec la valeur 0.
 */