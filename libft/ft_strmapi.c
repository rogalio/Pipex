/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:21:59 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 19:38:46 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/**
 * @file
 * @brief      Applique une fonction donnée à chaque caractère d'une chaîne de caractères en utilisant son index, puis crée une nouvelle chaîne avec les résultats.
 *
 * @param[in]  s     La chaîne de caractères source.
 * @param[in]  f     La fonction à appliquer à chaque caractère et son index.
 *
 * @return     Une nouvelle chaîne de caractères avec les résultats de l'application de la fonction à chaque caractère de la chaîne source, ou NULL en cas d'échec de l'allocation de mémoire.
 *
 * @details    La fonction ft_strmapi réalise les étapes suivantes :
 *             1. Alloue de la mémoire pour une nouvelle chaîne de caractères de la même taille que la chaîne source, plus un caractère pour le caractère de fin de chaîne ('\0').
 *             2. Si l'allocation de mémoire échoue, retourne NULL.
 *             3. Parcourt la chaîne source et applique la fonction `f` à chaque caractère en passant son index en paramètre, puis stocke le résultat dans la nouvelle chaîne.
 *             4. Ajoute le caractère de fin de chaîne à la fin de la nouvelle chaîne de caractères.
 *             5. Retourne la nouvelle chaîne de caractères.
 */
