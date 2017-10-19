/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:50:33 by wfung             #+#    #+#             */
/*   Updated: 2017/10/18 17:50:36 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//checks to see if all the characters inside .fdf are valid
//	i.e. 0 - 9, '-', 0x for hex, and spaces
//		spacing depends on the numbers?

//maybe add to libft?
static int		count_num_str(char *str, int n, char stop)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i] != stop)
	{
		if (str[i] >= '0' && str[i] <= '9' &&
				(str[i + 1] == ' ' || str[i + 1] == n
				 || str[i + 1] == stop))
			count++;
		i++;
	}
	return (count);
}
static int		parse_file(char **av, t_env *e)
{
	int			fd;
	char		*buff;

	e->row = 0;
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_puterror(".fdf file reading failed\n");
	while (get_next_line(fd, &buff) == 1)
	{
		e->col = count_num_str(buff, '\n', '\0');
		if (e->col != count_num_str(buff, '\n', '\0'))
		{
			close(fd);
			free(buff);
			ft_putstr("parse_file col count is not consistent\n");
			return (0);
		}
		free(buff);
		e->row = e->row + 1;
	}
	close(fd);
	if (e->row < 2 || e->col < 2)
	{
		ft_putstr("Invalid file contents: col or row off");
		return (0);
	}
	printf("parse row = %i\n", e->row);	//
	printf("parse col = %i\n", e->col);	//
	return (1);
}

static int		parse_contents(char **av)
{
	int		i;
	int		fd;
	char	*line;

	int		chk_line = 1;	//

	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_puterror(".fdf file reading failed\n");
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		while (line[i] != '\0')
		{
			if ((line[i] >= '0' && line[i] <= '9') || (line[i] == '-'
					&& line[i + 1] >= '0' && line[i + 1] <= '9')
				|| line[i] == ' ' || line[i] == '	')
				i++;
			else
			{
				printf("parse_contents line #%i char#%i fails\n", chk_line, i);	//
				free(line);
				close(fd);
				return (0);
			}
		}
		free(line);
		chk_line++;	//
	}
	printf("parse_contents chk line count [%i]\n", chk_line);//
	close(fd);
	return (1);
}

static void		parse_filename(char *str)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	if (i < 4)
		ft_puterror(".fdf file name invalid: file name too short");
	if (str[i] != 'f' && str[i - 1] != 'd' && str[i - 2] != 'f'
			&& str[i - 3] != '.')
		ft_puterror(".fdf file name invalid: file extension not correct");
}

t_env			*parse_fdf(char **av)
{
	t_env	*e;

	parse_filename(*av);
	if (parse_contents(av) == 0)
		ft_puterror(".fdf contents invalid");
	if (!(e = (t_env*)malloc(sizeof(t_env))))
		ft_puterror("struct malloc failed");
	if (parse_file(av, e) != 1)
	{
		free(e);
		ft_puterror(".fdf file contents invalid");
	}
	if (!(e->pts = create_struct(e->row, e->col)))
	{
		free(e);
		ft_puterror("struct malloc failed - array_int");
	}
	return (e);
}
