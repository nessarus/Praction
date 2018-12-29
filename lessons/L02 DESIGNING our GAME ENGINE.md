# DESIGNING our GAME ENGINE

## Difficulty of making a game engine
* Just using heuristics, it is hard to make a game engine:
    * Most game studios make games with pre-existing game engines
    * If game studio makes a game engine it usually takes a lot of resources
* There are already free resources on the internet
    * No reason to reinvent the wheel
* We are not a massive team so we have to limit the scope of project
    * Can't build Unreal or Unity
* Must take it slowly to present instructions

## Game Engine Framework
* Minimal frame work to get feature running
* Iterate over to further develop feature

## Future Features
* Level editor that operates at run time (ImGui)
* Shader compilation

## Next Planning Lessons
* API for renderer
* naming

## Game Engine Framework Features
* Entry point (i.e. at launch of the program)
    * what is executed in the main function
    * who is providing input to the program (user or game or engine)
        * engine macros
* Application layer
    * life cycle of applications
    * run loop
        * what keeps game executing code
    * time keeping
    * events
    * windows resized
    * controls
* Window layer (desktop support)
    *  input
    *  events
    *  events manager
* Renderer
* Render API abstraction using OpenGL
    *  OpenGL is the simplest API
    *  OpenGL is cross platform (Mac, Linux)
* Debugging support
    *  Logging
* Scripting language: allows artist/content creators to operate without thinking of low-level engine systems like memory
* Memory Systems
* Entity-component System
* Physics
* File I/O, Virtual File System
* Build system