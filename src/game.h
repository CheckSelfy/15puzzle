#pragma once

#include <array>
#include <numeric>
#include <algorithm>
#include <random>

class Game {
public:
    static constexpr int HEIGHT = 4;
    static constexpr int WIDTH = 4;
    using int_t = int32_t;

private:
    std::array<int_t, HEIGHT * WIDTH> data{}; // cell with number 0 is pointer of user
    int_t zero_tile = 0;
    std::size_t moves = 0;

public:
    using data_t = decltype(data);

private:
    template<class Pred>
    void move_tile(Pred &&pred, int delta) {
        if (pred()) {
            std::swap(data[zero_tile], data[zero_tile + delta]);
            zero_tile += delta;
            moves++;
        }
    }

public:
    explicit Game();

    [[nodiscard]] data_t const &get_data() const;

    bool is_running();

    void move_left();

    void move_right();

    void move_up();

    void move_down();

    [[nodiscard]] decltype(moves) get_moves() const;

};
