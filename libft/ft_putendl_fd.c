/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:14:29 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 19:30:39 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
}

/**
 * @file
 * @brief      Affiche une chaîne de caractères suivie d'un saut de ligne dans un fichier descripteur.
 *
 * @param[in]  str   Chaîne de caractères à afficher.
 * @param[in]  fd    Descripteur de fichier dans lequel afficher la chaîne de caractères.
 *
 * @details    La fonction ft_putendl_fd procède comme suit :
 *             1. Affiche la chaîne de caractères en utilisant la fonction `ft_putstr_fd`.
 *             2. Affiche un saut de ligne en utilisant la fonction `ft_putchar_fd`.
 */