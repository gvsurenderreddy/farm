cmake_minimum_required(VERSION 2.8.11)
project(farm)

# Find includes in corrisponing build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)
find_package(Qt5Gui)
find_package(Qt5Qml)
find_package(Qt5Quick)
find_package(Qt5Widgets)
# Add the include directories for the Qt5 modules to
# the compile lines
INCLUDE_DIRECTORIES(${Qt5Core_INCLUDE_DIRS} ${Qt5Gui_INCLUDE_DIRS} ${Qt5Qml_INCLUDE_DIRS} ${Qt5Quick_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})

# Use the compile definitions defined in the Qt5 modules
add_definitions(${Qt5Core_DEFINITIONS} ${Qt5Gui_DEFINITIONS} ${Qt5Qml_DEFINITIONS} ${Qt5Quick_DEFINITIONS} ${Qt5Widgets_DEFINITIONS})

# Add compiler flags for bulding executables (-fPIE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Core_EXECUTABLE_COMPILE_FLAGS} ${Qt5Gui_EXECUTABLE_COMPILE_FLAGS} ${Qt5Qml_EXECUTABLE_COMPILE_FLAGS} ${Qt5Quick_EXECUTABLE_COMPILE_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

set(farm_SRCS src/farm.cpp src/main.cpp)
set(farm_QRC farm.qrc)

QT5_ADD_RESOURCES(farm_RCC_SRCS ${farm_QRC})

foreach(farm_SRC ${farm_SRCS})
    GET_FILENAME_COMPONENT(farm_MOC ${farm_SRC} NAME_WE)
    set(farm_MOC "${farm_MOC}.moc")
    #message(${farm_SRC} " - " ${farm_MOC} " ;")
    qt5_generate_moc(${farm_SRC} ${farm_MOC})
    set(farm_MOCS ${farm_MOCS} ${farm_MOC})
endforeach()

add_executable(farm ${farm_SRCS} ${farm_MOCS} ${farm_RCC_SRCS})
target_link_libraries(farm ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5Qml_LIBRARIES} ${Qt5Quick_LIBRARIES} ${Qt5Widgets_LIBRARIES})

install(TARGETS farm RUNTIME DESTINATION bin)
