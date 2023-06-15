cmake_minimum_required(VERSION 3.25)
project(ext C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_SHARED_LIBRARY_PREFIX)

add_library(ext SHARED ext.c)

# Configure according to your setup
IF(WIN32)
  SET(RUBY_PLATFORM x64-mingw-ucrt)
  SET(INSTALL_ROOT C:/PortablePrograms/rubyinstaller-3.2.1-1-x64)
ELSE()
  SET(RUBY_PLATFORM x86_64-linux)
  SET(INSTALL_ROOT /usr/local)
ENDIF()
SET(RUBY_INCLUDE ${INSTALL_ROOT}/include/ruby-3.2.0)
target_include_directories(ext PRIVATE ${RUBY_INCLUDE} ${RUBY_INCLUDE}/${RUBY_PLATFORM})
