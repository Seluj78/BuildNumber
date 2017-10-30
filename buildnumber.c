/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 05:24:50 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/30 09:57:49 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildnumber_internal.h"

void	bn_print_header(int fd);

int		buildnumber_options(int build_number, int argc, char **argv)
{
	if (ft_strncmp(argv[1], "--version", 9) == 0)
	{
		ft_printf("Buildnumber version %d.%d build " BUILDNUMBER_STR "\n",
				MAJOR_VERSION, MINOR_VERSION);
		exit(EXIT_SUCCESS);
	}
	else if (ft_strncmp(argv[1], "--help", 6) == 0)
	{
		printf("Buildnumber version %d.%d build " BUILDNUMBER_STR "\n",
				MAJOR_VERSION, MINOR_VERSION);
		printf("Usage: buildnumber [OPTION]\n\n");
		printf("Options:\n");
		printf("  [num]        create/update buildnumber.h using [num]\n");
		printf("  --version    display current verion (and exit)\n");
		printf("  --help       display this message (and exit)\n\n");
		exit(EXIT_SUCCESS);
	}
	build_number = atoi(argv[1]);
	if (build_number > MAX_BUILDS)
		build_number = MAX_BUILDS;
	else if (build_number < MIN_BUILDS)
		build_number = MIN_BUILDS;
	if (argc > 2)
		ft_dprintf(2, "BuildNumber: extra command-line options ignored\n");
	return (build_number);
}

int		set_new_buildnumber(int build_number, char *line, int i)
{
	size_t	length;

	if (i < LINE_NUMBER)
		build_number = 1;
	else
	{
		line[26] = '\0';
		length = ft_strlen(line);
		if (length >= 21 && length < 26)
		{
			build_number = ft_atoi(&line[21]);
			if (build_number > MAX_BUILDS)
				build_number = MAX_BUILDS;
			else if (build_number < MIN_BUILDS)
				build_number = MIN_BUILDS;
			else if (build_number < MAX_BUILDS)
				build_number++;
		}
		else
			build_number = 1;
	}
	return (build_number);
}

int		main_help(int build_number)
{
	FILE	*file;
	char	line[80];
	int		fd;
	int		i;

	fd = open("buildnumber.h", O_RDONLY);
	file = fopen("buildnumber.h", "r");
	if (fd == -1)
		build_number = 1;
	else
	{
		i = 0;
		while (i < LINE_NUMBER)
		{
			if ((fgets(line, 80, file) == NULL) || feof(file))
				break ;
			i++;
		}
		build_number = set_new_buildnumber(build_number, line, i);
		close(fd);
	}
	return (build_number);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		build_number;

	build_number = 0;
	if (argc > 1)
		build_number = buildnumber_options(build_number, argc, argv);
	if (build_number == 0)
		build_number = main_help(build_number);
	else
		ft_printf("BuildNumber: using command-line option as value\n");
	fd = open("buildnumber.h", O_WRONLY);
	if (fd == -1)
	{
		ft_dprintf(2, "BuildNumber: error creating buildnumber.h\n");
		return (1);
	}
	else
		bn_print_infile(fd, build_number);
	return (0);
}
