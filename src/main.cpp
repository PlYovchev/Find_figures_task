#include <iostream>
#include <set>

#include "test_loaders/json_loader.h"
#include "task_executors/find_figures_solver.h"

using namespace std;

int main() 
{
   FindFiguresSolver findFiguresSolver;
   JsonTestsLoader* jsonTestsLoader = new JsonTestsLoader("resources/test_cases.json");
   int x;
   while (cin >> x)
   {  
      Matrix matrix = jsonTestsLoader->getTestCase(x);
      int numberOfIndividualFigures = findFiguresSolver.findNumberOfFigures(matrix);
      cout << "The number of individual figures is: " << numberOfIndividualFigures << endl;
   }
   delete jsonTestsLoader;
}

