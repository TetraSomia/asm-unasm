##
## Makefile for corewar in /home/josso/rendu/cpe/CPE_2015_corewar
## 
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
## 
## Started on  Tue Jan 26 15:39:47 2016 Arthur Josso
## Last update Tue May 17 15:18:56 2016 Arthur Josso
##

NAME	=	asm

CC	=	gcc

INC	=	./include/

CFLAGS	+=	-I$(INC) \
		-W -Wall -Wextra

SRCS	=	./src/

CORE	=	./src/core/

PARSING	=	./src/parsing/

MY	=	./src/my/

COMPIL	=	./src/compilation/

ERROR	=	./src/error/

SRC	=	$(SRCS)main.c \
		$(SRCS)open.c \
		$(SRCS)free.c \
		$(SRCS)gen_file.c \
		$(COMPIL)compil.c \
		$(COMPIL)add_label.c \
		$(COMPIL)add_value.c \
		$(COMPIL)add_byte.c \
		$(COMPIL)get_inst_code.c \
		$(COMPIL)get_param_type.c \
		$(PARSING)tab.c \
		$(PARSING)line.c \
		$(PARSING)word.c \
		$(PARSING)meta.c \
		$(ERROR)label_err.c \
		$(ERROR)err_msg.c \
		$(ERROR)error.c \
		$(ERROR)get_info.c \
		$(ERROR)overflow.c \
		$(CORE)op.c \
		$(CORE)is_item.c \
		$(CORE)is_value.c \
		$(MY)get_next_line.c \
		$(MY)my_char_valid.c \
		$(MY)my_err.c \
		$(MY)my_getnbr.c \
		$(MY)my_putnbr.c \
		$(MY)my_strcat.c \
		$(MY)my_strcmp.c \
		$(MY)my_strlen.c \
		$(MY)my_strdup.c \
		$(MY)my_memset.c \
		$(MY)my_isnum.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
