/*
** error.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Mar  5 15:35:58 2016 Arthur Josso
** Last update Fri Mar 25 20:38:41 2016 Arthur Josso
*/

#include "asm.h"
#include "op.h"
#include "my.h"

static int	check_arg(const char *token, int line, int instruc, int arg)
{
  int		arg_type;

  arg_type = get_arg_type(token, line, is_index(instruc, arg));
  if (arg_type < 0)
    return (1);
  else if ((g_op_tab[instruc].type[arg] & arg_type) == 0)
    return (err_at("The argument given to the instruction is invalid", line));
  return (0);
}

static int	line_err(char ***token, int line)
{
  int		i;
  int		instruc;
  int		nb_arg;
  int		arg;

  i = 0;
  if (is_lbl_list(token[line][i]))
    i++;
  if (!token[line][i])
    return (0);
  if (!is_instruc(token[line][i]))
    return (err_at("Invalid instruction", line));
  instruc = get_instruc_num(token[line][i++]);
  nb_arg = get_nb_arg(token[line] + i);
  if (nb_arg < g_op_tab[instruc].nbr_args)
    return (err_at("Too few arguments given to the instruction", line));
  else if (nb_arg > g_op_tab[instruc].nbr_args)
    return (err_at("Too many arguments given to the instruction", line));
  arg = i;
  while (token[line][arg++])
    if (check_arg(token[line][arg - 1], line, instruc, arg - 1 - i) == 1)
      return (1);
  return (0);
}

static int	line_loop(char ***token)
{
  int		i;

  i = 0;
  while (token[i])
    {
      if (token[i][0]
	  && my_strcmp(token[i][0], COMMENT_CMD_STRING) != 0
	  && my_strcmp(token[i][0], NAME_CMD_STRING) != 0)
	{
	  if (line_err(token, i) == 1)
	    return (1);
	}
      i++;
    }
  return (0);
}

static int	is_item(char ***token)
{
  int		i;

  i = 0;
  if (!token)
    return (0);
  while (token[i])
    {
      if (token[i][0])
	return (1);
      i++;
    }
  return (0);
}

int     error_parsing(char ***token)
{
  if (is_item(token) == 0)
    return (err("Your file is empty\n"));
  if (line_loop(token) == 1)
    return (1);
  return (0);
}
