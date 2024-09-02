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
        GameApp() = default;
        virtual ~GameApp();
        void Initialize(const AppInitInfo& initInfo);
        void Run();
        void Quit();

        virtual void Startup() = 0;
        virtual void Cleanup() = 0;
    protected:
        virtual void Update();
	};
}