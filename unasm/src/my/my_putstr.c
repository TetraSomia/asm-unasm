/*
** my_putstr.c for my in /home/josso/rendu/cpe/CPE_2015_corewar/bonus/unasm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Mar 10 12:46:55 2016 Arthur Josso
** Last update Thu Mar 10 12:48:09 2016 Arthur Josso
*/

#include <unistd.h>

static void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(const char *s)
{
  int	i;

  i = 0;
  while (s && s[i])
    my_putchar(s[i++]);
}
