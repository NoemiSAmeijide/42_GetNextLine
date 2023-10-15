/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 22:09:52 by nosilves          #+#    #+#             */
/*   Updated: 2023/08/15 22:25:41 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
    int     fd;
    char    *linea;
    char    c;

    fd = open("tests/dua.txt", O_RDONLY);
    while ((linea = get_next_line(fd)))
    {
        printf("%s", linea);
        free(linea);
        c = getchar();
    }
    close(fd);
}