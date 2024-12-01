cmake_minimum_required(VERSION 3.13)

project(aoc)

macro(add_advent DAY)
    add_executable("day${DAY}")
    target_sources("day${DAY}"
        PRIVATE "day${DAY}/main.cpp"
        PRIVATE "day${DAY}/test_data.hpp"
        PRIVATE "day${DAY}/live_data.hpp")
    target_compile_features("day${DAY}"
        PUBLIC cxx_std_23)
    target_compile_options("day${DAY}"
        PUBLIC -fconstexpr-steps=111271242)
endmacro(add_advent)
