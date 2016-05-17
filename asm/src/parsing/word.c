/*
** word.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jan 29 16:01:12 2016 Arthur Josso
** Last update Sat Mar 26 17:26:38 2016 Arthur Josso
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"
#include "op.h"

static int      add_char(char c, char **word)
{
  char          *tmp;
  int		i;

  i = 0;
  while (*word && (*word)[i])
    i++;
  if ((tmp = realloc(*word, i + 2)) == NULL)
    return (err("Can't perform malloc\n"));
  *word = tmp;
  (*word)[i] = c;
  (*word)[i + 1] = '\0';
  return (SUCCESS);
}

static void     init(char **line, int *i, int *string, int *is_str)
{
  if (line == NULL)
    *i = 0;
  *string = 0;
  *is_str = 0;
}

static int	add_char_to_str(char c, char **word, char **line, int *string)
{
  if (c == '"' && line &&
      (my_strcmp(line[0], NAME_CMD_STRING) == 0 ||
       my_strcmp(line[0], COMMENT_CMD_STRING) == 0))
    *string = !(*string);
  if (add_char(c, word) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int             get_tab_word(char *str, char **word, char **line)
{
  static int	i;
  int		string;
  int		is_str;

  if (!str[0])
    return (BAD_LINE);
  init(line, &i, &string, &is_str);
  *word = NULL;
  while (str[i] && SEPAR(str[i]))
    i++;
  while (str[i] && (!SEPAR(str[i]) || string))
    {
      if (add_char_to_str(str[i], word, line, &string) == ERROR)
	return (ERROR);
      if (string)
	is_str = 1;
      i++;
    }
  if (string)
    return (error("String not ended (missing \' \" \')"));
  if (*word == NULL && line == NULL)
    return (BAD_LINE);
  return (is_str ? SUCCESS_STR : SUCCESS);
}
