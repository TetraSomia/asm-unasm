/*
** main.c for unasm in /home/josso/rendu/cpe/CPE_2015_corewar/bonus/unasm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Mar 10 10:35:13 2016 Arthur Josso
** Last update Fri Mar 11 17:41:19 2016 Arthur Josso
*/

#include <stdlib.h>
#include "unasm.h"
#include "op.h"
#include "my.h"

static void	init_data(t_data *data)
{
  data->curs = -2;
  data->curs_line = 0;
  data->line = -1;
  data->len = 0;
  data->bytecode = NULL;
  data->code = NULL;
  data->label = NULL;
  data->line_idx = NULL;
}

static void	free_all(t_data *data)
{
  int		i;
  int		j;

  i = 0;
  while (data->code[i])
    {
      j = 0;
      while (data->code[i][j])
	free(data->code[i][j++]);
      free(data->code[i]);
      i++;
    }
  free(data->code);
  free(data->bytecode);
  if (data->label)
    free(data->label);
  if (data->line_idx)
    free(data->line_idx);
}

int		main(int ac, char **av)
{
  t_data	data;

  if (ac != 2)
    return (my_put_err("USAGE : unasm file_name[.cor]\n"));
  init_data(&data);
  if (get_binary(&data, av[1]) == 1)
    return (1);
  if (unasm(&data) == 1)
    return (1);
  print_code(&data, data.code);
  free_all(&data);
  return (0);
}
