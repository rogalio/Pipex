/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:11:54 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 19:02:13 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*ptr;

	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	if (nitems > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nitems * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nitems * size);
	return (ptr);
}

/**
 * @file
 * @brief      Alloue et initialise un espace mémoire pour un certain nombre d'éléments de taille donnée.
 *
 * @param[in]  nitems  Nombre d'éléments à allouer.
 * @param[in]  size    Taille en octets de chaque élément.
 *
 * @return     Pointeur vers l'espace mémoire alloué et initialisé à zéro, ou NULL si l'allocation échoue ou provoque un débordement de size_t.
 *
 * @details    La fonction ft_calloc procède comme suit :
 *             1. Si nitems ou size est égal à zéro, les remplace par 1 pour garantir l'allocation de mémoire.
 *             2. Vérifie si l'allocation provoque un débordement de size_t en comparant nitems et SIZE_MAX / size. Si un débordement est détecté, retourne NULL.
 *             3. Alloue un espace mémoire suffisant pour contenir `nitems` éléments de taille `size`.
 *             4. Vérifie si l'allocation a réussi. Si ce n'est pas le cas, retourne NULL.
 *             5. Initialise l'espace mémoire alloué à zéro en utilisant la fonction `ft_memset`.
 *             6. Retourne le pointeur vers l'espace mémoire alloué et initialisé.
 */
