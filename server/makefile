all: listdir.o sendFile.o receive.o runfile.o sysinfo.o server.o
	g++ listdir.o sendFile.o receive.o runfile.o sysinfo.o server.o -o server

listdir.o: listdir.c common.h
	g++ -I. -c listdir.c

sendFile.o: sendFile.c common.h
	g++ -I. -c sendFile.c

receive.o: receive.c common.h
	g++ -I. -c receive.c

runfile.o: runfile.c common.h
	g++ -I. -c runfile.c

sysinfo.o: sysinfo.c common.h
	g++ -I. -c sysinfo.c


server.o: server.c common.h
	g++ -I. -c server.c

clean:
	rm *.o server
