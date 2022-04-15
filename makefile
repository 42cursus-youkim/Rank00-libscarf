# ===== Target & FLAGS =====
NAME     := libft.a

CC       := clang
CFLAGS   := -g3 -Wall -Wextra -Werror -std=c99
AR       := ar -rcs
RM       := rm -f

PRE      := src
INC      := -I include

HGEN     := hgen

# ===== @Packages =====
PKGS     := string error system vector

#FIXME: specify packages
stringV  := alloc util
errorV   := error
systemV  := alloc dalloc write

# ===== Macros =====
define choose_modules
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)V),\
			$(PRE)/lib__$(pkg)/$(file).c\
		)\
	)
endef

# ===== Sources & Objects & Include =====
SRC      := $(wildcard src/**/*.c)
# SRC      := $(call choose_modules, $(PKGS))
OBJ      := $(SRC:%.c=%.o)

# ===== Rules =====
.PHONY: all re clean fclean

%.o: %.c
	@echo "  $(WU)$(<F)$(R) -> $(E)$(@F)"
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(NAME): $(OBJ)
	@$(AR) $@ $^
	@echo 🗃️ archived with flag $(CFLAGS)

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@echo "cleaned $(NAME)'s object files"

fclean: clean
	@$(RM) $(NAME)
	@echo 🗑 cleaned $(NAME)

re: fclean all

# ===== Custom Rules =====
docs:
	@set -e;\
		for p in $(PKGS); do\
			$(HGEN) -I include/$$p.h src/$$p 1> /dev/null;\
		done

leak: docs all
	@$(CC)  $(INC) $(NAME) test.c -o test
	@colour-valgrind ./test
	@rm test
