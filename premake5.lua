workspace "Parrot"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist",
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLAD"] = "Parrot/vendor/GLAD/include"
IncludeDir["GLFW"] = "Parrot/vendor/GLFW/include"

-- Other folder of premake5.lua
include "Parrot/vendor/GLAD"
include "Parrot/vendor/GLFW"

project "Parrot"
    location "Parrot"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "ptpch.h"
    pchsource "Parrot/src/ptpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.GLFW}",
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
    }

    links
    {
        "GLAD",
        "GLFW",
        "opengl32.lib",
    }

    filter "system:Windows"
        cppdialect "C++17"
        staticruntime "on"
        systemversion "latest"

        defines
        {
            "PARROT_PLATFORM_WINDOWS",
            "PARROT_BUILD_DLL",
            "GLFW_INCLUDE_NONE",
        }

        postbuildcommands
        {
            "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox",
        }

    filter "configurations:Debug"
        defines "PT_DEBUG"
        buildoptions "/MDd"
        symbols "On"

        defines
        {
            "PARROT_ENABLE_ASSERTS",
        }

    filter "configurations:Release"
        defines "PT_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "PT_DIST"
        buildoptions "/MD"
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
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Parrot/vendor/spdlog/include",
        "Parrot/src",
    }

    links
    {
        "Parrot",
    }

    filter "system:Windows"
        cppdialect "C++17"
        staticruntime "on"
        systemversion "latest"

        defines
        {
            "PARROT_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "PT_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "PT_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "PT_DIST"
        buildoptions "/MD"
        optimize "On"
