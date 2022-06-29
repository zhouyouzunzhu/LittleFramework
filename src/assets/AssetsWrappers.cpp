#include "AssetsWrappers.h"
#include "AssetsManager.h"

void AssetsWrappers::initWrappers(AssetsManager* from, AssetsCell* cell)
{
    this->_from = from;
    this->_cell = cell;
    this->onWrappers(cell);
}

AssetsWrappers::~AssetsWrappers()
{
    if(this->_from)
    {
        this->_from->unload(this->_cell);
        this->_from = nullptr;
        this->_cell = nullptr;
    }
}

void AssetsWrappers::onWrappers(AssetsCell* cell)
{
}