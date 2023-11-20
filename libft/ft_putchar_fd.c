/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:10:17 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/05 14:06:51 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

/**
 * @file
 * @brief      Écrit un caractère dans un fichier descripteur.
 *
 * @param[in]  c     Caractère à écrire.
 * @param[in]  fd    Descripteur de fichier dans lequel écrire le caractère.
 *
 * @details    La fonction ft_putchar_fd procède comme suit :
 *             1. Utilise la fonction `write` pour écrire le caractère dans le fichier descripteur.
 */