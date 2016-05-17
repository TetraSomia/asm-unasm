##
## Makefile for corewar in /home/josso/rendu/cpe/CPE_2015_corewar
## 
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
## 
## Started on  Tue Jan 26 15:39:47 2016 Arthur Josso
## Last update Fri Mar 11 18:00:56 2016 Arthur Josso
##

NAME	=	unasm

CC	=	gcc

INC	=	./include/

CFLAGS	+=	-I$(INC) \
		-W -Wall -Wextra

SRCS	=	./src/

CORE	=	./src/core/

MY	=	./src/my/

UNASM	=	./src/unasm/

CORE	=	./src/core/

OPEN	=	./src/open/

SRC	=	$(SRCS)main.c \
		$(OPEN)get_binary.c \
		$(UNASM)unasm.c \
		$(UNASM)get_arg_type.c \
		$(UNASM)put.c \
		$(UNASM)label.c \
		$(UNASM)verif_label.c \
		$(CORE)print.c \
		$(CORE)op.c \
		$(CORE)add.c \
		$(CORE)inc_curs.c \
		$(MY)my_err.c \
		$(MY)my_putstr.c \
		$(MY)my_strcmp.c \
		$(MY)my_strlen.c \
		$(MY)my_strdup.c \
		$(MY)my_nbr_to_str.c \
		$(MY)my_strcpy.c

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
