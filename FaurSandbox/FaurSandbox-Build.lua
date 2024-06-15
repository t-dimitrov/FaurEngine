project "FaurSandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir ("%{wks.location}/Build/bin/"..outputDir.."/%{prj.name}")
    objdir ("%{wks.location}/Build/bin-int/"..outputDir.."/%{prj.name}")

    files {
        "src/**.h",
        "src/**.cpp",
    }

    includedirs {
        "%{wks.location}/FaurEngine/src",
        externalIncludes["spdlog"]
    }

    links {
        "FaurEngine"
    }

    filter "configurations:Debug"
        defines { "FAUR_DEBUG", "FAUR_ENABLE_ASSERTS" }
        symbols "on"

    filter "configurations:Release"
        defines { "FAUR_ENABLE_ASSERTS" }
        optimize "on"

    filter "configurations:Distribution"
        defines {}
        optimize "on"
