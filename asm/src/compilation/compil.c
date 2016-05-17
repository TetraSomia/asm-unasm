/*
** compil.c for ams in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Feb 29 19:06:57 2016 Arthur Josso
** Last update Fri Mar 25 17:28:28 2016 Arthur Josso
*/

#include <unistd.h>
#include "asm.h"
#include "op.h"
#include "my.h"

static int	add_args(t_data *data, char **param, int instruc)
{
  int		i;

  i = 0;
  while (param[i])
    {
      if (is_lbl_ref(param[i]) && add_lbl_ref(data, param[i]) == 1)
	return (1);
      if (is_reg(param[i]) && add_reg_value(data, param[i]) == 1)
	return (1);
      if (is_indirect(param[i]) || (is_direct(param[i]) &&
				    is_index(instruc, i + 1)))
	{
	  if (add_ind_value(data, param[i]) == 1)
	    return (1);
	}
      else if (is_direct(param[i]) && add_dir_value(data, param[i]) == 1)
	return (1);
      i++;
    }
  return (0);
}

static int	compil_line(t_data *data, char **line)
{
  int		i;
  int		instruc;

  i = 0;
  if (is_lbl_list(line[i]) && add_lbl_list(data, line[i++]) == 1)
    return (1);
  if (!line[i])
    return (0);
  instruc = get_instruc_num(line[i++]);
  if (add_byte(data, g_op_tab[instruc].code) == 1)
    return (1);
  if ((g_op_tab[instruc].nbr_args > 1 ||
       my_strcmp(g_op_tab[instruc].mnemonique, "aff") == 0)
      && add_byte(data, get_param_type(line + i)) == 1)
    return (1);
  if (add_args(data, line + i, instruc) == 1)
    return (1);
  return (0);
}

static int	compil_lines(t_data *data)
{
  int		i;

  i = 0;
  while (data->token[i])
    {
      data->curs_line = data->curs;
      if (data->token[i][0]
	  && my_strcmp(data->token[i][0], COMMENT_CMD_STRING) != 0
	  && my_strcmp(data->token[i][0], NAME_CMD_STRING) != 0
	  && compil_line(data, data->token[i]) == 1)
	return (err("Can't perform malloc\n"));
      i++;
    }
  if (lbl_unknown_ref(data))
    return (1);
  if (lbl_mult_def(data))
    return (1);
  add_labels(data);
  return (0);
}

int     get_binary(t_data *data)
{
  data->curs = 0;
  data->bytecode = NULL;
  data->lbl_list = NULL;
  data->lbl_ref = NULL;
  if (compil_lines(data) == 1)
    return (1);
  return (0);
}
