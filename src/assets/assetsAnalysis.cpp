#include "AssetsAnalysis.h"
#include <fstream>
#include <sstream>

AssetsAnalysis::AssetsAnalysis(const String& supporTypes)
{
    if(supporTypes.find(",") != -1)
        this->_supportAnalysisTypes = supporTypes.split(",");
    else if(!supporTypes.isEmpty())
        this->_supportAnalysisTypes.emplace_back(supporTypes);
}

bool AssetsAnalysis::readAllTextFromFile(const String& filePath, String& out)
{
    std::ifstream file;
    file.open(filePath.data());
    if(!file.is_open())
        return false;

    std::stringstream buffer;
    buffer<<file.rdbuf();
    out = buffer.str();
    file.close();

    return true;
}

AssetsAnalysis::~AssetsAnalysis()
{
}

AssetsCell* AssetsAnalysis::loadFromFile(const String& file, const String& type)
{
    return nullptr;
}

void AssetsAnalysis::unloadAssetes(AssetsCell* cell)
{
}

const std::vector<String>& AssetsAnalysis::getSupportAnalysisType()
{
    return this->_supportAnalysisTypes;
}
