/*
** get_info.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Mar  5 19:51:58 2016 Arthur Josso
** Last update Tue Mar 29 11:25:19 2016 Arthur Josso
*/

#include "asm.h"
#include "op.h"

char     get_arg_type(const char *param, int line, int is_index)
{
  if (is_reg(param))
    {
      if (overflow_reg(param, line))
	return (-1);
      return (T_REG);
    }
  else if (is_direct(param))
    {
      if (is_index)
	overflow_indirect(param, line);
      else
	overflow_direct(param, line);
      return (T_DIR);
    }
  else if (is_lbl_ref(param) && param[0] == DIRECT_CHAR)
    return (T_DIR);
  else if (is_lbl_ref(param) && param[0] == LABEL_CHAR)
    return (T_IND);
  else if (is_indirect(param))
    {
      overflow_indirect(param, line);
      return (T_IND);
    }
  else
    return (0);
}

int	get_nb_arg(char **line)
{
  int	i;

  i = 0;
  while (line && line[i])
    i++;
  return (i);
}
