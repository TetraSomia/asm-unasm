/*
** overflow.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Mar  6 11:34:04 2016 Arthur Josso
** Last update Sun Mar 27 13:05:23 2016 Arthur Josso
*/

#include "my.h"
#include "asm.h"
#include "op.h"

int	overflow_reg(const char *param, int line)
{
  int	reg_num;

  reg_num = my_getnbr(param + 1);
  if (reg_num <= 0 || reg_num > REG_NUMBER)
    return (err_at("No such register", line));
  return (0);
}

void	overflow_indirect(const char *param, int line)
{
  int	value;

  if (is_direct(param))
    value = my_getnbr(param + 1);
  else
    value = my_getnbr(param);
  if (my_strlen(param) > 5)
    warn_at("Indirection value overflow", line);
  else if (value < -IDX_MOD || value > IDX_MOD)
    warn_at("Indirection value overflow", line);
}

void    overflow_direct(const char *param, int line)
{
  int	i;

  i = 1;
  if (param[1] == '-')
    i++;
  while (param[i] == '0')
    i++;
  if (my_strlen(param) - i > 11)
    warn_at("Direct value overflow", line);
  if (my_getnbr(param + 1) != my_getlnbr(param + 1))
    warn_at("Direct value overflow", line);
}
