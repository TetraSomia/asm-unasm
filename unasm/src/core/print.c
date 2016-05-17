/*
** print.c for unasm in /home/josso/rendu/cpe/CPE_2015_corewar/bonus/unasm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Mar 10 16:06:03 2016 Arthur Josso
** Last update Fri Mar 11 14:45:10 2016 Arthur Josso
*/

#include "unasm.h"
#include "my.h"
#include "op.h"

static int	is_instruc(const char *token)
{
  int   i;

  i = 0;
  while (op_tab[i].mnemonique)
    {
      if (my_strcmp(token, op_tab[i].mnemonique) == 0)
	return (1);
      i++;
    }
  return (0);
}

static void	print_header(char ***code)
{
  int           i;

  i = 0;
  while (i < 2)
    {
      my_putstr(code[i][0]);
      my_putstr(" ");
      my_putstr("\"");
      my_putstr(code[i][1]);
      my_putstr("\"");
      my_putstr("\n");
      i++;
    }
  my_putstr("\n");
}

static void	print_label(t_data *data, int line)
{
  int		i;

  i = 0;
  while (data->label && data->label[i].name[0])
    {
      if (data->label[i].line == line)
	{
	  my_putstr("\n");
	  my_putstr(data->label[i].name);
	  my_putstr(":\t");
	  return;
	}
      i++;
    }
  my_putstr("\t");
}

void    print_code(t_data *data, char ***code)
{
  int           i;
  int           j;
  int		arg;

  print_header(code);
  i = 2;
  while (code[i])
    {
      j = 0;
      arg = 0;
      print_label(data, i);
      while (code[i][j])
	{
	  my_putstr(code[i][j]);
	  if (arg && code[i][j + 1])
	    my_putstr(", ");
	  else if (code[i][j + 1])
	    my_putstr("\t");
	  if (is_instruc(code[i][j]))
	    arg = 1;
	  j++;
	}
      my_putstr("\n");
      i++;
    }
}
