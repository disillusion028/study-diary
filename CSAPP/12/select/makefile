cc = gcc
deps = ../csapp.h
obj = ../csapp.o
all : selectecho hw22 testclient

.PHONY : all
selectecho: $(obj) select.o 
	$(cc) -o selectecho $(obj) select.o -lpthread
hw22: $(obj) hw22.o
	$(cc) -o hw22 $(obj) hw22.o -lpthread
testclient: $(obj) client.o
	$(cc) -o testclient $(obj) client.o -lpthread

csapp.o: $(deps)
hw22.o: $(deps)
client.o: $(deps)

.PHONY : clean
clean:
	rm -rf $(obj)
	rm -rf *.o
	rm -rf selectecho
	rm -rf hw22
	rm -rf testclient