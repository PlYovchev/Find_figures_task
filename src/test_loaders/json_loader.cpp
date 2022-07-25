#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

#include "json_loader.h"

using namespace std;
using json = nlohmann::json;

JsonTestsLoader::JsonTestsLoader(string testResourceFilePath)
{
    this->resourceFilePath = testResourceFilePath;
    this->getAllTestCases();
}

void JsonTestsLoader::getAllTestCases()
{
   std::ifstream f(this->resourceFilePath);
   json data = json::parse(f);
   json testCases = data["tests"];
   for (json::iterator testsIterator = testCases.begin(); testsIterator != testCases.end(); ++testsIterator)
   {
        Matrix matrix;
        matrix.rows = (*testsIterator)["rows"];
        matrix.cols = (*testsIterator)["cols"];
        matrix.data = new int*[10];
        json jsonData =  (*testsIterator)["data"];
        int count = 0;
        for (json::iterator it = jsonData.begin(); it != jsonData.end(); ++it) {
            matrix.data[count] = new int[matrix.cols];
            vector<int> dataRow =  (*it).get<std::vector<int>>();
            std::copy(dataRow.begin(), dataRow.end(), matrix.data[count]);
            ++count;
        }

        this->testMatrixes.push_back(matrix);
   }
}

Matrix JsonTestsLoader::getTestCase(int number) 
{
    if (number < 0 || number >= this->testMatrixes.size()) 
    {
        throw invalid_argument("The test number is outside test cases list boundaries.");
    }

    return this->testMatrixes[number];
}

int JsonTestsLoader::getTestCasesCount()
{
    return this->testMatrixes.size();
}
