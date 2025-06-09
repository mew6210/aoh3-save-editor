cmake_minimum_required(VERSION 3.15) 
project(AOH3_Save_Editor)               
set(CMAKE_CXX_STANDARD 14)           

find_package(nlohmann_json CONFIG REQUIRED)

set(SOURCE_FILES 
"main.cpp"
"src/config/config.cpp"
"src/utilities/utilities.cpp"
)


add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)