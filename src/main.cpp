#include <deque>
#include <iostream>
#include <raylib.h>
#include <raymath.h>

using namespace std;

// Color variable
Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};
// Grid variables
int cellSize = 30;
int cellCount = 25;
int offset = 75;

// Time restrictions for the snake
double lastInterval = 0;

bool eventTriggered(double interval) {
  double cTime = GetTime();
  if (cTime - lastInterval >= interval) {
    lastInterval = cTime;
    return true;
  }
  return false;
}
bool ElementInDeque(Vector2 element, deque<Vector2> deque) {
  for (unsigned int i = 0; i < deque.size(); i++) {
    if (Vector2Equals(deque[i], element)) {
      return true;
    }
  }
  return false;
}
// Food Class
class Food {
public:
  Vector2 position = getRandomPos();
  Texture2D foodTexture;

  Food() {
    Image foodImage = LoadImage("Graphics/food.png");
    foodTexture = LoadTextureFromImage(foodImage);
    UnloadImage(foodImage);
  }

  ~Food() { UnloadTexture(foodTexture); }

  void Draw() {
    DrawTexture(foodTexture, offset + position.x * cellSize,
                offset + position.y * cellSize, WHITE);
  }

  Vector2 getRandomPos() {
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);
    return {x, y};
  }
};

// Snake Class
class Snake {

public:
  deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
  bool addSegment = false;

  Vector2 direction{1, 0};
  void Draw() {
    for (unsigned int i = 0; i < body.size(); i++) {
      float x = body[i].x;
      float y = body[i].y;
      Rectangle segment{offset + x * cellSize, offset + y * cellSize,
                        (float)cellSize, (float)cellSize};

      DrawRectangleRounded(segment, 0.5, 6, darkGreen);
    }
  }

  void Update() {

    body.push_front(Vector2Add(body[0], direction));
    if (addSegment == true) {
      addSegment = false;
    } else {
      body.pop_back();
    }
  }
  // Reset the position of the snake
  void Reset() {
    body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    direction = {1, 0};
  }
};
// Game class for both snake and food
class Game {
public:
  Snake snake;
  Food food;
  bool running = true;
  int score = 0;
  int High_Score = 0;
  Sound eat;
  Sound wall;

  Game() {

    eat = LoadSound("Sound/eat.mp3");
    wall = LoadSound("Sound/wall.mp3");
  }
  ~Game() {
    UnloadSound(eat);
    UnloadSound(wall);
  }
  void Draw() {
    if (running == false) {
      DrawText("! GAME OVER", 200, 375, 70, BLACK);
      DrawText("Pres -> <- To Restart", 200, 500, 40, BLACK);
    } else {
      food.Draw();
      snake.Draw();
    }
  }

  void Update() {
    if (running) {
      snake.Update();
      checkCollisionFood();
      checkCollisionEdges();
      checkCollisionTail();
    }
  }

  void checkCollisionFood() {
    if (Vector2Equals(snake.body[0], food.position)) {
      // cout << " food hit" << endl;
      food.position = food.getRandomPos();
      snake.addSegment = true;
      score++;
      PlaySound(eat);
    }
  }
  void checkCollisionEdges() {
    if (snake.body[0].x == cellCount || snake.body[0].x == -1) {
      GameOver();
    }
    if (snake.body[0].y == cellCount || snake.body[0].y == -1) {
      GameOver();
    }
  }
  void checkCollisionTail() {
    deque<Vector2> headlessBody = snake.body;
    headlessBody.pop_front();

    if (ElementInDeque(snake.body[0], headlessBody)) {
      GameOver();
    }
  }

  void GameOver() {
    snake.Reset();
    food.position = food.getRandomPos();
    running = false;
    if (score > High_Score)
      High_Score = score;
    score = 0;
    PlaySound(wall);
    // DrawText("!GAME OVER :)", 50, 50, 40, darkGreen);
  }
};

int main() {
  InitWindow(2 * offset + cellSize * cellCount,
             2 * offset + cellSize * cellCount, "SNAKE-GAME");
  InitAudioDevice();
  Music music = LoadMusicStream("Sound/music.mp3");
  PlayMusicStream(music);
  SetTargetFPS(90);

  Game game;

  while (!WindowShouldClose()) {
    // 1. Event handling
    UpdateMusicStream(music);
    // 2. Update positions
    if (eventTriggered(0.1)) {
      game.Update();
    }

    // snake movements
    if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1) {
      game.snake.direction = {0, -1};
      game.running = true;
    }
    if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1) {
      game.snake.direction = {0, 1};
      game.running = true;
    }
    if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1) {
      game.snake.direction = {-1, 0};
      game.running = true;
    }
    if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1) {
      game.snake.direction = {1, 0};
      game.running = true;
    }

    // 3. Drawing
    BeginDrawing();

    ClearBackground(green);
    game.Draw();
    DrawRectangleLinesEx(Rectangle{(float)offset - 5, (float)offset - 5,
                                   (float)cellSize * cellCount + 10,
                                   (float)cellSize * cellCount + 10},
                         5, darkGreen);
    DrawText("Snake", offset - 5, 20, 40, darkGreen);
    DrawText("Score", offset - 5, offset + cellSize * cellCount + 10, 40,
             darkGreen);
    DrawText(TextFormat("%i", game.score), 200,
             offset + cellSize * cellCount + 10, 40, darkGreen);
    DrawText("High Score", cellSize * cellCount - 170, 20, 40, darkGreen);
    DrawText(TextFormat("%i", game.High_Score),
             cellSize * cellCount + offset - 10, 20, 40, darkGreen);

    EndDrawing();
  }
  UnloadMusicStream(music);
  CloseAudioDevice();
  CloseWindow();
  return 0;
}