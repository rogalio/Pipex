/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:07:37 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 19:47:43 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strtrim(char const *s1, char const *set)
 
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	j = len - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j]))
		j--;
	len = j - i + 1;
	str = ft_substr(s1, i, len);
	return (str);
}

/**
 * @file
 * @brief      Supprime les caractères spécifiés en début et fin de chaîne de caractères.
 *
 * @param[in]  s1   Chaîne de caractères à traiter.
 * @param[in]  set  Chaîne de caractères contenant les caractères à supprimer.
 *
 * @return     Un pointeur vers une nouvelle chaîne de caractères allouée dynamiquement, sans les caractères spécifiés en début et fin, ou NULL si l'allocation de mémoire a échoué.
 *
 * @details    La fonction ft_strtrim procède comme suit :
 *             1. Vérifie que les deux chaînes de caractères d'entrée (s1 et set) ne sont pas NULL.
 *             2. Trouve les indices du premier et du dernier caractère de la chaîne s1 qui ne sont pas dans la chaîne set.
 *             3. Crée une nouvelle chaîne de caractères en utilisant la fonction `ft_substr`, en se basant sur les indices trouvés précédemment.
 *             4. Retourne un pointeur vers la nouvelle chaîne de caractères.
 */