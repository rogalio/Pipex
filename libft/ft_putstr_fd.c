/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:13:18 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 19:30:49 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		ft_putchar_fd(*str++, fd);
}

/**
 * @file
 * @brief      Affiche une chaîne de caractères dans un fichier descripteur.
 *
 * @param[in]  str   Chaîne de caractères à afficher.
 * @param[in]  fd    Descripteur de fichier dans lequel afficher la chaîne de caractères.
 *
 * @details    La fonction ft_putstr_fd procède comme suit :
 *             1. Parcourt la chaîne de caractères en utilisant une boucle while.
 *             2. Écrit chaque caractère de la chaîne de caractères dans le fichier descripteur en utilisant la fonction `ft_putchar_fd`.
 */