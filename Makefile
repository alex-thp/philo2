SRCS = main.c tools.c parse.c run.c eat.c sleep.c time.c print_message.c check.c custom_free.c
CFLAGS = -Wall -Werror -Wextra
NAME = philo
INC = philo.h
OBJS = ${SRCS:%.c=%.o}

all: ${NAME}

${NAME} : ${INC} ${OBJS}
	gcc ${CFLAGS} ${OBJS} -o philo

%.c : %.o
	@gcc ${CFLAGS} -c -I philo.h

debug: extend_flag re

extend_flag:
	$(eval CFLAGS+=-g)

clean:
	@rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all