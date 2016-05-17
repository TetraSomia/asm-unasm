/*
** op.h for corewar in /home/josso/rendu/cpe/CPE_2015_corewar/asm
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Feb 26 13:25:39 2016 Arthur Josso
** Last update Fri Mar 25 18:59:56 2016 Arthur Josso
*/

#ifndef _OP_H_
# define _OP_H_

# define MEM_SIZE		(6*1024)
# define IDX_MOD		(512)
# define MAX_ARGS_NUMBER	(4)

# define COMMENT_CHAR		'#'
# define LABEL_CHAR		':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','

# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"

/*
** regs
*/

# define REG_NUMBER	(16)

typedef char    t_args_type;

# define T_REG		(1)
# define T_DIR		(2)
# define T_IND		(4)
# define T_LAB		(8)

struct  s_op
{
  char		*mnemonique;
  char		nbr_args;
  t_args_type	type[MAX_ARGS_NUMBER];
  char		code;
  int		nbr_cycles;
  char		*comment;
};

typedef struct s_op	t_op;

/*
** size
*/

# define IND_SIZE	(2)
# define REG_SIZE	(4)
# define DIR_SIZE	(REG_SIZE)

/*
** op_tab
*/

extern t_op	g_op_tab[];

/*
** header
*/

# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)

# define COREWAR_EXEC_MAGIC	(0x00ea83f3)

struct s_header
{
  int  magic;
  char prog_name[PROG_NAME_LENGTH+1];
  int  prog_size;
  char comment[COMMENT_LENGTH+1];
};

typedef struct s_header	t_header;

/*
** live 
*/

# define CYCLE_TO_DIE	(1536)
# define CYCLE_DELTA	(5)
# define NBR_LIVE	(40)

#endif
