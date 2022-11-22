mk:
	gcc ls.c -o ls
	gcc mkdir.c -o mkdir
	gcc date.c -o date
	gcc rm.c -o rm
	gcc -pthread test.c -o test
	gcc cat.c -o cat

run:
	./test

