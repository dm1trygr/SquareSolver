CFLAGS=-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal \
	   -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs \
	   -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe \
	   -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body \
	   -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers \
	   -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo \
	   -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits \
	   -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

OBJ_PATH=source/objects/
SRC_PATH=source/

MAIN_PATH=$(OBJ_PATH)main.o
MODES_PATH=$(OBJ_PATH)modes.o
INPUT_PATH=$(OBJ_PATH)input.o
OUTPUT_PATH=$(OBJ_PATH)output.o
SOLVE_PATH=$(OBJ_PATH)solve.o
TESTS_PATH=$(OBJ_PATH)unittests.o

OBJ_FILES=$(MAIN_PATH) $(MODES_PATH) $(INPUT_PATH) $(OUTPUT_PATH) $(SOLVE_PATH) $(TESTS_PATH)

all: square_solver

square_solver: $(OBJ_PATH)main.o $(OBJ_PATH)modes.o $(OBJ_PATH)input.o $(OBJ_PATH)output.o $(OBJ_PATH)solve.o $(OBJ_PATH)unittests.o
	g++ $(OBJ_FILES) -o square_solver $(CFLAGS)

$(OBJ_PATH)main.o: main.cpp
	g++ -o $(MAIN_PATH) -c main.cpp $(CFLAGS)

$(OBJ_PATH)modes.o: source/modes.cpp
	g++ -o $(MODES_PATH) -c $(SRC_PATH)modes.cpp $(CFLAGS)

$(OBJ_PATH)input.o: source/input.cpp
	g++ -o $(INPUT_PATH) -c $(SRC_PATH)input.cpp $(CFLAGS)

$(OBJ_PATH)output.o: source/output.cpp
	g++ -o $(OUTPUT_PATH) -c $(SRC_PATH)output.cpp $(CFLAGS)

$(OBJ_PATH)solve.o: source/solve.cpp
	g++ -o $(SOLVE_PATH) -c $(SRC_PATH)solve.cpp $(CFLAGS)

$(OBJ_PATH)unittests.o: source/unittests.cpp
	g++ -o $(TESTS_PATH) -c $(SRC_PATH)unittests.cpp $(CFLAGS)

clean:
	rm -rf *.o square_solver
