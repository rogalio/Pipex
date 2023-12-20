/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:22:07 by rogalio           #+#    #+#             */
/*   Updated: 2023/12/14 13:19:58 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	args_count_valid(int argc)
{
	if (argc != 5)
		throw_error("Invalid number of arguments");
	return (0);
}

int	check_valid_arguments(int argc, char **argv)
{
	args_count_valid(argc);
	check_file(argv[1], R_OK);
	return (0);
}
