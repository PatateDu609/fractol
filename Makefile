NAME		=	fractol

SRCS_FOLDER	=	srcs
OBJS_FOLDER	=	objs
HEAD_FOLDER	=	include

MLX_FOLDER	=	minilibx-linux
MLX_LIB		=	$(MLX_FOLDER)/mlx.a

CC			:=	gcc
CFLAGS		:=	-Werror -Wextra -Wall -fsanitize=address -g -I$(HEAD_FOLDER) -I$(MLX_FOLDER)
LDFLAGS		:=	-fsanitize=address -g -fsanitize=leak -L$(MLX_FOLDER) -lmlx -lXext -lX11 -lm

SRCS_BASE	=	main			\
				draw			\
				init			\
				hook			\
				free			\
				utils			\
				check			\
				parse			\
				error			\
				fractol			\
				chk_set			\
				release			\

SRCS		=	$(addsuffix .c, $(addprefix $(SRCS_FOLDER)/, $(SRCS_BASE)))
OBJS		=	$(addsuffix .o, $(addprefix $(OBJS_FOLDER)/, $(SRCS_BASE)))

$(OBJS_FOLDER)/%.o:		$(SRCS_FOLDER)/%.c
			$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):	folders $(OBJS) $(MLX_LIB)
			$(CC)  -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
			@make -s -C $(MLX_FOLDER) clean >> /dev/null 2>> /dev/null
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

$(MLX_LIB):
			@make -C $(MLX_FOLDER) >> /dev/null 2>> /dev/null

all:		$(NAME)

re:			fclean all

folders:
			@mkdir -p $(OBJS_FOLDER)

.PHONY:		re fclean clean folders all
