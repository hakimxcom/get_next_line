/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhakim <hhakim>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:44:12 by hhakim            #+#    #+#             */
/*   Updated: 2023/02/17 13:12:48 by hhakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//finds 'n' in currentline
//retruns a cpy of the past chars before '\n' *PAST LINE*
char	*ft_line_dilemeter(char *current_lines)
{
	int	i;
	int	j;
	char *line;

	i = 0;
	j = 0;
	if (!current_lines)
		return (NULL);
	while (current_lines[i] && !ft_isnewline(current_lines))
		i++;
	i++;
	line = (char *)malloc(sizeof(char)* (i + 1));
	if (!line)
		return (NULL);
	while (current_lines[j] && !ft_isnewline(current_lines) && j <= i);
	{
		line[j] = current_lines[j];
		j ++;
	}
	if (ft_isnewline(&current_lines[j]))
	{	
		line[j] = '\n';
		j++;
	}
	line[j] = 0;
	return (line);
}
//read and save the line being read inputs fd, and char *
//returns new created str with muliple lines
char	*ft_read_lines(int fd, char *current_lines)
{
	char	*temp_line;
	int		nbyts;

	nbyts = 1;
	temp_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_line)
		return (NULL);
	while(!ft_isnewline(current_lines) && nbyts)
	{
		nbyts = read(fd, temp_line, BUFFER_SIZE);
		if (nbyts == -1)
			return(free(temp_line), NULL);
		temp_line[nbyts] = 0;
		current_lines = ft_join(current_lines, temp_line);

	}
	return(free(temp_line), current_lines);
}
//read a file through fd(int) and returns a ptr to the begining of the line
//that was read (until end of line \n or EOF)
char	*get_next_line(int fd)
{
	char	*current_line;
	static char	*next_lines;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next_lines = ft_read_lines(fd, next_lines);
	if (!next_lines)
		return (NULL);
	current_line = ft_line_dilemeter(next_lines); 
	if (!next_lines)
		return (NULL);
	next_lines = ft_read_next_lines(next_lines);
	return (current_line);
}

 #include <stdio.h>
 #include <fcntl.h>
 
int main()
{
    char *line; 
	int fd1;
    int fd2;
    int fd3;
	int	i;

    fd1 = open("test1", O_RDONLY);
    fd2 = open("test2", O_RDONLY);
    fd3 = open("test3", O_RDONLY);
	i = 0; 
	while (i < 10)
	{
		line = get_next_line(fd1); 
		printf(" the line is %d : %s", i, line);
		free(line);
		i ++;
	}
	
}