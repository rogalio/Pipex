/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:35:07 by rogalio           #+#    #+#             */
/*   Updated: 2023/12/14 11:40:02 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	file_exists(char *filename)
{
	struct stat	buffer;

	return (stat(filename, &buffer) == 0);
}

int	is_directory(char *filename)
{
	struct stat	buffer;

	if (stat(filename, &buffer) == 0)
		return (S_ISDIR(buffer.st_mode));
	return (0);
}

int	file_has_permission(char *filename, int mode)
{
	return (access(filename, mode) == 0);
}

void	check_file(char *filename, char permission)
{
	if (!file_exists(filename))
		throw_error("File does not exist");
	if (is_directory(filename))
		throw_error("Given path is a directory");
	if (!file_has_permission(filename, permission))
		throw_error("File does not have the required permissions");
}
