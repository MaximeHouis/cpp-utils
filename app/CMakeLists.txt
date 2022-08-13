add_executable(
        ${PROJECT_NAME}-app
        src/Main.cpp include/Main.hpp
)
target_link_libraries(${PROJECT_NAME}-app PUBLIC ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME}-app PRIVATE include/ ../lib/include)
