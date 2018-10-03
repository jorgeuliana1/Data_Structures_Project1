all: install execute clear

install:
		@gcc source/main.c source/libs/*.c -o NetMap
execute:
		./NetMap
clear:
		@rm NetMap
