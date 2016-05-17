/*
** my_strlen.c for corewar in /home/josso/rendu/cpe/CPE_2015_corewar/asm/src/my
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jan 26 17:40:53 2016 Arthur Josso
** Last update Tue Mar  1 12:08:01 2016 Arthur Josso
*/

int     my_strlen(const char *s)
{
  int   i;

  i = 0;
  while (s && s[i])
    i++;
  return (i);
}
