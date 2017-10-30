/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildnumber_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 09:53:21 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/30 09:55:02 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDNUMBER_INTERNAL_H
# define BUILDNUMBER_INTERNAL_H

/*
** Theses versions are the buildnumber versions
*/

# define MAJOR_VERSION 1
# define MINOR_VERSION 0

# define MAX_BUILDS 9999
# define MIN_BUILDS -999

# define LINE_NUMBER 27

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "buildnumber.h"

# include "libcbc/libftprintf/includes/ftprintf.h"
# include "libcbc/libft/includes/libft.h"

void	bn_print_header(int fd);
void	bn_print_infile(int fd, int build_number);

#endif
