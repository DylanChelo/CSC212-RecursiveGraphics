# CSC 212 Final Group Project: Recursive Graphics (Fractals)
*Created by Dylan Chelo, Mason Jacob, and Nick Powers*

## Overview
This project uses the SFML Library to create an interative program that generates recursive graphics. Users interact with the program using keystrokes, to create the following fractals:
1. Sierpinski's Triangle
2. Koch's Snowflake
3. Hilbert's Curve
4. Dragon's Curve

## Setup

This program is mainly tested on Ubuntu, and currently requires that the SFML library is installed using the command listed below. There was an attempt made to use the Linux version of the SFML Library installed directly into the libraries folder of this repository, and instructions on how to try that are in comments in the Makefile. However, at this time it is not 100% working, so the steps below are recommended. 

### Prerequisites

1. **Install g++**

` sudo apt-get update `

` sudo apt-get install g++ `

2.  **Install SFML library**

The SFML Library is currently installed in this repository, however compiling the files using the Makefile is not 100% working. Therefore, it is necessary to install the library through the linus command line using the command below in order to use the current version of the Makefile. 

` sudo apt-get install libsfml-dev `

## Compile and Run
1. Clone this repository
2. cd to the 'Recursive Graphics' directory
3. Type 'make' in your terminal (without quotes)
4. Type './generator.out' in your terminal (also without quotes)
5. Read the Menu screen for instructions on how to use the generator

## Troubleshooting
The most common issue with this method of installing and compiling the files with SFML is that the files do compile, however the following error occurs when the ./generator.out comnmand is run to start the program:

The solution to this can be found here[https://www.reddit.com/r/bashonubuntuonwindows/comments/6p3u56/cannot_get_sfml_to_work_properly/]. To solve this problem, you must install a Windows XServer like Mwing, and then run the following command in the linux terminal to set the display correctly:
` export DISPLAY=:0 `
To check that the display has been set, execute the following command:
` echo $DISPLAY `
which should return the set display, :0

# Gallery:
## Sierpinski Triangle:

![Sierpinski Triangle](Resources/Images/SierpinskiTriangle1.jpg)
![Sierpinski Triangle](Resources/Images/SierpinskiTriangle2.jpg)

------------------------------------------------------------
## Koch's Snowflake:

![Koch's Snowflake](Resources/Images/KochSnowflake1.jpg)
![Koch's Snowflake](Resources/Images/KochSnowflake2.jpg)
![Koch's Snowflake](Resources/Images/KochSnowflake3.jpg)

------------------------------------------------------------
## Hilbert's Curve:

![Hilbert's Curve](Resources/Images/HilbertCurve1.jpg)
![Hilbert's Curve](Resources/Images/HilbertCurve2.jpg)
![Hilbert's Curve](Resources/Images/HilbertCurve3.jpg)

------------------------------------------------------------
## Dragon's Curve:

![Dragon's Curve](Resources/Images/DragonCurve1.jpg)
![Dragon's Curve](Resources/Images/DragonCurve2.jpg)
![Dragon's Curve](Resources/Images/DragonCurve3.jpg)

------------------------------------------------------------
