cmake_minimum_required(VERSION 3.22)
project(Monopoly)

set(CMAKE_CXX_STANDARD 17)

add_executable(Monopoly main.cpp GameFields.cpp GameFields.h GameBoard.cpp GameBoard.h BankHandler.cpp BankHandler.h Player.cpp Player.h RingList.cpp RingList.h Utility.cpp Utility.h)
