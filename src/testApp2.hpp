#pragma once

#include "core/Director.h"
#include "assets/shader/Renderer.h"
#include "assets/image/Texture.h"
#include "core/WindowFramework.h"



class TestApp2 : public App
{
    struct DrawVert
    {
        Vec2 pos;
        Vec2 coord;
    };

protected:
    Renderer* renderer;
    Texture* texture;

    virtual void onStart(){
        renderer = assets->getObj<Renderer>(u8"res/shaders/test2.shader");
        texture = assets->getObj<Texture>(u8"res/img.png");

        std::vector<DrawVert> vtxList = {
            {Vec2(-0.5f, 0.5f), Vec2(0.0f, 1.0f)},
            {Vec2(-0.5f, -0.5f), Vec2(0.0f, 0.0f)},
            {Vec2(0.5f, -0.5f), Vec2(1.0f, 0.0f)},
            {Vec2(0.5f, 0.5f), Vec2(1.0f, 1.0f)}
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

        // 设置uniform
        renderer->set("projection", Math->ortho(Vec2(800.0f, 600.0f)));
        renderer->useTexture("texture0", texture);

        // 更新要渲染的数据和索引
        renderer->updateData(vtxList.size(), &vtxList[0]);
        renderer->updateIndex(indexList.size(), &indexList[0]);
    }

    virtual void onFrame(){
        static double lastTime = 0.0;
        double currentTime = Framework->getTime();
        double dt = currentTime - lastTime;
        lastTime = currentTime;

        Mat3 baseMat;

        // 激活准备渲染
        renderer->active();

        // 应用缩放
        {
            static float val = 50.0f;
            static Vec2 size = texture->getSize();
            size.x += val * dt * std::sin(currentTime);    // 尺寸周期变化
            size.y += val * dt * std::sin(currentTime);    // 尺寸周期变化

            Mat3 mat;
            mat[0][0] = size.x;   mat[1][0] = 0.0f;      mat[2][0] = 0.0f;
            mat[0][1] = 0.0f;     mat[1][1] = size.y;    mat[2][1] = 0.0f;
            mat[0][2] = 0.0f;     mat[1][2] = 0.0f;      mat[2][2] = 1.0f;

            baseMat = baseMat * mat;
            renderer->set("model", baseMat);
            renderer->set("color", Color(0xff0000ff));
            renderer->draw();
        }

        // 应用旋转
        {
            static float speed = 100.0f;
            static float angle = 0.0f;
            angle += speed * dt;     // 一直旋转

            float sinVal = std::sin(Math->angleToRadian(angle));
            float cosVal = std::cos(Math->angleToRadian(angle));

            Mat3 mat;
            mat[0][0] = cosVal;   mat[1][0] = -sinVal;   mat[2][0] = 0.0f;
            mat[0][1] = sinVal;   mat[1][1] = cosVal;    mat[2][1] = 0.0f;
            mat[0][2] = 0.0f;     mat[1][2] = 0.0f;      mat[2][2] = 1.0f;

            baseMat = baseMat * mat;
            renderer->set("model", baseMat);
            renderer->set("color", Color(0x00ff00ff));
            renderer->draw();
        }

        // 应用平移
        {
            static float speed = 20.0f;
            static float x = 400.0f, y = 300.0f;
            x += speed * dt * std::sin(currentTime);    // x轴周期变化

            Mat3 mat;
            mat[0][0] = 1.0f;     mat[1][0] = 0.0f;      mat[2][0] = x;
            mat[0][1] = 0.0f;     mat[1][1] = 1.0f;      mat[2][1] = y;
            mat[0][2] = 0.0f;     mat[1][2] = 0.0f;      mat[2][2] = 1.0f;

            baseMat = baseMat * mat;
            renderer->set("model", baseMat);
            renderer->set("color", Color(0x0000ffff));
            renderer->draw();
        }


    }

    virtual void onExit(){
        delete renderer;
        delete texture;
    }
};
