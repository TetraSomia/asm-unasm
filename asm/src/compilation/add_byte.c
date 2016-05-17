/*
** add_byte.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Mar  1 14:27:17 2016 Arthur Josso
** Last update Thu Mar  3 14:05:21 2016 Arthur Josso
*/

#include <stdlib.h>
#include "asm.h"

int	add_byte(t_data *data, char byte)
{
  if ((data->bytecode = realloc(data->bytecode, data->curs + 1)) == NULL)
    return (1);
  data->bytecode[data->curs] = byte;
  data->curs++;
  return (0);
}
