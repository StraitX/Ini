cmake_minimum_required(VERSION 3.10)

add_library(StraitXIni STATIC
    "./thirdparty/inih/ini.c"
    "./thirdparty/inih/cpp/INIReader.cpp"
    "./sources/ini/ini.cpp"
)

target_include_directories(StraitXIni
    PRIVATE "./thirdparty/inih"
    PUBLIC "./thirdparty/inih/cpp"
    PUBLIC "./sources"
)

target_link_libraries(StraitXIni
    PUBLIC StraitXCore
)

