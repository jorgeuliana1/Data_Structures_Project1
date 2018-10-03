all: install execute clear

install:
		@gcc source/main.c source/libs/*.c -o NetMap
execute: $(arg)
		./NetMap $(arg)
clear:
		@rm NetMap
