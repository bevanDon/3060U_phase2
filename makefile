CFLAGS = -Wall -c

.PHONY : all clean

all: main account Transactions FileIO

main : main.o
	cc -o main main.o

account : account.o
	cc -o account account.o

Transactions : Transactions.o
	cc -o Transactions Transactions.o

FileIO : FileIO.o
	cc -o FileIO FileIO.o

clean:
	rm main main.o account account.o Transactions Transactions.o FileIO FileIO.o
