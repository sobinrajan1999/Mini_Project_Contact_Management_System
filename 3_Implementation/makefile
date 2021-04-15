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

all:$(BUILD_DIR)
	gcc main.c $(SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

run: all
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

test: $(SRC) $(TEST)
	gcc $^ $(INC) -o $(call FixPath,$(BUILD_DIR)/test.$(EXEC))
	$(call FixPath,$(BUILD_DIR)/test.$(EXEC))

coverage:
	gcc -fprofile-arcs -ftest-coverage $(SRC) $(TEST) $(INC) -o $(call FixPath,$(BUILD_DIR)/test.$(EXEC))
	$(call FixPath,$(BUILD_DIR)/test.$(EXEC))
	gcov -a test.c

cppcheck:
	cppcheck --enable=all $(SRC) main.c

valgrind:
	valgrind ./test.out


clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/*)
	make clean -C doc
	rmdir $(BUILD_DIR) doc/html
