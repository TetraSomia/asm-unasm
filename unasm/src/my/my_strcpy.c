/*
** my_strcpy.c for my in /home/josso/rendu/cpe/CPE_2015_corewar/bonus/unasm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Mar 11 13:19:26 2016 Arthur Josso
** Last update Fri Mar 11 14:01:13 2016 Arthur Josso
*/

void	my_strcpy(char *dest, const char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
}
