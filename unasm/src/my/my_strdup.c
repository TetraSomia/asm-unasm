/*
** my_strdup.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Mar  1 10:26:33 2016 Arthur Josso
** Last update Thu Mar 10 17:41:00 2016 Arthur Josso
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(const char *str)
{
  char  *dest;
  int   i;

  if (str == NULL || (dest = malloc(my_strlen(str) + 1)) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      dest[i] = str[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
