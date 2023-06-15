cmake_minimum_required(VERSION 3.25)
project(ext C)
set(CMAKE_C_STANDARD 99)

# Configure `RUBY_INCLUDE` according to your setup
IF(WIN32)
  SET(RUBY_INCLUDE C:/PortablePrograms/rubyinstaller-3.2.1-1-x64/include/ruby-3.2.0/)
ELSE()
  SET(RUBY_INCLUDE /usr/local/include/ruby-3.2.0/)
ENDIF()

add_library(ext SHARED ext.c)
target_include_directories(ext PRIVATE ${RUBY_INCLUDE})
