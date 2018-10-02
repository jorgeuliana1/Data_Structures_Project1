all: install
test: install-all test-all
teste-ndiff: install-all test-all diff-saida-txt
install:
		@gcc source/main.c source/libs/*.c -o NetMap
install-all:
		@gcc source/main.c source/libs/*.c -o outputs/output1/NetMap
		@echo "MAKE: compile1   done"
		@gcc source/main.c source/libs/*.c -o outputs/output2/NetMap
		@echo "MAKE: compile2   done"
		@gcc source/main.c source/libs/*.c -o outputs/output3/NetMap
		@echo "MAKE: compile3   done"
		@gcc source/main.c source/libs/*.c -o outputs/output4/NetMap
		@echo "MAKE: compile4   done"
		@gcc source/main.c source/libs/*.c -o outputs/output5/NetMap
		@echo "MAKE: compile5   done"
		@gcc source/main.c source/libs/*.c -o outputs/output6/NetMap
		@echo "MAKE: compile6   done"
test-all:
		@cd outputs/output1 && ./NetMap ../../inputs/input1.txt && cd ../../
		@echo "MAKE: test1      done"
		@cd outputs/output2 && ./NetMap ../../inputs/input2.txt && cd ../../
		@echo "MAKE: test2      done"
		@cd outputs/output3 && ./NetMap ../../inputs/input3.txt && cd ../../
		@echo "MAKE: test3      done"
		@cd outputs/output4 && ./NetMap ../../inputs/input4.txt && cd ../../
		@echo "MAKE: test4      done"
		@cd outputs/output5 && ./NetMap ../../inputs/input5.txt && cd ../../
		@echo "MAKE: test5      done"
		@cd outputs/output6 && ./NetMap ../../inputs/input6.txt && cd ../../
		@echo "MAKE: test6      done"
test-all-valgrind:
		@cd outputs/output1 && valgrind --leak-check=full ./NetMap ../../inputs/input1.txt && cd ../../
		@echo "MAKE: test1      done"
		@cd outputs/output2 && valgrind --leak-check=full ./NetMap ../../inputs/input2.txt && cd ../../
		@echo "MAKE: test2      done"
		@cd outputs/output3 && valgrind --leak-check=full ./NetMap ../../inputs/input3.txt && cd ../../
		@echo "MAKE: test3      done"
		@cd outputs/output4 && valgrind --leak-check=full ./NetMap ../../inputs/input4.txt && cd ../../
		@echo "MAKE: test4      done"
		@cd outputs/output5 && valgrind --leak-check=full ./NetMap ../../inputs/input5.txt && cd ../../
		@echo "MAKE: test5      done"
		@cd outputs/output6 && valgrind --leak-check=full ./NetMap ../../inputs/input6.txt && cd ../../
		@echo "MAKE: test6      done"
diff-saida-txt:
		@diff outputs/default1/saida.txt outputs/output1/saida.txt
		@echo "MAKE: diff1      done"
		@diff outputs/default2/saida.txt outputs/output2/saida.txt
		@echo "MAKE: diff2      done"
		@diff outputs/default3/saida.txt outputs/output3/saida.txt
		@echo "MAKE: diff3      done"
		@diff outputs/default4/saida.txt outputs/output4/saida.txt
		@echo "MAKE: diff4      done"
		@diff outputs/default5/saida.txt outputs/output5/saida.txt
		@echo "MAKE: diff5      done"
		@diff outputs/default6/saida.txt outputs/output6/saida.txt
		@echo "MAKE: diff6      done"
clear:
		@rm NetMap
