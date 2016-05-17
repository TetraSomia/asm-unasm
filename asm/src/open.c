/*
** open.c for corewar in /home/josso/rendu/cpe/CPE_2015_corewar
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jan 26 16:24:28 2016 Arthur Josso
** Last update Sat Mar 26 16:57:35 2016 Arthur Josso
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "asm.h"
#include "my.h"

static char	*get_dest_name(char *path)
{
  char  *name;
  char	is_dot_s;
  int	name_len;
  int	beg;

  name = NULL;
  name_len = my_strlen(path);
  is_dot_s = my_strcmp(path + (name_len - 2), ".s") == 0 ? 1 : 0;
  beg = name_len - 1;
  while (beg > 0 && path[beg - 1] != '/')
    beg--;
  if (my_strcat(&name, path + beg) == 1)
    return (NULL);
  name_len = my_strlen(name);
  if (is_dot_s)
    name[name_len - 2] = '\0';
  if (my_strcat(&name, ".cor") == 1)
    return (NULL);
  return (name);
}

int	get_dest_fd(char *path, int *fd)
{
  char	*dest_path;

  if ((dest_path = get_dest_name(path)) == NULL)
    return (err("Can't perform malloc\n"));
  if ((*fd = creat(dest_path, 00644)) == -1)
    {
      err("File ");
      err(dest_path);
      err(" not creatable\n");
      return (1);
    }
  free(dest_path);
  return (0);
}

static int	get_src_fd(char *path, int *fd)
{
  if ((*fd = open(path, O_RDONLY)) == -1)
    {
      err("File ");
      err(path);
      err(" not accessible\n");
      return (1);
    }
  return (0);
}

int	get_token(char ****token, char *path)
{
  int	fd;

  if (get_src_fd(path, &fd))
    return (1);
  if (get_tab_tab(fd, token) == 1)
    return (1);
  close(fd);
  return (0);
}
