/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:11:39 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/06 16:13:26 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*i;

	i = lst;
	while (i)
	{
		f(i->content);
		i = i->next;
	}
}

/**
 * @file
 * @brief      Applique une fonction à chaque élément d'une liste chaînée.
 *
 * @param[in]  lst   Un pointeur vers la tête de la liste chaînée.
 * @param[in]  f     Un pointeur vers une fonction qui prend en charge l'application d'une opération sur le contenu de chaque élément de la liste.
 *
 * @details    La fonction ft_lstiter procède comme suit :
 *             1. Initialise un pointeur `i` qui pointe vers la tête de la liste chaînée.
 *             2. Parcourt la liste chaînée en utilisant une boucle `while` qui continue tant que le pointeur `i` n'est pas NULL.
 *             3. À chaque itération de la boucle, appelle la fonction `f` avec le contenu de l'élément courant `i`.
 *             4. Met à jour le pointeur `i` pour qu'il pointe vers l'élément suivant de la liste chaînée.
 *
 *             Cette fonction permet d'appliquer une fonction `f` à chaque élément d'une liste chaînée sans modifier les liens entre les éléments. Elle est utile pour effectuer des opérations sur l'ensemble des éléments de la liste sans avoir besoin de les extraire un par un.
 */