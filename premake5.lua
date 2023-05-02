project "yaml-cpp"
language "C++"
cppdialect "C++17"

staticruntime "off"
kind "StaticLib"

targetdir("bin/" .. outputdir)
objdir("build/" .. outputdir)

files {
   "src/**.cpp",
   "src/**.h",
   "include/**.h"
}

includedirs {
   "include",
   "%{wks.location}/vendor/glm"
}
