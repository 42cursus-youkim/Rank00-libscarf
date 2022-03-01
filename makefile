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

# ===== @Packages =====
PKGS     := string error system

stringV  := new util
errorV   := error
systemV  := alloc

# ===== Macros =====
define choose_modules
	$(foreach pkg, $(1),\
		$(foreach file, $($(pkg)V),\
			$(PRE)/lib_$(pkg)/$(file).c\
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

test:
	@$(CC) $(DFLAGS) $(INC) $(NAME) $(TEST).c -o test
	@./$(TEST)

leak: docs all
	@$(CC) $(DFLAGS) $(INC) $(NAME) test.c -o test
	@colour-valgrind $(VFLAGS) ./test
	@rm test

supp: docs all cls
	@$(CC) $(DFLAGS) $(INC) $(NAME) tests/test.c -o test
	@valgrind $(VFLAGS) --gen-suppressions=yes ./test
	@rm test

.PHONY: all re clean fclean test red docs