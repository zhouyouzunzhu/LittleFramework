set_languages("gnuxx17")
--set_optimize("aggressive")

if is_host("windows") then
	if is_mode("release") then
	    set_runtimes("MD")
	elseif is_mode("debug") then
		set_runtimes("MDd")
	end
	add_cxxflags("/Zc:__cplusplus")
	add_defines("_SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING", "_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS")
end

if is_mode("release") then
	set_optimize("fastest")
	set_symbols("hidden")
	set_strip("all")
elseif is_mode("debug") then
	add_defines("DEBUG")
end

add_includedirs("libs/glfw")
add_includedirs("libs/glad/include")
add_includedirs("libs/stb_image")


add_linkdirs("libs/glfw/lib")
if is_host("macosx") then
	-- add_linkdirs("/usr/local/lib")
	add_frameworks("OpenGL", "Carbon")
	-- add_frameworkdirs("/System/Library/Frameworks/")
	if is_arch("arm64") then
		add_links("glfw-arm64")
	else
		add_links("glfw")
	end
end

if is_host("windows") then
	add_links("opengl32")
	add_links("gdi32")
	add_links("glfw3")
	add_links("shell32")
	add_links("ws2_32")
	add_links("user32")
end

target("glad")
	set_kind("static")
	add_files("libs/glad/src/*.c")

target("App")
	set_kind("binary")
	add_includedirs("src")
	add_files("src/**.cpp")
	add_deps("glad")
	set_rundir("$(projectdir)/")
