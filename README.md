# CSC 212 Final Group Project: Recursive Graphics (Fractals)
------------------------------------------------------------
*Created by Dylan Chelo, Nick Powers, and Mason Jacob*

## Overview
This project uses the SFML Library to create an interative program that generates recursive graphics. Users interact with the program using keystrokes, to create the following fractals:
1. Sierpinski's Triangle
2. Koch's Snowflake
3. Hilbert's Curve
4. Dragon's Curve

## Setup

This program is mainly tested on Ubuntu, as it uses the Linux version of the SFML Library installed directly into the libraries folder of this repository.

### Prerequisites

1. **Install g++**

` sudo apt-get update `

` sudo apt-get install g++ `

2.  **Install SFML library (Optional)**

There are three ways to install SFML library:

* Using package manager

$ sudo apt-get install libsfml-dev

* Download the SDK

Download the SDK from the [download page](https://www.sfml-dev.org/download.php), unpack it and copy the files to your preferred location: either a separate path in your personal folder (like /home/me/sfml), or a standard path (like /usr/local).

* Building SFML yourself

If you want to go this way, there's a [dedicated tutorial](https://www.sfml-dev.org/tutorials/2.0/compile-with-cmake.php) on building SFML yourself.

## Compile and Run
1. Clone this repository
3. Type 'make' in your terminal (without quotes)
4. Type './generator.out' in your terminal (also without quotes)
5. Read the Menu screen for instructions on how to use the generator

# Gallery:
## Sierpinski Triangle:

![Sierpinski Triangle](https://raw.githubusercontent.com/BojanV03/SFML_Fractals/master/Images/Mandelbrot.jpg "Sierpinski Triangle")


## Sierpinski Triangle:
You can render the Sierpinski Triangle with as many iterations as you want(or as many as your processor can handle) and set an arbitrary bounding box to position and set the scale of the triangle. It also has a color member variable which you can use to change the color of it but I preffer this gradient so i'll keep it this way.
![Sierpinski Triangle Animation](https://raw.githubusercontent.com/BojanV03/SFML_Fractals/master/Images/SierpinskiTriangle.gif "Sierpinski Triangle Animation")

## Sierpinski Carpet:
You can render the Sierpinski Carpet with as many iterations as you want(or as many as your processor can handle) and set an arbitrary bounding box to position and set the scale of the carpet. It also has a color member variable which you can use to change the color of it but I preffer this gradient so i'll keep it this way.

Additionally you can set the carpet matrix(instead of the usual 3x3) to arbitrary width/height and pass it an array of indexes you don't want to render recursively.

standard 3x3 carpet excluding the (1, 1) square where (0, 0) is the top left square:
![Sierpinski Carpet Animation](https://raw.githubusercontent.com/BojanV03/SFML_Fractals/master/Images/SierpinskiCarpet.gif "Sierpinski Carpet Animation")

custom 5x5 carpet excluding the (1, 1), (1, 2), (1, 3), (2, 1), (2, 3), (3, 1), (3, 2), (3, 3) squares.
![Sierpinski Carpet 5x5](https://raw.githubusercontent.com/BojanV03/SFML_Fractals/master/Images/SierpinskiCarpet5x5.jpg "Sierpinski Carpet 5x5")

custom 5x5 carpet excluding the top left and bottom right edge squares, looks kinda like a snowflake, doesn't it?
![Sierpinski Carpet Snowflake](https://raw.githubusercontent.com/BojanV03/SFML_Fractals/master/Images/SierpinskiCarpetSnowflake.jpg "Sierpinski Carpet Snowflake")

custom 3x3 carpet excluding the top left and bottom right squares:
![Sierpinski Carpet Tank](https://raw.githubusercontent.com/BojanV03/SFML_Fractals/master/Images/SierpinskiCarpetTank.png "Sierpinski Carpet Tank")

## Tree Fractal:
You can render the standard Tree Fractal with as many iterations as you want(or as many as your processor can handle), set the initial seed location, adjust the width/height of a branch, change the scaling factor and color and have seperate angles for the left and right branch.

The following gif shows several iteration of a tree with starting color (70,190,63), scaling factor 0.88, left branch angle of 30 degrees, right branch angle of 13 degrees, Height/Width of 96/12
![Tree Fractal Animation](https://raw.githubusercontent.com/BojanV03/SFML_Fractals/master/Images/TreeFractal.gif "Tree Fractal Animation")

## Koch Snowflake:
You can render the Koch Snowflake with as many iterations as you want(or as many as your processor can handle) and set an arbitrary bounding box to position and set the scale of the flake. Adjusting the color and wether or not it grows outwards or inwards is also possible

![Koch Snowflake Animation](https://raw.githubusercontent.com/BojanV03/SFML_Fractals/master/Images/KochSnowflake.gif "Koch Snowflake Animation")