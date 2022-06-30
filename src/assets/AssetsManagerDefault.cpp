#include "AssetsManager.h"

#include "assets/csv/AnalysisCsv.h"             // csv解析
#include "assets/shader/AnalysisShader.h"       // shader解析
#include "assets/image/AnalysisImage.h"         // 图片解析

AssetsManager* AssetsManager::CreateDefaultManager()
{
    AssetsManager* manager = new AssetsManager;

    manager->regAnlysis(new AnalysisCsv);
    manager->regAnlysis(new AnalysisShader);
    manager->regAnlysis(new AnalysisImage);

    return manager;
}
