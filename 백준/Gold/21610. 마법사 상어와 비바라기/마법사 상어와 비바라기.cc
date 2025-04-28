#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

enum class Direction : uint16_t
{
    Left,
    LeftUp,
    Up,
    UpRight,
    Right,
    RightDown,
    Down,
    LeftDown
};

int N, M;
int MAP[55][55];
int SquareSize = 2;

vector<pair<int, int>> Cmd;
vector<pair<int, int>> Clouds;

void PrintMaps()
{
    cout << "Print Map" << "\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
}

void InitClouds()
{
    Clouds.push_back({N - 1, 0});
    Clouds.push_back({N - 1, 1});
    Clouds.push_back({N - 2, 0});
    Clouds.push_back({N - 2, 1});
}

void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        Cmd.push_back(make_pair(a, b));
    }
}

Direction CheckDirection(int dirNum)
{
    switch (dirNum)
    {
    case 1:
        return Direction::Left;
    case 2:
        return Direction::LeftUp;
    case 3:
        return Direction::Up;
    case 4:
        return Direction::UpRight;
    case 5:
        return Direction::Right;
    case 6:
        return Direction::RightDown;
    case 7:
        return Direction::Down;
    case 8:
        return Direction::LeftDown;
    default:
        return Direction::Up;
    }
}

void Move(Direction dir, int loop)
{
    for (auto &cp : Clouds)
    {
        for (int i = 0; i < loop; i++)
        {
            int x = cp.first;
            int y = cp.second;

            switch (dir)
            {
            case Direction::Left:
                if (y == 0)
                    cp.second = N - 1;
                else
                    cp.second--;
                break;

            case Direction::LeftUp:
                if (y == 0)
                    cp.second = N - 1;
                else
                    cp.second--;
                if (x == 0)
                    cp.first = N - 1;
                else
                    cp.first--;
                break;

            case Direction::Up:
                if (x == 0)
                    cp.first = N - 1;
                else
                    cp.first--;
                break;

            case Direction::UpRight:
                if (y == N - 1)
                    cp.second = 0;
                else
                    cp.second++;
                if (x == 0)
                    cp.first = N - 1;
                else
                    cp.first--;
                break;

            case Direction::Right:
                if (y == N - 1)
                    cp.second = 0;
                else
                    cp.second++;
                break;

            case Direction::RightDown:
                if (y == N - 1)
                    cp.second = 0;
                else
                    cp.second++;
                if (x == N - 1)
                    cp.first = 0;
                else
                    cp.first++;
                break;

            case Direction::Down:
                if (x == N - 1)
                    cp.first = 0;
                else
                    cp.first++;
                break;

            case Direction::LeftDown:
                if (y == 0)
                    cp.second = N - 1;
                else
                    cp.second--;
                if (x == N - 1)
                    cp.first = 0;
                else
                    cp.first++;
                break;

            default:
                break;
            }
        }
    }
}

void MakeRain()
{
    for (auto &cp : Clouds)
    {
        int x = cp.first;
        int y = cp.second;
        MAP[x][y]++;
    }
}

void DrainRain()
{
    for (auto &cp : Clouds)
    {
        int x = cp.first;
        int y = cp.second;

        int cnt = 0;

        int dx[4] = {-1, -1, 1, 1};
        int dy[4] = {-1, 1, 1, -1};

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N)
            {
                if (MAP[nx][ny] > 0)
                    cnt++;
            }
        }

        MAP[x][y] += cnt;
    }
}

void MakeCloud()
{
    vector<pair<int,int>> newClouds;

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    for (auto& cp : Clouds)
    {
        int x = cp.first;
        int y = cp.second;

        visited[x][y] = true;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j]) continue;
            if (MAP[i][j] >= 2)
            {
                MAP[i][j] -= 2;
                newClouds.push_back({i,j});
            }
        }
    }

    Clouds = newClouds;
}

void PrintSum()
{
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum += MAP[i][j];
        }
    }

    cout << sum << "\n";
}

void Execute()
{
    Direction dir;

    for (const auto SingleCmd : Cmd)
    {
        dir = CheckDirection(SingleCmd.first);
        Move(dir, SingleCmd.second);
        MakeRain();
        DrainRain();
        MakeCloud();
    }
}

int main()
{
    Input();
    InitClouds();
    Execute();
    PrintSum();

    return 0;
}