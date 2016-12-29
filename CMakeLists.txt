cmake_minimum_required (VERSION 3.5)
project (plt)

# Directories
include_directories ("${PROJECT_SOURCE_DIR}/src")
include_directories ("${PROJECT_SOURCE_DIR}/extern/jsoncpp-0.10.5/dist")


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Enable C++11
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

IF(CMAKE_COMPILER_IS_GNUCC)
	SET(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -Wall -Wno-strict-overflow -std=c11   -pthread -g")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-strict-overflow -std=c++11 -pthread -g")
ENDIF(CMAKE_COMPILER_IS_GNUCC)

# jsoncpp
include_directories ("${PROJECT_SOURCE_DIR}/extern/jsoncpp-0.10.5/dist")
file(GLOB jsoncpp_sources "${PROJECT_SOURCE_DIR}/extern/jsoncpp-0.10.5/dist/jsoncpp.cpp")

# Generate headers
set(DIA2CODE "${PROJECT_SOURCE_DIR}/dia2code/bin/dia2code")
exec_program(${DIA2CODE} ARGS -d ../src -t cpp ../src/state.dia)

exec_program(${DIA2CODE} ARGS -d ../src -t cpp ../src/render.dia)

exec_program(${DIA2CODE} ARGS -d ../src -t cpp ../src/engine.dia)

exec_program(${DIA2CODE} ARGS -d ../src -t cpp ../src/ai.dia)

exec_program(${DIA2CODE} ARGS -d ../src -t cpp ../src/client.dia)

exec_program(${DIA2CODE} ARGS -d ../src -t cpp ../src/server.dia)

# Sources
file(GLOB_RECURSE main_sources src/*.cpp)
file(GLOB jsoncpp_sources "${PROJECT_SOURCE_DIR}/extern/jsoncpp-0.10.5/dist/jsoncpp.cpp")

# Executables
add_executable(run ${jsoncpp_sources} ${main_sources} )

# SFML
if(WIN32)
set(SFML_ROOT "D:/Utils/SFML-2.3")
set(CMAKE_MODULE_PATH "${SFML_ROOT}/cmake/Modules" ${CMAKE_MODULE_PATH})
else(WIN32)
SET(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})
endif(WIN32)
find_package(SFML 2 COMPONENTS graphics window audio system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(run ${SFML_LIBRARIES})
endif()




