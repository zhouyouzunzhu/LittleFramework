#pragma once

#include "assets/AssetsCell.h"
#include <unordered_map>
#include <vector>

class CellShader : public AssetsCell
{
    friend class AnalysisShader;
    friend class WrappersShader;

private:
    unsigned int _id;   // programId
};

