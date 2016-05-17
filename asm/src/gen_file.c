/*
** header.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jan 26 20:12:17 2016 Arthur Josso
** Last update Sun Mar 27 12:31:23 2016 Arthur Josso
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"
#include "op.h"
#include "my.h"

static int	get_name(t_data *data, t_header *header)
{
  int		i;
  int		j;

  i = 0;
  while (data->token[i] && my_strcmp(data->token[i][0], NAME_CMD_STRING) != 0)
    i++;
  if (!data->token[i] || !data->token[i][1])
    return (err_at("Name is missing", i));
  j = 0;
  while (data->token[i][1][j] && j < PROG_NAME_LENGTH)
    {
      header->prog_name[j] = data->token[i][1][j];
      j++;
    }
  return (0);
}

static int      get_comment(t_data *data, t_header *header)
{
  int		i;
  int		j;

  i = 0;
  while (data->token[i] && my_strcmp(data->token[i][0],
				     COMMENT_CMD_STRING) != 0)
    i++;
  if (!data->token[i] || !data->token[i][1])
    return (warn_at("Comment is missing", i));
  j = 0;
  while (data->token[i][1][j] && j < COMMENT_LENGTH)
    {
      header->comment[j] = data->token[i][1][j];
      j++;
    }
  return (0);
}

static int	change_endianess(int nb)
{
  int		ret;
  int		i;
  int		byte;

  ret = 0;
  i = 1;
  while (i <= 4)
    {
      byte = (nb >> ((sizeof(nb) - i) * BYTE_SIZE)) & 0xFF;
      ret ^= byte << (i - 1) * BYTE_SIZE;
      i++;
    }
  return (ret);
}

int		gen_file(t_data *data, char *path)
{
  t_header	header;
  int		fd;

  if (parse_meta(data) == 1)
    return (1);
  if (get_dest_fd(path, &fd) == 1)
    return (1);
  my_memset(&header, 0, sizeof(t_header));
  header.magic = change_endianess(COREWAR_EXEC_MAGIC);
  header.prog_size = change_endianess(data->curs);
  if (get_name(data, &header) == 1)
    return (1);
  if (get_comment(data, &header) == 1)
    return (1);
  if (write(fd, &header, sizeof(t_header)) == -1)
    return (err("ERROR : write failed\n"));
  if (write(fd, data->bytecode, data->curs) == -1)
    return (err("ERROR : write failed\n"));
  close(fd);
  return (0);
}
