cc = gcc
deps = ../csapp.h
obj = ../csapp.o
all : selectecho

.PHONY : all
selectecho: $(obj) echoservers.o
	$(cc) -o echoservers $(obj) echoservers.o -lpthread

csapp.o: $(deps)

.PHONY : clean
clean:*.o
	rm -rf $(obj)
	rm -rf *.o
	rm -rf echoservers