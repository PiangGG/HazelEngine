workspace "HazelEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
--include directories relative to root folder (solution directory)
IncludeDir ={}
IncludeDir["GLFW"] ="HazelEngine/vendor/GLFW/include"
IncludeDir["Glad"] ="HazelEngine/vendor/Glad/include"
IncludeDir["ImGui"] ="HazelEngine/vendor/imgui"
IncludeDir["glm"] ="HazelEngine/vendor/glm"

include "HazelEngine/vendor/GLFW"
include "HazelEngine/vendor/Glad"
include "HazelEngine/vendor/imgui"

project "HazelEngine"
	location "HazelEngine"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	pchheader "hzpch.h"
	pchsource "HazelEngine/src/hzpch.cpp"

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
		"HZ_PLATFORM_WINDOWS",
		"HZ_BUILD_DLL",
		"GLFW_INCLUDE_NONE"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir .. "/Sandbox")
	}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"HazelEngine/vendor/spdlog/include",
		"HazelEngine/src",
		"HazelEngine/vendor",
		"%{IncludeDir.glm}"
	}
	
	links
	{
		"HazelEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		
	defines
	{
		"HZ_PLATFORM_WINDOWS",
	}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
		runtime "Release"
		optimize "On"