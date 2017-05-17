workspace "SkinControl"
    location "build"
    configurations { "Debug", "Release" }
    platforms { "x86", "x64" }
    
    flags { "StaticRuntime" }
    targetprefix ""
    buildoptions "/std:c++latest"
    
    symbols "On"
    characterset "Unicode"
    pic "On"
    systemversion "10.0.15063.0"
    toolset "v141"
    
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
