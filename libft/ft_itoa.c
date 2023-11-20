/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:23:42 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 19:45:22 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	ft_numlen(int n)
{
	int		len;
	unsigned int un;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		un = (unsigned int)(-n);
	}
	else
		un = (unsigned int)n;
	while (un > 0)
	{
		un /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*res;
	int		len;
	unsigned int	un;

	len = ft_numlen(n);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		res[0] = '-';
		un = (unsigned int)(-n);
	}
	else
		un = (unsigned int)n;
	while (un > 0)
	{
		res[--len] = (un % 10) + '0';
		un /= 10;
	}
	return (res);
}

/**
 * @file
 * @brief      Convertit un entier (int) en une chaîne de caractères (char *).
 *
 * @param[in]  n     Entier (int) à convertir en chaîne de caractères.
 *
 * @return     Pointeur vers la chaîne de caractères résultante, ou NULL si l'allocation échoue.
 *
 * @details    La fonction ft_itoa procède comme suit :
 *             1. Calcule la longueur nécessaire pour la chaîne de caractères avec la fonction `ft_numlen`.
 *             2. Alloue un espace mémoire suffisant pour contenir la chaîne de caractères, y compris le caractère null de fin.
 *             3. Vérifie si l'allocation a réussi. Si ce n'est pas le cas, retourne NULL.
 *             4. Traite le cas où n est égal à 0, en assignant le caractère '0' à la première position de la chaîne.
 *             5. Traite le cas où n est négatif, en ajoutant un signe moins en début de chaîne et convertissant n en positif.
 *             6. Convertit les chiffres de l'entier en caractères et les insère dans la chaîne de caractères.
 *             7. Retourne le pointeur vers la chaîne de caractères résultante.
 */