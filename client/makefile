all: client.o sendFile.o
	g++ sendFile.o client.o -o client

sendFile.o: sendFile.c common.h
	g++ -I. -c sendFile.c

client.o: client.c common.h
	g++ -I. -c client.c

clean:
	rm *.o client
