#include <chrono>
#include <filesystem>
#include <string>

namespace GameCore
{
	class BilaiEngine
	{
        static const float s_fps_alpha;

    public:
        void StartEngine(const std::string& config_file_path);
        void ShutdownEngine();

        void Initialize();
        void Clear();

        bool IsQuit() const { return m_is_quit; }
        void Run();
        bool TickOneFrame(float delta_time);

        int GetFPS() const { return m_fps; }

    protected:
        void LogicalTick(float delta_time);
        bool RendererTick(float delta_time);

        void CalculateFPS(float delta_time);

        /**
         *  Each frame can only be called once
         */
        float CalculateDeltaTime();

    protected:
        bool m_is_quit{ false };

        std::chrono::steady_clock::time_point m_last_tick_time_point{ std::chrono::steady_clock::now() };

        float m_average_duration{ 0.f };
        int   m_frame_count{ 0 };
        int   m_fps{ 0 };
	};
}