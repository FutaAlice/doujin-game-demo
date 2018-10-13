project(entry)

aux_source_directory(./ SRC)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC on)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC on)

find_package(Qt5 REQUIRED Core Gui Widgets)

FILE(GLOB SRC_FILES "./*.cpp")
FILE(GLOB HEADER_FILES "./*.h")
FILE(GLOB FORM_FILES "./*.ui")
FILE(GLOB RESOURCE_FILES "./*.qrc")

add_executable(${PROJECT_NAME}
    ${HEADER_FILES}
    ${SRC_FILES}
    ${FORM_FILES}
    ${RESOURCE_FILES}
)

target_link_libraries(${PROJECT_NAME}
    Qt5::Core Qt5::Gui Qt5::Widgets
)