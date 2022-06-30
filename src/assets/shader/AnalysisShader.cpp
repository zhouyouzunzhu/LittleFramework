#include "AnalysisShader.h"
#include "CellShader.h"

// shader后缀是虚拟的，对应vs、fs、gs明文着色器的解析

AnalysisShader::AnalysisShader():
    AssetsAnalysis("shader")
{
}

AssetsCell* AnalysisShader::loadFromFile(const String& file, const String& type)
{
    if(type == "shader")
        return this->loadSrcShader(file);

    return nullptr;
}

void AnalysisShader::unloadAssetes(AssetsCell* cell)
{
    if(cell != nullptr)
    {
        CellShader* shaderCell = dynamic_cast<CellShader*>(cell);
        if(shaderCell->id > 0)
            glDeleteProgram(shaderCell->id);
        delete shaderCell;
    }
}

AssetsCell* AnalysisShader::loadSrcShader(const String& filePath)
{
    String basePath = filePath.substr(0, filePath.rfind("."));
    String vs, fs, gs;

    if(!this->readAllTextFromFile(basePath + ".vs", vs))
    {
        pWarning(u8"顶点着色器读取失败！%s", filePath.data());
        return nullptr;
    }

    if(!this->readAllTextFromFile(basePath + ".fs", fs))
    {
        pWarning(u8"片段着色器读取失败！%s", filePath.data());
        return nullptr;
    }

    if(!this->readAllTextFromFile(basePath + ".gs", gs))
    {
    }


    unsigned int vsObj = this->compileShader(vs, GL_VERTEX_SHADER, u8"vertex", filePath);
    unsigned int fsObj = this->compileShader(fs, GL_FRAGMENT_SHADER, u8"fragmet", filePath);
    unsigned int gsObj = this->compileShader(gs, GL_GEOMETRY_SHADER, u8"geometry", filePath);
    unsigned int program = this->linkProgram(vsObj, fsObj, gsObj, filePath);
    this->deleteShader(vsObj);
    this->deleteShader(fsObj);
    this->deleteShader(gsObj);

    if(program > 0)
    {
        CellShader* cell = new CellShader();
        cell->id = program;
        return cell;
    }


    return nullptr;
}


unsigned int AnalysisShader::compileShader(const String& code, int intType, const String& strType, const String& resPath)
{
    if(code.isEmpty())
        return 0;

    unsigned int shaderId = glCreateShader(intType);
    if(shaderId > 0)
    {
        const char* cCode = code.data();
        glShaderSource(shaderId, 1, &cCode, NULL);
        glCompileShader(shaderId);
        if(!checkCompileErrors(shaderId, strType, resPath))
            return shaderId;
    }
    return 0;
}

void AnalysisShader::deleteShader(unsigned int obj)
{
    if(obj > 0)
        glDeleteShader(obj);
}

unsigned int AnalysisShader::linkProgram(unsigned int vsObj, unsigned int fsObj, unsigned int gsObj, const String& resPath)
{
    if(vsObj == 0 || fsObj == 0)
        return 0;

    unsigned int program = glCreateProgram();
    if(program > 0)
    {
        glAttachShader(program, vsObj);
        glAttachShader(program, fsObj);
        if (gsObj > 0)
            glAttachShader(program, gsObj);
        glLinkProgram(program);
        if(!checkProgramErrors(program, resPath))
            return program;
    }
    return 0;
}

bool AnalysisShader::checkCompileErrors(unsigned int obj, const String& strType, const String& resPath)
{
    int success;
    char infoLog[1024];
    glGetShaderiv(obj, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(obj, 1024, NULL, infoLog);
        pWarning(u8"%s shader编译失败: %s\n%s", strType.data(), resPath.data(), infoLog);
        return true;
    }
    return false;
}

bool AnalysisShader::checkProgramErrors(unsigned int obj, const String& resPath)
{
    int success;
    char infoLog[1024];
    glGetProgramiv(obj, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(obj, 1024, NULL, infoLog);
        pWarning(u8"shader链接失败: %s\n%s", resPath.data(), infoLog);
        return true;
    }
    return false;
}
