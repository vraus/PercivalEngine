-- premake5.lua
workspace "Project Percival"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "Percival-Editor"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Core"
	include "Percival-Core/Build-Core.lua"
group ""

include "Percival-Editor/Build-Editor.lua"