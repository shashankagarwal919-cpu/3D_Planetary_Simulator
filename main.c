#include "raylib.h"
#include <math.h>

#define PLANETS 8
#define STAR_COUNT 400

typedef struct
{
    float radius;
    float orbitRadius;
    float speed;
    float angle;
    Color color;

} Planet;

int main()
{
    InitWindow(1200, 800, "3D Planetary Simulator");

    SetTargetFPS(60);

    Camera3D camera = {0};

    camera.position = (Vector3){0, 35, 55};
    camera.target = (Vector3){0, 0, 0};
    camera.up = (Vector3){0, 1, 0};
    camera.fovy = 45;
    camera.projection = CAMERA_PERSPECTIVE;

    Planet planets[PLANETS] =
    {
        {0.4f,  4, 4.15f, 0, GRAY},
        {0.7f,  6, 1.63f, 0, ORANGE},
        {0.8f,  9, 1.00f, 0, BLUE},
        {0.6f, 12, 0.53f, 0, RED},
        {2.0f, 17, 0.084f, 0, BROWN},
        {1.7f, 23, 0.034f, 0, GOLD},
        {1.3f, 28, 0.012f, 0, SKYBLUE},
        {1.2f, 33, 0.006f, 0, DARKBLUE}
    };

    float sunRadius = 2.5f;

    Vector3 stars[STAR_COUNT];

    SetRandomSeed(12345);

    for (int i = 0; i < STAR_COUNT; i++)
    {
    float x = GetRandomValue(-1000, 1000);
    float y = GetRandomValue(-1000, 1000);
    float z = GetRandomValue(-1000, 1000);

    float length = sqrtf(x*x + y*y + z*z);

    if (length == 0)
        length = 1;

    float distance = GetRandomValue(850, 1100) / 10.0f;

    stars[i].x = (x / length) * distance;
    stars[i].y = (y / length) * distance;
    stars[i].z = (z / length) * distance;
}

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        UpdateCamera(&camera, CAMERA_ORBITAL);

        // Update planetary positions
        for (int i = 0; i < PLANETS; i++)
        {
            planets[i].angle += planets[i].speed * dt;
        }

        BeginDrawing();

        ClearBackground(BLACK);

        BeginMode3D(camera);

        // Draw background stars
for (int i = 0; i < STAR_COUNT; i++)
{
    DrawSphere(
        stars[i],
        0.15f,
        WHITE
    );
}

        // Draw the Sun
        DrawSphere(
            (Vector3){0, 0, 0},
            sunRadius,
            YELLOW
        );

        // Draw the orbital paths
        for (int i = 0; i < PLANETS; i++)
        {
            DrawCircle3D(
                (Vector3){0, 0, 0},
                planets[i].orbitRadius,
                (Vector3){1, 0, 0},
                90,
                DARKGRAY
            );
        }

        // Draw the planets
        for (int i = 0; i < PLANETS; i++)
        {
            float x = planets[i].orbitRadius *
                      cosf(planets[i].angle);

            float z = planets[i].orbitRadius *
                      sinf(planets[i].angle);

            Vector3 position = {x, 0, z};

            DrawSphere(
                position,
                planets[i].radius,
                planets[i].color
            );
        }

        EndMode3D();

        DrawText(
            "3D PLANETARY ORBIT SIMULATOR",
            20, 20, 25, WHITE
        );

        DrawFPS(20, 60);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}