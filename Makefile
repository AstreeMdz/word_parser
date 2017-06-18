all: main

main: main.o list.o dict.o parser.o
		gcc -o main list.o dict.o parser.o main.o -g

list.o: list.c list.h
		gcc -o list.o -c list.c -W -Wall -Werror -g

dict.o: dict.c dict.h list.c list.h
		gcc -o dict.o -c dict.c -W -Wall -Werror -g
		
parser.o: parser.c parser.h dict.c dict.h list.c list.h
		gcc -o parser.o -c parser.c -W -Wall -Werror -g

main.o: main.c list.c list.h dict.c dict.h parser.c parser.h
		gcc -o main.o -c main.c -W -Wall -Werror -g

clean:
		rm -rf *.o
		rm -rf *.exe
