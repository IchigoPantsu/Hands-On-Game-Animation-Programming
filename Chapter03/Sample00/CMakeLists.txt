set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "-Wall -fpermissive -g")
set(CMAKE_CXX_FLAGS "-Wall")
#set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} -ldl")
#set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/$<IF:$<CONFIG:Debug>,Debug,Release>/chapter03")

file(GLOB ENGINE_FILES
./Code/Application.h
./Code/glad.c
./Code/glad.h
./Code/khrplatform.h
./Code/main.cpp
./Code/mat4.cpp
./Code/mat4.h
./Code/vec2.h
./Code/vec3.cpp
./Code/vec3.h
./Code/vec4.h
#./Code/WinMain.cpp
)

add_executable (chapter03_sample00 ${ENGINE_FILES})
target_link_libraries(chapter03_sample00 
  #Vulkan::Vulkan
  ${LIBS}
)
