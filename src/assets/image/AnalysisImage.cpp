#include "AnalysisImage.h"
#include "CellImage.h"

#ifndef STB_IMAGE_IMPLEMENTATION
    #define STB_IMAGE_IMPLEMENTATION
#endif
extern "C" {
    #include "stb_image.h"
}


AnalysisImage::AnalysisImage():
    AssetsAnalysis("png,jpg,jpeg")
{
}

AssetsCell* AnalysisImage::loadFromFile(const String& file, const String& type)
{
    if(type == "png" || type == "jpg" || type == "jpeg")
        return this->loadSrcImageByFile(file);

    return nullptr;
}

void AnalysisImage::unloadAssetes(AssetsCell* cell)
{
    if(cell != nullptr)
    {
        CellImage* image = dynamic_cast<CellImage*>(cell);
        if(image->data != nullptr)
            stbi_image_free(image->data);
        delete image;
    }
}

AssetsCell* AnalysisImage::loadSrcImageByFile(const String& filePath)
{
    CellImage* image = new CellImage;
    if (image->data = stbi_load(filePath.data(), &image->width, &image->height, &image->component, 4))
    {
		return image;
	}
    delete image;
    return nullptr;
}

