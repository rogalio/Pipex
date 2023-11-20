/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:43:02 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 20:39:19 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptr_dest;
	char	*ptr_src;

	ptr_dest = (char *) dest;
	ptr_src = (char *) src;
	if (ptr_dest > ptr_src)
	{
		while (n > 0)
		{
			n--;
			ptr_dest[n] = ptr_src[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}


/**
 * @file
 * @brief      Copie n octets d'un bloc de mémoire vers un autre, gérant les chevauchements.
 *
 * @param[out] dest  Pointeur vers le bloc de mémoire de destination.
 * @param[in]  src   Pointeur vers le bloc de mémoire source.
 * @param[in]  n     Nombre d'octets à copier.
 *
 * @return     Pointeur vers le bloc de mémoire de destination.
 *
 * @details    La fonction ft_memmove procède comme suit :
 *             1. Crée des pointeurs pour parcourir les blocs de mémoire source et destination.
 *             2. Vérifie si les blocs de mémoire se chevauchent et détermine l'ordre de copie.
 *             3. Si le bloc de destination est après le bloc source, copie les octets en commençant par la fin.
 *             4. Si le bloc de destination est avant le bloc source, copie les octets en utilisant la fonction `ft_memcpy`.
 *             5. Retourne le pointeur vers le bloc de mémoire de destination.
 */
