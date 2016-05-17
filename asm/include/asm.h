/*
** asm.h for corewar in /home/josso/rendu/cpe/CPE_2015_corewar
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jan 26 16:16:27 2016 Arthur Josso
** Last update Sat Mar 26 17:27:57 2016 Arthur Josso
*/

#ifndef ASM_H_
# define ASM_H_

# define BYTE_SIZE (8)

typedef struct	s_label
{
  char		*name;
  int		index;
  int		index_line;
}		t_label;

typedef struct	s_data
{
  char          ***token;
  char		*bytecode;
  int		curs;
  int		curs_line;
  t_label       *lbl_list;
  t_label       *lbl_ref;
}		t_data;

/*
** File Generation
*/

int	gen_file(t_data *data, char *path);
int     get_dest_fd(char *path, int *fd);

/*
** Compilation
*/

int	get_instruc_num(const char *mnemo);
char	get_param_type(char **params);

int	add_byte(t_data *data, char byte);

int     get_binary(t_data *data);

/*
** Add item
*/

int	add_lbl_list(t_data *data, const char *label);
int     add_lbl_ref(t_data *data, const char *label);
void	add_labels(t_data *data);
int     add_ind_value(t_data *data, const char *param);
int     add_dir_value(t_data *data, const char *param);
int	add_reg_value(t_data *data, const char *param);

/*
** Is item
*/

int     is_lbl_list(const char *token);
int     is_lbl_ref(const char *token);
int     is_instruc(const char *token);
int	is_reg(const char *token);
int	is_direct(const char *token);
int	is_indirect(const char *token);
int	is_index(int instruc, int param_num);

/*
** Parsing
*/

# define SEPAR(x) ((x) == ',' ? 1 : ((x) == ' ' ? 1 : ((x) == '\t' ? 1 : 0)))

int	get_tab_tab(int fd, char ****tab);
int     get_tab_line(int fd, char ***line);
int	get_tab_word(char *str, char **word, char **line);

int     get_token(char ****token, char *path);

int     parse_meta(t_data *data);

/*
** Error
*/

int     error_parsing(char ***token);

int     err_at(const char *msg, int line);
int     warn_at(const char *msg, int line);
int     error(const char *msg);

int     lbl_unknown_ref(const t_data *data);
int     lbl_mult_def(const t_data *data);

int	get_nb_arg(char **line);
char	get_arg_type(const char *param, int line, int is_index);

int	overflow_reg(const char *param, int line);
void	overflow_indirect(const char *param, int line);
void	overflow_direct(const char *param, int line);

/*
** Exiting
*/

typedef enum	e_exit
  {
    SUCCESS	= 0,
    ERROR	= 1,
    BAD_LINE	= 2,
    SUCCESS_STR	= 3
  }		t_exit;

void	free_all(t_data *data);

#endif
