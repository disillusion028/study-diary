cc = gcc
deps = ../mycsapp.h ../10/unix_error.h
obj = rio.o unix_error.o open_fd.o
all : myclient myserver

.PHONY : all
myclient: $(obj) echoclient.o
	$(cc) -o myclient $(obj) echoclient.o
myserver: $(obj) echoserver.o
	$(cc) -o myserver $(obj) echoserver.o

open_fd.o: open_fd.c $(deps)
rio.o: ../10/rio.c $(deps)
	$(cc) -c ../10/rio.c
echoclient.o: echoclient.c $(deps)
	$(cc) -c echoclient.c
unix_error.o: ../10/unix_error.c $(deps)
	$(cc) -c ../10/unix_error.c
echoserver.o: echoserver.c $(deps)
	$(cc) -c echoserver.c

.PHONY : clean
clean:
	rm -rf $(obj)
	rm myclient
	rm myserver
	rm echoclient.o
	rm echoserver.o