/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:13:37 by gualvare          #+#    #+#             */
/*   Updated: 2024/09/06 15:38:51 by gualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	first_child_process(t_pipex *pipex, char **argv)
{
	pipex->in_fd = open(argv[1], O_RDONLY);
	if (pipex->in_fd == -1)
		handle_exit(ERROR_OP);
	if (dup2(pipex->in_fd, STDIN_FILENO) == -1)
		handle_exit("dup2");
	if (dup2(pipex->end[1], STDOUT_FILENO) == -1)
		handle_exit("dup2");
	close(pipex->end[0]);
	close(pipex->end[1]);
	execute_command(pipex, pipex->cmd1, pipex->path1);
}

void	second_child_process(t_pipex *pipex, char **argv)
{
	pipex->out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->out_fd == -1)
		handle_exit(ERROR_OP);
	if (dup2(pipex->end[0], STDIN_FILENO) == -1)
		handle_exit("dup2");
	if (dup2(pipex->out_fd, STDOUT_FILENO) == -1)
		handle_exit("dup2");
	close(pipex->end[1]);
	close(pipex->end[0]);
	execute_command(pipex, pipex->cmd2, pipex->path2);
}

void	init_pipex(t_pipex *pipex, char **argv, char **env)
{
	if ((env == NULL) || (*env == NULL))
		handle_exit(NULL_PATH);
	pipex->env = env;
	pipex->cmd1 = ft_split(argv[2], ' ');
	pipex->cmd2 = ft_split(argv[3], ' ');
	pipex->path1 = find_path(pipex->cmd1[0], env);
	pipex->path2 = find_path(pipex->cmd2[0], env);
	if (!pipex->path1 || !pipex->path2)
		handle_exit(NOT_FOUND);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		id1;
	int		id2;
	int		status;

	if (argc != 5)
		return (handle_error(ERROR_ARGS));
	init_pipex(&pipex, argv, env);
	if (pipe(pipex.end) == -1)
		handle_exit("pipe");
	id1 = fork();
	if (id1 == -1)
		handle_exit(ERROR_FORK);
	if (id1 == 0)
		first_child_process(&pipex, argv);
	id2 = fork();
	if (id2 == -1)
		handle_exit(ERROR_FORK);
	if (id2 == 0)
		second_child_process(&pipex, argv);
	close_ends(&pipex);
	waitpid(id1, &status, 0);
	waitpid(id2, &status, 0);
	free_pipex(&pipex);
}
