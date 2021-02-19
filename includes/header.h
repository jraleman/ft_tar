/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_archive.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 04:02:02 by jaleman           #+#    #+#             */
/*   Updated: 2018/01/27 04:02:03 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARCHIVE_H
# define FT_ARCHIVE_H

// Header files dependencies.
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <strings.h>

// Read block size.
// Used 512 bytes to copy tar's block size. :)
// Source: http://www.gnu.org/software/tar/manual/html_node/Blocking.html
# define BLOCK_SIZE	(512)

// Program return values
# define OK_CODE	(0)
# define ERR_USAGE	(1)
# define ERR_CREATE	(2)
# define ERR_OPEN	(3)

// Metadata structure
typedef struct	s_mdata
{
	char	name[100];
	char	mode[8];
	char	owner[8];
	char	group[8];
	char	size[12];
	char	modified[12];
	char	checksum[8];
	char	type[1];
	char	link[100];
	char	padding[255];
}	t_mdata;

int		usage_error(char *name);
int		archive_error(void);
void	expand_file(FILE *fp, size_t amount);
int		ft_archive(char *argv[], int argc);

#endif