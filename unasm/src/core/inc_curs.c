/*
** inc_curs.c for unasm in /home/josso/rendu/cpe/CPE_2015_corewar/bonus/unasm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Mar 10 14:44:05 2016 Arthur Josso
** Last update Thu Mar 10 14:49:52 2016 Arthur Josso
*/

#include "unasm.h"
#include "my.h"

int	inc_curs(t_data *data)
{
  data->curs++;
  if (data->curs >= data->len)
    return (err(1));
  return (0);
}
