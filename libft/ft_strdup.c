/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:31:19 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 19:37:15 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;

	ptr =  malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, ft_strlen(s) + 1);
	return (ptr);
}




/**
 * @file
 * @brief      Duplique une chaîne de caractères.
 *
 * @param[in]  s     Chaîne de caractères à dupliquer.
 *
 * @return     Un pointeur vers une nouvelle chaîne de caractères allouée dynamiquement, ou NULL si l'allocation de mémoire a échoué.
 *
 * @details    La fonction ft_strdup procède comme suit :
 *             1. Alloue de la mémoire pour une nouvelle chaîne de caractères en utilisant la fonction `malloc`.
 *             2. Copie la chaîne de caractères d'entrée dans la nouvelle chaîne de caractères en utilisant la fonction `ft_strlcpy`.
 *             3. Retourne un pointeur vers la nouvelle chaîne de caractères.
 */