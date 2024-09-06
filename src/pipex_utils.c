/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:40:12 by gualvare          #+#    #+#             */
/*   Updated: 2024/09/06 15:40:02 by gualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	free_pipex(t_pipex *pipex)
{
	if (pipex->cmd1)
		free_all(pipex->cmd1);
	if (pipex->cmd2)
		free_all(pipex->cmd2);
	if (pipex->path1)
		free(pipex->path1);
	if (pipex->path2)
		free(pipex->path2);
}

int	handle_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}

void	handle_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	close_ends(t_pipex *pipex)
{
	close(pipex->end[0]);
	close(pipex->end[1]);
}

void	free_all(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}
