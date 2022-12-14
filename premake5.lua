workspace "Neo-Engine"
    architecture "x64"
    startproject "Sandbox"

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
IncludeDir["Glad"] = "Neo-Engine/vendor/Glad/include"
IncludeDir["ImGui"] = "Neo-Engine/vendor/ImGui"
IncludeDir["glm"] = "Neo-Engine/vendor/glm"

include "Neo-Engine/vendor/GLFW"
include "Neo-Engine/vendor/Glad"
include "Neo-Engine/vendor/ImGui"

project "Neo-Engine"
    location "Neo-Engine"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "NeoPCH.h"
    pchsource "Neo-Engine/src/NeoPCH.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"
        
        defines
        {
            "NEO_PLATFORM_WINDOWS",
            "NEO_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        }

    filter "configurations:Debug"
        defines "NEO_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "NEO_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "NEO_DIST"
        runtime "Release"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

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
        "Neo-Engine/src",
		"%{IncludeDir.glm}"
    }

    links
    {
        "Neo-Engine"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"
        
        defines
        {
            "NEO_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "NEO_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "NEO_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "NEO_DIST"
        runtime "Release"
        optimize "On"
