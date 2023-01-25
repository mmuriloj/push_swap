NAME			=	push_swap

HEADERS_DIR 	=	./includes/
SOURCES_DIR		=	./sources/

HEADERS_LIST	=	push_swap.h
SOURCES_LIST	=	max_min_values.c utils.c bubblesort.c \
					main.c swap.c push.c rotate.c \
					reverse_rotate.c push_swap.c big_sort.c \
					error.c

HEADERS			=	${addprefix ${HEADERS_DIR}, ${HEADERS_LIST}}
SOURCES			=	${addprefix ${SOURCES_DIR}, ${SOURCES_LIST}}
INCLUDES		=	-I ${HEADERS_DIR} -I ${LIBFT_HEADERS}

OBJECTS_DIR		=	./objs/
OBJECTS_LIST	=	${patsubst %.c, %.o, ${SOURCES_LIST}}
OBJS			=	$(SOURCES_LIST:.c=.o)
OBJECTS			=	${addprefix ${OBJECTS_DIR}, ${OBJECTS_LIST}}

LIBFT			=	${LIBFT_DIR}libft.a
LIBFT_DIR		=	./libft/
LIBFT_HEADERS	=	${LIBFT_DIR}includes/

CC				=	cc 
CFLAGS			=	-Wall -Werror -Wextra -g3

#-fsanitize=address -static-libasan

VALGRIND_FLAGS		=	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

all: ${NAME}

libft: ${LIBFT}

pyviz:
	python3 pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`

${NAME}:		${LIBFT} ${OBJECTS_DIR} ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} ${LIBFT} ${INCLUDES} -o ${NAME}
	@echo "\033[1;92mpush_swap created successfully!\033[0m"

${OBJECTS_DIR}:
	mkdir -p ${OBJECTS_DIR}

${OBJECTS_DIR}%.o : ${SOURCES_DIR}%.c ${HEADERS}
	${CC} ${CFLAGS} -c ${INCLUDES} $< -o $@

${LIBFT}:
	clear && make -sC ${LIBFT_DIR}

clean:
	clear
	@make -sC ${LIBFT_DIR} clean
	@echo "Removing push_swap objects..."
	@rm -rf ${OBJECTS_DIR}

fclean: clean
	@echo "Removing Libft..."
	@rm -rf ${LIBFT}
	@echo "\033[31mLibft removed successfully!\033[0m"
	@echo "Removing push_swap..."
	@rm -rf ${NAME}
	@echo "\033[31mpush_swap removed successfully!\033[0m"

re:	fclean all


.PHONY:		all, clean, fclean, re


#clear && make && clear && ARG=$(shuf -i 0-500 -n 3) && echo $ARG && ./push_swap $ARG
#python3 pyviz.py `ruby -e "puts (1..20).to_a.shuffle.join(' ')"`