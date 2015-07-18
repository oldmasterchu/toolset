RM:=rm -rf
CC:=gcc
FLAG:=-g3 -Wall 
PRODUCT:=toolset.exe
OBJS:=*.o
HEADERS:=../headers/*.h

all: $(PRODUCT)

$(PRODUCT): *.o
	@echo 'linking object files to create $(PRODUCT)'
	$(CC) $(FLAG) -o $@ *.o

$(OBJS): ../src/*.c $(HEADERS)
	@echo 'compiling code with $?'
	$(CC) $(FLAG) -c ../src/*.c
clean:
	@echo 'cleaning built files'
	$(RM) $(PRODUCT) *.o
	
.PHONY: all clean 