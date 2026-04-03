# MY PHYSICS ENGINE

## introduction

This is a personal project  
a simple 2D physics engine, to practice my C++

## How to use

This project only works on Linux (for now...)

### dependencies

I used some C++ Libraries
- Catch2
- SFML

you'll also need **CMake** version 3.28.3 or above, and **Doxygen** for documentation.

### build

Download the repo

using https
```
$ git clone https://github.com/Axolotl5156/my_physic_engine.git 
```
using ssh
```
$ git clone git@github.com:Axolotl5156/my_physic_engine.git
```
or simply download the zip file  
  
  
in the project folder, build it simply using CMake
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```
the binary will be in `build/app/my_physic_engine`  

generate the documentation with
```
$ make doc
```
the docs will be available in `build/docs/html/index.html`

### run

```
$ ./my_physic_engine
```
You'll be asked to choose a simulation to run. Select one and enjoy!

## Content

For now, the engine can only run one simple simulation, a falling ball in a gravity field  
More to come...

## How does it work

The project is seperate in 4 parts
1. the engine itself
2. the renderer
3. the simulation
4. the main app

### the engine

is in `engine/`  
each object is built as a `Body` object  
they have a `Shape` attribut, which is an abstract class that inherits different geometries, such as `CircleShape`  
`Body` is for all the physics (mass, position, velocity...), and `Shape` is only for the geometry. It is more convenient to separate, especially when it comes to the rendering part..  
finally, the `World` class is for the place where objects will evolve.  

### the renderer

I used `SFML` for the graphics part  

### the simulations

This is where I set up all settings for running one case (for example the bouncing ball)

### the main app

it's where `main.cpp` come in, the user can choose a simulation to run, and the corresponding function from the correct class will be called

## More to come

I have some plans to upgrade this tiny project
- add more simulation cases
- add a way to save the results as a video file
- allow the user to run a personalized simulation described in a JSON file