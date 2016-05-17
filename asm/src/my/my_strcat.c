/*
** my_strcat.c for my in /home/josso/rendu/cpe/CPE_2015_corewar/asm/src/my
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jan 26 17:43:59 2016 Arthur Josso
** Last update Fri Feb 26 18:41:06 2016 Arthur Josso
*/

#include <stdlib.h>
#include "my.h"

int     my_strcat(char **dest, char *src)
{
  char  *str;
  int   len;
  int   i;
  int   j;

  len = my_strlen(*dest) + my_strlen(src);
  if ((str = malloc(len + 1)) == NULL)
    return (1);
  i = 0;
  j = 0;
  while (*dest && (*dest)[j])
    str[i++] = (*dest)[j++];
  j = 0;
  while (src && src[j])
    str[i++] = src[j++];
  str[i] = '\0';
  if (*dest)
    free(*dest);
  *dest = str;
  return (0);
}
