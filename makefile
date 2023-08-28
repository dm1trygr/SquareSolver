CFLAGS=-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE
OBJ_FILES=main.o modes.o input.o output.o solve.o unittests.o

all: square_solver

square_solver: main.o modes.o input.o output.o solve.o unittests.o
	g++ $(OBJ_FILES) -o square_solver $(CFLAGS)

main.o: main.cpp
	g++ -c main.cpp

modes.o: modes.cpp
	g++ -c modes.cpp

input.o: input.cpp
	g++ -c input.cpp

output.o: output.cpp
	g++ -c output.cpp

solve.o: solve.cpp
	g++ -c solve.cpp

unittests.o: unittests.cpp
	g++ -c unittests.cpp

clean:
	rm -rf *.o square_solver
