#ifndef __KOALA_H__
#define __KOALA_H__
// 头文件保护

namespace koala {
namespace code_style_sample {

// 测试用
#define KOALA_SAFE_DELETE(p) do {\
    if (NULL != p) {\
        delete p;\
        p = NULL;\
    } else {\
    }\
}while (0)

}; // namespace code_style_sample
}; // namespace koala

#endif // __KOALA_H__
