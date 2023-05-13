#pragma once
#include "SFML/Graphics.hpp"

const float WINDOW_WIDTH = 1920;
const float WINDOW_HEIGHT = 1080;
const std::string WINDOW_TITLE = "title";
const float FPS = 60.f;

const std::string PLAYER_FILE_NAME = "images\\crosshair.png";

const float ENEMY_WIDTH = 99.f;
const float ENEMY_HEIGHT = 75.f;
const size_t ENEMY_QTY = 3;

const int CHAR_SIZE = 32;
const float TEXT_OFFSET = 60.f;
const sf::Vector2f TEXT_START_POS{ WINDOW_WIDTH - TEXT_OFFSET, 0.f };