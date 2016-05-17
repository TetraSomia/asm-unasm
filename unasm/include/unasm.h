/*
** unasm.h for unasm in /home/josso/rendu/cpe/CPE_2015_corewar/bonus/unasm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Mar 10 10:43:23 2016 Arthur Josso
** Last update Fri Mar 11 17:17:25 2016 Arthur Josso
*/

#ifndef UNASM_H_
#define UNASM_H_

#define BUFF_SIZE (256)

typedef struct s_label
{
  char	name[BUFF_SIZE];
  int	address;
  int	line;
  int	ex_line;
  int	ex_word;
  int	ex_value;
} t_label;

typedef struct s_data
{
  int	curs;
  int	curs_line;
  int	len;
  char	*bytecode;
  int	line;
  char	***code;
  t_label *label;
  int	*line_idx;
} t_data;

typedef union u_get_int
{
  int	nb;
  char	byte[4];
}t_get_int;

int     add_line(t_data *data);
int     add_word(t_data *data, char *word);

void    print_code(t_data *data, char ***code);

/*
** Read
*/

int     get_binary(t_data *data, char *path);

/*
** Unassemble
*/

int     unasm(t_data *data);

int	get_arg_type(t_data *data, int instruc, char *arg_type);
int     inc_curs(t_data *data);
int	decode_arg(t_data *data, int instruc, char *arg_type);

/*
** Label
*/

int     is_label(t_data *data, int addr, char *buff);
void    add_line_to_lbl(t_data *data);
int     verif_label(t_data *data);

#endif
