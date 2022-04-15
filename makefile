# ===== Target & FLAGS =====
NAME     := libft.a

CC       := clang
CFLAGS   := -Wall -Wextra -Werror -std=c99	\
						-I include -I include/types			\
						-g3

AR       := ar -rcs
HGEN     := hgen

# ===== @Packages =====
PKGS     := error math string system vector test

#FIXME: specify packages
stringV  := alloc util
errorV   := error
systemV  := alloc dalloc write

# ===== Macros =====
define choose_modules
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)V),\
			src/lib__$(pkg)/$(file).c\
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
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	@$(AR) $@ $^
	@echo 🗃️ archived with flag $(CFLAGS)

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "cleaned $(NAME)'s object files"

fclean: clean
	@rm -f $(NAME)
	@echo 🗑 cleaned $(NAME)

re: fclean all

# ===== Custom Rules =====
docs:
	@set -e;\
		for p in $(PKGS); do\
			$(HGEN) -I include/lib__$$p.h src/lib__$$p 1> /dev/null;\
		done

leak: docs all
	@$(CC) $(NAME) test.c -o test
	@colour-valgrind ./test
	@rm test

test: docs all
	@$(CC) $(NAME) $(CFLAGS) test/main.c -o test/test.out
	@./test/test.out
	@rm test/test.out
