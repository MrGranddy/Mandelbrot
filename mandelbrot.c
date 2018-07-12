#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int manderIter(float cx, float cy, int maxIter, float divRange){
    float xx = 0;
    float yy = 0;
    float xy = 0;
    float x = 0;
    float y = 0;
    int iter = maxIter;
    while(iter-- && xx + yy <= divRange){
        x = xx - yy + cx;
        y = 2 * xy + cy;
        xx = pow(x, 2);
        yy = pow(y, 2);
        xy = x * y;
    }
    return maxIter - iter - 1;
}

void mandelbrot(int height, int width, float xmin, float xmax, float ymin, float ymax, int maxIter, float divRange, char *fileName){
    float x_unit = (xmax - xmin) / width;
    float y_unit = (ymax - ymin) / height;
    FILE *mandel = fopen(fileName, "w");
    int i, j;
    for(i = 0; i < height; ++i){
        fprintf(mandel, "%d", manderIter(xmin, ymax - i * y_unit, maxIter, divRange));
        for(j = 1; j < width; ++j){
            fprintf(mandel, " %d", manderIter(xmin + j * x_unit, ymax - i * y_unit, maxIter, divRange));
        }
        fprintf(mandel, "\n");
    }
    fclose(mandel);
}

int main(int argc, char **argv){
    int height = atoi(argv[1]);
    int width = atoi(argv[2]);
    float xmin, xmax, ymin, ymax, divRange;
    int maxIter;
    xmin = atof(argv[3]);
    xmax = atof(argv[4]);
    ymin = atof(argv[5]);
    ymax = atof(argv[6]);
    maxIter = atoi(argv[7]);
    divRange = atoi(argv[8]);
    mandelbrot(height, width, xmin, xmax, ymin, ymax, maxIter, divRange, argv[9]);
    return 0;
}