CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
HEADER = Man/pipex.h
HEADER_BONUS = Bonus/pipex_bonus.h

SRC =	Man/failfork.c Man/Parsingexec/pathnexec.c Man/Sphelpers/ft_split_helper3.c \
		Man/Parsingexec/trimbparse.c Man/Parsingexec/execabso.c \
		Man/Sphelpers/ft_split_helper2.c Man/Sphelpers/ft_split_helper.c \
		Man/pipex.c Man/Parsingexec/miniparser.c Man/Phelpers/pipex_helpers3.c \
		Man/Phelpers/pipex_helpers2.c Man/Phelpers/pipex_helpers.c

BSRC = 	Bonus/failfork.c Bonus/Parsingexec/pathnexec.c Bonus/Bphelpers/tools.c \
		Bonus/HereDoc/gename.c Bonus/multpipe.c \
		Bonus/HereDoc/here_doc.c Bonus/HereDoc/children.c \
		Bonus/Getline/get_next_line.c Bonus/Getline/get_next_line_utils.c \
		Bonus/Parsingexec/trimbparse.c Bonus/Parsingexec/execabso.c \
		Bonus/Bsphelpers/ft_split_helper2.c Bonus/Bsphelpers/ft_split_helper.c \
		Bonus/pipex_bonus.c Bonus/Parsingexec/miniparser.c \
		Bonus/Bsphelpers/ft_split_helper3.c Bonus/Bphelpers/pipex_helpers_b3.c \
		Bonus/Bphelpers/pipex_helpers_b2.c Bonus/Bphelpers/pipex_helpers_b.c

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o) 

all: $(NAME)

bonus: $(BOBJ)
	@echo "\033[32mPipex Bonus is ready...\033[0m"
	@$(CC) $(BOBJ) $(CFLAGS) -o $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32mPipex is ready...\033[0m"
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	
%.o: %.c $(HEADER_BONUS)
	@if [ -f $(NAME) ]; then rm -f $(NAME); fi;
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[32mCleaning Pipex...\033[0m"
	@rm -f $(OBJ) $(BOBJ)

fclean:	clean
	@echo "\033[32mExecutable removed...\033[0m"
	@rm -f $(NAME)

re: fclean all
