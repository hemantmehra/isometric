#include <iostream>
#include <raylib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

void DrawLineISO(int startPosX, int startPosY, int endPosX, int endPosY, Color color)
{
    DrawLine(
        SCREEN_WIDTH/2 + (startPosX - startPosY),
        (startPosX + startPosY) * 0.5,
        SCREEN_WIDTH/2 + (endPosX - endPosY),
        (endPosX + endPosY) * 0.5,
        color
    );
}

void DrawRectISO(int startPosX, int startPosY, int width, int height, Color color)
{
    int endPosX = startPosX + width;
    int endPosY = startPosY + height;
    DrawLineISO(startPosX, startPosY, endPosX, startPosY, WHITE);
    DrawLineISO(endPosX, startPosY, endPosX, endPosY, RED);
    DrawLineISO(endPosX, endPosY, startPosX, endPosY, YELLOW);
    DrawLineISO(startPosX, endPosY, startPosX, startPosY, BLUE);
}

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "ISOMETRIC");
    
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
            // DrawRectISO(0, 0, 50, 50, WHITE);
            // DrawRectISO(50, 0, 100, 50, WHITE);

            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    DrawRectISO(j*50, i*50, 50, 50, WHITE);
                }
            }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
