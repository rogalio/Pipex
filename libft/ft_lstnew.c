/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:44:44 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/06 14:45:10 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
   	t_list *ptr;

    ptr = malloc(sizeof(t_list));
    if (!ptr)
        return (NULL);
    ptr->content = content;
    ptr->next = NULL;
    return (ptr);
}

/**
 * @file
 * @brief      Crée un nouvel élément de liste chaînée et l'initialise avec le contenu donné.
 *
 * @param[in]  content Le contenu à stocker dans le nouvel élément de la liste.
 *
 * @return     Un pointeur vers le nouvel élément de liste, ou NULL si l'allocation de mémoire échoue.
 *
 * @details    La fonction ft_lstnew procède comme suit :
 *             1. Alloue de la mémoire pour un nouvel élément de liste en utilisant la fonction `malloc`.
 *             2. Vérifie si l'allocation de mémoire a réussi. Si ce n'est pas le cas, retourne NULL.
 *             3. Initialise le membre `content` de la structure `t_list` avec le contenu donné en paramètre.
 *             4. Initialise le membre `next` de la structure `t_list` avec NULL.
 *             5. Retourne un pointeur vers le nouvel élément de liste.
 */