#pragma once

#include "assets/AssetsAnalysis.h"


class AnalysisShader : public AssetsAnalysis
{
public:
    AnalysisShader();


    virtual AssetsCell* loadFromFile(const String& file, const String& type);

    virtual void unloadAssetes(AssetsCell* cell);


private:
    // 加载原始文本形式
    AssetsCell* loadSrcShader(const String& filePath);

    // 编译shader
    unsigned int compileShader(const String& code, int intType, const String& strType, const String& resPath);

    // 移除编译好的shader
    void deleteShader(unsigned int obj);

    // 链接program
    unsigned int linkProgram(unsigned int vsObj, unsigned int fsObj, unsigned int gsObj, const String& resPath);

    // 检查错误
    bool checkCompileErrors(unsigned int obj, const String& strType, const String& resPath);

    // 检查着色程序错误
    bool checkProgramErrors(unsigned int obj, const String& resPath);
};

