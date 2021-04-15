# SRC = src/add_contact.c\
# src/print_list.c\
# src/list_all_contact.c\
# src/search_result.c\
# src/edit_delete_contact.c\
# src/search_contact.c

# PROJ_NAME = main.out

# INC = inc

# UNITY = unity

# TEST = test.c\
# unity/unity.c

# $(PROJ_NAME) : $(SRC)
# 	gcc -I $(INC) $(SRC) main.c -o $(PROJ_NAME)

# test: $(SRC)
# 	gcc -I $(INC) -I $(UNITY) $(SRC) $(TEST) -o test.out

# run_test:
# 	./test.out

# run: 
# 	./main.out

# analyze: memcheck staticcheck codesize

# staticcheck:
# 	cppcheck --enable=all $(SRC) main.c

# memcheck:
# 	valgrind ./test.out

# coverage:
# 	gcc -fprofile-arcs -ftest-coverage -I $(INC) -I $(UNITY) $(TEST) $(SRC)  -o test.out
# 	./test.out
# 	gcov -a test.out

# codesize:$(PROJ_NAME)
# 	size $^

# clean:
# 	rm -rf $(PROJ_NAME) *.gcov *.gcda *.gcno












PROJ_NAME = main

SRC = src/add_contact.c\
src/print_list.c\
src/list_all_contact.c\
src/search_result.c\
src/edit_delete_contact.c\
src/search_contact.c

TEST = test.c\
unity/unity.c

BUILD_DIR = Build

INC = -Iinc\
-Iunity

ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

# Makefile will not run target command if the name with file already exists. To override, use .PHONY
.PHONY : all test coverage run clean doc

all:
	gcc main.c $(SRC) $(INC) -o $(call FixPath,$(PROJ_NAME).$(EXEC))

run: all
	$(call FixPath,$(PROJ_NAME).$(EXEC))

test: $(SRC) $(TEST)
	gcc $^ $(INC) -o $(call FixPath,test.$(EXEC))
	./test.$(EXEC)

coverage:
	gcc -fprofile-arcs -ftest-coverage $(SRC) $(TEST) $(INC) -o $(call FixPath,test.$(EXEC))
	./test.$(EXEC)
	gcov -a test.c

cppcheck:
	cppcheck --enable=all $(SRC) main.c

valgrind:
	valgrind ./test.out


clean:
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov
