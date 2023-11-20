/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:16:41 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/08 19:49:16 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strchr(const char *str, int c)
{
	char	*ptr;
	size_t	i;

	ptr = (char *) str;
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == (char) c)
			return (&ptr[i]);
		i++;
	}
	if (ptr[i] == (char) c)
		return (&ptr[i]);
	return (NULL);
}


/**
 * @file
 * @brief      Cherche la première occurrence d'un caractère dans une chaîne de caractères.
 *
 * @param[in]  str   Chaîne de caractères dans laquelle chercher le caractère.
 * @param[in]  c     Caractère à chercher.
 *
 * @return     Un pointeur vers la première occurrence du caractère dans la chaîne de caractères, ou NULL s'il n'est pas trouvé.
 *
 * @details    La fonction ft_strchr procède comme suit :
 *             1. Parcourt la chaîne de caractères en utilisant une boucle while.
 *             2. Retourne un pointeur vers la première occurrence du caractère dans la chaîne de caractères, s'il est trouvé.
 *             3. Retourne NULL si le caractère n'est pas trouvé dans la chaîne de caractères.
 */