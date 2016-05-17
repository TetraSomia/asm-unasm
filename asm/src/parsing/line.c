/*
** line.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jan 29 14:03:19 2016 Arthur Josso
** Last update Sat Mar 26 16:55:36 2016 Arthur Josso
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"
#include "my.h"

static int      add_word(char *word, char ***line)
{
  char          **tmp;
  int		i;

  i = 0;
  while (*line && (*line)[i])
    i++;
  if ((tmp = realloc(*line, (i + 2) * sizeof(char*))) == NULL)
    return (err("Can't perform malloc\n"));
  *line = tmp;
  (*line)[i] = word;
  (*line)[i + 1] = NULL;
  return (SUCCESS);
}

static int	my_exit(int value, char *str)
{
  free(str);
  return (value);
}

int	get_tab_line(int fd, char ***line)
{
  char	*str;
  char	*word;
  int	ret;

  str = NULL;
  *line = NULL;
  if (((str = get_next_line(fd)) == NULL))
    return (SUCCESS);
  while (42)
    {
      ret = get_tab_word(str, &word, *line);
      if (ret != SUCCESS && ret != SUCCESS_STR)
	return (my_exit(ret, str));
      if (word == NULL)
	return (my_exit(SUCCESS, str));
      if (word[0] == COMMENT_CHAR && ret != SUCCESS_STR)
	{
	  free(word);
	  if (*line == NULL)
	    return (my_exit(BAD_LINE, str));
	  return (my_exit(SUCCESS, str));
	}
      if (add_word(word, line) == ERROR)
	return (my_exit(ERROR, str));
    }
}
