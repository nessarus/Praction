workspace "Praction"
    architecture "x64"
    
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

--[[ output directory is the location of built files --]]
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
--[[ cfg.buildcfg       : debug/release/etc --]]
--[[ cfg.system         : windows/mac/linux --]]
--[[ cfg.architecture   : x64/x86/etc --]]

-- Include directories are set relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Praction/vendor/GLFW/include"
-- IncludeDir is a struct that will grow as more directories are to be included

include "Praction/vendor/GLFW"

project "Praction"
    location "Praction"
    kind "SharedLib"
    language "C++"

    --[[ binaries executable --]]
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    --[[ prj.name : project name --]]

    --[[ object files --]]
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	--[[ precompiled files --]]
	pchheader "ptpch.h"
	pchsource "Praction/src/ptpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
		"%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include", 
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "PT_PLATFORM_WINDOWS", 
            "PT_BUILD_DLL"
        }

        --[[ automatically copies game engine's dll into sanbox's after each build --]]
        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "PT_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PT_RELEASE"
        symbols "On"
    
    filter "configurations:Dist"
        defines "PT_DIST"
        symbols "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

      --[[ binaries --]]
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")

    --[[ object files --]]
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Praction/vendor/spdlog/include", 
        "Praction/src"
    }

    links
    {
        "Praction"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "PT_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "PT_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PT_RELEASE"
        symbols "On"
    
    filter "configurations:Dist"
        defines "PT_DIST"
        symbols "On"

