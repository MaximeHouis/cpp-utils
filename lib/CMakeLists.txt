add_library(
        ${PROJECT_NAME} STATIC
        include/lib/ClassUtils.hpp
        include/lib/Macros.hpp
        include/lib/Time.hpp
        src/FrameManager.cpp include/lib/FrameManager.hpp
        src/ScopedProfiler.cpp include/lib/ScopedProfiler.hpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)
