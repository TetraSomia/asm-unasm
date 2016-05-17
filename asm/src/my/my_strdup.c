/*
** my_strdup.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Mar  1 10:26:33 2016 Arthur Josso
** Last update Tue Mar  1 14:34:36 2016 Arthur Josso
*/

#include <stdlib.h>
#include "my.h"

char	*my_strndup(const char *src, int len)
{
  char	*dest;
  int	i;

  if (src == NULL || (dest = malloc(len + 1)) == NULL)
    return (NULL);
  i = 0;
  while (src[i] && i < len)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char    *my_str_end_dup(const char *src, int beg)
{
  char  *dest;
  int   i;

  if (src == NULL ||
      my_strlen(src) - beg < 0 ||
      (dest = malloc(my_strlen(src) - beg + 1)) == NULL)
    return (NULL);
  i = 0;
  while (src[i + beg])
    {
      dest[i] = src[i + beg];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
