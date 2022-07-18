#include <stddef.h>

using namespace std;

struct Matrix {
   int **data;
   size_t rows;
   size_t cols;
};

struct Cell {
   size_t row;
   size_t column;
};

class FindFiguresSolver {
   public:
      int findNumberOfFigures(Matrix& matrix);

   private:
      static const int FigureMarker = 1;

      bool isFigureAdjacentToCell(Matrix& matrix, Cell& cell);
      bool isCellMarked(Matrix& matrix, Cell& cell);
      bool isCellNotPartOfFigure(Matrix& matrix, Cell& cell);
};