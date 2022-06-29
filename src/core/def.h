#pragma once

#include "String.h"
#include "Math.h"
#include <glad/glad.h>


// 日志管理器
class _LogManager
{
InstClass(_LogManager){
}
public:
    void log(const String& info);

    void warning(const String& info);

    void error(const String& info);
};

// 输出日志
#define pLog(info, ...)                                                                    \
	do                                                                                     \
	{                                                                                      \
		Inst(_LogManager)->log(String("%s:%d: {0}", __FILE__, __LINE__).arg(String((info), ##__VA_ARGS__)).data());      \
	} while (0)

#define pWarning(info, ...)                                                                    \
	do                                                                                     \
	{                                                                                      \
		Inst(_LogManager)->warning(String("%s:%d: {0}", __FILE__, __LINE__).arg(String((info), ##__VA_ARGS__)).data());      \
	} while (0)

#define pErr(info, ...)                                                                    \
	do                                                                                     \
	{                                                                                      \
		Inst(_LogManager)->error(String("%s:%d: {0}", __FILE__, __LINE__).arg(String((info), ##__VA_ARGS__)).data());      \
	} while (0)

enum ExitCode
{
    Normal = 0,
    InitError = 1
};