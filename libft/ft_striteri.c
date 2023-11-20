/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:03:28 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 15:41:12 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}


/**
 * @file
 * @brief      Applique une fonction à chaque caractère d'une chaîne de caractères, en passant l'index et le caractère en tant que paramètres.
 *
 * @param[in,out]  s     Chaîne de caractères à modifier.
 * @param[in]      f     Pointeur vers la fonction à appliquer à chaque caractère.
 *
 * @details    La fonction ft_striteri procède comme suit :
 *             1. Parcourt la chaîne de caractères en utilisant une boucle while.
 *             2. Appelle la fonction `f` avec l'index de caractère et le caractère en tant que paramètres.
 */