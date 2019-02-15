main: main.o functions.o
	gcc -o main main.o functions.o -g
main1: main.c
	gcc -o main1 main.c
main2: functions.c
	gcc -c main2 funcitons.c


