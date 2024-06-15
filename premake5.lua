workspace "Faur"
    startproject "FaurSandbox"
    architecture "x86_64"
    configurations { "Debug", "Release", "Distribution" }

outputDir = "%{cfg.buildcfg}-%{cfg.system}"

group "External"
include "External-Build.lua"
group ""

include "FaurEngine/FaurEngine-Build.lua"
include "FaurSandbox/FaurSandbox-Build.lua"
