set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "-Wall -fpermissive -g")
set(CMAKE_CXX_FLAGS "-Wall")
#set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} -ldl")
#set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/$<IF:$<CONFIG:Debug>,Debug,Release>/chapter03")

file(GLOB ENGINE_FILES
./Code/main.cpp
./Code/mat2.cpp
./Code/mat2.h
./Code/mat3.cpp
./Code/mat3.h
./Code/mat4.cpp
./Code/mat4.h
)

add_executable (chapter03_sample01 ${ENGINE_FILES})
target_link_libraries(chapter03_sample01 
  #Vulkan::Vulkan
  ${LIBS}
)
