cmake_minimum_required(VERSION 3.5)
project(AnyDock LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "d:/Program/Qt/6.4.3/msvc2019_64")
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

include_directories(inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ui)
aux_source_directory(src srcs)

file(GLOB MOC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/inc/*.h")
file(GLOB UI_FILES "${CMAKE_CURRENT_SOURCE_DIR}/ui/*.ui")

qt6_wrap_cpp(MOC_SOURCES ${MOC_FILES})
qt6_wrap_ui(UI_HEADERS ${UI_FILES})


set(RESOURCES
    res/anydock.qrc
)

qt6_add_resources(RESOURCES_RCC ${RESOURCES})

list(APPEND srcs ${UI_HEADERS} ${MOC_SOURCES} ${RESOURCES_RCC})

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_executable(${PROJECT_NAME}
    WIN32 
    ${srcs} 
) 
target_link_libraries(${PROJECT_NAME}
    Qt6::Core
    Qt::Gui
    Qt6::Widgets
)