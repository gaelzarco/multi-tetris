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
    explicit Game(State state = State::Menu) : m_state(state) {}

    /// @brief  State getter
    /// @return Game state
    State get_state(void) const noexcept { return m_state; }
    /// @brief State setter
    void set_state(State state) { m_state = state; }

private:
    State m_state;
};

/// @brief Network related methods
class Network {
public:
private:
};

// =============================================================================
// ENTRY-POINT
// =============================================================================
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

    return 0;
}

// EOF game.cxx
