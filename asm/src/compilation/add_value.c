/*
** add_value.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Mar  2 10:56:52 2016 Arthur Josso
** Last update Thu Mar  3 13:58:07 2016 Arthur Josso
*/

#include "asm.h"
#include "op.h"
#include "my.h"

int	add_ind_value(t_data *data, const char *param)
{
  short	value;
  char	byte;
  int	i;

  if (is_direct(param))
    value = my_getnbr(param + 1);
  else
    value = my_getnbr(param);
  i = 1;
  while (i <= IND_SIZE)
    {
      byte = (value >> ((IND_SIZE - i) * BYTE_SIZE)) & 0xFF;
      if (add_byte(data, byte) == 1)
	return (1);
      i++;
    }
  return (0);
}

int	add_dir_value(t_data *data, const char *param)
{
  int	value;
  char	byte;
  int	i;

  value = my_getnbr(param + 1);
  i = 1;
  while (i <= DIR_SIZE)
    {
      byte = (value >> ((DIR_SIZE - i) * BYTE_SIZE)) & 0xFF;
      if (add_byte(data, byte) == 1)
	return (1);
      i++;
    }
  return (0);
}

int	add_reg_value(t_data *data, const char *param)
{
  int	reg_num;

  reg_num = my_getnbr(param + 1);
  if (add_byte(data, reg_num) == 1)
    return (1);
  return (0);
}
