add_library(
        cpp-utils STATIC
        include/utils/ClassUtils.hpp
        include/utils/Macros.hpp
        include/utils/Time.hpp
        include/utils/ScopeExit.hpp
        src/FrameManager.cpp include/utils/FrameManager.hpp
        src/ScopeProfiler.cpp include/utils/ScopeProfiler.hpp
        include/utils/Math.hpp
)

target_include_directories(cpp-utils PRIVATE include)
target_compile_options(cpp-utils PRIVATE ${PROJECT_WARNINGS})
