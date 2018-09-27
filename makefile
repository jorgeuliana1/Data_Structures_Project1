all: install
install:
		@gcc source/main.c source/libs/*.c -o NetMap
test:
		@gcc source/main.c source/libs/*.c -o outputs/output1/NetMap
		@gcc source/main.c source/libs/*.c -o outputs/output2/NetMap
		@gcc source/main.c source/libs/*.c -o outputs/output3/NetMap
		@gcc source/main.c source/libs/*.c -o outputs/output4/NetMap
		@gcc source/main.c source/libs/*.c -o outputs/output5/NetMap
		@gcc source/main.c source/libs/*.c -o outputs/outputespecial/NetMap
		@echo compiled all
		@cd outputs/output1 && ./NetMap ../../inputs/input1.txt && cd ../../
		@echo test1 done
		@cd outputs/output2 && ./NetMap ../../inputs/input2.txt && cd ../../
		@echo test2 done
		@cd outputs/output3 && ./NetMap ../../inputs/input3.txt && cd ../../
		@echo test3 done
		@cd outputs/output4 && ./NetMap ../../inputs/input4.txt && cd ../../
		@echo test4 done
		@cd outputs/output5 && ./NetMap ../../inputs/input5.txt && cd ../../
		@echo test5 done

clear:
		@rm NetMap
