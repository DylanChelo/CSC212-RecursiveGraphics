# Recursive Graphics Generator Makefile V1
# Written by Mason Jacob

generator.out: main.o Menu.o SierpinskiTriangle.o KochSnowflake.o HilbertCurve.o DragonCurve.o
	g++ *.o -o generator.out -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp

Menu.o: Source/Menu.cpp Headers/Menu.hpp
	g++ -c Source/Menu.cpp

SierpinskiTriangle.o: Source/SierpinskiTriangle.cpp Headers/SierpinskiTriangle.hpp
	g++ -c Source/SierpinskiTriangle.cpp

KochSnowflake.o: Source/KochSnowflake.cpp Headers/KochSnowflake.hpp
	g++ -c Source/KochSnowflake.cpp

HilbertCurve.o: Source/HilbertCurve.cpp Headers/HilbertCurve.hpp
	g++ -c Source/HilbertCurve.cpp

DragonCurve.o: Source/DragonCurve.cpp Headers/DragonCurve.hpp
	g++ -c Source/DragonCurve.cpp
