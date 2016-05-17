/*
** my_err.c for my in /home/josso/rendu/cpe/CPE_2015_corewar/asm/src/my
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jan 26 17:44:36 2016 Arthur Josso
** Last update Sat Mar  5 15:53:31 2016 Arthur Josso
*/

#include <unistd.h>

void    my_putchar_err(char c)
{
  write(2, &c, 1);
}

int     err(const char *s)
{
  int   i;

  i = 0;
  while (s && s[i])
    my_putchar_err(s[i++]);
  return (1);
}
