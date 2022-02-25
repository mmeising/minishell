/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 20:59:34 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/05 00:01:05 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 *	puts rest of buffer after \n to the beginning, filling with \0
 */
static char	*ft_rest(char **buf, int fd, int *read_flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[fd][i] != '\n' && *read_flag > 0)
		i++;
	i++;
	while (buf[fd][i])
	{
		buf[fd][j] = buf[fd][i];
		i++;
		j++;
	}
	while (j < BUFFER_SIZE)
	{
		buf[fd][j] = '\0';
		j++;
	}
	if (buf[fd][0] == '\0')
	{
		free(buf[fd]);
		buf[fd] = NULL;
	}
	return (buf[fd]);
}

/* 
 * increases n by BUFFER_SIZE, mallocs a new ret of the new size, copies
 * everything over, null-terminates, frees old ret
 */
static char	*ft_realloc(char *ret_old, int *n)
{
	char	*ret;
	int		i;

	i = 0;
	*n += BUFFER_SIZE;
	ret = ft_calloc(sizeof(char), *n + 1);
	while (ret_old[i])
	{
		ret[i] = ret_old[i];
		i++;
	}
	free(ret_old);
	ret_old = NULL;
	return (ret);
}

/*
 *	clears buffer, resets r, re-reads (returns 0 if that fails)
 */
static int	ft_finished_buf(char **buf, int fd, int *r, int *read_flag)
{
	ft_bzero(buf[fd], BUFFER_SIZE + 1);
	*r = 0;
	*read_flag = read(fd, buf[fd], BUFFER_SIZE);
	if (*read_flag <= 0)
		return (0);
	return (1);
}

/*	
 *	starting main loop which runs until newline or end of file is found, 
 *	pasting each character into the return string, reallocating the string 
 *	and re-reading into the buffer as needed
 */
static char	*gnl_main(char **buf, char *ret, int fd, int *n)
{
	int	r;
	int	read_flag;
	int	w;

	read_flag = 1;
	r = 0;
	w = 0;
	if (buf[fd][0] == '\0')
		read_flag = read(fd, buf[fd], BUFFER_SIZE);
	if (read_flag <= 0)
		return (ft_read_fail(buf, fd, ret));
	while (buf[fd][r] != '\n' && read_flag > 0)
	{
		if (w == *n - 1)
			ret = ft_realloc(ret, n);
		ret[w] = buf[fd][r];
		w++;
		r++;
		if (buf[fd][r] == '\0')
			ft_finished_buf(buf, fd, &r, &read_flag);
	}
	if (buf[fd][r] == '\n')
		ret[w] = buf[fd][r];
	buf[fd] = ft_rest(buf, fd, &read_flag);
	return (ret);
}

/*
 *  setting everything up as needed
 */
char	*get_next_line(int fd)
{
	static char	*buf[10240];
	char		*ret;
	int			n;

	n = BUFFER_SIZE;
	ret = ft_calloc(sizeof(*ret), n + 1);
	if (ret == NULL)
		return (NULL);
	if (buf[fd] == NULL)
		buf[fd] = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (buf[fd] == NULL)
		return (NULL);
	ret = gnl_main(buf, ret, fd, &n);
	return (ret);
}
