# Praction engine

Praction engine is my attempt to make a game engine. I will be following the guidance TheChernoProject's Hazel engine and other internet related resources in this endeavor. 

## Features
* Windowing (windows only)
* Debugging Tools (Logger)

## Features in development
* Game Engine Framework
* Windowing (desktop only for now)
* Renderer using OpenGL (Windows only for now)
* Debugging Tools
* Level editor that operates at run time (ImGui)
* Scripting language for content creators
* Memory Management System
* Entity-component System (game objects functions and family tree)
* Physics
* File management system (virtual support)
* Build system

## Patch notes:
* Patch 0.0.13 ImGui
Added in debug menu screen (non-functional yet)

* Patch 0.0.12 OpenGL extension (Glad)
Added Glad to modernize and extend OpenGL.

* Patch 0.0.11 Layers
Added in the Layer Class.

* Patch 0.0.10 Window Event
Added in the Window Event system.

* Patch 0.0.9 Window Abstraction and GLFW
Added in Window class using GLFW

* Patch 0.0.8 Precompiled headers
Added in precompiled headers file. 

* Patch 0.0.7 Events
Created Event, mouse event, keyboard event, application classes.

* Patch 0.0.6 Premake
Created premake5.lua to assist in automating generation of project files 

* Patch 0.0.5 Logger
Clients have now access to a error display logger. 

* Patch 0.0.4 Entry Point  
Clients can now create Praction engine's applications objects

* Patch 0.0.1 Initial setup