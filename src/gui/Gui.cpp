#include <iostream>
#include <atomic>
#include <SDL3/SDL.h>
#include <imgui.h>
#include <backends/imgui_impl_sdl3.h>
#include <backends/imgui_impl_sdlrenderer3.h>

#include "../Game.hpp"
#include "../util.hpp"
#include "../graphic/Renderer.hpp"
#include "GuiUtils.hpp"
#include "Gui.hpp"

namespace Gui {
    typedef int32_t i32;
    using Renderer::renderer, Renderer::window, Renderer::scale, Renderer::realWidth, Renderer::baseDim, std::cout, std::endl, std::atomic;

    ImGuiContext* context;
    ImVector<ImWchar> rangeS, rangeM, rangeL;
    Cache cache;

    void init() noexcept {
        context = ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.LogFilename = nullptr;
        io.IniFilename = nullptr;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
        io.DisplaySize.x = realWidth;
        io.DisplaySize.y = realWidth;
        io.ConfigViewportsNoAutoMerge = true;
        io.ConfigViewportsNoTaskBarIcon = true;
        io.DisplayFramebufferScale.x = scale;
        io.DisplayFramebufferScale.y = scale;
        ImGui::GetStyle().ScaleAllSizes(scale);
        ImGui::StyleColorsDark();
        ImGuiStyle& style = ImGui::GetStyle();
        style.WindowRounding = 0.0f;
        style.WindowTitleAlign = ImVec2(0.5f, 0.0f);
        ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
        ImGui_ImplSDLRenderer3_Init(renderer);
        io.Fonts->Clear();
        io.Fonts->Flags |= ImFontAtlasFlags_::ImFontAtlasFlags_NoPowerOfTwoHeight;
        io.FontGlobalScale = scale;
        const auto* defaultRange = io.Fonts->GetGlyphRangesDefault();
        ImFontGlyphRangesBuilder builder;
        {
            builder.Clear();
            builder.AddText(CJK(u8"开始备用坦克等级射速弹匣"));
            builder.AddRanges(defaultRange);
            rangeM.clear();
            builder.BuildRanges(&rangeM);
            io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/msyh.ttc", 20.0f * scale, nullptr, rangeM.Data);
        }
        {
            builder.Clear();
            builder.AddText(CJK(u8"坦克大战"));
            builder.AddRanges(defaultRange);
            rangeL.clear();
            builder.BuildRanges(&rangeL);
            io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/msyh.ttc", 48.0f * scale, nullptr, rangeL.Data);
        }
        {
            builder.Clear();
            builder.AddText(CJK(u8"林峻茗大作业（）调试控制台"));
            builder.AddRanges(defaultRange);
            rangeS.clear();
            builder.BuildRanges(&rangeS);
            io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/msyh.ttc", 14.0f * scale, nullptr, rangeS.Data);
        }
        io.Fonts->Build();
        ImGui_ImplSDLRenderer3_CreateDeviceObjects();
    }

    void processEvent(atomic<bool>& running) noexcept {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL3_ProcessEvent(&event);
            if (event.type == SDL_EVENT_QUIT || (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED && event.window.windowID == SDL_GetWindowID(window))) running = false;
        }
    }

    void render() noexcept {
        using namespace ImGui;
        SDL_GetWindowSize(window, &cache.width, &cache.height);
        ImGui_ImplSDLRenderer3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        NewFrame();
        ImGuiIO& io = GetIO();
        if (Tank::gameStarted) {
            PushStyleColor(ImGuiCol_WindowBg, ImVec4(1.0f, 1.0f, 1.0f, 0.3f));
            Begin("progress", NULL, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);
            auto drawList = GetWindowDrawList();
            drawList->PushClipRectFullScreen();
            
            TextUnformatted("as");
            drawList->PopClipRect();
            End();
            PopStyleColor(1);
        }
        else {
            PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.6f));
            GuiUtils::centerWindow("ready", false);
            PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
            NewLine();
            PushFont(io.Fonts->Fonts[1]);
            GuiUtils::centerText(u8"   坦克大战   ");
            PopFont();
            NewLine();
            GuiUtils::centerButton(u8"开始", ImVec2(240.0f * scale, 90.0f * scale), &Tank::start);
            PushFont(io.Fonts->Fonts[2]);
            NewLine();
            GuiUtils::centerText(u8"By LJM12914（林峻茗）");
            GuiUtils::centerText(u8"SCU 2025 C++ 大作业");
            PopFont();
            PopStyleColor(1);
            GuiUtils::endWindow(false);
            PopStyleColor(1);
        }
        Render();
        ImGui_ImplSDLRenderer3_RenderDrawData(GetDrawData(), renderer);
    }

    void shutdown() noexcept {
        ImGui_ImplSDLRenderer3_Shutdown();
        ImGui_ImplSDL3_Shutdown();
        ImGui::DestroyContext(context);
    }
}