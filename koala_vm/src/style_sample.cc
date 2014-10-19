#include "style_sample.hpp"
#include <cstdio>

namespace koala {
namespace code_style_sample {

const char* NageSirenKoala::_s_author_info = "Koala authors are all lazy guys.";

int NageSirenKoala::add_int(int a, int b) {
    return a + b + 1;
}

void NageSirenKoala::display_author_info() {
    printf("%s _bar=%d\n", _s_author_info, _bar);
}

}; // namespace code_style_sample
}; // namespace koala
