/*
** my.h for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Feb 26 18:19:20 2016 Arthur Josso
** Last update Fri Mar 11 13:21:54 2016 Arthur Josso
*/

#ifndef MY_H_
# define MY_H_

void	my_putstr(const char *s);
int     err(int binary_corrupted);
int     my_put_err(const char *s);
int     my_strcmp(const char *s1, const char *s2);
int     my_strlen(const char *s);
void    my_strcpy(char *dest, const char *src);
char    *my_strdup(const char *str);
void    my_nbr_to_str(long nb, char *buff, int buff_size);

#endif
