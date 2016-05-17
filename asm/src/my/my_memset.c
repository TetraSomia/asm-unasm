/*
** my_memset.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Mar  2 16:45:39 2016 Arthur Josso
** Last update Wed Mar  2 16:48:19 2016 Arthur Josso
*/

void	my_memset(void *ptr, char c, int size)
{
  char	*s;
  int	i;

  s = ptr;
  i = 0;
  while (i < size)
    s[i++] = c;
}
