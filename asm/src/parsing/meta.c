/*
** meta.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Mar 25 20:18:01 2016 Arthur Josso
** Last update Sun Mar 27 12:29:54 2016 Arthur Josso
*/

#include <stdlib.h>
#include "op.h"
#include "my.h"
#include "asm.h"

static int	mult_def(t_data *data, int *name_line, int *comm_line)
{
  int		i;
  int		comm_counter;
  int		name_counter;

  i = -1;
  comm_counter = 0;
  name_counter = 0;
  while (data->token[++i])
    {
      if (my_strcmp(data->token[i][0], NAME_CMD_STRING) == 0)
	{
	  *name_line = i;
	  name_counter++;
	}
      if (my_strcmp(data->token[i][0], COMMENT_CMD_STRING) == 0)
	{
	  *comm_line = i;
	  comm_counter++;
	}
      if (name_counter > 1)
	return (error("Multiple definition of .name"));
      if (comm_counter > 1)
	return (error("Multiple definition of .comment"));
    }
  return (0);
}

static int	too_much_name(char **tok)
{
  int		i;
  int		ended;

  i = -1;
  while (tok[++i])
    if (i > 0)
      return (1);
  if (i == 0)
    return (1);
  if (tok[0][0] != '"')
    return (1);
  i = 1;
  ended = 0;
  while (tok[0][i])
    {
      if (tok[0][i] == '"' && !tok[0][i + 1])
	ended = 1;
      else if (tok[0][i] == '"')
	return (1);
      i++;
    }
  if (!ended)
    return (1);
  return (0);
}

static void	epur_str_of_quote(char *s)
{
  int		i;

  i = 0;
  while (s[i + 2])
    {
      s[i] = s[i + 1];
      i++;
    }
  s[i] = '\0';
}

int	parse_meta(t_data *data)
{
  int	comm_line;
  int	name_line;

  comm_line = -1;
  if (mult_def(data, &name_line, &comm_line) == 1)
    return (1);
  if (comm_line != -1)
    {
      if (too_much_name(data->token[comm_line] + 1) == 1)
	return (error("Bad .comment syntax"));
      epur_str_of_quote(data->token[comm_line][1]);
      if (my_strlen(data->token[comm_line][1]) > COMMENT_LENGTH)
	return (error("Program comment is too long"));
    }
  if (too_much_name(data->token[name_line] + 1) == 1)
    return (error("Bad .name syntax"));
  epur_str_of_quote(data->token[name_line][1]);
  if (my_strlen(data->token[name_line][1]) > PROG_NAME_LENGTH)
    return (error("Program name is too long"));
  return (0);
}
