add_library(lib ../lib/myString.cpp ../lib/myString.h)
add_executable(acic main.cpp)
target_link_libraries(acic lib)