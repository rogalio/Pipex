/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:00:11 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/06 16:02:35 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del) (void *))
{
	del(lst->content);
	free(lst);
}

/**
 * @file
 * @brief      Supprime un élément d'une liste chaînée et libère la mémoire associée.
 *
 * @param[in]  lst   Un pointeur vers l'élément à supprimer de la liste chaînée.
 * @param[in]  del   Un pointeur vers une fonction qui prend en charge la suppression et la libération du contenu de l'élément de la liste.
 *
 * @details    La fonction ft_lstdelone procède comme suit :
 *             1. Appelle la fonction `del` avec le contenu de l'élément `lst` pour supprimer et libérer la mémoire associée au contenu.
 *             2. Libère la mémoire associée à l'élément `lst` lui-même en utilisant la fonction `free`.
 *
 *             Cette fonction permet de supprimer un élément d'une liste chaînée tout en libérant la mémoire associée au contenu de l'élément et à l'élément lui-même.
 *             Notez que cette fonction ne met pas à jour les liens entre les autres éléments de la liste chaînée. Pour supprimer correctement un élément et mettre à jour les liens, vous devrez implémenter une autre fonction qui ajuste les pointeurs `next` des éléments adjacents avant d'appeler ft_lstdelone.
 */