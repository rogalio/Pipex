/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:04:46 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/06 16:07:46 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		*lst = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = *lst;
	}
	*lst = NULL;
}

/**
 * @file
 * @brief      Supprime tous les éléments d'une liste chaînée et libère la mémoire associée.
 *
 * @param[in]  lst   Un pointeur vers un pointeur vers la tête de la liste chaînée.
 * @param[in]  del   Un pointeur vers une fonction qui prend en charge la suppression et la libération du contenu de chaque élément de la liste.
 *
 * @details    La fonction ft_lstclear procède comme suit :
 *             1. Vérifie si les pointeurs `lst` et `del` sont valides (non NULL). Si l'un d'eux est NULL, la fonction retourne sans effectuer d'action.
 *             2. Initialise un pointeur temporaire `tmp` qui pointe vers la tête de la liste chaînée.
 *             3. Parcourt la liste chaînée en utilisant une boucle `while` qui continue tant que le pointeur temporaire `tmp` n'est pas NULL.
 *             4. À chaque itération de la boucle, met à jour le pointeur `*lst` pour qu'il pointe vers l'élément suivant de la liste chaînée.
 *             5. Appelle la fonction `del` avec le contenu de l'élément courant `tmp` pour supprimer et libérer la mémoire associée au contenu.
 *             6. Libère la mémoire associée à l'élément courant `tmp` lui-même en utilisant la fonction `free`.
 *             7. Met à jour le pointeur temporaire `tmp` pour qu'il pointe vers l'élément suivant de la liste chaînée (c'est-à-dire l'élément pointé par `*lst`).
 *             8. Une fois tous les éléments de la liste chaînée supprimés, affecte NULL à `*lst`.
 *
 *             Cette fonction permet de supprimer tous les éléments d'une liste chaînée et de libérer la mémoire associée à chaque élément et à son contenu.
 */