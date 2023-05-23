#pragma once
#include "SFML/Graphics.hpp"

const float WINDOW_WIDTH = 1920;
const float WINDOW_HEIGHT = 1080;
const std::string WINDOW_TITLE = "title";
const float FPS = 75.f;

const std::string PLAYER_FILE_NAME = "images\\crosshair.png";

const float ENEMY_WIDTH = 99.f;
const float ENEMY_HEIGHT = 75.f;
const size_t ENEMY_QTY_GREEN = 2;
const size_t ENEMY_QTY_RED = 3;
const size_t ENEMY_TYPE_QTY = 1;
const float RIGHT_DEAD_ZONE = WINDOW_WIDTH - ENEMY_WIDTH;
const float DOWN_DEAD_ZONE = WINDOW_HEIGHT - ENEMY_HEIGHT;

const int CHAR_SIZE = 32;
const float TEXT_OFFSET = 60.f;
const sf::Vector2f TEXT_START_POS{ WINDOW_WIDTH - TEXT_OFFSET, 0.f };
