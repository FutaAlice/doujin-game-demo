project(layer-avg)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC on)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC on)

find_package(Qt5 REQUIRED Core Gui Widgets)

file(GLOB SRC_FILES "./*.cpp")
file(GLOB HEADER_FILES "./*.h" "./*.hpp")
file(GLOB FORM_FILES "./*.ui")
file(GLOB RESOURCE_FILES "./*.qrc")

add_definitions(-DAVGLAYER_LIBRARY)

include_directories(../ ../../3rdparty)

add_library(${PROJECT_NAME} SHARED
    ${HEADER_FILES}
    ${SRC_FILES}
    ${FORM_FILES}
    ${RESOURCE_FILES}
)

target_link_libraries(${PROJECT_NAME}
    Qt5::Core Qt5::Gui Qt5::Widgets
    cli-args
)