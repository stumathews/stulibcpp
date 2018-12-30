cmake_minimum_required(VERSION 3.2)
# Define project name & version
set(PROJECT_VERSION "1.3.0")
set (CMAKE_CXX_STANDARD 98)

project(stucpp VERSION ${PROJECT_VERSION} LANGUAGES CXX)

# To build shared libraries in Windows, we set CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS to TRUE.
# See https://cmake.org/cmake/help/v3.4/variable/CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS.html
# See https://blog.kitware.com/create-dlls-on-windows-without-declspec-using-new-cmake-export-all-feature/
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(stucpp SHARED)

target_include_directories(stucpp
PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(stucpp
PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION}
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN 1
)

target_sources(stucpp
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ApiClass.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/CApi.cpp
  )

include(GenerateExportHeader)
# Generate our EXPORT and NO_EXPORT macros in stucpp_exported.h
generate_export_header(stucpp)

# Compiler-specific compile flags
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    message(STATUS "Setting G++ flags")
    # G++
    target_compile_options(stucpp PRIVATE -Wall -Wextra)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    message(STATUS "Setting MSVC flags")
    # MSVC
    target_compile_options(stucpp PRIVATE /EHsc /W2 /c)
    # Set the DLLEXPORT variable to export symbols
    target_compile_definitions(stucpp PRIVATE WIN_EXPORT)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    message(STATUS "Setting Clang flags")
    # Activate all clang warnings except those that don't really affect much
    target_compile_options(stucpp PRIVATE -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-newline-eof -Wno-padded -Wno-exit-time-destructors -Wno-global-constructors -Wno-constant-conversion)
endif()

#Tests
add_executable(basic ${CMAKE_CURRENT_SOURCE_DIR}/test/basic.cpp)
target_link_libraries(basic stucpp ${CMAKE_DL_LIBS})

# Set output directory for the libraries & interactive binary. Tests go in build directory, except on windows because windows sucks my balls
set(OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/output)
set_target_properties(stucpp
PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}

)
