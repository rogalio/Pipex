/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:14:30 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 18:58:19 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int		sign;
	long	nbr;
	size_t	i;

	i = 0;
	sign = 1;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

/**
 * @file
 * @brief      Convertit une chaîne de caractères en entier (int) en respectant le signe (+ ou -).
 *
 * @param[in]  str   Chaîne de caractères constante (const char *) à convertir en entier.
 *
 * @return     Entier (int) résultant de la conversion de la chaîne de caractères en entrée.
 *
 * @details    La fonction ft_atoi fonctionne de la manière suivante :
 *             1. Initialisation des variables locales `sign` et `nbr` à 1 et 0 respectivement.
 *             2. Passage des éventuels espaces blancs en début de chaîne avec la fonction `ft_isspace`.
 *             3. Vérification de la présence d'un signe négatif en début de chaîne. Si présent, mise à jour de `sign`.
 *             4. Passage du signe si présent (+ ou -).
 *             5. Parcours de la chaîne et conversion des caractères numériques en entier.
 *             6. Retour de la valeur convertie, en tenant compte du signe.
 */