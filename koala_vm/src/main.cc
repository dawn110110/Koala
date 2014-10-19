// 自带头文件放在前面，字典序排列
#include "koala.hpp"
#include "style_sample.hpp"

// 其他放在后面，字典序排列
#include <cstdio>
#include <new>

int main(int argc, const char *argv[])
{
    // 可以使用 auto
    auto* foo = new (std::nothrow) koala::code_style_sample::NageSirenKoala();

    if (NULL != foo) {
        foo->display_author_info();
    } else {
        printf("Failed to allocate for NageSirenKoala\n");
    }

    KOALA_SAFE_DELETE(foo);
    return 0;
}
