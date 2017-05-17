project "SkinControl"
    language "C++"
    kind "SharedLib"
    
    targetname "GTA5.SkinControl"
    targetextension ".asi"
    targetdir("%{wks.location}/../bin/")
    
    vpaths
    {
        ["Headers/*"] = "**.h",
        ["Sources/*"] = "**.cpp",
        ["*"] = "premake5.lua"
    }
    
    libdirs
    {
        "../vendor/scripthookv"
    }
    
    includedirs
    {
        "../vendor"
    }
    
    links
    {
        "scripthookv.lib"
    }
    
    files
    {
        "*.h",
        "*.cpp",
        "premake5.lua"
    }
