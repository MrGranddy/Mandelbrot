# Mandelbrot
A python code which runs a c code to create the mandelbrot set.

The file you should run is the python script "mandelbrot_with_c.py", it uses numpy and matplotlib also os and sys modules.
To run the script you have to give console arguments, the format should be like:

>>> python3 mandelbrot_with_c.py [height] [width] [xmin] [xmax] [ymin] [ymax] [MaxIterations] [Diverge Range Squared]

An example: python3 mandelbrot_with_c.py 10000 10000 -2 2 -2 2 200 4

The python script runs a compiled C code, a further addition might be that if the code is not compiled yet the python
script can compile it itself. But for now if you don't have a compiled version of the C code then first you must
compile it with the following command:

>>> gcc mandelbrot.c -o mandelbrot -lm

This will create an executable called "mandelbrot" then when you run the python script it will give the console arguments
to this program and run it by itself. The C code creates a txt file called "mandelbrot.txt" then the python script
takes this txt file and creates an image with it, the image will be named "mandelbrot.png".

So if we sum up a quick run would be, first if you don't have "mandelbrot" executable use:

>>> gcc mandelbrot.c -o mandelbrot -lm

then create your mandelbrot with:

>>> python3 mandelbrot_with_c.py [height] [width] [xmin] [xmax] [ymin] [ymax] [MaxIterations] [Diverge Range Squared]

Ahter you compiled the C code you don't have to compile it over and over.
