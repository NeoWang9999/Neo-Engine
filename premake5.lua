workspace "Neo-Engine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Neo-Engine/vendor/GLFW/include"

include "Neo-Engine/vendor/GLFW"

project "Neo-Engine"
    location "Neo-Engine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "NeoPCH.h"
    pchsource "Neo-Engine/src/NeoPCH.cpp"

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
            "NEO_PLATFORM_WINDOWS",
            "NEO_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "NEO_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "NEO_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "NEO_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Neo-Engine/vendor/spdlog/include",
        "Neo-Engine/src"
    }

    links
    {
        "Neo-Engine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        
        defines
        {
            "NEO_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "NEO_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "NEO_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "NEO_DIST"
        optimize "On"