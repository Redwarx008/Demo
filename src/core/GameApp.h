#include <chrono>
#include <filesystem>
#include <string>
#include <cassert>

namespace GameCore
{
    struct AppCommandLineArgs
    {
        int Count = 0;
        char** Args = nullptr;

        const char* operator[](int index) const
        {
            assert(index < Count);
            return Args[index];
        }
    };

    struct AppInitInfo
    {
        std::string Name = "Application";
        std::string WorkingDirectory;
        AppCommandLineArgs CommandLineArgs;
    };


	class GameApp
	{
    public:
        void Initialize(const AppInitInfo& initInfo);
        void Run();
        virtual void Startup() = 0;
        virtual void Cleanup() = 0;
    protected:
        virtual void Update();

    protected:
        bool m_is_quit{ false };

        std::chrono::steady_clock::time_point m_last_tick_time_point{ std::chrono::steady_clock::now() };

        float m_average_duration{ 0.f };
        int   m_frame_count{ 0 };
        int   m_fps{ 0 };
	};
}