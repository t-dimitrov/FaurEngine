externalIncludes = {}
externalIncludes["spdlog"] = "%{wks.location}/FaurEngine/external/spdlog/include"

-- spdlog project
externalproject "spdlog"
    location "%{wks.location}/Build/spdlog"
    uuid "218B9000-2A66-11EF-8465-0800200C9A66"
    kind "StaticLib"
    language "C++"

    configmap {
        ["Debug"] = "Debug",
        ["Release"] = "Release",
        ["Distribution"] = "Release"
    }
