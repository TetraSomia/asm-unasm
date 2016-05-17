/*
** main.c for corewar in /home/josso/rendu/cpe/CPE_2015_corewar
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jan 26 15:42:08 2016 Arthur Josso
** Last update Tue Mar  8 11:20:44 2016 Arthur Josso
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

void	init_data(t_data *data)
{
  data->curs = 0;
  data->bytecode = NULL;
  data->lbl_list = NULL;
  data->lbl_ref = NULL;
  data->token = NULL;
}

int	freed_exit(t_data *data, int ret_value)
{
  free_all(data);
  return (ret_value);
}

int		main(int ac, char **av)
{
  t_data	data;

  if (ac != 2)
    return (err("USAGE : asm file_name[.s]\n"));
  init_data(&data);
  if (get_token(&data.token, av[1]) == 1)
    return (1);
  if (error_parsing(data.token) == 1)
    return (freed_exit(&data, 1));
  if (get_binary(&data) == 1)
    return (freed_exit(&data, 1));
  if (gen_file(&data, av[1]) == 1)
    return (freed_exit(&data, 1));
  return (freed_exit(&data, 0));
}
