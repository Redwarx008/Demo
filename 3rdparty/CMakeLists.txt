set(third_party_folder "ThirdParty")

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

if(NOT TARGET Diligent-GraphicsEngineVk-static)
    set(DILIGENT_NO_DIRECT3D11 ON CACHE BOOL "Disable DX11" FORCE)
    set(DILIGENT_NO_DIRECT3D12 ON CACHE BOOL "Disable DX12" FORCE)
    set(DILIGENT_NO_OPENGL ON CACHE BOOL "Disable OpenGL" FORCE)
    set(DILIGENT_NO_METAL ON CACHE BOOL "Disable METAL" FORCE)

    set(DILIGENT_NO_GLSLANG ON CACHE BOOL "Do not build GLSLang and SPRIV-Tools" FORCE)
    set(DILIGENT_NO_HLSL ON CACHE BOOL "Disable HLSL support in non-Direct3D backends" FORCE)
    add_subdirectory(DiligentCore)
    set_target_properties(Diligent-GraphicsEngineVk-static PROPERTIES FOLDER ${third_party_folder}/Diligent)
endif()

if(NOT TARGET glfw)
    option(GLFW_BUILD_EXAMPLES "" OFF)
    option(GLFW_BUILD_TESTS "" OFF)
    option(GLFW_BUILD_DOCS "" OFF)
    option(GLFW_INSTALL "" OFF)
    add_subdirectory(glfw)
    set_target_properties(glfw PROPERTIES FOLDER ${third_party_folder}/glfw)
    set_target_properties(update_mappings PROPERTIES FOLDER ${third_party_folder}/glfw)
endif()

if(NOT TARGET spdlog)
    option(SPDLOG_BUILD_EXAMPLE "" OFF)
    option(SPDLOG_INSTALL "" OFF)
    add_subdirectory(spdlog)
    set_target_properties(spdlog PROPERTIES FOLDER ${third_party_folder}/spdlog)
endif()

