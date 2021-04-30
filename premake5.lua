workspace "HazelEngine"
	architecture "x86_x64"
	startproject "HazelEnginenut"

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
IncludeDir["stb_image"] ="HazelEngine/vendor/stb_image"
group "Dependencies"
	include "HazelEngine/vendor/GLFW"
	include "HazelEngine/vendor/Glad"
	include "HazelEngine/vendor/imgui"
group ""

project "HazelEngine"
	location "HazelEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	pchheader "hzpch.h"
	pchsource "HazelEngine/src/hzpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}
	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"

	}
	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"
		
	defines
	{
		"HZ_PLATFORM_WINDOWS",
		"HZ_BUILD_DLL",
		"GLFW_INCLUDE_NONE"
	}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HZ_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		systemversion "latest"
		
	defines
	{
		"HZ_PLATFORM_WINDOWS",
	}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HZ_DIST"
		runtime "Release"
		optimize "on"

project "HazelEnginenut"
	location "HazelEnginenut"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		systemversion "latest"
		
	defines
	{
		"HZ_PLATFORM_WINDOWS",
	}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HZ_DIST"
		runtime "Release"
		optimize "on"