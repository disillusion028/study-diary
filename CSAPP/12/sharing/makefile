cc = gcc
deps = ../csapp.h
obj = ../csapp.o
all : sharing

.PHONY : all
sharing: $(obj) sharing.o
	$(cc) -o sharing $(obj) sharing.o -pthread

csapp.o: $(deps)
#	$(cc) -o $(obj) -pthread
.PHONY : clean
clean:
	rm -rf sharing.o
	rm -rf $(obj)
	rm -rf sharing