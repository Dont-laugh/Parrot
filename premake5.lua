workspace "Parrot"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Distribute",
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
    }

    filter "system:Windows"
        cppdialect "C++17"
        staticruntime "on"
        systemversion "latest"

        defines
        {
            "PARROT_PLATFORM_WINDOWS",
            "PARROT_BUILD_DLL",
        }

        postbuildcommands
        {
            "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox",
        }

    filter "configurations:Debug"
        defines "PT_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PT_RELEASE"
        optimize "On"

    filter "configurations:Distribute"
        defines "PT_DIST"
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
        symbols "On"

    filter "configurations:Release"
        defines "PT_RELEASE"
        optimize "On"

    filter "configurations:Distribute"
        defines "PT_DIST"
        optimize "On"
