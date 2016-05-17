/*
** label_err.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Mar  5 14:02:55 2016 Arthur Josso
** Last update Mon Mar 14 16:20:40 2016 Arthur Josso
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"
#include "my.h"

static int	find_line(char ***token, const char *label)
{
  int		i;
  int		ii;

  i = 0;
  while (token && token[i])
    {
      ii = 0;
      while (token[i][ii])
	{
	  if (token[i][ii][0] == DIRECT_CHAR &&
	      token[i][ii][1] == LABEL_CHAR &&
	      my_strcmp(token[i][ii] + 2, label) == 0)
	    return (i);
	  ii++;
	}
      i++;
    }
  return (0);
}

static int      find_line_decl(char ***token, const char *label)
{
  int           i;
  int           ii;
  char		*tmp;

  if ((tmp = malloc(my_strlen(label) + 2)) == NULL)
    return (0);
  i = -1;
  while (label[++i])
    tmp[i] = label[i];
  tmp[i++] = LABEL_CHAR;
  tmp[i] = '\0';
  i = 0;
  while (token && token[i])
    {
      ii = 0;
      while (token[i][ii])
	{
	  if (my_strcmp(token[i][ii], tmp) == 0)
	    return (i);
	  ii++;
	}
      i++;
    }
  return (0);
}

static int	find_ref(const t_data *data, int ref)
{
  int		i;

  i = 0;
  while (data->lbl_list && data->lbl_list[i].name)
    {
      if (my_strcmp(data->lbl_ref[ref].name,
		    data->lbl_list[i].name) == 0)
	return (1);
      i++;
    }
  return (0);
}

int     lbl_mult_def(const t_data *data)
{
  int   i;
  int   ii;

  i = 0;
  while (data->lbl_list && data->lbl_list[i].name)
    {
      ii = 0;
      while (data->lbl_list[ii].name)
	{
	  if (my_strcmp(data->lbl_list[i].name, data->lbl_list[ii].name) == 0
	      && i != ii)
	    return (err_at("Multiple definition of the same label",
			   find_line_decl(data->token,
					  data->lbl_list[i].name)));
	  ii++;
	}
      i++;
    }
  return (0);
}

int	lbl_unknown_ref(const t_data *data)
{
  int	i;

  i = 0;
  while (data->lbl_ref && data->lbl_ref[i].name)
    {
      if (find_ref(data, i) == 0)
	return (err_at("Undefined label",
		       find_line(data->token, data->lbl_ref[i].name)));
      i++;
    }
  return (0);
}
