cmake_minimum_required(VERSION 3.5)

project(TandaPlayer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "C:/Qt/6.6.2/msvc2019_64/")
# set(QT_QMAKE_EXECUTABLE )
set(CMAKE_COLOR_DIAGNOSTICS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcolor-diagnostics -fdiagnostics-color=always -O3 -g")

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()
file(GLOB TandaPlayer_SRC
     "*.cpp"
     "*.qrc"
)
set(PROJECT_SOURCES
${TandaPlayer_SRC}
)

add_library(playlist playlist.cpp tanda.cpp cortina.cpp)
enable_testing()
add_subdirectory(tests)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
qt_add_executable(TandaPlayer
MANUAL_FINALIZATION
${PROJECT_SOURCES}
)
#
else()
if(ANDROID)
add_library(TandaPlayer SHARED
${PROJECT_SOURCES}
)
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
else()
add_executable(TandaPlayer
${PROJECT_SOURCES}
)
endif()
endif()

target_link_libraries(TandaPlayer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.TandaPlayer)
endif()
set_target_properties(TandaPlayer PROPERTIES
${BUNDLE_ID_OPTION}
MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
MACOSX_BUNDLE TRUE
WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS TandaPlayer
BUNDLE DESTINATION .
LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
qt_finalize_executable(TandaPlayer)
endif()
