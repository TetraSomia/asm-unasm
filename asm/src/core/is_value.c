/*
** is_value.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Mar  1 14:00:23 2016 Arthur Josso
** Last update Fri Mar 25 17:29:08 2016 Arthur Josso
*/

#include "my.h"
#include "op.h"

int	is_index(int instruc, int param_num)
{
  if (my_strcmp(g_op_tab[instruc].mnemonique, "zjmp") == 0)
    return (1);
  else if (my_strcmp(g_op_tab[instruc].mnemonique, "fork") == 0)
    return (1);
  else if (my_strcmp(g_op_tab[instruc].mnemonique, "lfork") == 0)
    return (1);
  else if (my_strcmp(g_op_tab[instruc].mnemonique, "sti") == 0
	   && (param_num == 2 || param_num == 3))
    return (1);
  else if (my_strcmp(g_op_tab[instruc].mnemonique, "ldi") == 0
	   && (param_num == 1 || param_num == 2))
    return (1);
  else if (my_strcmp(g_op_tab[instruc].mnemonique, "lldi") == 0
	   && (param_num == 1 || param_num == 2))
    return (1);
  return (0);
}

int     is_reg(const char *token)
{
  int   len;
  int	i;

  i = 0;
  len = my_strlen(token);
  if (token[i++] != 'r' || len < 2 || len > 10)
    return (0);
  while (i < len)
    if (!is_char_valid(token[i++], "0"))
      return (0);
  return (1);
}

int	is_direct(const char *token)
{
  if (token[0] != DIRECT_CHAR)
    return (0);
  if (!is_num(token + 1))
    return (0);
  return (1);
}

int	is_indirect(const char *token)
{
  if (is_num(token))
    return (1);
  return (0);
}
