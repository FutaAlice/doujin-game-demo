project (cli-args)

find_package(Qt5 REQUIRED Core)

file(GLOB SRC_FILES "./*.cpp")
file(GLOB HEADER_FILES "./*.h")

include_directories(../../3rdparty)

add_library(${PROJECT_NAME} SHARED
    ${SRC_FILES}
    ${HEADER_FILES}
)

target_link_libraries(${PROJECT_NAME} Qt5::Core)

if (UNIX)
    target_link_libraries(${PROJECT_NAME} stdc++fs)
endif ()