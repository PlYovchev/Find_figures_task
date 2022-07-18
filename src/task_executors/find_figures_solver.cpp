#include <iostream>
#include <set>

#include "find_figures_solver.h"

using namespace std;

/**
 * The algorithm of this find the number of figures works as follow:
 * 1. Iteratively walk through the matrix/space;
 * 2. Each cell which is marked as part of a figure but the cells on the left (cell.row - 1) and on the top (cell.column -1) 
 * are not marked as part of figures, should be given a new unique number and this number has to be placed in an auxiliary set 
 * which to contain all unique numbers identifying figures that are found so far;
 * 3. Each cell which is marked as part of a figure and there is other figure either in the cell
 * on the left or on the top, should be marked with the number of the adjacent figure;
 * 4. Each cell which is marked as part of a figure and there are two different figures on the left and on the top,
 * should be marked with the number of the figure designated by the lesser number. The other number, bigger of the two,
 * has to be removed from the auxiliary set containing all unique numbers identifying figures 
 * as the two figures are now considered merged.
 * 5. In the end the number of individual figures is equal to the count of the elements in the auxiliary set.
 */
int FindFiguresSolver::findNumberOfFigures(Matrix& matrix) {
   // A helper matrix where each cell which is marked as part of a figures in the input matrix, 
   // is marked with either a new unique number or the number of an adjacent (on the left or on the top) figure.
   // The matrix is initialized with one additional row and column in order to avoid making checks for the boundaries of the matrix 
   // when iterating through the first row or the first column of the input matrix;
   int markedFiguresMatrix[matrix.rows+1][matrix.cols+1] = {{0}};
   // Auxiliary set which to hold the numbers identifying the individual figures.
   set<int> individualFigures;
   // A counter which to be incremented when a new figure is encountered.
   int nextFigureNumber = 0;
   for (size_t i = 0; i < matrix.rows; ++i) {
      for (size_t j = 0; j < matrix.cols; ++j) {
         Cell cell = { i, j };
         if (isCellMarked(matrix, cell)) {
            int figureNumber;
            if(isFigureAdjacentToCell(matrix, cell)) {
               int leftCellValue = markedFiguresMatrix[cell.row][cell.column+1];
               int topCellValue = markedFiguresMatrix[cell.row+1][cell.column];
               if (leftCellValue == 0 || topCellValue == 0) {
                  figureNumber = max(leftCellValue, topCellValue);
               } else {
                  figureNumber = min(leftCellValue, topCellValue);
                  if (leftCellValue != topCellValue) {
                     int figureNumberToDelete = max(leftCellValue, topCellValue);
                     individualFigures.erase(figureNumberToDelete);
                  }
               }
            } else {
               figureNumber = ++nextFigureNumber;
               individualFigures.insert(nextFigureNumber);
            }

            markedFiguresMatrix[i+1][j+1] = figureNumber;
         }
      }
   }
   return individualFigures.size();
}

/**
 * @brief Check if the cell is marked as part of a figure.
 * 
 * @param matrix The space containing the figures.
 * @param cell The cell which to be check if it is part of a figure.
 * @return true If the cell is part of a figure;
 * @return false Otherwise
 */
bool FindFiguresSolver::isCellMarked(Matrix& matrix, Cell& cell) {
   return matrix.data[cell.row][cell.column] == FigureMarker;
}

/**
 * @brief Check if there is a figure next to the current cell. The figure is identified by a number
 * 
 * @param matrix The space containing the figures.
 * @param cell  The cell which to be check if it is adjacect to figure.
 * @return true If the cell is adjacent to figure;
 * @return false Otherwise
 */
bool FindFiguresSolver::isFigureAdjacentToCell(Matrix& matrix, Cell& cell)
{
   return (cell.row > 0 && matrix.data[cell.row - 1][cell.column] != 0)
      || (cell.column > 0 && matrix.data[cell.row][cell.column - 1] != 0);
}