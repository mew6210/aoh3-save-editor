cmake_minimum_required(VERSION 3.14) 
project(AOH3_Save_Editor)               
set(CMAKE_CXX_STANDARD 14)           

include(FetchContent)

FetchContent_Declare(
  nlohmann_json
  URL https://github.com/nlohmann/json/archive/refs/tags/v3.11.2.tar.gz
  
)

FetchContent_MakeAvailable(nlohmann_json)


set(SOURCE_FILES 
"main.cpp"
"src/config/config.cpp"
"src/utilities/utilities.cpp"
)


add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
