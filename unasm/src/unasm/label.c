/*
** label.c for unasm in /home/josso/rendu/cpe/CPE_2015_corewar/bonus/unasm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Mar 10 18:26:26 2016 Arthur Josso
** Last update Fri Mar 11 17:47:08 2016 Arthur Josso
*/

#include <stdlib.h>
#include "unasm.h"
#include "op.h"
#include "my.h"

static int	add_label(t_data *data, int addr, char *buff, int value)
{
  int   nb;

  nb = 0;
  while (data->label && data->label[nb].name[0])
    nb++;
  if ((data->label = realloc(data->label, (nb + 2) * sizeof(t_label))) == NULL)
    return (err(0));
  data->label[nb + 1].name[0] = '\0';
  data->label[nb].address = addr;
  my_strcpy(data->label[nb].name, "lbl_");
  my_nbr_to_str(nb + 1, data->label[nb].name + 4, BUFF_SIZE - 4);
  my_strcpy(buff, data->label[nb].name);
  data->label[nb].line = -1;
  data->label[nb].ex_line = data->line;
  data->label[nb].ex_word = 0;
  while (data->code[data->line] &&
	 data->code[data->line][data->label[nb].ex_word])
    data->label[nb].ex_word++;
  data->label[nb].ex_value = value;
  return (0);
}

static int	already_exists(t_data *data, int addr, char *buff)
{
  int		i;

  i = 0;
  while (data->label && data->label[i].name[0])
    {
      if (data->label[i].address == addr)
	{
	  my_strcpy(buff, data->label[i].name);
	  return (1);
	}
      i++;
    }
  return (0);
}

static int	is_correct_ref(t_data *data, int addr, int ref)
{
  int	i;

  if (ref >= data->len || addr == 0)
    return (0);
  i = 0;
  while (op_tab[i].code)
    {
      if (op_tab[i].code == data->bytecode[ref])
	return (1);
      i++;
    }
  return (0);
}

int	is_label(t_data *data, int addr, char *buff)
{
  int	ref;

  ref = (addr + data->curs_line) % 0x1000;
  if (!is_correct_ref(data, addr, ref))
    return (0);
  if (!already_exists(data, ref, buff))
    {
      if (add_label(data, ref, buff, addr) == 1)
	return (0);
    }
  return (1);
}
