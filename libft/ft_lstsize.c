/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:42:37 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/06 15:45:17 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = lst;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

/**
 * @file
 * @brief      Calcule et retourne la taille d'une liste chaînée.
 *
 * @param[in]  lst   Un pointeur vers la tête de la liste chaînée.
 *
 * @return     La taille de la liste chaînée (le nombre d'éléments qu'elle contient).
 *
 * @details    La fonction ft_lstsize procède comme suit :
 *             1. Initialise un compteur `i` à 0 et un pointeur `ptr` qui pointe vers la tête de la liste chaînée.
 *             2. Parcourt la liste chaînée en utilisant une boucle `while` qui continue tant que `ptr` n'est pas NULL.
 *             3. À chaque itération de la boucle, met à jour le pointeur `ptr` pour qu'il pointe vers l'élément suivant de la liste chaînée, et incrémente le compteur `i`.
 *             4. Retourne la valeur du compteur `i` après avoir parcouru toute la liste chaînée.
 *
 *             Cette fonction permet de déterminer rapidement la taille d'une liste chaînée en parcourant ses éléments.
 */