/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:46:16 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/06 15:54:00 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*i;

	i = lst;
	if (!i)
		return (NULL);
	while (i->next)
		i = i->next;
	return (i);
}

/**
 * @file
 * @brief      Trouve et retourne le dernier élément d'une liste chaînée.
 *
 * @param[in]  lst   Un pointeur vers la tête de la liste chaînée.
 *
 * @return     Un pointeur vers le dernier élément de la liste chaînée, ou NULL si la liste est vide.
 *
 * @details    La fonction ft_lstlast procède comme suit :
 *             1. Initialise un pointeur `i` qui pointe vers la tête de la liste chaînée.
 *             2. Vérifie si la liste chaînée est vide (c'est-à-dire si `lst` est NULL). Si c'est le cas, retourne NULL.
 *             3. Parcourt la liste chaînée en utilisant une boucle `while` qui continue tant que le pointeur `next` de l'élément courant n'est pas NULL.
 *             4. À chaque itération de la boucle, met à jour le pointeur `i` pour qu'il pointe vers l'élément suivant de la liste chaînée.
 *             5. Retourne le pointeur `i` après avoir parcouru toute la liste chaînée, qui correspond au dernier élément de celle-ci.
 *
 *             Cette fonction permet de trouver rapidement le dernier élément d'une liste chaînée en parcourant ses éléments et en gérant le cas où la liste est vide.
 */