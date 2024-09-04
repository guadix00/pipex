/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:44:00 by gualvare          #+#    #+#             */
/*   Updated: 2024/09/04 15:13:55 by gualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>

# define ERROR_ARGS "wrong number of aguments.\n"
# define ERROR_FORK "Fork.\n"
# define ERROR_OP "Error opening file.\n"
# define NOT_FOUND "Command not found.\n"
# define NO_PATH "Path not found.\n"
# define NULL_PATH "Environment variable PATH is missing.\n"

typedef struct s_pipex
{
	int		end[2];
	int		in_fd;
	int		out_fd;
	char	**cmd1;
	char	**cmd2;
	char	*path1;
	char	*path2;
	char	**env;
}	t_pipex;

int		handle_error(char *str);
void	handle_exit(char *str);
void	free_pipex(t_pipex *pipex);
void	close_ends(t_pipex *pipex);
void	free_all(char **array);
void	init_pipex(t_pipex *pipex, char **argv, char **env);
void	second_child_process(t_pipex *pipex, char **argv);
void	first_child_process(t_pipex *pipex, char **argv);
void	execute_command(t_pipex *pipex, char **cmd, char *path);
char	*find_path(char *command, char **env);
#endif
