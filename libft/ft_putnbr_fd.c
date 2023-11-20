/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:19:50 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/05 18:12:37 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		c;
	long int	ln;

	ln = n;
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln = -ln;
	}
	if (ln > 9)
	{
		ft_putnbr_fd(ln / 10, fd);
	}
	c = '0' + (ln % 10);
	write(fd, &c, 1);
}

/**
 * @file
 * @brief      Écrit un nombre entier sur un descripteur de fichier spécifié.
 *
 * @param[in]  n    Le nombre entier à écrire.
 * @param[in]  fd   Le descripteur de fichier sur lequel écrire le nombre.
 *
 * @details    La fonction ft_putnbr_fd réalise les étapes suivantes :
 *             1. Convertit le nombre entier en long int pour gérer les nombres négatifs.
 *             2. Si le nombre est négatif, écrit le caractère '-' sur le descripteur de fichier et change le signe du nombre.
 *             3. Si le nombre est supérieur à 9, appelle récursivement ft_putnbr_fd avec le nombre divisé par 10.
 *             4. Convertit le dernier chiffre du nombre en caractère et l'écrit sur le descripteur de fichier.
 */