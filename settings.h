#pragma once
#include "SFML/Graphics.hpp"

const float WINDOW_WIDTH = 1920;
const float WINDOW_HEIGHT = 1080;
const std::string WINDOW_TITLE = "title";
const float FPS = 60.f;

const std::string PLAYER_FILE_NAME = "images\\crosshair.png";
const int START_HP = 100;
const size_t HP_DECREACE = 10;

const int SCORE_INCREACE_ENEMY_R = 150;
const int SCORE_INCREASE_ENEMY_G = 100;
const int SCORE_INCREACE_BOMB = 50;

const float ENEMY_WIDTH = 99.f;
const float ENEMY_HEIGHT = 75.f;
const size_t ENEMY_QTY_GREEN = 2;
const size_t ENEMY_QTY_RED = 3;
const float RIGHT_DEAD_ZONE = WINDOW_WIDTH - ENEMY_WIDTH;
const float DOWN_DEAD_ZONE = WINDOW_HEIGHT - ENEMY_HEIGHT;
const int SPEED_INCREACE_CD = 10;
//const float BOMB_POINT = WINDOW_WIDTH - (WINDOW_WIDTH / 2);

const float RED_START_SPEED_1 = 3;
const float RED_START_SPEED_2 = 1;
const float GREEN_START_SPEED_1 = 5;
const float GREEN_START_SPEED_2 = 2;

const int CHAR_SIZE = 32;
const float TEXT_OFFSET = 60.f;
const sf::Vector2f SCORETEXT_START_POS{ WINDOW_WIDTH / 2,0.f };
const sf::Vector2f TEXT_END_POS{ 1000, 1000 };
