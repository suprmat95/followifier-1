# The following lines of boilerplate have to be in your project's CMakeLists
# in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_FLAGS "-g -Wall -Werror")
project(core)

# Boost
find_package(Boost 1.67.0 COMPONENTS system filesystem thread REQUIRED)
if (Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
endif ()

# pthread
find_package(Threads REQUIRED)
if (CMAKE_USE_PTHREADS_INIT)
    add_definitions(-DHAVE_PTHREAD)
endif (CMAKE_USE_PTHREADS_INIT)

# Protobuf
set(PROTO_FILE_DIR ./common)
set(PROTO_EXEC protoc)
set(PROTO_FILE_NAME message.proto)
set(GEN_DIR ./gen)
find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
file(MAKE_DIRECTORY ${GEN_DIR})
message(STATUS "Generating C++ proto stubs...")
list(APPEND PROTO_CPP_ARGS "--cpp_out=${GEN_DIR}" "--proto_path=${PROTO_FILE_DIR}" "${PROTO_FILE_NAME}")
execute_process(COMMAND ${Protobuf_PROTOC_EXECUTABLE} ${PROTO_CPP_ARGS}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        RESULT_VARIABLE result
        OUTPUT_VARIABLE output
        ERROR_VARIABLE error)
message(STATUS "...done. ${output}")
message(STATUS "Generating Python proto stubs...")
list(APPEND PROTO_PYTHON_ARGS "--python_out=${GEN_DIR}" "--proto_path=${PROTO_FILE_DIR}" "${PROTO_FILE_NAME}")
execute_process(COMMAND ${Protobuf_PROTOC_EXECUTABLE} ${PROTO_PYTHON_ARGS}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        RESULT_VARIABLE result
        OUTPUT_VARIABLE output
        ERROR_VARIABLE error)
message(STATUS "...done. ${output}")
file(GLOB PROTOBUF_MODELS_INCLUDES "gen/message.pb.cc")

# Allowing inbound and outbound TCP connections on the specified port
set(PORT 12345)
message(STATUS "Asking password to allow TCP inbound and outbound connections on port ${PORT} on this machine...")
execute_process(COMMAND sudo iptables -A INPUT -p tcp --dport ${PORT} -m conntrack --ctstate NEW,ESTABLISHED -j ACCEPT)
execute_process(COMMAND sudo iptables -A OUTPUT -p tcp --sport ${PORT} -m conntrack --ctstate ESTABLISHED -j ACCEPT)
message(STATUS "...done. ${output}")

# Building executable
add_executable(${PROJECT_NAME} src/receiver.cpp src/receiver.h ${PROTOBUF_MODELS_INCLUDES}
        src/main.cpp
        src/connection.h src/connection.cpp
        src/server.cpp src/server.h)
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
if (Boost_FOUND)
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif ()
if (Protobuf_FOUND)
    target_link_libraries(${PROJECT_NAME} ${Protobuf_LIBRARIES})
endif()