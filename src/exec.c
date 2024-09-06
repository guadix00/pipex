/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:40:23 by gualvare          #+#    #+#             */
/*   Updated: 2024/09/06 19:01:17 by gualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*find_path(char *command, char **env)
{
	int		i;
	char	**get_paths;
	char	*tmp_join;
	char	*path;

	i = 0;
	while (env[i] && ft_strnstr(env[i], "PATH", 4) == NULL)
		i++;
	get_paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (get_paths[i])
	{
		tmp_join = ft_strjoin(get_paths[i], "/");
		path = ft_strjoin(tmp_join, command);
		free(tmp_join);
		if (access(path, X_OK) == 0)
		{
			free_all(get_paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_all(get_paths);
	return (0);
}

void	execute_command(t_pipex *pipex, char **cmd, char *path)
{
	if (!path)
	{
		free_pipex(pipex);
		handle_exit(NOT_FOUND);
	}
	if (execve(path, cmd, pipex->env) == -1)
	{
		free_pipex(pipex);
		handle_exit("Execve");
	}
}
