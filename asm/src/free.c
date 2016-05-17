/*
** free.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Mar  2 13:59:51 2016 Arthur Josso
** Last update Tue Mar  8 11:20:22 2016 Arthur Josso
*/

#include <stdlib.h>
#include "asm.h"

static void	free_label(t_label *label)
{
  int		i;

  i = 0;
  while (label && label[i].name)
    free(label[i++].name);
  if (label)
    free(label);
}

static void	free_token(char ***token)
{
  int		i;
  int		ii;

  i = 0;
  while (token && token[i])
    {
      ii = 0;
      while (token[i][ii])
	free(token[i][ii++]);
      free(token[i++]);
    }
  if (token)
    free(token);
}

void	free_all(t_data *data)
{
  free_label(data->lbl_list);
  free_label(data->lbl_ref);
  if (data->bytecode)
    free(data->bytecode);
  free_token(data->token);
}
