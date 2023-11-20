/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:47:29 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 19:02:37 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t i;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		++i;
	}
	return (b);
}




/**
 * @file
 * @brief      Remplit un bloc de mémoire avec une valeur donnée.
 *
 * @param[out] b     Pointeur vers le bloc de mémoire à remplir.
 * @param[in]  c     Valeur à utiliser pour le remplissage.
 * @param[in]  len   Nombre d'octets à remplir.
 *
 * @return     Pointeur vers le bloc de mémoire rempli.
 *
 * @details    La fonction ft_memset procède comme suit :
 *             1. Crée un pointeur non signé pour parcourir le bloc de mémoire.
 *             2. Copie la valeur donnée dans chaque octet du bloc de mémoire, en utilisant le pointeur pour le déplacement.
 *             3. Décrémente le compteur de taille à chaque copie.
 *             4. Retourne le pointeur vers le bloc de mémoire rempli.
 */