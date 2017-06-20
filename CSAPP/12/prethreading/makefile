cc = gcc
deps = ../csapp.h sbuf.h
obj = ../csapp.o
all : pret_server

.PHONY : all
pret_server: $(obj) echoservert_pre.o echo_cnt.o sbuf.o
	$(cc) -o pret_server $(obj)  echoservert_pre.o echo_cnt.o sbuf.o -lpthread

csapp.o: $(deps)

sbuf.o: $(deps)

echo_cnt.o: $(deps)

.PHONY : clean
clean:
	rm -rf $(obj)
	rm -rf *.o
	rm -rf pret_server