cc = gcc
deps = ../csapp.h
obj = ../csapp.o
all : hellopth hw16

.PHONY : all
hellopth: $(obj) hello.o
	$(cc) -o hellopth $(obj) hello.o -lpthread
hw16: $(obj) hw12_16.o
	$(cc) -o hw16 $(obj) hw12_16.o -lpthread
csapp.o: $(deps)

.PHONY : clean
clean:
	rm -rf *.o
	rm -rf $(obj)
	rm -rf hellopth
	rm -rf hw16