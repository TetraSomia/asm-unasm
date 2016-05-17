/*
** unasm.c for unasm in /home/josso/rendu/cpe/CPE_2015_corewar/bonus/unasm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Mar 10 13:05:18 2016 Arthur Josso
** Last update Fri Mar 11 17:32:15 2016 Arthur Josso
*/

#include "unasm.h"
#include "op.h"
#include "my.h"

static int	get_instruc(t_data *data)
{
  int		i;

  i = 0;
  while (op_tab[i].code)
    {
      if (op_tab[i].code == data->bytecode[data->curs])
	{
	  if (add_word(data, op_tab[i].mnemonique) == 1)
	    return (-1);
	  if (inc_curs(data) == 1)
	    return (-1);
	  return (i);
	}
      i++;
    }
  return (-1);
}

static int	decode_line(t_data *data)
{
  int		instruc;
  char		arg_type[MAX_ARGS_NUMBER];

  if ((instruc = get_instruc(data)) == -1)
    return (err(1));
  if (get_arg_type(data, instruc, arg_type) == 1)
    return (1);
  data->curs--;
  if (decode_arg(data, instruc, arg_type) == 1)
    return (1);
  return (0);
}

int	unasm(t_data *data)
{
  data->curs = 0;
  while (data->curs < data->len)
    {
      if (add_line(data) == 1)
	return (1);
      if (decode_line(data) == 1)
	return (1);
      data->curs++;
    }
  add_line_to_lbl(data);
  if (verif_label(data) == 1)
    return (1);
  return (0);
}
