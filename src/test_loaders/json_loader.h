#include <string>
#include <vector>
#include "../task_executors/find_figures_solver.h"

using namespace std;

class JsonTestsLoader 
{
    public:
        JsonTestsLoader(string testResourceFilePath);
        Matrix getTestCase(int number);
        int getTestCasesCount();

    private:
        void getAllTestCases();
        string resourceFilePath;
        vector<Matrix> testMatrixes;
};