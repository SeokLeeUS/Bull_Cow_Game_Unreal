# Bull_Cow_Game_Unreal
Unreal game development C++ practice

[Reference](https://www.udemy.com/share/1000hGA0MSdVdUR3w=/)


- The following tips are I have collected so far from bull and cow game lecture:

  - @ Visual Studio (VS), set the solution name separately while choosing a project name when you create a new project. The solution is inclusive of projects. You can have multiple projects under a solution.

  - @VS 2017, after creating a project from an “empty” application, go to project property to set linker>subsystem as “console”. [Udemy response] The main reason for doing it this way was to avoid having to explain or what precompiled headers are which was enabled by default if you chose to use the Console Application project template. This is no longer enabled by default in VS 2019 so if it were to be redone today, we would just use that template.

  - Create a main C++ source flie by right-click on project name.

  - When you see warning message saying “console exit with zero” for compiling (@ VS 2017, <kbd>ctrl</kbd> + <kbd>F5</kbd>), Go to <kbd>debug</kbd>><kbd>options</kbd>><kbd>general</kbd>> tick the box saying “automatically close the console when debugging stops”

  - ```\n``` is called new line.

  - Constexpr vs Const? If you define a constant using constexpr, the constant value will be known at compile not at the run time.
[Udemy response] That's technically not guaranteed that it will be evaluated at compile time just that it can be. Though general rule is just constexpr > const > nothing. Use what compiles.

  - Good practice is to put the constant in all CAPITAL. [Udemy response] That's kind of an old practice , ALL_CAPS is basically only used for macros these days as it's loud and noisy which is what you want macros to be.

  - Always try to put return on your function (even if there’s no value to return back). It's a good practice to declare a custom function after main function, but calling the custom function before main function. [Udemy response] That's not really necessary and kind of odd that Ben did that.

  - Grab lines of code and <kbd>right click</kbd> > <kbd>Quick Actions</kbd> (or <kbd>Ctrl</kbd>+ <kbd>+</kbd>) from header, it will create a function cpp file and function codes, automatically.

  - ```' '``` is for character, ```" "``` is for string.

  - When you search C++ syntax, [MSDN](MSDN.microsoft.com) could be useful than [cplusplus site](cplusplus.com).

  - Please refer to [Unreal coding standard](https://docs.unrealengine.com/en-US/Programming/Development/CodingStandard/index.html)  

  - General pattern of Object Oriented Programming (OOP) is, don’t expose any variables publicly.

  - [Jing](https://www.techsmith.com/jing-tool.html) is a snapshot tool. [Greenshot](https://getgreenshot.org/) would be also a good alternative. 

  - @ VS code, in order to compile multiple codes at the same time, you must add the file to the end of the command line: ```cl main.cpp FBullCowGame.cpp /EHsc```

  - When you create a header file and include dummy function inside of a class, <kbd>right click</kbd> > <kbd> quick action </kbd> and refactoring so that source code (.cpp) will be created automatically.

  - 'Instantiation' is to set a variable for the class. Ex) ```FBullCowGame Player1Game```; ```FBullCowGame Player2Game```; (two instances are separate and independently running)

  - If you want to look for function definition/declaration from main source file, <kbd>right click</kbd> > go to definition (<kbd>F12</kbd>) or go to declaration (<kbd>ctrl</kbd>+<kbd>alt</kbd>+<kbd>F12</kbd>) will direct you to function source file/header file. 

  - Do not trust compiler completely. In case unexpected result pops, rebuild the solution.

  - Class instance can be called at any function (including main function) when it is located area where the pre-processing directive resides (where ```#include``` is located).  BCGame is an instance of the class FBullCowGame. Please refer to [this](https://www.quora.com/How-are-C++-class-instances-created) about class instance. 
  ![class_definition](https://github.com/SeokLeeUS/Bull_Cow_Game_Unreal/raw/master/_image/class_definition.png)

  - ```GetMaxTries () const {return MyMaxTries;}: const``` is a protective method not allowing the change the value outside of where it’s defined and originated, but it only works with a function inside of a custom class. [Udemy response] It prevents data members from being modified, which is why it's only for member functions and has no meaning for non-member functions.

  - @VS, <kbd>View</kbd> <kbd>Task List</kbd> will list down comment with ```TODO``` (to add token). Utilize task list (<kbd>view</kbd> + <kbd>task list</kbd>) to know the remaining ```TODO```.

  - @ VS 2017, in order to replace a variable, hit <kbd>ctrl</kbd>+<kbd>r</kbd> x2

  - Debugger, highlight the condition which you want to examine further, then <kbd> right click </kbd> <kbd>watch</kbd> during debugging (but make sure you are not at “pause” in debugging mode (next to debugger stop button)

  - Try to store reference instead of the result. You can always get an instance of   the result from the reference (i.e. birthday(reference) vs. age). Until proven otherwise, don’t store the result. The data locality (game programming patterns)

  - ```enum``` member is global, if you define two different enums, and same member name (i.e. ```OK```) on both place, it will throw the error. In order to fix this, define  ```enum class``` instead of ```enum```.

  - Accessing enum is ```::```.

  - When declaring a function, it doesn’t require an input variable name, but when defining the function in cpp source code, supply the variable name as an input handle.

  - ```#define``` is preprocessor directive to tell the pre-processor to create macro. (usage: ```#define TMap std::map```). 
  Please refer to [compiler vs pre-processor](https://www.quora.com/What-is-the-difference-between-a-compiler-directive-and-a-preprocessor-in-C)

  - When you select the data type ```auto```, the compiler sets the datatype automatically.

  - Range for loop ```for (auto Letter : Word)```

  - Use ```#pragma once``` at the top of each file to prevent double import

  - Function resides in main.cpp which is outside of class definition (header/and function definition cpp file) is called as prototype.

  - When you share source codes, share only main.cpp, header(.h) and source code(.cpp) of the class definition with others.


- The following tip is from triple X lecture (mainly tips for Visual Code (VC)):

  - If there’s a white space on VS or VC, it can still compile.

  - Have a good habit to “Auto Save” from <kbd>file</kbd>><kbd>Auto</kbd> save @ VC.

  - Preprocessor Directive (I don’t know why name it is quite complicate), but basically, instruct the compiler to include (```#include```) a library before compiling the code. 
  [Udemy response] It's called "preproccessor directive" because it's a directive (instruction) to the preproccessor which is something that is run before compilation. ```#include``` is a just a copy and paste.

  - When changing a variable name in multiple locations, right click on the variable name @ VC, then select “change all occurrences” (or <kbd>ctrl</kbd>+<kbd>F2</kbd>)

  - The variable name could start with underscore, and try to follow the naming convention of UpperCamelCase.

  - ``<<`` is called  as “insertion operator”, ```>>``` as  “extraction operator” with ```#include <iostream>```

  - After putting a statement (i.e. if), then hit the <kbd>tab</kbd> key, it will do auto format the rest of statement (handy!!)

  - Highlight lines of code, then <kbd>ctrl</kbd> + <kbd>/</kbd> will comment out the lines of code, automatically (handy!)
