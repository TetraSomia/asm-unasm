/*
** add.c for unasm in /home/josso/rendu/cpe/CPE_2015_corewar/bonus/unasm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Mar 10 12:20:40 2016 Arthur Josso
** Last update Fri Mar 11 17:38:55 2016 Arthur Josso
*/

#include <stdlib.h>
#include "my.h"
#include "unasm.h"

int	add_line(t_data *data)
{
  char	***tmp;
  int	*idx_tmp;
  int	i;

  i = 0;
  while (data->code && data->code[i])
    i++;
  if ((tmp = realloc(data->code, (i + 2) * sizeof(char**))) == NULL)
    return (err(0));
  data->code = tmp;
  data->code[i] = NULL;
  data->code[i + 1] = NULL;
  data->line += 1;
  data->curs_line = data->curs;
  i = 0;
  while (data->line_idx && data->line_idx[i] != -1)
    i++;
  if ((idx_tmp = realloc(data->line_idx, (i + 2) * sizeof(int))) == NULL)
    return (err(0));
  data->line_idx = idx_tmp;
  data->line_idx[i] = data->curs;
  data->line_idx[i + 1] = -1;
  return (0);
}

int	add_word(t_data *data, char *word)
{
  char	**tmp;
  int	i;

  i = 0;
  while (data->code[data->line] && data->code[data->line][i])
    i++;
  if ((tmp = realloc(data->code[data->line], (i + 2) * sizeof(char*))) == NULL)
    return (err(0));
  data->code[data->line] = tmp;
  data->code[data->line][i] = my_strdup(word);
  if (data->code[data->line][i] == NULL)
    return (err(0));
  data->code[data->line][i + 1] = NULL;
  return (0);
}
