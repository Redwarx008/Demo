set(third_party_folder "ThirdParty")

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

if(NOT TARGET DiligentCore)
    set(DILIGENT_NO_DIRECT3D11 ON CACHE BOOL "Disable DX11" FORCE)
    set(DILIGENT_NO_DIRECT3D12 ON CACHE BOOL "Disable DX12" FORCE)
    set(DILIGENT_NO_OPENGL ON CACHE BOOL "Disable OpenGL" FORCE)
    set(DILIGENT_NO_METAL ON CACHE BOOL "Disable METAL" FORCE)

    set(DILIGENT_NO_GLSLANG ON CACHE BOOL "Do not build GLSLang and SPRIV-Tools" FORCE)
    set(DILIGENT_NO_HLSL ON CACHE BOOL "Disable HLSL support in non-Direct3D backends" FORCE)
    add_subdirectory(DiligentCore)
endif()