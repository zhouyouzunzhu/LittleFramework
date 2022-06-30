#pragma once

#include "assets/AssetsCell.h"
#include <unordered_map>
#include <vector>

class CellShader : public AssetsCell
{
    friend class AnalysisShader;
    friend class Shader;

private:
    unsigned int _id;   // programId
};

