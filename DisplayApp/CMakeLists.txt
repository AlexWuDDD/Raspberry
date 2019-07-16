cmake_minimum_required(VERSION 3.5.1)
project(DisplayApp)


#SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
#SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")


#set(CMAKE_CXX_STANDARD 11)

set(INC_DIR /usr/local/include)
set(LINK_DIR /usr/local/lib)

include_directories(${INC_DIR}
        ./
        ./Config
        ./ePaper
        ./Fonts
        ./GUI)
link_directories(${LINK_DIR})

#add_definitions(-DUSE_BCM2835_LIB)
add_definitions(-DUSE_WIRINGPI_LIB)

add_executable(DisplayApp main.cpp
        test.cpp test.h
        Config/DEV_Config.c Config/DEV_Config.h Config/Debug.h
        ePaper/EPD_2in7.c ePaper/EPD_2in7.h
        GUI/GUI_BMPfile.c GUI/GUI_BMPfile.h
        GUI/GUI_Paint.c GUI/GUI_Paint.h
        Fonts/font8.c Fonts/font12.c Fonts/font16.c Fonts/font20.c Fonts/font24.c
        Fonts/fonts.h)
target_link_libraries(DisplayApp bcm2835 wiringPi)