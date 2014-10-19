#ifndef __KOALA_STYLE_SAMPLE__
#define __KOALA_STYLE_SAMPLE__
// 头文件保护

namespace koala {
namespace code_style_sample {

class NageSirenKoala {
public:
    NageSirenKoala():_bar(0) {}
    virtual ~NageSirenKoala() {}
    virtual int add_int(int a, int b);
    virtual void display_author_info();

    static const char* _s_author_info;

private:
    int _bar;
};

}; // namespace code_style_sample
}; // namespace koala

#endif // __KOALA_STYLE_SAMPLE__

