#include <iostream>
#include <set>

#include "find_figures_solver.h"

using namespace std;

/**
 * @brief Finds the number of figures in the provided space;
 * 
 * @param matrix The space which to be searched for the individual figures;
 * @return int - The number of individual figures
 */
int FindFiguresSolver::findNumberOfFigures(Matrix& matrix) {
   // The algorithm of this function is as follows:
   // 1. Iteratively walk through the matrix/space;
   // 2. Mark each of the cells with a number of a new figure as long as it meets the following conditions:
   // 2.1. there is no number identifying another figure in the cell on the left or in cell on top of the current cell;
   // 3. If the above condition is not met and there is a number identifying another figure in any of the two cells mentioned above, do the following:
   // 3.1. If any of the two adjacent cells (on left and on top) is marked as not part of a figure e.g. 0, mark the current cell with the number of the cell part of a figure;
   // 3.2. If both of the two adjacent cells are marked as part of different figures, mark the current figure with the smaller number of the two figures. 
   // The bigger number identifying the other figure has to be removed from the auxiliary set with individual numbers as both figures are not considered merged.
   // then take the smallest 
   int markedFiguresMatrix[matrix.rows+1][matrix.cols+1] = {{0}};
   set<int> individualFigures;
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
   return matrix.data[cell.row][cell.column] == FindFiguresSolver::FigureMarker;
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