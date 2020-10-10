#include <BearLibTerminal.h>

class Controls
{
private:
    bool is_exit = false;
    bool is_up = false;
    bool is_down = false;
    bool is_right = false;
    bool is_left = false;
public:
    bool Is_Exit() const {return is_exit;}
    bool Is_Up() const {return is_up;}
    bool Is_Down() const {return is_down;}
    bool Is_Right() const {return is_right;}
    bool Is_Left() const {return is_left;}
    void Update()
    {
        is_exit = false;
        is_up = false;
        is_down = false;
        is_right = false;
        is_left = false;

        while(terminal_has_input())
        {
            auto event = terminal_read();

            if(event == TK_UP)
                is_up = true;

            if(event == TK_DOWN)
                is_down = true;

            if(event == TK_RIGHT)
                is_right = true;

            if(event == TK_LEFT)
                is_left = true;

            if(event == TK_CLOSE)
                is_exit = true;
        }
    }
};

class Ground
{
private:
    int ground_x = 80;
    int ground_y = 25;
public:
    int Ground_X() const {return ground_x;}
    int Ground_Y() const {return ground_y;}
};

class Player
{
private:
    const Ground &ground;
    const Controls &control;
    float player_x;
    float player_y;
    char symbol = '@';
public:
    Player(Controls &control, Ground &ground, float x = 0, float y = 0): control(control), ground(ground), player_x(x), player_y(y) {}
    void Render() const {terminal_put(player_x, player_y, symbol);}
    void Update() {Move(); Render();}
    void Move()
    {
        if(control.Is_Up() && player_y>0)
            player_y-=1;
        if(control.Is_Down() && player_y<ground.Ground_Y()-1)
            player_y+=1;
        if(control.Is_Left() && player_x>0)
            player_x-=1;
        if(control.Is_Right() && player_x<ground.Ground_X()-1)
            player_x+=1;
    }
};

int main()
{
    terminal_open();
    terminal_refresh();

    Ground ground;
    Controls controls;
    Player player(controls, ground);

    while(true)
    {
        terminal_clear();

        controls.Update();

        if(controls.Is_Exit())
            break;

        player.Update();

        terminal_refresh();
    }
    terminal_close();
}