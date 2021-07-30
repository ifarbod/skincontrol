workspace "SkinControl"
    location "build"
    configurations { "Debug", "Release" }
    platforms { "x64" }
    
    staticruntime "On"
    targetprefix ""
    cppdialect "C++latest"
    
    symbols "On"
    characterset "Unicode"
    pic "On"
    systemversion "latest"
    toolset "v142"
    
    filter "configurations:Release"
        optimize "Speed"
    
    -- Disable deprecation warnings and errors
    filter "action:vs*"
        defines
        {
            "_CRT_SECURE_NO_WARNINGS",
            "_CRT_SECURE_NO_DEPRECATE",
            "_CRT_NONSTDC_NO_WARNINGS",
            "_CRT_NONSTDC_NO_DEPRECATE",
            "_SCL_SECURE_NO_WARNINGS",
            "_SCL_SECURE_NO_DEPRECATE",
            "_WINSOCK_DEPRECATED_NO_WARNINGS"
        }

    include "code"

-- Cleanup
if _ACTION == "clean" then
    os.rmdir("bin");
    os.rmdir("build");
end
