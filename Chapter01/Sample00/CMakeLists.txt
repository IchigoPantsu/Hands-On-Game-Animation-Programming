set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "-Wall -fpermissive -g")
set(CMAKE_CXX_FLAGS "-Wall")
#set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} -ldl")
#set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/$<IF:$<CONFIG:Debug>,Debug,Release>/chapter01")

file(GLOB ENGINE_FILES
./Code/Application.h
./Code/glad.c
./Code/glad.h
./Code/khrplatform.h
./Code/main.cpp
#./Code/WinMain.cpp
)

add_executable (chapter01_sample00 ${ENGINE_FILES})
target_link_libraries(chapter01_sample00 
  #Vulkan::Vulkan
  ${LIBS}
)
