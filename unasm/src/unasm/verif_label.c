/*
** verif_label.c for unasm in /home/josso/rendu/cpe/CPE_2015_corewar/bonus/unasm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Mar 11 16:25:40 2016 Arthur Josso
** Last update Fri Mar 11 17:48:20 2016 Arthur Josso
*/

#include <stdlib.h>
#include "unasm.h"
#include "op.h"
#include "my.h"

void    add_line_to_lbl(t_data *data)
{
  int   i;
  int   idx;

  idx = 0;
  while (data->line_idx && data->line_idx[idx] != -1)
    {
      i = 0;
      while (data->label && data->label[i].name[0])
	{
	  if (data->label[i].address == data->line_idx[idx])
	    data->label[i].line = idx;
	  i++;
	}
      idx++;
    }
}

int	verif_label(t_data *data)
{
  int	i;
  char	*word;
  char	buff[BUFF_SIZE];

  i = 0;
  while (data->label && data->label[i].name[0])
    {
      if (data->label[i].line == -1)
	{
	  word = data->code[data->label[i].ex_line][data->label[i].ex_word];
	  free(word);
	  buff[0] = DIRECT_CHAR;
	  my_nbr_to_str(data->label[i].ex_value, buff + 1, BUFF_SIZE - 1);
	  word = my_strdup(buff);
	  if (word == NULL)
	    return (1);
	  data->code[data->label[i].ex_line][data->label[i].ex_word] = word;
	}
      i++;
    }
  return (0);
}
