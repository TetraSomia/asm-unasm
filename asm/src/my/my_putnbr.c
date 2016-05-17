/*
** my_putnbr.c for my in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Mar  5 14:32:04 2016 Arthur Josso
** Last update Sat Mar  5 14:47:07 2016 Arthur Josso
*/

#include <unistd.h>

static void	putchar_err(char c)
{
  write(2, &c, 1);
}

void    my_putnbr(int nb)
{
  int   mult;

  if (nb < 0)
    {
      putchar_err('-');
      nb *= -1;
    }
  mult = 1;
  while (mult <= nb)
    mult *= 10;
  mult /= 10;
  if (mult == 0)
    putchar_err('0');
  while (mult != 0)
    {
      putchar_err(nb / mult + '0');
      nb %= mult;
      mult /= 10;
    }
}
