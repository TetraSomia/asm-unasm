/*
** tab.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jan 29 13:02:12 2016 Arthur Josso
** Last update Sat Mar 26 16:56:04 2016 Arthur Josso
*/

#include <stdlib.h>
#include "asm.h"
#include "op.h"
#include "my.h"

static int	add_line(char **line, char ****tab)
{
  char          ***tmp;
  int           i;

  i = 0;
  while (*tab && (*tab)[i])
    i++;
  if ((tmp = realloc(*tab, (i + 2) * sizeof(char**))) == NULL)
    return (err("Can't perform malloc\n"));
  *tab = tmp;
  (*tab)[i] = line;
  (*tab)[i + 1] = NULL;
  return (SUCCESS);
}

int     get_tab_tab(int fd, char ****tab)
{
  char	**line;
  int	ret;

  while (42)
    {
      ret = get_tab_line(fd, &line);
      if (ret == ERROR)
	return (ERROR);
      if (line == NULL && ret != BAD_LINE)
	return (SUCCESS);
      if (ret == BAD_LINE)
	{
	  if ((line = malloc(sizeof(char*))) == NULL)
	    return (ERROR);
	  line[0] = NULL;
	  if (add_line(line, tab) == ERROR)
	    return (ERROR);
	}
      if (ret == SUCCESS && add_line(line, tab) == ERROR)
	return (ERROR);
    }
}
