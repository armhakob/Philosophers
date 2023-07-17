NAME			= philo
BUILD			= ./build
SRCDIR			= src
SRCS			= $(wildcard $(SRCDIR)/*.c)
OBJS			= $(patsubst $(SRCDIR)/%.c, $(BUILD)/%.o, $(SRCS))
INCS			= -Iincludes
HEADER			= $(wildcard includes/*.h)
RM				= rm -rf
CC				= cc
FLAGS			= -Wall -Wextra -Werror #-fsanitize=address -g


all:	$(BUILD) lib $(NAME)

$(BUILD)/%.o:	$(SRCDIR)/%.c $(HEADER) Makefile
		$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) $(INCS) -o $(NAME) 

$(BUILD):	$(SRCDIR) $(BSRCDIR)
			@mkdir -p $@

clean:
		$(RM) $(BUILD)

fclean:	clean
		$(RM) $(NAME)

re: fclean all 


.PHONY : all clean fclean re lib
