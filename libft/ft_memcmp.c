/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:36:35 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 19:28:30 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;
	size_t				j;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	j = 0;
	if (n == 0)
		return (0);
	while (i < n && str1[i] == str2[j])
	{
		j++;
		i++;
	}
	if (i == n)
		return (0);
	return (str1[i] - str2[j]);
}



/**
 * @file
 * @brief      Compare les octets de deux zones mémoire.
 *
 * @param[in]  s1    Pointeur vers la première zone mémoire à comparer.
 * @param[in]  s2    Pointeur vers la deuxième zone mémoire à comparer.
 * @param[in]  n     Nombre d'octets à comparer.
 *
 * @return     0 si les zones mémoire sont égales, sinon la différence entre les premiers octets non égaux (s1[i] - s2[j]).
 *
 * @details    La fonction ft_memcmp procède comme suit :
 *             1. Convertit les pointeurs en pointeurs `unsigned char`.
 *             2. Compare les octets des deux zones mémoire à l'aide d'une boucle.
 *             3. Si un nombre d'octets égal à `n` a été comparé sans trouver de différence, retourne 0.
 *             4. Si une différence est trouvée, retourne la différence entre les premiers octets non égaux (s1[i] - s2[j]).
 */