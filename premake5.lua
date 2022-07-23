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
IncludeDir["ImGui"] = "Parrot/vendor/imgui"
IncludeDir["spdlog"] = "Parrot/vendor/spdlog/include"

-- Other folder of premake5.lua
group "Dependencies"
    include "Parrot/vendor/GLAD"
    include "Parrot/vendor/GLFW"
    include "Parrot/vendor/imgui"

group ""

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
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.spdlog}",
        "%{prj.name}/src",
    }

    links
    {
        "GLAD",
        "GLFW",
        "ImGui",
        "opengl32.lib",
    }

    filter "system:Windows"
        cppdialect "C++17"
        staticruntime "off"
        systemversion "latest"

        defines
        {
            "_CRT_SECURE_NO_WARNINGS",
            "PARROT_PLATFORM_WINDOWS",
            "PARROT_BUILD_DLL",
            "GLFW_INCLUDE_NONE",
        }

        postbuildcommands
        {
            "IF NOT EXIST ../bin/" .. outputdir .. "/Sandbox mkdir ../bin/" .. outputdir .. "/Sandbox",
            "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox",
        }

    filter "configurations:Debug"
        defines "PT_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "PT_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "PT_DIST"
        runtime "Release"
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
        staticruntime "off"
        systemversion "latest"

        defines
        {
            "PARROT_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "PT_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "PT_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "PT_DIST"
        runtime "Release"
        optimize "On"
