project(sfmlgame)
cmake_minimum_required(VERSION 3.5.2)

# Download automatically, you can also just copy the conan.cmake file
# if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
#    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
#    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
#                   "${CMAKE_BINARY_DIR}/conan.cmake")
# endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(sfmlgame Source.cpp)
target_link_libraries(sfmlgame ${CONAN_LIBS}) # note the conan libs over here

add_custom_command(TARGET sfmlgame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${PROJECT_SOURCE_DIR}/resource/"
    $<TARGET_FILE_DIR:sfmlgame>
)