#pragma once

#include <stddef.h>

using namespace std;

const int FigureMarker = 1;

struct Matrix
{
   int **data;
   size_t rows;
   size_t cols;
};

struct Cell
{
   size_t row;
   size_t column;
};

class FindFiguresSolver
{
   public:
      /**
       * @brief Finds the number of individual figures in the provided space;
       * 
       * @param matrix The space which to be searched for the individual figures;
       * @return int - The number of individual figures
       */
      int findNumberOfFigures(Matrix& matrix);

   private:
      bool isFigureAdjacentToCell(Matrix& matrix, Cell& cell);
      bool isCellMarked(Matrix& matrix, Cell& cell);
};