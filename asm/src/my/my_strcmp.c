/*
** my_strcmp.c for my in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jan 26 17:47:45 2016 Arthur Josso
** Last update Sat Mar  5 16:41:41 2016 Arthur Josso
*/

int     my_strcmp(const char *s1, const char *s2)
{
  int   i;

  if (!s1 && !s2)
    return (0);
  else if (!s1 || !s2)
    return (1);
  i = 0;
  while (!(s1[i] == 0 || s2[i] == 0))
    {
      if (s1[i] < s2[i])
	return (-1);
      else if (s1[i] > s2[i])
	return (1);
      i++;
    }
  if (s1[i] == 0 && s2[i] != 0)
    return (-1);
  else if (s2[i] == 0 && s1[i] != 0)
    return (1);
  else
    return (0);
}

int	my_strncmp(const char *s1, const char *s2, int n)
{
  int	i;

  if (!s1 && !s2)
    return (0);
  i = 0;
  while (i < n)
    {
      if (s1[i] < s2[i])
	return (-1);
      else if (s1[i] > s2[i])
	return (1);
      i++;
    }
  if (s1[i] == 0 && s2[i] != 0)
    return (-1);
  else if (s2[i] == 0 && s1[i] != 0)
    return (1);
  else
    return (0);
}
