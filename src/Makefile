CC = g++ -std=c++17
TEST_FLAGS =-lgtest
TARGET = 3dviewer.a

OS = $(shell uname -s)
ifeq ($(OS), Darwin)
CHECK_FLAGS = -lcheck
OPEN_COMMAND = open
APP = 3dViewer.app 
else ifeq ($(OS), Linux)
CHECK_FLAGS = -lcheck -lsubunit -lpthread -lrt -lm
OPEN_COMMAND = less
APP = 3dViewer
endif

all: clean tests install

$(TARGET):
	$(CC) -c model/model.cpp
	ar rcs $(TARGET) model.o
	ranlib $(TARGET) 

tests: clean $(TARGET)
	$(CC) tests/tests.cpp $(TARGET) $(TEST_FLAGS) -o unit-test
	./unit-test
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --log-file="vlg.log" ./unit-test

clean:
	@rm -rf *.o *.a *.gch tests/*.gcno tests/*.gcda report/ s21_test.info *.dSYM/ *.out *.log build/ unit-test html/ latex/

gcov_report: clean
	$(CC) tests/*.cpp -o tests/gcov_test --coverage $(TEST_FLAGS) -lm
	./tests/gcov_test
	lcov --directory tests -t "stest" -o s21_test.info -c --no-external
	genhtml -o report/ s21_test.info 
	open ./report/index.html
	rm -rf gcov_test

clang:
	clang-format -style=Google -n tests/* controller/* 3dViewer/*.cpp 3dViewer/*.h


install: build
	cp -r build/$(APP) $(HOME)/
	make clean

uninstall: clean
	rm $(HOME)/$(APP)

build:
	mkdir build
	cd ./build/ && qmake ../3dViewer/ && make

rebuild: clean build

dist:
	mkdir 3dViewer2.0/
	mkdir 3dViewer2.0/src
	cp -r 3dViewer controller model object_files tests Doxyfile Makefile 3dViewer2.0/src/
	tar cvzf 3dViewer2.0.tgz 3dViewer2.0/
	mv 3dViewer2.0.tgz $(HOME)/
	rm -rf 3dViewer2.0/

dvi:
	doxygen Doxyfile
	open ./html/index.html

