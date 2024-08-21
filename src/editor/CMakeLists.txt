set(TARGET_NAME Editor)

file(GLOB EDITOR_HEADERS CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB EDITOR_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${EDITOR_HEADERS} ${EDITOR_SOURCES})

add_executable(${TARGET_NAME} ${EDITOR_HEADERS} ${EDITOR_SOURCES} )

target_compile_options(${TARGET_NAME}  PRIVATE -DUNICODE)

target_compile_definitions(${TARGET_NAME} PRIVATE ENGINE_DLL=0)

target_link_libraries(${TARGET_NAME} 
PRIVATE
    Diligent-GraphicsEngineVk-static
    #Diligent-BuildSettings
    #glfw
)
