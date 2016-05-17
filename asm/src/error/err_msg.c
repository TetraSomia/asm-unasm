/*
** err_msg.c for asm in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Mar  5 14:17:25 2016 Arthur Josso
** Last update Sat Mar 26 16:25:58 2016 Arthur Josso
*/

#include "my.h"

#define ERROR ("\x1b[1;91m")
#define WARNING ("\x1b[1;93m")
#define MSG ("\x1b[1;36m")
#define RESET ("\x1b[0m")

int	err_at(const char *msg, int line)
{
  err(ERROR);
  err("Error");
  err(RESET);
  err(" line ");
  my_putnbr(line + 1);
  err(": ");
  err(MSG);
  err(msg);
  err(RESET);
  err("\n");
  return (1);
}

int     error(const char *msg)
{
  err(ERROR);
  err("Error");
  err(RESET);
  err(": ");
  err(MSG);
  err(msg);
  err(RESET);
  err("\n");
  return (1);
}

int     warn_at(const char *msg, int line)
{
  err(WARNING);
  err("Warning");
  err(RESET);
  err(" line ");
  my_putnbr(line + 1);
  err(": ");
  err(MSG);
  err(msg);
  err(RESET);
  err("\n");
  return (0);
}

int     warning(const char *msg, int line)
{
  err(WARNING);
  err("Warning");
  err(RESET);
  err(" line ");
  my_putnbr(line + 1);
  err(": ");
  err(MSG);
  err(msg);
  err(RESET);
  err("\n");
  return (1);
}
