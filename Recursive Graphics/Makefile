generator.out: main.o SierpinskiTriangle.o menu.o
	g++ *.o -o generator.out -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp

#KochSnowflake.o: Source/KochSnowflake.cpp Header/KochSnowflake.h
#g++ -c Source/KochSnowflake.cpp

SierpinskiTriangle.o: Source/SierpinskiTriangle.cpp Headers/SierpinskiTriangle.hpp
	g++ -c Source/SierpinskiTriangle.cpp

menu.o: Source/menu.cpp Headers/menu.hpp
	g++ -c Source/menu.cpp