set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "-Wall -fpermissive -g")
set(CMAKE_CXX_FLAGS "-Wall")
#set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} -ldl")
#set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/$<IF:$<CONFIG:Debug>,Debug,Release>/chapter06")

file(GLOB ENGINE_FILES

./Code/Application.h
./Code/Attribute.cpp
./Code/Attribute.h
./Code/Draw.cpp
./Code/Draw.h
./Code/glad.c
./Code/glad.h
./Code/IndexBuffer.cpp
./Code/IndexBuffer.h
./Code/khrplatform.h
./Code/main.cpp
./Code/mat4.cpp
./Code/mat4.h
./Code/quat.cpp
./Code/quat.h
./Code/Shader.cpp
./Code/Shader.h
./Code/stb_image.cpp
./Code/stb_image.h
./Code/Texture.cpp
./Code/Texture.h
./Code/Transform.cpp
./Code/Transform.h
./Code/Uniform.cpp
./Code/Uniform.h
./Code/vec2.h
./Code/vec3.cpp
./Code/vec3.h
./Code/vec4.h
#./Code/WinMain.cpp
)

add_executable (chapter06_sample00 ${ENGINE_FILES})
target_link_libraries(chapter06_sample00 
  #Vulkan::Vulkan
  ${LIBS}
)
