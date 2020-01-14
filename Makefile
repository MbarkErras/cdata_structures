NAME = cdstruct.a

SRCS = stack/stack.c

SRCS_DIRS = stack

OBJS_DIR = build
OBJS_DIRS = $(addprefix $(OBJS_DIR)/, $(SRCS_DIRS))
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

SHARED_INCLUDES = shared_includes

FLAGS = #-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS): $(OBJS_DIRS)/%.o : $(SRCS_DIRS)/%.c | $(OBJS_DIRS)
	gcc $(FLAGS) -I$(SHARED_INCLUDES) -c $< -o $@

$(OBJS_DIRS):
	mkdir build $(OBJS_DIRS)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all