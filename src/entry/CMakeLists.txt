project(entry)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC on)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC on)

find_package(Qt5 REQUIRED Core Gui Widgets)

file(GLOB SRC_FILES "./*.cpp")
file(GLOB HEADER_FILES "./*.h")
file(GLOB FORM_FILES "./*.ui")
file(GLOB RESOURCE_FILES "./*.qrc")

include_directories(../ ../../3rdparty)

add_executable(${PROJECT_NAME}
    ${HEADER_FILES}
    ${SRC_FILES}
    ${FORM_FILES}
    ${RESOURCE_FILES}
)

target_link_libraries(${PROJECT_NAME}
    Qt5::Core Qt5::Gui Qt5::Widgets
    cli-args
    layer-title
    layer-setting
)

if (UNIX)
    target_link_libraries (${PROJECT_NAME}
        pthread
    )
endif ()