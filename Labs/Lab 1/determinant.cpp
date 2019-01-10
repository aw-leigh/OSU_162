/*********************************************************************
** Author: Andrew Wilson
** Date: Jan 10, 2019
** Description: Calculates the determinant of the matrix in MatrixCalculator
*********************************************************************/
#include <iostream>
#include "determinant.hpp"

int determinant(int **array_in, int size)
{
    if (size == 2) //determinant is ad - bc
    {
        return (array_in[0][0] * array_in[1][1]) - (array_in[1][0] * array_in[0][1]);
    }
    else if (size == 3)  //determinant is a(ei − fh) − b(di − fg) + c(dh − eg)
    {
        return ((array_in[0][0])*((array_in[1][1]*array_in[2][2]) - (array_in[1][2]*array_in[2][1]))) - 
               ((array_in[0][1])*((array_in[1][0]*array_in[2][2]) - (array_in[1][2]*array_in[2][0]))) +
               ((array_in[0][2])*((array_in[1][0]*array_in[2][1]) - (array_in[1][1]*array_in[2][0])));
    }
    else
    {
        return -777; //junk value
    }
}