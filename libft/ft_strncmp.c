/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:38:06 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 19:39:59 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;
	
	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

/**
 * @file
 * @brief      Compare lexicographiquement les n premiers caractères de deux chaînes de caractères.
 *
 * @param[in]  s1        Première chaîne de caractères à comparer.
 * @param[in]  s2        Deuxième chaîne de caractères à comparer.
 * @param[in]  n         Nombre de caractères à comparer.
 *
 * @return     Un entier inférieur, égal, ou supérieur à zéro, si s1 est respectivement inférieure, égale ou supérieure à s2.
 *
 * @details    La fonction ft_strncmp procède comme suit :
 *             1. Itère sur les deux chaînes de caractères jusqu'à atteindre le nombre de caractères spécifié par n ou jusqu'à atteindre la fin de l'une des deux chaînes.
 *             2. Compare chaque caractère des deux chaînes de caractères. Si un caractère différent est trouvé, retourne la différence entre les valeurs des caractères.
 *             3. Si aucun caractère différent n'est trouvé après la comparaison des n caractères ou à la fin des chaînes de caractères, retourne 0 pour indiquer que les chaînes sont égales.
 */
