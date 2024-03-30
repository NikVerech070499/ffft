flags=--std=c++17 -pthread -fopenmp -g

a.out: entrypoint.cpp entrypoint.h fft.cpp
	g++ $(flags) -o a.out entrypoint.cpp fft.cpp

#exe.out:entrypoint.o fft.o
#	g++ $(flags) $^ -o $@
#
#entrypoint.o:entrypoint.cpp
#	g++ $(flags) -c entrypoint.cpp
#
#fft.o:fft.cpp
#	g++ $(flags) -c fft.cpp
