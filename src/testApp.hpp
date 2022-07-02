#pragma once

#include "core/Director.h"

#include "assets/shader/Renderer.h"
#include "assets/image/Texture.h"

#include "core/WindowFramework.h"

struct DrawVert
{
    Vec2 pos;
    Vec2 coord;
    Color color;
};


class TestApp : public App
{
protected:
    Renderer* renderer;
    Texture* texture;

    virtual void onStart(){
        renderer = assets->getObj<Renderer>(u8"res/shaders/test.shader");
        texture = assets->getObj<Texture>(u8"res/img.png");

        std::vector<DrawVert> vtxList = {
            {Vec2(-0.5f, 0.5f), Vec2(0.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f)},
            {Vec2(-0.5f, -0.5f), Vec2(0.0f, 0.0f), Color(1.0f, 1.0f, 1.0f, 1.0f)},
            {Vec2(0.5f, -0.5f), Vec2(1.0f, 0.0f), Color(1.0f, 1.0f, 0.0f, 1.0f)},
            {Vec2(0.5f, 0.5f), Vec2(1.0f, 1.0f), Color(1.0f, 1.0f, 0.0f, 1.0f)}
        };
        std::vector<int> indexList = {
            0, 1, 2,
            2, 3, 0
        };

        // 绑定结构类型，其实只是获取下结构大小
        renderer->bindType<DrawVert>();

        // 激活
        renderer->active();

        // 绑定shader输入属性对应的结构字段
        renderer->bindAttribute(u8"inputVertices", StructElement(DrawVert, pos));
        renderer->bindAttribute(u8"inputCoord", StructElement(DrawVert, coord));
        renderer->bindAttribute(u8"inputColor", StructElement(DrawVert, color));

        // 设置uniform
        renderer->set("projection", Math->ortho(Vec2(800.0f, 600.0f)));
        renderer->set("model", Math->transform(Vec2(200.0f, 200.0f), texture->getSize(), 0.0f));
        renderer->useTexture("texture0", texture);

        // 更新要渲染的数据和索引
        renderer->updateData(vtxList.size(), &vtxList[0]);
        renderer->updateIndex(indexList.size(), &indexList[0]);
    }

    virtual void onFrame(){

        // 激活并渲染
        renderer->active();
        renderer->set("time", Framework->getTime());
        renderer->draw();
    }

    virtual void onExit(){
        delete renderer;
        delete texture;
    }
};
