all: install
install:
		@gcc source/main.c source/libs/*.c -o NetMap
test:
		@echo "**MAKEFILE**"
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
		@gcc source/main.c source/libs/*.c -o outputs/output7/NetMap
		@echo "MAKE: compile7   done"
		@gcc source/main.c source/libs/*.c -o outputs/output8/NetMap
		@echo "MAKE: compile8   done"
		@gcc source/main.c source/libs/*.c -o outputs/output9/NetMap
		@echo "MAKE: compile9   done"
		@gcc source/main.c source/libs/*.c -o outputs/output10/NetMap
		@echo "MAKE: compile10  done"
		@gcc source/main.c source/libs/*.c -o outputs/output11/NetMap
		@echo "MAKE: compile11  done"
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
		@cd outputs/output7 && ./NetMap ../../inputs/input7.txt && cd ../../
		@echo "MAKE: test7      done"
		@cd outputs/output8 && ./NetMap ../../inputs/input8.txt && cd ../../
		@echo "MAKE: test8      done"
		@cd outputs/output9 && ./NetMap ../../inputs/input9.txt && cd ../../
		@echo "MAKE: test9      done"
		@cd outputs/output10 && ./NetMap ../../inputs/input10.txt && cd ../../
		@echo "MAKE: test10     done"
		@cd outputs/output11 && ./NetMap ../../inputs/input11.txt && cd ../../
		@echo "MAKE: test11     done"

clear:
		@rm NetMap
