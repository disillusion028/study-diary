cc = gcc
deps = ../csapp.h
obj = ../csapp.o
all : selectecho

.PHONY : all
selectecho: $(obj) select.o
	$(cc) -o selectecho $(obj) select.o -lpthread

csapp.o: $(deps)

.PHONY : clean
clean:
	rm -rf $(obj)
	rm -rf select.o
	rm -rf selectecho