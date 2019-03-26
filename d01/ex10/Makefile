


#------------------------------------------------------------------------------#
# Colors

BLACK =		\033[1;30m
RED =		\033[1;31m
GREEN =		\033[1;32m
YELLOW =	\033[1;33m
BLUE =		\033[1;34m
PINK =		\033[1;35m
CYAN =		\033[1;36m
GREY =		\033[1;37m
RES =		\033[0m

#------------------------------------------------------------------------------#
# Folders

SRCS_DIR =			.

OBJS_DIR =			./objs

HEADERS_DIR =		./includes

LIB_DIR =			./libft

LIB_HEADERS_DIR =	./libft/includes

#------------------------------------------------------------------------------#
# Sources

SRCS =			main.cpp \
				Cat.cpp 

OBJS =			$(SRCS:%.cpp=$(OBJS_DIR)/%.o)

HEADERS =		$(HEADERS_DIR)/Cat.hpp

#------------------------------------------------------------------------------#
# Compilation

NAME =			cato9tails

CC =			clang++

FLAGS =			-Wall \
				-Wextra \
				-Werror \
				-std=c++98
				#-fsanitize=address

HEADERS_FLAGS =	-I $(HEADERS_DIR)

LIB_FLAGS =		-L $(LIB_DIR) -lft

ALL_FLAGS =		$(FLAGS)		\
				$(HEADERS_FLAGS)

# Automatic Variables :
# $@	Le nom de la cible
# $^	La liste des dépendances
# $<	Le nom de la première dépendance
# $?	La liste des dépendances plus récentes que la cible
# $*	Le nom du fichier sans suffixe
#------------------------------------------------------------------------------#

all: $(NAME)

.SILENT:

$(NAME): $(OBJS)
	@$(CC) -g $(ALL_FLAGS) $^ -o $@
	@echo "$(GREEN)Executable created : $(RES)" $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp $(HEADERS)
	@echo "$(GREEN)--- Compilation ---$(RES)";
	@mkdir -p $(OBJS_DIR)
	@echo "$(GREEN)Objects created : $(RES)" $@
	@$(CC) $(ALL_FLAGS) -o $@ -c $<

clean:
	@echo "$(RED)--- objects removed ---$(RES)";
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "$(RED)--- executable removed ---$(RES)";
	@rm -rf $(NAME)

re: fclean
	@$(MAKE) all

#------------------------------------------------------------------------------#
# Git

git:
	@git add Makefile $(SRCS_DIR) $(HEADERS_DIR) auteur

.PHONY: all clean fclean re git