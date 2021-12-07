# Recursive Graphics Generator Makefile V1
# Written by Mason Jacob
# This make file is intended to work for SFML installed on linux using the sudo apt-get install libsfml-dev command
# To attempt to use the SFML Library installed in this repository (might not work) use the commands commented below instead.
# Furthermore, using the installation in the repository also requires the ./generator.out command to be run like this the first time:
# export LD_LIBRARY_PATH=<sfml-install-path>/lib && ./generator.out
# After that, just ./generator.out will suffice

generator.out: main.o Menu.o SierpinskiTriangle.o KochSnowflake.o HilbertCurve.o DragonCurve.o 
	g++ *.o -o generator.out -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
# This is the command if you are attempting to use the library installed in the repository:
# g++ *.o -o generator.out -L<sfml-install-path>/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main.o: main.cpp
	g++ -c main.cpp
# This is the command if you are attempting to use the library installed in the repository:
# g++ -c main.cpp -I<sfml-install-path>/include

Menu.o: Source/Menu.cpp Headers/Menu.hpp
	g++ -c Source/Menu.cpp
# This is the command if you are attempting to use the library installed in the repository:
# g++ -c Source/Menu.cpp -I<sfml-install-path>/include

SierpinskiTriangle.o: Source/SierpinskiTriangle.cpp Headers/SierpinskiTriangle.hpp
	g++ -c Source/SierpinskiTriangle.cpp
# This is the command if you are attempting to use the library installed in the repository:
# g++ -c Source/SierpinskiTriangle.cpp -I<sfml-install-path>/include

KochSnowflake.o: Source/KochSnowflake.cpp Headers/KochSnowflake.hpp
	g++ -c Source/KochSnowflake.cpp
# This is the command if you are attempting to use the library installed in the repository:
# g++ -c Source/KochSnowflake.cpp -I<sfml-install-path>/include

HilbertCurve.o: Source/HilbertCurve.cpp Headers/HilbertCurve.hpp
	g++ -c Source/HilbertCurve.cpp
# This is the command if you are attempting to use the library installed in the repository:
# g++ -c Source/HilbertCurve.cpp -I<sfml-install-path>/include

DragonCurve.o: Source/DragonCurve.cpp Headers/DragonCurve.hpp
	g++ -c Source/DragonCurve.cpp
# This is the command if you are attempting to use the library installed in the repository:
# g++ -c Source/DragonCurve.cpp -I<sfml-install-path>/include