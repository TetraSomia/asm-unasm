/*
** my_isnum.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Mar  3 15:09:05 2016 Arthur Josso
** Last update Thu Mar  3 15:18:14 2016 Arthur Josso
*/

#include "my.h"

int	is_num(const char *s)
{
  int	i;

  i = 0;
  if (!s[i])
    return (0);
  if (!is_char_valid(s[i++], "0-"))
    return (0);
  while (s[i])
    if (!is_char_valid(s[i++], "0"))
      return (0);
  if (i == 1 && s[0] == '-')
    return (0);
  return (1);
}
