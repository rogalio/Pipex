/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:32:37 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/06 15:40:22 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

/**
 * @file
 * @brief      Ajoute un élément en tête de liste chaînée.
 *
 * @param[in]  lst   Un pointeur vers un pointeur de tête de liste chaînée.
 * @param[in]  new   Un pointeur vers l'élément à ajouter en tête de la liste chaînée.
 *
 * @details    La fonction ft_lstadd_front procède comme suit :
 *             1. Si la liste chaînée est vide (pointeur de tête est NULL), assigne simplement l'élément `new` comme tête de liste.
 *             2. Si la liste chaînée n'est pas vide, met à jour le pointeur `next` de l'élément `new` pour qu'il pointe vers l'élément actuel en tête de liste.
 *             3. Met à jour le pointeur de tête de liste pour qu'il pointe vers l'élément `new`.
 *
 *             En utilisant cette fonction, il est possible d'ajouter des éléments en tête d'une liste chaînée de manière efficace.
 */