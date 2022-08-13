add_library(
        ${PROJECT_NAME} STATIC
        include/utils/ClassUtils.hpp
        include/utils/Macros.hpp
        include/utils/Time.hpp
        src/FrameManager.cpp include/utils/FrameManager.hpp
        src/ScopedProfiler.cpp include/utils/ScopedProfiler.hpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)
