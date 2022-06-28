#pragma once

#include "mstr.h"

// 单例模板辅助
template<typename Type>
struct _InstanceTemplate {
    static Type* getInstance(){
        static Type obj;
        return &obj;
    }
};

// 单例类
#define InstClass(Type) \
    friend _InstanceTemplate<Type>; \
    private: Type(const Type&); Type()
// 获取单例
#define Inst(Type) (_InstanceTemplate<Type>::getInstance())


// 错误退出代码
enum ExitCode
{
    Normal = 0,
    InitError = 1,
};


