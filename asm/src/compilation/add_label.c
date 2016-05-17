/*
** add_label.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Feb 29 20:00:56 2016 Arthur Josso
** Last update Sat Mar 26 17:39:06 2016 Arthur Josso
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"
#include "my.h"

static void	insert_code(t_data *data, int lbl, int ref)
{
  short		value;
  char		byte;
  int           i;

  if (data->lbl_ref[lbl].index_line < data->lbl_list[ref].index_line)
    value = data->lbl_list[ref].index_line - data->lbl_ref[lbl].index_line;
  else
    value = 0xFFFF - data->lbl_ref[lbl].index_line
      + data->lbl_list[ref].index_line + 1;
  i = 1;
  while (i <= IND_SIZE)
    {
      byte = (value >> ((IND_SIZE - i) * BYTE_SIZE)) & 0xFF;
      data->bytecode[data->lbl_ref[lbl].index + i - 1] = byte;
      i++;
    }
}

void	add_labels(t_data *data)
{
  int	i;
  int	ref;

  i = 0;
  while (data->lbl_ref && data->lbl_ref[i].name)
    {
      ref = 0;
      while (my_strcmp(data->lbl_ref[i].name,
		       data->lbl_list[ref].name) != 0)
	ref++;
      insert_code(data, i, ref);
      i++;
    }
}

int	add_lbl_list(t_data *data, const char *label)
{
  int	nb;

  nb = 0;
  while (data->lbl_list && data->lbl_list[nb].name)
    nb++;
  if ((data->lbl_list =
       realloc(data->lbl_list, (nb + 2) * sizeof(t_label))) == NULL)
    return (1);
  data->lbl_list[nb].name = my_strndup(label, my_strlen(label) - 1);
  if (data->lbl_list[nb].name == NULL)
    return (1);
  data->lbl_list[nb].index_line = data->curs_line;
  data->lbl_list[nb + 1].name = NULL;
  return (0);
}

int	add_lbl_ref(t_data *data, const char *label)
{
  int	nb;

  nb = 0;
  while (data->lbl_ref && data->lbl_ref[nb].name)
    nb++;
  if ((data->lbl_ref =
       realloc(data->lbl_ref, (nb + 2) * sizeof(t_label))) == NULL)
    return (1);
  if (label[0] == DIRECT_CHAR)
    data->lbl_ref[nb].name = my_str_end_dup(label, 2);
  else
    data->lbl_ref[nb].name = my_str_end_dup(label, 1);
  if (data->lbl_ref[nb].name == NULL)
    return (1);
  data->lbl_ref[nb].index = data->curs;
  data->lbl_ref[nb].index_line = data->curs_line;
  data->lbl_ref[nb + 1].name = NULL;
  nb = 0;
  while (nb++ < IND_SIZE)
    if (add_byte(data, 0) == 1)
      return (1);
  return (0);
}
