project "Percival-Engine"
   kind "StaticLib"
   language "C++"
   cppdialect "C++20"
   targetdir "Binaries/%{cfg.buildcfg}"
   staticruntime "off"

   files { "Source/**.h", "Source/**.cpp", "Source/**.hpp" }

   includedirs
   {
      "Source",
      "C:/VulkanSDK/1.3.280.0/Include",
      "C:/Users/hadri/Documents/Visual Studio 2022/Libraries/glfw-3.4.bin.WIN64",
      "C:/Users/hadri/Documents/Visual Studio 2022/Libraries/glm-1.0.1"
   }

   links
   {
       "vulkan-1.lib",
       "glfw3.lib"
   }

   libdirs
   {
      "C:/VulkanSDK/1.3.280.0/Lib",
      "C:/Users/hadri/Documents/Visual Studio 2022/Libraries/glfw-3.4.bin.WIN64/lib-vc2022",
   }

   targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

   filter "system:windows"
       systemversion "latest"
       defines { }

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"

   filter "configurations:Dist"
       defines { "DIST" }
       runtime "Release"
       optimize "On"
       symbols "Off"