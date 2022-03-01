# ===== Target & FLAGS =====
NAME     := libft.a

CC       := clang
CFLAGS   := -Wall -Wextra -Werror -std=c99
DFLAGS	 := -g3 #-DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address"
VFLAGS   := --leak-check=full --show-leak-kinds=all \
			--track-origins=yes
AR       := ar -rcs
RM       := rm -f

PRE      := src
INC      := -I include

HGEN     := hgen
TEST     := test

# ===== @Packages =====
PKGS     := string

stringV  := new check util util2 array array2 split join

# ===== Macros =====
define choose_modules
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)V),\
			$(PRE)/$(pkg)/$(file).c\
		)\
	)
endef

# ===== Sources & Objects & Include =====
SRC      := $(call choose_modules, $(PKGS))
OBJ      := $(SRC:%.c=%.o)

# ===== Rules =====
%.o: %.c
	@echo "  $(WU)$(<F)$(R) -> $(E)$(@F)"
	@$(CC) $(CFLAGS) $(DFLAGS) $(INC) -c -o $@ $<

$(NAME): $(OBJ)
	@$(AR) $@ $^
	@echo 🗃️ archived with flag $(DFLAGS) $(CFLAGS)

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@echo cleaned $(NAME)'s object files

fclean: clean
	@$(RM) $(NAME)
	@echo 🗑 cleaned $(NAME)

re: fclean all

# ===== Custom Rules =====
red: fclean docs all
ald: docs all

docs:
	@set -e;\
		for p in $(PKGS); do\
			$(HGEN) -I include/$$p.h src/$$p 1> /dev/null;\
		done

testdry: docs all
	@$(CC) $(DFLAGS) $(INC) $(NAME) $(TEST).c -o test

test: testdry
	@./$(TEST)

leak: docs all
	@$(CC) $(DFLAGS) $(INC) $(NAME) test.c -o test
	@colour-valgrind $(VFLAGS) ./test
	@rm test

leaksup: docs all cls
	@echo <Creating Leak Suppressions>"
	@$(CC) $(DFLAGS) $(INC) $(NAME) tests/test.c -o test
	@valgrind $(VFLAGS) --gen-suppressions=yes ./test
	@rm test

.PHONY: all re clean fclean test red docs