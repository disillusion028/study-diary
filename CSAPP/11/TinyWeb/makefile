cc = gcc
deps = ../../mycsapp.h ../../10/unix_error.h
obj = rio.o unix_error.o open_fd.o

tinyhttp: $(obj) tiny.o
	$(cc) -o tinyhttp $(obj) tiny.c -lpthread

open_fd.o: ../open_fd.c $(deps)
	$(cc) -c ../open_fd.c
rio.o: ../../10/rio.c $(deps)
	$(cc) -c ../../10/rio.c
unix_error.o: ../../10/unix_error.c $(deps)
	$(cc) -c ../../10/unix_error.c

.PHONY : clean
clean:
	rm -rf $(obj)
	rm *.o
	rm tinyhttp
