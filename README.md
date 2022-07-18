# Find_figures_task

This project is a solution to the task - find the number of all individual figures.

# Implemantation

The algorithm in the solution works as follows:
1. Iteratively walk through the matrix/space;
2. Each cell which is marked as part of a figure but the cells on the left (cell.row - 1) and on the top (cell.column -1) 
   are not marked as part of figures, should be given a new unique number and this number has to be placed in an auxiliary set 
   which to contain all unique numbers identifying figures that are found so far;
3. Each cell which is marked as part of a figure and there is other figure either in the cell
   on the left or on the top, should be marked with the number of the adjacent figure;
4. Each cell which is marked as part of a figure and there are two different figures on the left and on the top,
   should be marked with the number of the figure designated by the lesser number. The other number, bigger of the two,
   has to be removed from the auxiliary set containing all unique numbers identifying figures 
   as the two figures are now considered merged.
5. In the end the number of individual figures is equal to the count of the elements in the auxiliary set.

# Complexity

The algorithm is with complexity O(n*m) where n and m are the dimensions of the input matrix.
It requires one auxiliary matrix and one additional set to track the unique figures numbers.

