#pragma once

#include <memory>
#include <string>

namespace GameCore
{
    class LogSystem;
    class InputSystem;
    //class PhysicsManager;
    class FileSystem;
    //class AssetManager;
    class ConfigManager;
    class WorldManager;
    class RenderSystem;
    class WindowSystem;
    //class ParticleManager;

    struct RuntimeContext
    {
        // create all global systems and initialize these systems
        void startSystems(const std::string& config_file_path);
        // destroy all global systems
        void shutdownSystems();

        std::shared_ptr<LogSystem>         logger_system;
        std::shared_ptr<InputSystem>       input_system;
        std::shared_ptr<FileSystem>        file_system;
        //std::shared_ptr<AssetManager>      asset_manager;
        std::shared_ptr<ConfigManager>     config_manager;
        std::shared_ptr<WorldManager>      world_manager;
        //std::shared_ptr<PhysicsManager>    physics_manager;
        std::shared_ptr<WindowSystem>      window_system;
        std::shared_ptr<RenderSystem>      render_system;
        //std::shared_ptr<ParticleManager>   particle_manager;
        //std::shared_ptr<DebugDrawManager>  debugdraw_manager;
        //std::shared_ptr<RenderDebugConfig> render_debug_config;
    };

    extern RuntimeContext g_runtime_context;
}