# Binary Search Tree

TODO write your own comments replace all Jun Hyung Park

Binary Search Tree by Jun Hyung Park

GitHub URL: 
https://github.com/2018WI343/bst-jhpp114/commit/907ea433d88a71b4befc0805a8528c4c91a9d273

Expected Mark: 99.8

Time spent: More than 50 hours

Compiled and tested on CSS Linux Lab: XXX // TODO, hopefully YES


> cpplint *.cpp *.h

> cppcheck --enable=all --force --inconclusive --language=c++ --std=posix --suppress=missingIncludeSystem *.cpp *.h

Jun Hyung Park

cpplint complains Nothing.

cppcheck complais about  
* can be static on postorder (Performance inconclusive)
* can be static on preorder (Performance inconclusive)
* can be static on inorder (Performance inconclusive)

* Warning: assert statement calls a function which may have desired side effects on remove

* Warning: Assignment of function parameter has no effect outside the function.

* Style 1 argument constructor that is not explicit

Aware all the warnings and error.
but the fix is too ugly, so I am not changing it

> valgrind ./bst.exe

Jun Hyung Park,

* Finally fixed it no!!! leak
* yes!

Implemented x, y, z, but did not have time for w, r
Imemented all

Program gives the following error, cannot find source or fix it
            blah blah blah

Improvements for next time:

// TODO pick and choose your own comments

- Create a non-template version of BST
- Write the due date on back of my hand
- More tests, more tests
- Build simpler test cases
- Compile and test on CSS Linux lab earlier
- use valgrind more frequently
- integrate cpplint with CLion
- My code is perfect, I rocked this assignment!

* I totally failed on time management because I had to work 3 people's work on other group project
* Since, it is cause a potential memory problem, I will use valgrind more.
* Start early on the project

// TODO optional ASCII art

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

