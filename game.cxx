/// @file   game.cxx
/// @author Gael Zarco
/// @date   02-10-2026
/// @brief  Idk what game this is yet.

import <print>;
import <raylib.h>;

// =============================================================================
// ADT(S)
// =============================================================================
/// @brief Game state (0 = fail, 1 = win)
class Game {
public:
    /// @brief Represents game state explicitly
    enum class State {
        Menu,
        Play,
        Pause,
        Win,
        Fail
    };

    /// @brief Default parameterized constructor
    explicit Game(State state = State::Menu) : state_(state) {}

    /// @brief  State getter
    /// @return Game state
    State get_state(void) const noexcept { return state_; }
    /// @brief State setter
    void set_state(State state) { state_ = state; }

private:
    State state_;
};

/// @brief Network related methods
class Network {
public:
private:
};

// =============================================================================
// MAIN
// =============================================================================
constexpr const int SCREEN_WIDTH  = 1080;
constexpr const int SCREEN_HEIGHT = 720;
constexpr const int TARGET_FPS    = 144;

int main(void) {
    Game game{};

    std::print("[LOG] Game state: ");
    switch (game.get_state()) {
        case Game::State::Menu:
            std::println("Menu");
            break;
        case Game::State::Play:
            std::println("Play");
            break;
        case Game::State::Pause:
            std::println("Pause");
            break;
        case Game::State::Win:
            std::println("Win");
            break;
        case Game::State::Fail:
            std::println("Fail");
            break;
    }

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Multitet");
    InitAudioDevice();
    SetTargetFPS(TARGET_FPS);

    while (!WindowShouldClose()) {
    }

    CloseWindow();

    return 0;
}

// EOF game.cxx
