generator.out: main.o Menu.o SierpinskiTriangle.o HilbertCurve.o #KochSnowflake.o HilbertCurve.o #DragonCurve.o
	g++ *.o -o generator.out -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp

Menu.o: Source/menu.cpp Headers/menu.hpp
	g++ -c Source/menu.cpp

SierpinskiTriangle.o: Source/SierpinskiTriangle.cpp Headers/SierpinskiTriangle.hpp
	g++ -c Source/SierpinskiTriangle.cpp

#KochSnowflake.o: Source/KochSnowflake.cpp Header/KochSnowflake.hpp
#	g++ -c Source/KochSnowflake.cpp

HilbertCurve.o: Source/HilbertCurve.cpp Headers/HilbertCurve.hpp
	g++ -c Source/HilbertCurve.cpp

#DragonCurve.o: Source/DragonCurve.cpp Headers/DragonCurve.hpp
#	g++ -c Source/DragonCurve.cpp