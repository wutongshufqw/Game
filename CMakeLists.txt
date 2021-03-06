cmake_minimum_required(VERSION 3.22)
project(Game)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "$ENV{QT_CMAKE}")

set(CMAKE_EXE_LINKER_FLAGS -static)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        REQUIRED)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/Source/Headers
)

add_executable(Game WIN32
        Source/assets/imagesrc.qrc Source/assets/qsssrc.qrc Source/assets/musicsrc.qrc
        Source/main.cpp
        Source/gameplay.cpp Source/Headers/gameplay.h Source/Forms/gameplay.ui
        Source/gameselect.cpp Source/Headers/gameselect.h Source/Forms/gameselect.ui
        Source/mainwindow.cpp Source/Headers/mainwindow.h Source/Forms/mainwindow.ui
        Source/gamestart.cpp Source/Headers/gamestart.h Source/Forms/gamestart.ui
        Source/gamecomplete.cpp Source/Headers/gamecomplete.h Source/Forms/gamecomplete.ui
        Source/Level.cpp Source/Headers/Level.h
        Source/gameshow.cpp Source/Headers/gameshow.h Source/Forms/gameshow.ui
        Source/GameCreator.cpp Source/Headers/GameCreator.h)
target_link_libraries(Game
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Multimedia
        )

if (WIN32)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
