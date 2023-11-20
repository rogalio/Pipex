/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:54:25 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/06 15:58:17 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

/**
 * @file
 * @brief      Ajoute un nouvel élément à la fin d'une liste chaînée.
 *
 * @param[in]  lst     Un pointeur vers un pointeur vers la tête de la liste chaînée.
 * @param[in]  new     Un pointeur vers l'élément à ajouter à la fin de la liste chaînée.
 *
 * @details    La fonction ft_lstadd_back procède comme suit :
 *             1. Vérifie si les pointeurs `lst` et `new_` sont valides (non NULL). Si l'un d'eux est NULL, la fonction retourne sans effectuer d'action.
 *             2. Si la liste chaînée est vide (c'est-à-dire que `*lst` est NULL), affecte `new_lst` à `*alst` et retourne.
 *             3. Initialise un pointeur temporaire `tmp` qui pointe vers la tête de la liste chaînée.
 *             4. Parcourt la liste chaînée en utilisant une boucle `while` qui continue tant que le pointeur `next` de l'élément courant n'est pas NULL.
 *             5. À chaque itération de la boucle, met à jour le pointeur temporaire `tmp` pour qu'il pointe vers l'élément suivant de la liste chaînée.
 *             6. Une fois la fin de la liste chaînée atteinte, affecte `new_lst` au pointeur `next` de l'élément courant (le dernier élément de la liste chaînée).
 *
 *             Cette fonction permet d'ajouter un nouvel élément à la fin d'une liste chaînée en parcourant ses éléments et en gérant le cas où la liste est vide.
 */