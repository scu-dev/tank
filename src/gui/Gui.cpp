#include <iostream>
#include <SDL3/SDL.h>
#include <imgui.h>
#include <backends/imgui_impl_sdl3.h>
#include <backends/imgui_impl_sdlrenderer3.h>

#include "../Tank.hpp"
#include "../util.hpp"
#include "../graphic/Renderer.hpp"
#include "GuiUtils.hpp"
#include "Gui.hpp"

namespace Gui {
    typedef int32_t i32;
    using Renderer::renderer, Renderer::window, Renderer::scale, Renderer::realDim, Renderer::baseDim, std::cout, std::endl;

    ImGuiContext* context;
    Cache cache;

    void init() noexcept {
        context = ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.LogFilename = nullptr;
        io.IniFilename = nullptr;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
        io.DisplaySize.x = realDim;
        io.DisplaySize.y = realDim;
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
        io.Fonts->Flags |= ImFontAtlasFlags_::ImFontAtlasFlags_NoPowerOfTwoHeight;
        io.Fonts->Clear();
        io.FontGlobalScale = scale;
        io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/msyh.ttc", 20.0f * scale, nullptr, io.Fonts->GetGlyphRangesChineseSimplifiedCommon());
        io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/msyh.ttc", 48.0f * scale, nullptr, io.Fonts->GetGlyphRangesChineseSimplifiedCommon());
        io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/msyh.ttc", 12.0f * scale, nullptr, io.Fonts->GetGlyphRangesChineseFull());
        io.Fonts->Build();
        ImGui_ImplSDLRenderer3_CreateDeviceObjects();
    }

    void processEvent(bool& running) noexcept {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL3_ProcessEvent(&event);
            if (event.type == SDL_EVENT_QUIT || (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED && event.window.windowID == SDL_GetWindowID(window))) running = false;
        }
    }

    void render() noexcept {
        SDL_GetWindowSize(window, &cache.width, &cache.height);
        ImGui_ImplSDLRenderer3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();
        ImGuiIO& io = ImGui::GetIO();
        switch (Tank::status) {
            case Tank::GameStatus::Ready: {
                ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.6f));
                GuiUtils::centerWindow("ready", false);
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
                ImGui::NewLine();
                ImGui::PushFont(io.Fonts->Fonts[1]);
                GuiUtils::centerText(u8"   坦克大战   ");
                ImGui::PopFont();
                ImGui::NewLine();
                GuiUtils::centerButton(u8"开始", ImVec2(240.0f * scale, 90.0f * scale), []() {
                    Tank::status = Tank::GameStatus::InProgress;
                });
                ImGui::PushFont(io.Fonts->Fonts[2]);
                ImGui::NewLine();
                GuiUtils::centerText(u8"By LJM12914（林峻茗）");
                GuiUtils::centerText(u8"SCU 2025 C++ 大作业");
                ImGui::PopFont();
                ImGui::PopStyleColor(1);
                GuiUtils::endWindow(false);
                ImGui::PopStyleColor(1);
                break;
            }
            case Tank::GameStatus::InProgress: {
                break;
            }
            case Tank::GameStatus::Stopped: {
                break;
            }
        }
        ImGui::Render();
        ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);
    }

    void shutdown() noexcept {
        ImGui_ImplSDLRenderer3_Shutdown();
        ImGui_ImplSDL3_Shutdown();
        ImGui::DestroyContext(context);
    }
}