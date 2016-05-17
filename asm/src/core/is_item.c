/*
** is_item.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Feb 29 19:24:38 2016 Arthur Josso
** Last update Sat Mar 26 17:33:29 2016 Arthur Josso
*/

#include "op.h"
#include "my.h"

int	is_lbl_list(const char *token)
{
  int	i;

  i = 0;
  while (token[i])
    {
      if (!is_char_valid(token[i], "a") &&
	  !is_char_valid(token[i], "0") &&
	  !is_char_valid(token[i], "_") &&
	  token[i + 1])
	return (0);
      i++;
    }
  if (i > 1 && token[i - 1] == LABEL_CHAR)
    return (1);
  return (0);
}

int	is_lbl_ref(const char *token)
{
  int   i;

  i = 0;
  if (token[i] == DIRECT_CHAR)
    i++;
  if (token[i++] != LABEL_CHAR)
    return (0);
  while (token[i])
    {
      if (!is_char_valid(token[i], "a") &&
	  !is_char_valid(token[i], "0") &&
	  !is_char_valid(token[i], "_"))
	return (0);
      i++;
    }
  if (token[i - 1] == LABEL_CHAR)
    return (0);
  return (1);
}

int	is_instruc(const char *token)
{
  int	i;

  i = 0;
  while (g_op_tab[i].mnemonique)
    {
      if (my_strcmp(token, g_op_tab[i].mnemonique) == 0)
	return (1);
      i++;
    }
  return (0);
}
