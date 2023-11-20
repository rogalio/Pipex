/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:54:09 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 19:38:02 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			n;
	char			*str;
	size_t			len;

	n = ft_strlen(s1);
	len = n + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, n + 1);
	ft_strlcpy(str + n, s2, len + 1);
	return (str);
}

/**
 * @file
 * @brief      Concatène deux chaînes de caractères en une seule chaîne de caractères.
 *
 * @param[in]  s1    La première chaîne de caractères à concaténer.
 * @param[in]  s2    La seconde chaîne de caractères à concaténer.
 *
 * @return     Un pointeur vers une nouvelle chaîne de caractères allouée dynamiquement, qui est la concaténation de `s1` et `s2`, ou NULL si l'allocation de mémoire a échoué.
 *
 * @details    La fonction ft_strjoin procède comme suit :
 *             1. Calcule la longueur totale de la nouvelle chaîne de caractères en utilisant la fonction `ft_strlen`.
 *             2. Alloue de la mémoire pour la nouvelle chaîne de caractères en utilisant la fonction `malloc`.
 *             3. Copie la première chaîne de caractères dans la nouvelle chaîne de caractères en utilisant la fonction `ft_strlcpy`.
 *             4. Concatène la seconde chaîne de caractères à la fin de la nouvelle chaîne de caractères en utilisant la fonction `ft_strlcat`.
 *             5. Retourne un pointeur vers la nouvelle chaîne de caractères.
 */
