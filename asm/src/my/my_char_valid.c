/*
** my_char_valid.c for my in /home/josso/rendu/cpe/CPE_2015_corewar/asm/src/my
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jan 26 17:43:47 2016 Arthur Josso
** Last update Tue Jan 26 17:43:48 2016 Arthur Josso
*/

int     is_char_valid(char c, char *s)
{
  int   i;

  i = 0;
  while (s[i])
    {
      if (s[i] == c)
	return (1);
      else if (s[i] == '0' && c >= '0' && c <= '9')
	return (1);
      else if (s[i] == 'a' && c >= 'a' && c <= 'z')
	return (1);
      else if (s[i] == 'A' && c >= 'A' && c <= 'Z')
	return (1);
      i++;
    }
  return (0);
}
