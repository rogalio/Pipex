/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:38:11 by rmouchel          #+#    #+#             */
/*   Updated: 2023/05/09 19:47:54 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    char *str;
    size_t i;
    size_t s_len;

    if (!s)
        return NULL;
    s_len = ft_strlen(s);
    if (start >= s_len)
        return ft_strdup("");
    if (len > s_len - start)
        len = s_len - start;
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return NULL;
    i = 0;
    while (s[start] && i < len)
        str[i++] = s[start++];
    str[i] = '\0';
    return str;
}

/**
 * @file
 * @brief      Extrait une sous-chaîne de caractères d'une chaîne donnée.
 *
 * @param[in]  s       La chaîne de caractères d'origine.
 * @param[in]  start   L'indice de départ de la sous-chaîne dans la chaîne d'origine.
 * @param[in]  len     La longueur maximale de la sous-chaîne à extraire.
 *
 * @return     La sous-chaîne extraite, ou NULL si l'allocation échoue.
 *
 * @details    La fonction ft_substr procède comme suit :
 *             1. Vérifie si la chaîne d'origine est NULL et retourne NULL si c'est le cas.
 *             2. Calcule la longueur de la chaîne d'origine.
 *             3. Si l'indice de départ est supérieur ou égal à la longueur de la chaîne d'origine, retourne une chaîne vide.
 *             4. Si la longueur demandée est supérieure à la longueur restante de la chaîne à partir de l'indice de départ, ajuste la longueur à extraire.
 *             5. Alloue de la mémoire pour la sous-chaîne extraite, incluant l'espace pour le caractère de fin de chaîne.
 *             6. Si l'allocation échoue, retourne NULL.
 *             7. Copie les caractères de la chaîne d'origine dans la sous-chaîne, en commençant à l'indice de départ et jusqu'à la longueur demandée.
 *             8. Ajoute le caractère de fin de chaîne à la sous-chaîne.
 *             9. Retourne la sous-chaîne extraite.
 */
