#include "AnalysisCsv.h"
#include "CellCsv.h"
#include <fstream>

AnalysisCsv::AnalysisCsv()
    :AssetsAnalysis("csv")
{
}

AssetsCell* AnalysisCsv::loadFromFile(const String& filePath, const String& type)
{
    if(type == "csv")
        return this->loadSrcCsv(filePath);
    
    return nullptr;
}

void AnalysisCsv::unloadAssetes(AssetsCell* cell)
{
    if(cell != nullptr)
        delete cell;
}

AssetsCell* AnalysisCsv::loadSrcCsv(const String& filePath)
{
    std::ifstream file;
    file.open(filePath.data());
    if(file.is_open())
    {
        CellCsv* cell = new CellCsv;
        bool isFirstLine = true;

        std::string line;
        while(std::getline(file, line))
        {
            String tempLine = line;
            auto items = tempLine.split(",");
            if(isFirstLine)
            {
                isFirstLine = false;
                for(auto& it : items)
                {
                    it.trim();
                    if(!it.isEmpty())
                    {
                        cell->header.emplace_back(it);
                    }
                }
            }else
            {
                CellCsv::LineItem& lineItem = cell->datas.emplace_back();
                for(size_t i = 0; i < cell->header.size() && i < items.size(); ++i)
                {
                    lineItem[cell->header[i]] = items[i].trim(); 
                }
            }
        }
        file.close();

        return cell;
    }
    return nullptr;
}
