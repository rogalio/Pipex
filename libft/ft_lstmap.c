/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:15:24 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 19:09:35 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void	*), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	new = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}

/**
 * @file
 * @brief      Crée une nouvelle liste chaînée en appliquant une fonction à chaque élément d'une liste existante.
 *
 * @param[in]  lst   Un pointeur vers la tête de la liste chaînée existante.
 * @param[in]  f     Un pointeur vers une fonction qui prend en charge l'application d'une opération sur le contenu de chaque élément de la liste.
 * @param[in]  del   Un pointeur vers une fonction de suppression qui libère la mémoire du contenu des éléments en cas d'erreur lors de la création de la nouvelle liste.
 *
 * @return     Un pointeur vers la nouvelle liste chaînée, ou NULL si une erreur s'est produite.
 *
 * @details    La fonction ft_lstmap procède comme suit :
 *             1. Vérifie si les paramètres `lst` et `f` sont valides, sinon retourne NULL.
 *             2. Initialise un pointeur `new` pour la nouvelle liste chaînée et le met à NULL.
 *             3. Parcourt la liste chaînée existante avec une boucle `while` qui continue tant que le pointeur `lst` n'est pas NULL.
 *             4. À chaque itération, crée un nouvel élément `tmp` en utilisant la fonction `ft_lstnew` avec le résultat de l'application de la fonction `f` au contenu de l'élément courant.
 *             5. Vérifie si l'allocation de `tmp` a réussi, sinon libère la mémoire de la nouvelle liste et retourne NULL.
 *             6. Ajoute l'élément `tmp` à la fin de la nouvelle liste en utilisant la fonction `ft_lstadd_back`.
 *             7. Met à jour le pointeur `lst` pour qu'il pointe vers l'élément suivant de la liste chaînée existante.
 *             8. Retourne un pointeur vers la tête de la nouvelle liste chaînée.
 *
 *             Cette fonction permet de créer une nouvelle liste chaînée en appliquant une fonction `f` à chaque élément d'une liste existante. La nouvelle liste est indépendante de l'ancienne, ce qui signifie que les modifications apportées à l'une n'affectent pas l'autre.
 */