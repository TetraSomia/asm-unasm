/*
** get_arg_type.c for unasm in /home/josso/rendu/cpe/CPE_2015_corewar/bonus/unasm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Mar 10 13:36:10 2016 Arthur Josso
** Last update Tue Mar 29 17:51:23 2016 Arthur Josso
*/

#include "my.h"
#include "unasm.h"
#include "op.h"

static char	get_type(char val)
{
  int		i;
  char		ret;

  if (val == 0)
    return (0);
  i = 0;
  ret = 1;
  while (i++ < val - 1)
    ret *= 2;
  return (ret);
}

static int	is_index(int instruc, int param_num)
{
  if (my_strcmp(op_tab[instruc].mnemonique, "zjmp") == 0)
    return (1);
  else if (my_strcmp(op_tab[instruc].mnemonique, "fork") == 0)
    return (1);
  else if (my_strcmp(op_tab[instruc].mnemonique, "lfork") == 0)
    return (1);
  else if (my_strcmp(op_tab[instruc].mnemonique, "sti") == 0
	   && (param_num == 2 || param_num == 3))
    return (1);
  else if (my_strcmp(op_tab[instruc].mnemonique, "ldi") == 0
	   && (param_num == 1 || param_num == 2))
    return (1);
  else if (my_strcmp(op_tab[instruc].mnemonique, "lldi") == 0
	   && (param_num == 1 || param_num == 2))
    return (1);
  return (0);
}

int	get_arg_type(t_data *data, int instruc, char *arg_type)
{
  char	byte;
  int	i;

  if (op_tab[instruc].nbr_args == 1 &&
      my_strcmp(op_tab[instruc].mnemonique, "aff") != 0)
    {
      arg_type[0] = op_tab[instruc].type[0];
      if (arg_type[0] == T_DIR && is_index(instruc, 1))
	arg_type[0] = T_IDX;
      return (0);
    }
  byte = data->bytecode[data->curs];
  i = 0;
  while (i < 4)
    {
      arg_type[i] = get_type((byte >> (3 - i) * 2) & 0b11);
      if (arg_type[i] == T_DIR && is_index(instruc, i + 1))
	arg_type[i] = T_IDX;
      i++;
    }
  if (inc_curs(data) == 1)
    return (1);
  return (0);
}
