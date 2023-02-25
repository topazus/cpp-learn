#include <string>
#include <fmt/core.h>
#include <fmt/format.h>
#include <cassert>
#include <iostream>

auto t1(){
    std::string a="hi";
    std::cout<<a[2]<<std::endl;
    fmt::print("--\n");
    fmt::print("size: {}, data: {}, c_str: {}, int(a[a.size()]): , a[2]: {}\n",a.size(), a.data(), a.c_str(), int(a[a.size()])), a[a.size()];
}

// check the char array is null terminated
template <std::size_t N>
constexpr bool is_null_terminated(const char (&arr)[N]) {
    return !arr[N - 1];
}

bool is_null_terminated2(const char* str) {
    if (str == nullptr) {
        return false;
    }

    for (size_t i = 0; ; i++) {
        if (str[i] == '\0') {
            return true;
        }
    }
    return false;
}

auto test_is_null_terminated()  {
    static_assert(is_null_terminated("Hello"));
    static_assert(is_null_terminated("Hello\0"));
    static_assert(is_null_terminated("Hello\0World"));
    constexpr char str[] = {'f', 'o', 'o'};
    static_assert(!is_null_terminated(str));
    char buf[5] = { 'H', 'e', 'l', 'l', 'o' };
    char b[255];
    auto a="test";
    // strcpy: copy a to b, including \0 terminating character.
    strcpy(b, a);
}
auto test_mem_buf(){
    auto out = fmt::memory_buffer();
    fmt::format_to(std::back_inserter(out), "a is {}.", 42);
    
    // a is 42
    fmt::print("{}\n",fmt::to_string(out));
}
auto num_to_string(int num) -> std::string {
    std::string str;
    str.resize(4);
    str[0] = num & 0xFF;
    str[1] = (num >> 8) & 0xFF;
    str[2] = (num >> 16) & 0xFF;
    str[3] = (num >> 24) & 0xFF;
    return str;
}
auto test_num_to_string(){
    // 0x756E6547 to Genu
    fmt::print("{}\n", num_to_string(0x756E6547));
}
int main(){
    t1();
    test_is_null_terminated();
    test_mem_buf();
    test_num_to_string();
}
