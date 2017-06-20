cc = gcc
deps = ../csapp.h
obj = ../csapp.o
all : race norace

.PHONY : all
race: $(obj) race.o
	$(cc) -o race $(obj) race.o -lpthread
norace: $(obj) norace.o
	$(cc) -o norace $(obj) norace.o -lpthread
csapp.o: $(deps)

.PHONY : clean
clean:
	rm -rf race.o
	rm -rf norace.o
	rm -rf $(obj)
	rm -rf race
	rm -rf norace