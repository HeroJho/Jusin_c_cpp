#include <iostream>
using namespace std;

#pragma region TOOL

enum JOB { WARRIOR = 1, MAGE, ACHER };

bool ChackRange(int _iValue, int _iMin, int _iMax)
{
    if (_iMin > _iValue || _iMax < _iValue)
        return false;
    return true;
}

#pragma endregion

#pragma region STRUCT

struct Player
{
    JOB job;
    const char* pJobStr;
    int iMaxHp;
    int iHp;
    int iAt;

    void Init(int _iMaxHp, int _iAt, const char* _pJobStr)
    {
        iMaxHp = _iMaxHp;
        iHp = iMaxHp;
        iAt = _iAt;
        pJobStr = _pJobStr;
    }
    void PrintInfo()
    {
        cout << "=============== PlayerInfo ===============" << endl;
        cout << "직업: " << pJobStr << "  공격력: " << iAt << "  체력: " << iHp << "/" << iMaxHp << endl;
    }
    void ChackRevival()
    {
        if (iHp <= 0)
            iHp = iMaxHp;
    }
};
struct Monster
{
    const char* pNameStr;
    int iMaxHp;
    int iHp;
    int iAt;

    void Init(int _iMaxHp, int _iAt, const char* _pNameStr)
    {
        iMaxHp = _iMaxHp;
        iHp = iMaxHp;
        iAt = _iAt;
        pNameStr = _pNameStr;
    }
    void PrintInfo()
    {
        cout << "=============== PlayerInfo ===============" << endl;
        cout << "이름: " << pNameStr << "  공격력: " << iAt << "  체력: " << iHp << "/" << iMaxHp << endl;
    }
    bool Attack(Player* _player)
    {
        _player->iHp -= iAt;
        if (_player->iHp <= 0)
            return true;
        return false;
    }
};

#pragma endregion

#pragma region FUNC

Player* MakePlayer();
Monster* MakeMonster();

int ShowVillageMenu(Player*);
void GoToHunt(Player*);
bool AttackAtoB(Player*, Monster*);
bool AttackAtoB(Monster*, Player*);

#pragma endregion

void main()
{
    int iInput = 0;
    Player* player = nullptr;

    cout << "텍스트 알피지!" << endl;
    system("pause");
    system("cls");
    
    player = MakePlayer();                          // 캐릭터 생성

    while (true)
    {
        iInput = ShowVillageMenu(player);           // 메뉴

        switch (iInput)
        {
        case 1:                                     // 사냥
            GoToHunt(player);
            player->ChackRevival();
            break;
        case 2:                                     // 로그아웃
            cout << "월드를 떠납니다..." << endl;
            return;
        }
    }

    delete player;
    player = nullptr;
}






#pragma region FuncDef

Player* MakePlayer()
{
    Player* player = new Player;
    int iInput = 0;

    do
    {
        system("cls");
        cout << "===== 캐릭터 생성 =====" << endl;
        cout << "1.전사  2.마법사  3.궁수  >> ";
        cin >> iInput;

        if (!ChackRange(iInput, 1, 3))
        {
            cout << "다시 입력해 주세요." << endl;
            system("pause");
            continue;
        }

        player->job = (JOB)iInput;

        switch (player->job)
        {
        case WARRIOR:
            player->Init(200, 5, "전사");
            break;
        case MAGE:
            player->Init(100, 10, "마법사");
            break;
        case ACHER:
            player->Init(50, 15, "궁수");
            break;
        }
        break;

    } while (true);

    return player;
}
Monster* MakeMonster()
{
    Monster* monster = new Monster;
    int iInput = 0;

    do
    {
        system("cls");
        cout << "===== 몬스터 선택 =====" << endl;
        cout << "1.주황버섯  2.뿔버섯  3.머쉬맘  >> ";
        cin >> iInput;

        if (!ChackRange(iInput, 1, 3))
        {
            cout << "다시 입력해 주세요." << endl;
            system("pause");
            continue;
        }

        switch (iInput)
        {
        case 1:
            monster->Init(5, 1, "주황버섯");
            break;
        case 2:
            monster->Init(20, 5, "뿔버섯");
            break;
        case 3:
            monster->Init(100, 10, "머쉬맘");
            break;
        }
        break;

    } while (true);

    return monster;
}
int ShowVillageMenu(Player* p)
{

    int iInput = 0;
    do
    {
        system("cls");

        p->PrintInfo();
        cout << "1.사냥  2.종료 >> ";
        cin >> iInput;

        if (!ChackRange(iInput, 1, 2))
        {
            cout << "다시 입력해 주세요." << endl;
            system("pause");
            continue;
        }

        break;

    } while (true);

    return iInput;
}
void GoToHunt(Player* player)
{
    int iInput = 0;
    bool isEsc = false;
    Monster* monster = MakeMonster();

    do
    {
        system("cls");
        player->PrintInfo();
        monster->PrintInfo();
        cout << "1.공격  2.도망 >> ";
        cin >> iInput;

        if (!ChackRange(iInput, 1, 2))
        {
            cout << "다시 입력해 주세요." << endl;
            system("pause");
            continue;
        }

        switch (iInput)
        {
        case 1:
            if (AttackAtoB(player, monster))
            {
                system("cls");
                cout << "승리!" << endl;
                cout << "마을로 돌아갑니다." << endl;
                system("pause");
                isEsc = true;
            }
            else if (AttackAtoB(monster, player))
            {
                system("cls");
                cout << "패배..." << endl;
                cout << "마을로 돌아갑니다." << endl;
                system("pause");
                isEsc = true;
            }
            break;
        case 2:
            cout << "도망갑니다!" << endl;
            isEsc = true;
            break;
        }

        if (isEsc)
            break;

    } while (true);

    delete monster;
    monster = nullptr;
}
bool AttackAtoB(Player* player, Monster* monster)
{
    monster->iHp -= player->iAt;
    if (monster->iHp <= 0)
        return true;
    return false;
}
bool AttackAtoB(Monster* monster, Player* player)
{
    player->iHp -= monster->iAt;
    if (player->iHp <= 0)
        return true;
    return false;
}

#pragma endregion