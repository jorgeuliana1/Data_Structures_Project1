all: install execute clear
install:
		@gcc source/main.c source/libs/connection.c source/libs/dot.c source/libs/output.c source/libs/readFile.c source/libs/router.c source/libs/terminal.c -o NetMap
execute:
		@./NetMap inputs/input.txt
clear:
		@rm NetMap
