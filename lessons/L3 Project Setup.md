# Project Setup
Things to setup
* Github
* Visual Studio Solution
* Visual Studio Configuration

Github
* Create new repository
* Clone the git repository to a folder

Visual Studio Solution
* Create an empty project in VS
* Copy all files in git folder into VS project folder
    * .git
    * README.md
    * LICENSE

Visual Studio Configuration
The game engine made into a dynamic link library for the game to link to. 
* Platforms
    * We won't be supporting 32 bit
    * project -> properties -> configuration manager
        * remove x86 and Win32 
            * active solution platform -> x86
            * project contexts -> platform -> Win32
* game engine is a dynamic library
    * back in properties -> General -> Configuration Type -> set to Dynamic Library (.dll)
* output and intermediate directories (where files generated go, VS defaults not good enough)
    * Output Directory -> set to $(SolutionDir)bin\$(Configuration)-$(Platform)\$(ProjectName)\
    * Intermediate Directory -> set to $(SolutionDir)bin-int\$(Configuration)-$(Platform)\$(ProjectName)\

Game Project (Sandbox)
The game engine needs an application to run it. 
* Create a new empty project called Sandbox
* Follow instructions again
    * Platforms
    * output and intermediate directories
* Set Sandbox as right click -> Set as the startup project 

Project Ordering
Other people may want to checkout the engine by downloading and hitting F5. Since the engine is a dll file it won't work automatically so changing the ordering so the Sandbox comes first will allow the Sandbox to start instead.
* Close the solution
* Open project solution in a text editor (not VS)
* Move Sandbox line above game-engine line. I.e.:
    * Project("...") = "Sandbox",...
    * EndProject
    * Project("...") = "game-engine",...
    * EndProject

Linking Projects
Link Sandbox and the game engine together
* Right-click -> Add -> Reference... -> game engine

Project folders
Add folders:
* src

 