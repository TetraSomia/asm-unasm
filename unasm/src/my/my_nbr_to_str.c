/*
** my_nbr_to_str.c for swag in /home/alies_a/rendu/CPE_2015_corewar/bonus/unasm
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Mar 10 14:52:43 2016 alies_a
** Last update Thu Mar 10 17:35:17 2016 Arthur Josso
*/

void	my_nbr_to_str(long nb, char *buff, int buff_size)
{
  long	x;
  long	mul;

  x = 0;
  mul = 1;
  if (nb < 0)
    {
      buff[x] = '-';
      nb *= -1;
      x += 1;
    }
  while (mul <= nb / 10)
    mul *= 10;
  while (mul && x < (buff_size - 1))
    {
      buff[x] = (nb / mul % 10) + '0';
      x += 1;
      mul /= 10;
    }
  buff[x] = '\0';
}
