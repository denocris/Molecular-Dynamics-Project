CC=gcc
CFLAGS=-I. -Wall -fPIC #-pg for profiling, for optimization -O3 -march=native
LDFLAGS=-lm
DEPS=$(wildcard src/*.h)
#SRCS=$(wildcard src/*.c)
SRCS=src/force.c src/ljmd.c src/output.c src/utilities.c src/verlet1.c src/verlet2.c src/input.c
#OBJS=$(SRCS:src/.c=Obj-serial/.o)

TEST_SRC=src/test1.c src/tes2.c
TEST_O = ($TEST_SRC:.c=.o)
TEST_EXE = $(TEST_SRC:.c=.x)

.SUFFIXES:



OBJS=$(SRCS:.c=.o)
TARGET=ljmd_serial


all: info $(TARGET)
					$(info You are ready to execute!!)

.PHONY: info

info:
	$(info --------------------------- deps)
	$(info $(DEPS))
	$(info ------------------------ srcs)
	$(info $(SRCS))
	$(info --------------------------- OBJS)
	$(info $(OBJS))

%.o: %.c $(DEPS)
	echo "$<" # frist element of r.h.s
	echo "$^" # all r.h.s.
	echo "$@" # target name (l.h.s.)
	$(CC) -c $< $(CFLAGS) -o $@


$(TARGET): $(OBJS)
	@echo "$^"
	$(CC) -o $@ $(OBJS) $(LDFLAGS)


clean:
	$(info ********** cleaning up *********)
	@rm -f *~ src/*.o $(TARGET) > /dev/null 2>&1


.PHONY: clean
# try to modify a .c file and recompile the library

$(TARGET).so: $(OBJS)
	$(CC) -shared $^ -o $@ -lm



test: test_1 test_2
	@echo "run test_1"
	@./test_1
	@echo "run test_2"
	@./test_2

test_1: src/test1.o $(TARGET).so
	$(CC) $^ -o $@ -Wl,-rpath,. -lm

src/test_1.o: src/test1.c
	$(CC) -c $^ -o $@ -I.


test_2: src/test2.o $(TARGET).so
	$(CC) $^ -o $@ -Wl,-rpath,. -lm

src/test_2.o: src/test2.c
	$(CC) -c $^ -o $@ -I.
