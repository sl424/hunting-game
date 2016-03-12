#########################################################
# File: Makefile
# Description: A more robust makefile for CS162.
# You need to edit the variables under "USER SECTION".
# To execute the makefile on unix-y systems, type 'make'.
# If that doesn't work, 'make -f makefile' might be useful.
#########################################################

# #'s are line-comments 

# CXX is a standard variable name used for the compiler. 
CXX = g++

# CXXFLAGS is a standard variable name for compile flags.
# -std=c++0x specifies to use a certain language version.
CXXFLAGS = -std=c++0x

# -Wall turns on all warnings
CXXFLAGS += -Wall

# -pedantic-errors strictly enforces the standard
CXXFLAGS += -pedantic-errors

# -g turns on debug information 
CXXFLAGS += -g

####################
### USER SECTION ###
####################

# SRCS is a standard name for the source files. 
# Edit as needed.
SRC1 = main.cpp
SRC2 = game.cpp
SRC3 = space.cpp
SRC4 = campground.cpp
SRC5 = item.cpp
SRC6 = human.cpp
SRC7 = creature.cpp
SRC8 = state.cpp
SRC9 = snake.cpp
SRC10 = forest.cpp
SRC11 = meadow.cpp
SRC12 = lake.cpp
SRC13 = river.cpp
SRC14 = fish.cpp
SRC15 = bird.cpp
SRC16 = mountain.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4} ${SRC5} ${SRC6} ${SRC7} ${SRC8} ${SRC9} ${SRC10} ${SRC11} ${SRC12} ${SRC13} ${SRC14} ${SRC15} ${SRC16} 

# HEADERS is a standard name for the header files. 
# Edit these as needed.
HEADER1 = game.hpp
HEADER2 = space.hpp
HEADER3 = campground.hpp
HEADER4 = item.hpp
HEADER5 = human.hpp
HEADER6 = creature.hpp
HEADER7 = state.hpp
HEADER8 = snake.hpp
HEADER9 = forest.hpp
HEADER10 = meadow.hpp
HEADER11 = lake.hpp
HEADER12 = river.hpp
HEADER13 = fish.hpp
HEADER14 = bird.hpp
HEADER15 = mountain.hpp
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3} ${HEADER4} ${HEADER5} ${HEADER6} ${HEADER7} ${HEADER8} ${HEADER9} ${HEADER10} ${HEADER11} ${HEADER12} ${HEADER13} ${HEADER14} ${HEADER15} 

# These will be your executable names. 
# Edit as needed.
PROG1 = huntergather
PROG2 = 
PROG3 = 
PROGS = ${PROG1} ${PROG2} ${PROG3}

# This is the name of your document(s). 
# Edit as needed.
DOC1 = bat.txt
DOC2 = bird.txt
DOC3 = camp.txt
DOC4 = snake.txt
DOC5 = fish.txt
DOC6 = mountain.txt
DOC7 = wolves.txt
DOC8 = hunter_design.pdf
DOC9 = gameplay.txt
DOC10 = item_list.txt
DOC = ${DOC1} ${DOC2} ${DOC3} ${DOC4} ${DOC5} ${DOC6} ${DOC7} ${DOC8} ${DOC9} ${DOC10} 
# This is the name of your compressed file. 
# Edit name as needed. Keep the format.
TAR = huntergather.tar.bz2
ZIP = huntergather.zip

#####################
### BUILD SECTION ###
#####################

# Typing 'make' in terminal calls the first build availible.
# In this case, default.
default:
	${CXX} ${SRCS} ${HEADERS} -o ${PROG1}

# Typing 'make all' in terminal calls this build.
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG1}

# Typing 'make tar' in terminal calls this build.
# This creates a compressed file for submission.
tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} ${DOC} makefile

zip:
	zip -r ${ZIP} ${SRCS} ${HEADERS} ${DOC} makefile

# Typing 'make clean' calls this build.
# It's designed to clean up the folder.
# Be careful with this, edit as needed.
clean: 
	rm -f ${PROGS} *.o *~

