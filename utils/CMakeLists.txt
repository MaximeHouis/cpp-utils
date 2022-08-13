add_library(
        ${PROJECT_NAME} STATIC
        include/utils/ClassUtils.hpp
        include/utils/Macros.hpp
        include/utils/Time.hpp
        include/utils/ScopeExit.hpp
        src/FrameManager.cpp include/utils/FrameManager.hpp
        src/ScopeProfiler.cpp include/utils/ScopeProfiler.hpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)
