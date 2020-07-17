PROJECT = main
#Sources files .C
C_SOURCES = main.cpp\
		Cell.cpp\
	       Grid.cpp	
 
#Compiler flags (.C)
C_FLAGS = -Wall -g
 
#Compiler
CC = g++
#OBJCOPY utility
OBJCOPY =obj 
OBJECTS = $(C_SOURCES:.cpp=.o) 
 
#Compile: create object files from C source files
%.o:%.cpp
	$(CC) -c $(C_FLAGS) $< -o $@
 
 
$(PROJECT).out:  $(OBJECTS)
	$(CC)  $(C_FLAGS) $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system
 

clean:
	rm -f $(OBJECTS)
	rm -f $(PROJECT).out
	rm -f $(PROJECT).hex
	rm -f $(PROJECT).lss
 
.PHONY: clean program_flash
