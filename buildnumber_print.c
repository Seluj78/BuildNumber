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

void	bn_print_header(int fd)
{
	ft_dprintf(fd, "/* ***********************************"
			"*************************************** */\n");
	ft_dprintf(fd, "/*                                    "
			"                                        */\n");
	ft_dprintf(fd, "/*                                          "
			"              :::      ::::::::   */\n");
	ft_dprintf(fd, "/*   buildnumber.h                          "
			"            :+:      :+:    :+:   */\n");
	ft_dprintf(fd, "/*                                          "
			"          +:+ +:+         +:+     */\n");
	ft_dprintf(fd, "/*   By: buildnumber <buildnumber@noemail.co"
			"m>      +#+  +:+       +#+        */\n");
	ft_dprintf(fd, "/*                                          "
			"      +#+#+#+#+#+   +#+           */\n");
	ft_dprintf(fd, "/*   Created: 1970/01/01 00:00:00 by buildnu"
			"mber       #+#    #+#             */\n");
	ft_dprintf(fd, "/*   Updated: 1970/01/01 00:00:00 by buildnu"
			"mber      ###   ########.fr       */\n");
	ft_dprintf(fd, "/*                                          "
			"                                  */\n");
	ft_dprintf(fd, "/* *****************************************"
			"********************************* */\n\n");
}

void	bn_print_infile(int fd, int build_number)
{
	bn_print_header(fd);
	ft_dprintf(fd, "#ifndef BUILDNUMBER_H\n");
	ft_dprintf(fd, "# define BUILDNUMBER_H\n\n");
	ft_dprintf(fd, "# define BUILDNUMBER %d\n", build_number);
	ft_dprintf(fd, "# define BUILDNUMBER_STR \"%d\"\n\n", build_number);
	ft_dprintf(fd, "#endif\n");
	close(fd);
	ft_printf("BuildNumber: new buildnumber is %d\n", build_number);
}
