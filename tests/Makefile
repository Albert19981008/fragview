CXX = g++
CFLAGS = -g3 -ggdb3 -O0

all: severity_test1
	make -C .. clusters.o

%.o: %.cpp
	$(CXX) $(CFLAGS) -o $@ -c $<

severity_test1: severity_test1.o ../clusters.o
	$(CXX) -o severity_test1 severity_test1.o ../clusters.o

clean:
	rm -f *.o
	rm -f severity_test1

