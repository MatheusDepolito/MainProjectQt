cmake_minimum_required(VERSION 3.16)

project(IdealArc VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOGEN_PARALLEL AUTO)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Charts Core Qml Network)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appIdealArc
    main.cpp
)

qt_add_qml_module(appIdealArc
    URI IdealArc
    VERSION 1.0
    RESOURCE_PREFIX /dep/imports
    QML_FILES Main.qml

)

add_subdirectory(ModuloConstantes)
add_subdirectory(ModuloComponentes)
set_target_properties(appIdealArc PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appIdealArc
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appIdealArc
    PRIVATE
    Qt6::Quick
    Qt6::Charts
    Qt6::Qml
    Qt6::Core
    Qt6::Network
    ModuloConstantesplugin
    ModuloComponentesplugin
)

include(GNUInstallDirs)
install(TARGETS appIdealArc
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
