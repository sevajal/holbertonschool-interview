#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H
#include <stdlib.h>
#include <stdio.h>
#define SLIDE_RIGHT 1
#define SLIDE_LEFT 0

int slide_line(int *line, size_t size, int direction);
int slide_left(int *line, size_t size);
int slide_right(int *line, size_t size);

#endif
