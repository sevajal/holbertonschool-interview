#!/usr/bin/python3
""" Rotate 2d matrix """


def rotate_2d_matrix(matrix):
    """ Function that rotates a 2d matrix 90 degrees clockwise """
    matrix.reverse()
    matrixCopy = [i.copy()
         for i in matrix]
    for i, row in enumerate(matrixCopy):
        for j, col in enumerate(row):
            matrix[j][i] = matrixCopy[i][j]
