# Graph

TODO write your own comments replace all XXX

Graph algorithms by Jun Hyung Park

GitHub URL: 
https://github.com/2018WI343/graph-jhpp114/commit/16ab4a5efefd6a40cf2a7878454f24a4a8bb942a

Expected Mark: 99.8

Time spent: 50 - 60 hours or maybe a little bit more

Compiled and tested on CSS Linux Lab: 
Yes It compiles until
I am completed.

The test testGraph0BFS, testGraph0Dijkstra, testGraph1 are not complete.

> cpplint *.cpp *.h

> cppcheck --enable=all --force --inconclusive --language=c++ --std=posix --suppress=missingIncludeSystem *.cpp *.h

Jun Hyung Park
*    It is giving out several warnings
*    Warning: statement has no effect
*    Warning: member variable is not initialized in the constructor
*    Warning: member variable is not initialized in the constructor
*    Technically the member function DFS can be static
*    Technically the member function BFS can be static
*    Technically the member function Dijkstra can be static
*    Technically the member function MST can be static
*    Prefer ++/-- opeartor for non primitive types
*    Assert statement calls a function which may have desired side effect
*    Assert statement calls a function which may have desired side effect

cppcheck complais about XXX, but the fix is too ugly, so I am not changing it

> valgrind ./bst.exe

There is no memory leak currently.

Implemented x, y, z, but did not have time for w, r

Program gives the following error, cannot find source or fix it
*    Function BFS
*    FUnction Dijkstra
*    Function MST 
*    are incomplete!

Improvements for next time:

Start early and time management.
If I bring out reason, I did not have enough time because I had to do all the work for group project in other class. 

Study more... I think I wasn't able to finish due to my knowledge...

- Create a non-template version of BST
- Write the due date on back of my hand
- More tests, more tests
- Build simpler test cases
- Compile and test on CSS Linux lab earlier
- use valgrind more frequently
- integrate cpplint with CLion
- My code is perfect, I rocked this assignment!

http://www.asciiworld.com/-Computers-.html

```

             ,----------------,              ,---------,
        ,-----------------------,          ,"        ,"|
      ,"                      ,"|        ,"        ,"  |
     +-----------------------+  |      ,"        ,"    |
     |  .-----------------.  |  |     +---------+      |
     |  |                 |  |  |     | -==----'|      |
     |  |  I LOVE DOS!    |  |  |     |         |      |
     |  |  Bad command or |  |  |/----|`---=    |      |
     |  |  C:\>_          |  |  |   ,/|==== ooo |      ;
     |  |                 |  |  |  // |(((( [33]|    ,"
     |  `-----------------'  |," .;'| |((((     |  ,"
     +-----------------------+  ;;  | |         |,"
        /_)______________(_/  //'   | +---------+
   ___________________________/___  `,
  /  oooooooooooooooo  .o.  oooo /,   \,"-----------
 / ==ooooooooooooooo==.o.  ooo= //   ,`\--{)B     ,"
/_==__==========__==_ooo__ooo=_/'   /___________,"
`-----------------------------'
```

