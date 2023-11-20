/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:56:16 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 19:47:22 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] && haystack[i + j] == needle[j] && i + j < len)
			j++;
		if (j == needle_len)
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}

/**
 * @file
 * @brief      Recherche une sous-chaîne dans une chaîne de caractères, en se limitant à une longueur donnée.
 *
 * @param[in]  haystack  Chaîne de caractères dans laquelle effectuer la recherche.
 * @param[in]  needle    Sous-chaîne de caractères à rechercher.
 * @param[in]  len       Longueur maximale de la chaîne de caractères dans laquelle effectuer la recherche.
 *
 * @return     Un pointeur sur le début de la première occurrence de la sous-chaîne dans la chaîne de caractères, ou NULL si la sous-chaîne n'a pas été trouvée.
 *
 * @details    La fonction ft_strnstr procède comme suit :
 *             1. Calcule la longueur de la sous-chaîne à rechercher (needle).
 *             2. Si la sous-chaîne est vide, retourne un pointeur vers le début de la chaîne de caractères haystack.
 *             3. Parcourt la chaîne de caractères haystack jusqu'à ce qu'une correspondance soit trouvée ou que la fin de la chaîne soit atteinte.
 *             4. Pour chaque caractère de haystack, vérifie s'il correspond au début de la sous-chaîne needle.
 *             5. Si une correspondance est trouvée, retourne un pointeur vers le début de cette occurrence dans la chaîne de caractères haystack.
 *             6. Si aucune correspondance n'est trouvée, retourne NULL.
 */