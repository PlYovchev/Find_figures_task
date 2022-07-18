#include <iostream>
#include <set>

#include "task_executors/find_figures_solver.h"

using namespace std;

int main() 
{
   Matrix* matrix = new Matrix;
   (*matrix).data = new int*[6];
   (*matrix).data[0] = new int[6] { 1, 0, 0, 1, 1, 0 };
   (*matrix).data[1] = new int[6] { 1, 0, 1, 1, 0, 0 };
   (*matrix).data[2] = new int[6] { 1, 1, 0, 1, 0, 0 };
   (*matrix).data[3] = new int[6] { 0, 1, 1, 1, 0, 0 };
   (*matrix).data[4] = new int[6] { 0, 0, 0, 0, 1, 0 };
   (*matrix).data[5] = new int[6] { 0, 1, 1, 1, 0, 1 };
   (*matrix).data[6] = new int[6] { 0, 0, 0, 0, 1, 1 };
   matrix->rows = 7;
   matrix->cols = 6;

   FindFiguresSolver findFiguresSolver;
   cout << "The number of individual figures is: " << findFiguresSolver.findNumberOfFigures(*matrix);

   delete [] matrix->data[0];
   delete [] matrix->data[1];
   delete [] matrix->data[2];
   delete [] matrix->data[3];
   delete [] matrix->data[4];
   delete [] matrix->data[5];
   delete [] matrix->data[6];
   // delete[] matrix->data;
   delete matrix;
}
