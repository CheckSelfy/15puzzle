#include "game.h"

Game::Game() {
    static std::mt19937 mt = std::mt19937{std::random_device{}()};
    std::iota(data.begin(), data.end() - 1, 1);
    data[15] = 0;
    zero_tile = 15;
    for (int i = 0; i < 1000; i++) {
        auto next_move = mt() % 4;
        if (next_move == 0) { move_left(); }
        if (next_move == 1) { move_right(); }
        if (next_move == 2) { move_up(); }
        if (next_move == 3) { move_down(); }
    }

    while (zero_tile > WIDTH) move_up();
    while (zero_tile > 0) move_left();
    moves = 0;
}

Game::data_t const &Game::get_data() const {
    return data;
}

bool Game::is_running() {
    if (zero_tile != WIDTH * HEIGHT - 1) { return true; }
    for (int i = 0; i < WIDTH * HEIGHT - 1; i++) {
        if (data[i] != i + 1) {
            return true;
        }
    }
    return false;
}

void Game::move_left() {
    move_tile([this]() { return this->zero_tile % WIDTH != 0; }, -1);
}

void Game::move_right() {
    move_tile([this]() { return this->zero_tile % WIDTH != WIDTH - 1; }, 1);
}

void Game::move_up() {
    move_tile([this]() { return this->zero_tile >= WIDTH; }, -WIDTH);
}

void Game::move_down() {
    move_tile([this]() { return this->zero_tile < WIDTH * (HEIGHT - 1); }, WIDTH);
}

decltype(std::declval<Game>().moves) Game::get_moves() const {
    return moves;
}
