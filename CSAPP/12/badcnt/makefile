cc = gcc
deps = ../csapp.h
obj = ../csapp.o
all : badcnt

.PHONY : all
badcnt: $(obj) badcnt.o
	$(cc) -o badcnt $(obj) badcnt.o -lpthread

csapp.o: $(deps)

.PHONY : clean
clean:
	rm -rf $(obj)
	rm -rf *.o
	rm -rf badcnt