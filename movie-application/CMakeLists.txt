cmake_minimum_required(VERSION 3.5)
project(moviestore)

set(CMAKE_CXX_STANDARD 14)

# have compiler give warnings, but not for signed/unsigned
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Wno-sign-compare")

# need to load data files from current directory as cpp files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(moviestore.exe main.cpp store_test.cpp borrow.cpp borrow.h BSTree.cpp BSTree.h classic.cpp classic.h comedy.cpp comedy.h commandRunner.cpp commandRunner.h customer.cpp customer.h drama.cpp drama.h hashTable.cpp hashTable.h history.cpp history.h inventory.cpp inventory.h manageCustomer.cpp manageCustomer.h manageInventory.cpp manageInventory.h movie.cpp movie.h movieMaker.cpp movieMaker.h return.cpp return.h runTransaction.cpp runTransaction.h storeManager.cpp storeManager.h transaction.cpp transaction.h)