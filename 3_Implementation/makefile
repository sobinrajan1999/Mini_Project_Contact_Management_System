SRC = src/add_contact.c\
src/print_list.c\
src/list_all_contact.c\
src/search_result.c\
src/edit_delete_contact.c\
src/search_contact.c

PROJ_NAME = main.out

INC = inc

UNITY = unity

TEST = test.c\
unity/unity.c

$(PROJ_NAME) : $(SRC)
	gcc -I $(INC) $(SRC) main.c -o $(PROJ_NAME)

test: $(SRC)
	gcc -I $(INC) -I $(UNITY) $(SRC) $(TEST) -o test.out

run_test:
	./test.out

run: 
	./main.out

analyze: memcheck staticcheck codesize

staticcheck:
	cppcheck --enable=all .

memcheck:
	valgrind ./$(PROJ_NAME)

codesize:$(PROJ_NAME)
	size $^

clean:
	rm -rf $(PROJ_NAME) test.out


