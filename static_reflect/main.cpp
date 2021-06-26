#include <iostream>
#include <string>
#include <cstdint>

#define message_name foo
#define message_body    \
    field_int64(number, 24)     \
    field_int64(scores, 81)     \
    field_string(name, "kobe")  \
    field_double(basket, 5.8)   \
    field_string(waihao, "hei man ba")  \
    //

#include "message_generator.h"

int main() {
    foo f;
    std::cout << f << std::endl;
    return 0;
}
