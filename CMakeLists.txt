cmake_minimum_required (VERSION 3.8)

project(Demo CXX)

set(SOURCES
    src/main.cpp
)

set(DILIGENT_NO_DIRECT3D11 ON CACHE BOOL "Disable DX11" FORCE)
set(DILIGENT_NO_DIRECT3D12 ON CACHE BOOL "Disable DX12" FORCE)
set(DILIGENT_NO_OPENGL ON CACHE BOOL "Disable OpenGL" FORCE)
set(DILIGENT_NO_METAL ON CACHE BOOL "Disable METAL" FORCE)

#set(DILIGENT_NO_GLSLANG ON CACHE BOOL "Do not build GLSLang and SPRIV-Tools" FORCE)
#set(DILIGENT_NO_HLSL ON CACHE BOOL "Disable HLSL support in non-Direct3D backends" FORCE)

set(DILIGENT_BUILD_TESTS ON CACHE BOOL "Build Unit Tests" FORCE)

add_subdirectory(3rdParty/DiligentCore)
add_subdirectory(3rdParty/glfw)

add_executable(Demo WIN32 ${SOURCES})

target_include_directories(Demo PRIVATE "3rdParty/DiligentCore")

target_compile_options(Demo  PRIVATE -DUNICODE)

target_compile_definitions(Demo PRIVATE ENGINE_DLL=0)

target_link_libraries(Demo 
PRIVATE
    Diligent-GraphicsEngineVk-static
    #Diligent-BuildSettings
    glfw
)
