/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:26:23 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 17:17:16 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)str;
	while (ptr[i])
		i++;
	while (i > 0)
	{
		if (ptr[i] == (char)c)
			return (&ptr[i]);
		i--;
	}
	if (ptr[i] == (char)c)
		return (&ptr[i]);
	return (NULL);
}

/**
 * @file
 * @brief      Recherche la dernière occurrence d'un caractère dans une chaîne de caractères.
 *
 * @param[in]  str  Chaîne de caractères dans laquelle effectuer la recherche.
 * @param[in]  c    Caractère à rechercher.
 *
 * @return     Un pointeur vers la dernière occurrence du caractère recherché, ou NULL s'il n'est pas présent dans la chaîne.
 *
 * @details    La fonction ft_strrchr procède comme suit :
 *             1. Trouve la longueur de la chaîne de caractères d'entrée.
 *             2. Parcourt la chaîne de caractères en partant de la fin, jusqu'au début.
 *             3. Compare chaque caractère de la chaîne avec le caractère recherché (c).
 *             4. Si une correspondance est trouvée, retourne un pointeur vers cette dernière occurrence du caractère recherché.
 *             5. Si aucune correspondance n'est trouvée, retourne NULL.
 */