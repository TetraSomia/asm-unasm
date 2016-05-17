/*
** my.h for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Feb 26 18:19:20 2016 Arthur Josso
** Last update Sun Mar 27 13:03:40 2016 Arthur Josso
*/

#ifndef MY_H_
# define MY_H_

# define READ_SIZE (512)

char		*get_next_line(const int fd);
int		err(const char *s);
int		my_getnbr(const char *s);
long		my_getlnbr(const char *s);
unsigned int	my_getunbr(const char *s);
void		my_putnbr(int nb);
int		is_char_valid(char c, char *s);
int		my_strcat(char **dest, char *src);
int		my_strcmp(const char *s1, const char *s2);
int		my_strncmp(const char *s1, const char *s2, int n);
int		my_strlen(const char *s);
char		*my_strndup(const char *src, int len);
char		*my_str_end_dup(const char *src, int beg);
void		my_memset(void *ptr, char c, int size);
int		is_num(const char *s);

#endif
