/*
** get_inst_code.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Feb 26 18:12:43 2016 Arthur Josso
** Last update Fri Mar 25 17:28:45 2016 Arthur Josso
*/

#include "op.h"
#include "my.h"

int	get_instruc_num(char *mnemo)
{
  int	i;

  i = 0;
  while (g_op_tab[i].mnemonique)
    {
      if (my_strcmp(g_op_tab[i].mnemonique, mnemo) == 0)
	return (i);
      i++;
    }
  return (0);
}
