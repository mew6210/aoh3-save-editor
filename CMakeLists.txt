cmake_minimum_required(VERSION 3.14) 
project(AOH3_Save_Editor)               
set(CMAKE_CXX_STANDARD 17)           

include(FetchContent)
set(RAYLIB_VERSION 5.5)
set(NLOHMANN_JSON_VERSION v3.11.2)

FetchContent_Declare(
  nlohmann_json
  URL https://github.com/nlohmann/json/archive/refs/tags/${NLOHMANN_JSON_VERSION}.tar.gz
  
)

FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
)


FetchContent_MakeAvailable(nlohmann_json)
FetchContent_MakeAvailable(raylib)

set(SOURCE_FILES 
"main.cpp"
"src/config/config.cpp"
"src/utilities/utilities.cpp"
"src/reader/reader.cpp"
)


add_executable(${PROJECT_NAME} ${SOURCE_FILES})

set(LIBRARIES 
nlohmann_json::nlohmann_json
raylib
)

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARIES})
