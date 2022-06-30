#pragma once

#include "core/Director.h"

#include "assets/shader/Shader.h"
#include "assets/image/Texture.h"

#include "core/WindowFramework.h"

class TestApp : public App
{
protected:
    unsigned int VAO;
    Shader* shader;
    Texture* texture;
    Mat3 projection;

    virtual void onStart(){
        shader = assets->getObj<Shader>(u8"res/shaders/test.shader");
        texture = assets->getObj<Texture>(u8"res/img.png");

        projection = Math->ortho(Vec2(800.0f, 600.0f));

        unsigned int VBO;
        float vertices[] = { 
            // pos          // coord          // color
            -0.5f, 0.5f,    0.0f, 1.0f,       1.0f, 0.0f, 0.0f, 1.0f,
            0.5f, -0.5f,    1.0f, 0.0f,       1.0f, 0.0f, 0.0f, 1.0f,
            -0.5f, -0.5f,   0.0f, 0.0f,       1.0f, 0.0f, 0.0f, 1.0f,

            -0.5f, 0.5f,    0.0f, 1.0f,       1.0f, 0.0f, 0.0f, 1.0f,
            0.5f, 0.5f,     1.0f, 1.0f,       1.0f, 0.0f, 0.0f, 1.0f,
            0.5f, -0.5f,    1.0f, 0.0f,       1.0f, 0.0f, 0.0f, 1.0f,
        };

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(2 * sizeof(float)));

        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(4 * sizeof(float)));

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    virtual void onFrame(){
        shader->use();
        shader->set("projection", projection);


        auto model = Math->transform(Vec2(200.0f, 200.0f), texture->getSize(), 0.0f);
        shader->set("model", model);
        shader->set("time", Framework->getTime());


        glBindVertexArray(VAO);
        texture->active();
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);
    }

    virtual void onExit(){
        delete shader;
        glDeleteVertexArrays(1, &VAO);
    }
};
