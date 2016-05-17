/*
** get_param_type.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Mar  1 14:11:51 2016 Arthur Josso
** Last update Tue Mar 29 11:04:40 2016 Arthur Josso
*/

#include "op.h"
#include "asm.h"

static char	get_type(const char *param)
{
  if (is_reg(param))
    return (1);
  else if (is_direct(param) ||
	   (is_lbl_ref(param) && param[0] == DIRECT_CHAR))
    return (2);
  else if (is_indirect(param) ||
	   (is_lbl_ref(param) && param[0] == LABEL_CHAR))
    return (3);
  else
    return (0);
}

char	get_param_type(char **params)
{
  char	type;
  int	offset;
  int	i;

  type = 0;
  offset = 6;
  i = 0;
  while (params[i])
    {
      type ^= get_type(params[i]) << offset;
      offset -= 2;
      i++;
    }
  return (type);
}
