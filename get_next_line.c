/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 19:35:54 by chsu              #+#    #+#             */
/*   Updated: 2018/11/15 16:02:49 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*get_cur_data(t_list **data, int fd)
{
	t_list	*cur;

	cur = *data;
	while (cur)
	{
		if ((int)(cur->content_size) == fd)
			return (cur);
		cur = cur->next;
	}
	cur = ft_lstnew(NULL, fd);
	cur->content_size = fd;
	ft_lstadd(data, cur);
	cur = *data;
	return (cur);
}

static int		copy_line_until(char **dst, char *src, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] == c)
			break ;
		i++;
	}
	if (!(*dst = ft_strnew(i)))
		return (0);
	while (src[j] && j < i)
	{
		(*dst)[j] = src[j];
		j++;
	}
	return (i);
}

static int		append_line(t_list *data, char **line)
{
	int		i;
	char	*tmp;

	i = copy_line_until(line, data->content, '\n');
	if (i < (int)ft_strlen(data->content))
	{
		tmp = ft_strdup((&(data->content)[i + 1]));
		free(data->content);
		data->content = tmp;
	}
	else
		ft_strclr(data->content);
	return (1);
}

static int		get_return_value(int ret, t_list *cur, char **line)
{
	if (ret < 0)
		return (-1);
	else if (ret < BUFF_SIZE && (!cur->content || !ft_strlen(cur->content)))
		return (0);
	else
		return (append_line(cur, line));
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*data;
	t_list			*cur;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	if (fd < 0 || !line)
		return (-1);
	cur = get_cur_data(&data, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!cur->content)
			cur->content = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(cur->content, buf);
			free(cur->content);
			cur->content = tmp;
		}
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (get_return_value(ret, cur, line));
}
