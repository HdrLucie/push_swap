SRCS =	srcs/push_swap.c \
		srcs/ft_lst_utils.c \
		srcs/ft_generals_utils.c \
		srcs/ft_check_params.c \
		srcs/ft_lst_operations.c \
		srcs/ft_which_algo.c \
		srcs/ft_tab_utils.c \
		srcs/ft_median_algo.c \
		srcs/ft_algo_utils.c \
		srcs/ft_print_utils.c

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all:		${NAME} ${SRCS}
			@echo "\033[33;31mCOMPILED\t\t\tCONGRATS"

${NAME} :	${SRCS}
			@make -C libft
			${CC} ${SRCS} ${CFLAGS} -I includes -L./libft -lft -o ${NAME}
%.o : %.c
			${CC} %(CFLAGS) -I libft -I includes -c -o $@
clean:
			${MAKE} clean -C libft
			@echo "\033[33;34mCLEAN !\t\t\t\tBUT YOU CAN DO BETTER"
fclean:		clean
			${MAKE} fclean -C libft
			rm -f ${NAME}
			@echo "\033[33;32mALL CLEAN !\t\t\tYOU'RE VERY PROPER"
re:			fclean all
			@echo "\033[33;36mRECOMPILED !\t\t\tIT'S WORK NOW ?"
.PHONY:		all fclean clean re
