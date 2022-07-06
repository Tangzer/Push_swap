NAME = push_swap

SRCS = ./src/main.c\
        ./src/utils.c\
        ./src/utils_lst.c\
		./src/lst.c\
		./src/do_operations.c\
		./src/operations.c\
		./src/sort_small.c\
	    ./src/radix.c\
	    ./src/parsing.c
        

OBJ =   ${SRCS:.c=.o}

RM = rm -f

GCC = cc

CFLAGS = -Wall -Wextra -Werror

%.o : %.c
			@echo "$(C_YELLOW_B)Compiling...$(C_RESET)";
			@${GCC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJ}
			@${GCC} $(CFLAGS) $(OBJ) -o ${NAME}
			@echo "$(C_GREEN_B)Finished!$(C_RESET)"

all:        ${NAME}
			@echo "$(C_YELLOW_B)Creation fichier ${NAME}$(C_RESET)"

clean:
			@echo "$(C_GREEN_B) Clean $(C_RESET)"
			@${RM} ${OBJ}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re


C_PURPLE_B		=\033[1;95m
C_YELLOW_B		=\033[1;33m
C_RED_B			=\033[1;31m
C_WHITE			=\033[0;97m
C_GREEN_B		=\033[1;32m
C_RESET			=\033[0m
