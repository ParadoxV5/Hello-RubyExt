cmake_minimum_required(VERSION 3.25)
project(ext C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_SHARED_LIBRARY_PREFIX)

add_library(ext SHARED ext.c)

# Configure according to your setup
if(WIN32)
  set(RUBY_PLATFORM x64-mingw-ucrt)
  set(INSTALL_ROOT C:/PortablePrograms/rubyinstaller-3.2.1-1-x64)
  target_link_libraries(ext ${INSTALL_ROOT}/bin/x64-ucrt-ruby320.dll)
  set(CMAKE_SHARED_LIBRARY_SUFFIX .so) # Damn MinGW Ruby, doesn’t load `.dll` but loads `.so`
else()
  set(RUBY_PLATFORM x86_64-linux)
  set(INSTALL_ROOT /usr/local)
endif()
set(RUBY_INCLUDE ${INSTALL_ROOT}/include/ruby-3.2.0)
target_include_directories(ext PRIVATE ${RUBY_INCLUDE} ${RUBY_INCLUDE}/${RUBY_PLATFORM})
