/*
** put.c for unasm in /home/josso/rendu/cpe/CPE_2015_corewar/bonus/unasm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Mar 10 14:58:17 2016 Arthur Josso
** Last update Fri Mar 11 18:00:31 2016 Arthur Josso
*/

#include "unasm.h"
#include "op.h"
#include "my.h"

int	put_reg(t_data *data)
{
  char	buff[BUFF_SIZE];
  char	byte;

  if (inc_curs(data) == 1)
    return (1);
  byte = data->bytecode[data->curs];
  if (byte <= 0 || byte > REG_NUMBER)
    return (err(1));
  buff[0] = 'r';
  my_nbr_to_str((int)byte, buff + 1, BUFF_SIZE - 1);
  if (add_word(data, buff) == 1)
    return (1);
  return (0);
}

int		put_dir(t_data *data)
{
  char		buff[BUFF_SIZE];
  t_get_int	nb;
  int		i;

  i = DIR_SIZE - 1;
  while (i >= 0)
    {
      if (inc_curs(data) == 1)
	return (1);
      nb.byte[i] = data->bytecode[data->curs];
      i--;
    }
  buff[0] = DIRECT_CHAR;
  my_nbr_to_str(nb.nb, buff + 1, BUFF_SIZE - 1);
  if (add_word(data, buff) == 1)
    return (1);
  return (0);
}

int	put_ind(t_data *data)
{
  char          buff[BUFF_SIZE];
  t_get_int     nb;
  int		i;

  nb.byte[3] = 0;
  nb.byte[2] = 0;
  i = IND_SIZE - 1;
  while (i >= 0)
    {
      if (inc_curs(data) == 1)
	return (1);
      nb.byte[i] = data->bytecode[data->curs];
      i--;
    }
  my_nbr_to_str(nb.nb, buff, BUFF_SIZE);
  if (add_word(data, buff) == 1)
    return (1);
  return (0);
}

int	put_idx(t_data *data)
{
  char          buff[BUFF_SIZE];
  t_get_int     nb;
  int           i;

  nb.byte[3] = 0;
  nb.byte[2] = 0;
  i = IND_SIZE - 1;
  while (i >= 0)
    {
      if (inc_curs(data) == 1)
	return (1);
      nb.byte[i] = data->bytecode[data->curs];
      i--;
    }
  buff[0] = DIRECT_CHAR;
  if (is_label(data, nb.nb, buff + 2))
    buff[1] = LABEL_CHAR;
  else
    my_nbr_to_str(nb.nb, buff + 1, BUFF_SIZE - 1);
  if (add_word(data, buff) == 1)
    return (1);
  return (0);
}

int      decode_arg(t_data *data, int instruc, char *arg_type)
{
  int	arg;

  arg = 0;
  while (arg < op_tab[instruc].nbr_args)
    {
      if (arg_type[arg] == T_REG && put_reg(data) == 1)
	return (1);
      if (arg_type[arg] == T_DIR && put_dir(data) == 1)
	return (1);
      if (arg_type[arg] == T_IND && put_ind(data) == 1)
	return (1);
      if (arg_type[arg] == T_IDX && put_idx(data) == 1)
	return (1);
      arg++;
    }
  return (0);
}
