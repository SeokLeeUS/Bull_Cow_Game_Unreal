# Bull_Cow_Game_Unreal
Unreal game development C++ practice

[Reference](https://www.udemy.com/share/1000hGA0MSdVdUR3w=/)


The following tips are I have collected so far from bull and cow game lecture:


· @ Visual Studio (VS), set the solution name separately while choosing a project name when you create a new project. The solution is inclusive of projects. You can have multiple projects under a solution.

· After creating a project from an “empty” application, go to project property to set linker>subsystem as “console”.

· Create a main C++ source code by right-clicking on project name.

· When you see warning message saying “console exit with zero” for compiling (@ VS 2017, ctrl+F5) , Go to debug>options>general> tick the box saying “automatically close the console when debugging stops”

· \n is called new line.

· Constexpr vs Const? If you define a constant using constexpr, the constant value will be known at compile not at the run time.

· Good practice to put the constant in all CAPITAL.

· always to put return on your function (even if there’s no value to return back). It's a good practice to declare a custom function after main function, but calling the custom function before main function.

· Grab lines of code and right click> Quick Actions (or ctrl+ “+”) from header, it will create a function cpp file and function codes, automatically.

· ‘ ‘ is for character, “ “ is for string.

· When you search syntax, MSDN.microsoft.com could be useful than c ++ plus.com.

· Unreal coding standard

· General pattern of Object Oriented Programming (OOP) is we don’t expose any variables publicly.

· Jing for snapshot tool

· @ VS code, in order to compile multiple codes at the same time, you must add the file to the end of the command line: cl main.cpp FBullCowGame.cpp /EHsc

· When you create a header file and include dummy function inside of a class, right click and choose quick action and refactoring so that source code (.cpp) will be created automatically.

· Instantiation is to set a variable for the class. Ex) FBullCowGame Player1Game; FBullCowGame Player2Game; (two instances are separate and independently running)

· If you want to look for function definition/declaration from main source code, right click> go to definition (F12) or go to declaration (ctrl+alt+F12) will direct you to function cpp/ header

· Do not trust compiler completely. In case unexpected result pops, rebuild solution.

· Class instance can be called at any function (including main function) when it is located at pre-processing directive (where #include is located).

· ```GetMaxTries () const {return MyMaxTries;}: const``` is protective method not allowing the change the value outside of where it’s defined and originated, but it only works with a function inside of a custom class.

View>Task List will list down comment with TODO (to add token). Utilize task list (view + task list) to know the remaining TODO.

· @ VS 2017, in order to replace a variable, hit ctrl+R x2

· Debugger, highlight the condition which you want to examine further, then right click > watch during debugging (but make sure you are not at “pause” in debugging mode (next to debugger stop button)

· Try to store reference instead of result. You can always get an instance of result from the reference (i.e. birthday(reference) vs. age). Until proven otherwise, don’t store result. The data locality (game programming patterns)

· Enum member is global, if you define two different enums, and same member name (i.e. OK) on both place, it will throw the error. In order to fix this, define enum as enum class.

· Accessing enum is ```::```.

· When declaring a function, it doesn’t require an input variable name, but when defining the function in cpp source code, supply the variable name as an input handle.

· # define is preprocessor directive to tell the compiler to use macro. (usage: #define TMap std::map)

· When you select the data type “auto”, the compiler sets the datatype automatically.

· Range for loop ```for (auto Letter : Word)```

· Use #pragma once at the top of each file to prevent double import

· Function resides in main.cpp which is outside of class definition (header/and function definition cpp file) is called as prototype.

· When you share source codes, share only main.cpp, header(.h) and source code(.cpp) of the class definition with others.



The following tip is from triple X lecture (mainly tips for Visual Code (VC)):



· If there’s a white space on VS, it can still compile.

· Have a good habit to “Auto Save” from file>Auto save @ VC.

· Preprocessor Directive (I don’t know why name it so complicate), but basically, instruct the compiler to include a library before compiling (```#include```)

· When changing a variable name in multiple locations, right click on the variable name @ VC, then select “change all occurrences” (or ctrl+F2)

· The variable name could start with underscore, and try to follow the naming convention of UpperCamelCase.

· ``<<`` is called  as “insertion operator”, ```>>``` as  “extraction operator”.

· After putting a statement (i.e. if), then hit “tab” button, it will auto formatting the rest of statement (handy!!)

· Highlight lines of code, then Ctrl+/ will comment out the lines of code, automatically (handy!)
