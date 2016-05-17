/*
** my_getnbr.c for my in /home/josso/rendu/cpe/CPE_2015_corewar/asm/src/my
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jan 26 17:42:49 2016 Arthur Josso
** Last update Sun Mar 27 13:02:13 2016 Arthur Josso
*/

#include "my.h"

int	my_getnbr(const char *s)
{
  int	is_neg;
  int	nb;

  nb = 0;
  is_neg = *s == '-' ? ((unsigned long)(++s) && 1) : 0;
  while (*s)
    nb = (nb << 3) + (nb << 1) + (*s++ & 0xF);
  return ((nb ^ -is_neg) + is_neg);
}

long	my_getlnbr(const char *s)
{
  int	is_neg;
  long	nb;

  nb = 0;
  is_neg = *s == '-' ? ((unsigned long)(++s) && 1) : 0;
  while (*s)
    nb = (nb << 3) + (nb << 1) + (*s++ & 0xF);
  return ((nb ^ -is_neg) + is_neg);
}

unsigned int	my_getunbr(const char *s)
{
  int		len;
  unsigned int	ret;
  long		mult;

  ret = 0;
  len = -1;
  mult = 1;
  while (s && s[++len]);
  len--;
  while (len >= 0)
    {
      ret += mult * (s[len] - '0');
      mult *= 10;
      len--;
    }
  return (ret);
}
