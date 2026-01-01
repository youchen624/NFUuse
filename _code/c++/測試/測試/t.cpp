/*
#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    // 初始化 SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL 初始化失敗: " << SDL_GetError() << std::endl;
        return 1;
    }

    // 建立視窗
    SDL_Window* window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "視窗創建失敗: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // 建立渲染器
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "渲染器創建失敗: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // 主循環
    bool isRunning = true;
    SDL_Event event;

    while (isRunning) {
        // 處理事件
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
        }

        // 清空螢幕
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // 繪製矩形
        SDL_Rect rect = { 350, 250, 100, 100 };
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);

        // 更新畫面
        SDL_RenderPresent(renderer);
    }

    // 清理資源
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

*/





#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
    return 0;
}