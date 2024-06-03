#include <ncurses.h>
#include "game.h"

namespace {
    void draw_line() {
        int cols = getcurx(stdscr);
        int rows = getcury(stdscr);

        for (int cell = 0; cell < Game::WIDTH; cell++) {
            addch('+');
            for (int wall = 0; wall < 3; wall++) {
                addch('-');
            }
        }
        addch('+');

        move(rows + 1, cols);
    }

    void draw_empty() {
        int cols = getcurx(stdscr);
        int rows = getcury(stdscr);

        for (int cell = 0; cell < Game::WIDTH; cell++) {
            addch('|');
            for (int wall = 0; wall < 3; wall++) {
                addch(' ');
            }
        }
        addch('|');

        move(rows + 1, cols);
    }

    void draw_numbers(Game::data_t const &data, std::size_t shift) {
        int cols = getcurx(stdscr);
        int rows = getcury(stdscr);

        for (int cell = 0; cell < Game::WIDTH; cell++) {
            addch('|');
            addch(' ');
            int k = data[shift + cell];

            if (k > 9) k += 'A' - 10;
            else if (k > 0) k += '0';
            else k = ' ';

            addch(k);
            addch(' ');
        }
        addch('|');

        move(rows + 1, cols);
    }

    void draw(Game const &game) {
        clear();
        mvprintw(0, 0, "Moves: %zu", game.get_moves());
        int tty_cols = getmaxx(stdscr);
        int tty_rows = getmaxy(stdscr);

        int center_row = tty_rows / 2;
        int center_col = tty_cols / 2;

        int width = Game::WIDTH * 4 + 1;
        int height = Game::HEIGHT * 4 + 1;

        int start_row = center_row - width / 2;
        int start_col = center_col - height / 2;

        move(start_row, start_col);

        for (int i = 0; i < Game::HEIGHT; i++) {
            draw_line();
            draw_empty();
            draw_numbers(game.get_data(), i * Game::WIDTH);
            draw_empty();
        }
        draw_line();
    }

}

int main() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    Game game;

    draw(game);

    int key = ' ';

    while (game.is_running() && key) {
        key = getch();
        if (key == KEY_UP) game.move_up();
        else if (key == KEY_LEFT) game.move_left();
        else if (key == KEY_RIGHT) game.move_right();
        else if (key == KEY_DOWN) game.move_down();

        draw(game);
    }

    endwin();

    printf("You won! Moves: %zu", game.get_moves());

    return 0;
}
