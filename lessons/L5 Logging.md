# Logging

Developing games are an error prone business. Some bugs are not visible using just breakpoint and watch windows. Printf debugging helps display the program internal state. 

Win32 does not have a console however it does provide the function OutputDebugString().

The format of the string however is quite complicated with the different types of variables can output. We will use a library called spdlog to create a standard format. 

https://github.com/gabime/spdlog

As this will be an external library, we will use Git's sub-module to attach it our repository. 

Open Praction directory in CMD.

~ >> git submodule add https://github.com/gabime/spdlog Praction/vendor/spdlog

In the game engines' and sandbox's properties:
C/C++ >> General >> Additional Include Directories >> add
    $(SolutionDir)Praction\vendor\spdlog\include; 

