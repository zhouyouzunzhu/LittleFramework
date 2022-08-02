#pragma once

#include "core/Director.h"

#include "assets/shader/Renderer.h"
#include "assets/image/Texture.h"

#include "core/WindowFramework.h"


#include "core/Transform.h"


bool checkCollide(Transform& a, Transform& b)
{
    // 获取半长
    Vec2 hA = a.getSize() * 0.5;
    Vec2 hB = b.getSize() * 0.5;

    Vec2 posA = a.getPosition();
    Vec2 posB = b.getPosition();

    // 获取旋转矩阵
    Mat3 RotA = Math->rotate(a.getAngle());
    Mat3 RotB = Math->rotate(b.getAngle());

    // 获取旋转矩阵的逆矩阵
    Mat3 RotAT = RotA.reversal();
    Mat3 RotBT = RotB.reversal();

    Vec2 dp = posB - posA;  // 获取连线长度
    Vec2 dA = dp * RotAT;   // 获取连线在A坐标系下的表示
    Vec2 dB = dp * RotBT;   // 获取连线在B坐标系下的表示

    Mat3 C = RotAT * RotB;  // 获取可以把B坐标系转A坐标系的矩阵
    Mat3 absC = C.abs();    // 矩阵取绝对值，这样可以取到B在A坐标系下xy的最值

    Mat3 D = RotBT * RotA;  
    Mat3 absD = D.abs();

    Vec2 faceA = dA.abs() - hA - hB * absC; 
    Vec2 faceB = dB.abs() - hB - hA * absD;

    if(faceA.x > 0.0f || faceA.y > 0.0f)
        return false;

    if (faceB.x > 0.0f || faceB.y > 0.0f)
		return false;
    return true;
}

class TestApp : public App
{
    struct DrawVert
    {
        Vec2 pos;
        Vec2 coord;
        Color color;
    };

protected:
    Renderer* renderer;
    Texture* texture;

    Transform a;
    Transform b;

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
        renderer->useTexture("texture0", texture);

        // 更新要渲染的数据和索引
        renderer->updateData(vtxList.size(), &vtxList[0]);
        renderer->updateIndex(indexList.size(), &indexList[0]);

        a.setSize(100.0f, 200.0f);
        a.setPosition(300.0f, 200.0f);


        b.setSize(100.0f, 100.0f);
        b.setPosition(300.0f, 200.0f);
    }

    virtual void onFrame(){
        a.setPosition(Framework->cursorPos);
        a.rotate(Framework->roll * Framework->dt * 1000.0f);

        // 激活并渲染
        renderer->active();
        if(checkCollide(a, b))
            renderer->set("uColor", Color(1.0f, 0.0f, 0.0f));
        else
            renderer->set("uColor", Color(1.0f, 1.0f, 1.0f));
        renderer->set("model", a.worldMat);
        renderer->draw();


        renderer->set("uColor", Color(0.0f, 1.0f, 1.0f));
        renderer->set("model", b.worldMat);
        renderer->draw();
    }

    virtual void onExit(){
        delete renderer;
        delete texture;
    }
};
