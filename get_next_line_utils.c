/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhakim <hhakim>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:44:15 by hhakim            #+#    #+#             */
/*   Updated: 2023/02/17 13:16:21 by hhakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//checks for the char '\n' in str
//returns 1 if found, 0 otherwise
int	ft_isnewline(char *str)
{
	while(*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

//return the length of str
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0; 
	if (!str)
		return (0);
	while (str[i])
			i++;
	return (i);
}

// joins from src to dest into a newly created str
//retrun the new joint str
char	*ft_join( char *dest, char *src)
{
	//join src ino destination
}

//copies from src too dest
void	ft_strcpy(char *dest, char *src)
{
	if (!dest && !src)
		return (NULL);
	while (*dest)
		*dest++ = *src++;
	*dest = 0;
}
//read and save lines after a '\n'
char	*ft_read_next_lines(char *current_lines)
{
	int	i;
	int	j;
	char	*next_lines;

	i = 0;
	j = 0;
	while (current_lines[i] && !ft_isnewline(&current_lines[i]))
		i++;
	if (!current_lines[i])
		return (free(current_lines) NULL);
	next_lines = (char *)malloc(ft_strlen(current_lines) - i);
	if(!next_lines)
		return (NULL);
	i++;
	while(current_lines)
		ft_strcpy(next_lines, current_lines);
	return(free(current_lines), next_lines);
}