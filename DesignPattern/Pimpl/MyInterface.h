#pragma once

// 减少头文件包含链，大型项目编译优化。
// 隐藏第三方库依赖，减少编译依赖和暴露的实现细节。
#include <memory>

class MyInterface {
public:
    MyInterface();
    ~MyInterface();

    // 只暴露公共API。
    // 用于第三方API封装。

    int publicApi1();
    int publicApi2();

private:

    // 这个暴露公共API的头文件中不包含任何成员变量。
    // 修改 Impl 的实现不会引起 MyInterface 的重新编译，接口稳定。

    struct Impl;
    std::unique_ptr<Impl> mImpl;
};
