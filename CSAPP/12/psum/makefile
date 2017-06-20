cc = gcc
deps = ../csapp.h
obj = ../csapp.o
all : psum_mutex psum_array psum_local

.PHONY : all
psum_mutex: $(obj) psum_mutex.o
	$(cc) -o psum_mutex $(obj) psum_mutex.o -lpthread
psum_array: $(obj) psum_array.o
	$(cc) -o psum_array $(obj) psum_array.o -lpthread
psum_local: $(local) psum_local.o
	$(cc) -o psum_local $(obj) psum_local.o -lpthread

csapp.o: $(deps)

.PHONY : clean
clean:
	rm -rf *.o
	rm -rf $(obj)
	rm -rf psum_mutex
	rm -rf psum_array
	rm -rf psum_local