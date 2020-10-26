run_identify_token: test_identify_token
	./test_identify_token
	
run test_linked_list: test_linked_list	
	./test_linked_list
	
compile_all: linked_list.c is_ID.c identify_token.c is_keyword.c
	gcc -g is_ID.c is_keyword.c is_constant.c identify_token.c linked_list.c -o test_linked_list

compile_identify_token:	is_ID.c identify_token.c is_keyword.c driver_identify_token.c
	gcc -g is_ID.c is_keyword.c is_constant.c identify_token.c driver_identify_token.c -o test_identify_token 

