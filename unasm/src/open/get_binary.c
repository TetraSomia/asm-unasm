/*
** get_binary.c for unasm in /home/josso/rendu/cpe/CPE_2015_corewar/bonus/unasm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Mar 10 10:50:23 2016 Arthur Josso
** Last update Thu Mar 10 12:53:41 2016 Arthur Josso
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "unasm.h"
#include "op.h"
#include "my.h"

static int	add_buff(t_data *data, char buff[BUFF_SIZE], int len)
{
  char		*tmp;
  int		i;

  if ((tmp = realloc(data->bytecode, data->len + len)) == NULL)
    return (err(0));
  data->bytecode = tmp;
  i = 0;
  while (i < len)
    data->bytecode[data->len++] = buff[i++];
  return (0);
}

static int	put_header(t_data *data, header_t *header)
{
  header->prog_name[PROG_NAME_LENGTH] = '\0';
  header->comment[COMMENT_LENGTH] = '\0';
  if (add_line(data) == 1)
    return (1);
  if (add_word(data, NAME_CMD_STRING) == 1)
    return (1);
  if (add_word(data, header->prog_name) == 1)
    return (1);
  if (add_line(data) == 1)
    return (1);
  if (add_word(data, COMMENT_CMD_STRING) == 1)
    return (1);
  if (add_word(data, header->comment) == 1)
    return (1);
  return (0);
}

int		get_binary(t_data *data, char *path)
{
  int		fd;
  char		buff[BUFF_SIZE];
  int		len;
  header_t	header;

  if ((fd = open(path, O_RDONLY)) == -1)
    return (my_put_err("No such file or directory\n"));
  if (read(fd, &header, sizeof(header_t)) == -1)
    return (my_put_err("Read failed\n"));
  while ((len = read(fd, buff, BUFF_SIZE)) > 0)
    if (add_buff(data, buff, len) == 1)
      return (1);
  if (len == -1)
    return (my_put_err("Read failed\n"));
  if (data->bytecode == NULL)
    return (my_put_err("No code on this binary file\n"));
  if (put_header(data, &header) == 1)
    return (1);
  return (0);
}
