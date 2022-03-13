#include <iostream>
using namespace std;

#pragma region TOOL

enum JOB        { WARRIOR = 1, MAGE, ACHER };
enum PROCESS    { NONE, MAIN, VILLAGE, HUNT, INVEN, LOGOUT, COUNT = LOGOUT};
enum ITEMTYPE   { _CONSUM, _WEAPON, _ARMOR };
enum POTION     { S, M, L, V };
enum ARMOR      { AA = 100, AB, AC };
enum WEAPON     { WA = 200, WB, WC };

bool ChackRange(int _iValue, int _iMin, int _iMax)
{
    if (_iMin > _iValue || _iMax < _iValue)
        return false;
    return true;
}

#pragma endregion

#pragma region STRUCTPRE

typedef struct Player p;
typedef struct Inventory i;
typedef struct EquipmentInven e;

#pragma endregions

#pragma region Managers

struct GameManager
{
    Player* player = nullptr;
    Inventory* inven = nullptr;
    EquipmentInven* equip = nullptr;

    PROCESS process = NONE;
    PROCESS preProcess = NONE;

    void SetPlayer(Player* _player)
    {
        if (player != nullptr)
            delete player;

        player = _player;
    }

    void MoveProcess(PROCESS _pro) {
        preProcess = process;
        process = _pro;
    }
    void MovePreProcess() {
        PROCESS temp = process;
        process = preProcess;
        preProcess = temp;
    }

    void DeleteManager()
    {
        delete player;
    }
};

GameManager manager = { };

#pragma endregion


#pragma region STRUCT

struct StatData
{
    JOB job;
    int iLevel;
    int iExp;
    int iMaxHp;
    int iHp;
    int iAt;
    int iDf;

};
struct EquipmentInven
{
    int iAt = 0;
    int iDf = 0;
};

struct Player
{
    const char* pJobStr;
    StatData statData;

    void Init(int _iMaxHp, int _iAt)
    {
        statData.iLevel = 1;
        statData.iExp = 0;
        statData.iMaxHp = _iMaxHp;
        statData.iHp = statData.iMaxHp;
        statData.iAt = _iAt;
        statData.iDf = 0;
    }
    void SetJob(JOB _j)
    {
        statData.job = _j;

        switch (_j)
        {
        case WARRIOR: pJobStr = "전사";       break;

        case MAGE:    pJobStr = "마법사";     break;

        case ACHER:   pJobStr = "궁수";       break;
        }
    }
    void GetExp(int _exp)
    {
        statData.iExp += _exp;
        if (statData.iExp >= statData.iLevel * statData.iLevel)
            ++statData.iLevel;
    }
    void GetHp(int _ivalue)
    {
        statData.iHp += _ivalue;
        if (statData.iHp > statData.iMaxHp)
            statData.iHp = statData.iMaxHp;
    }

    int GetTotalAt() { return statData.iAt + manager.equip->iAt; }
    int GetTotalDf() { return statData.iDf + manager.equip->iDf; }

    void PrintInfo()
    {
        cout << "=============== PlayerInfo ===============" << endl;
        cout << "직업: " << pJobStr << "  공격력: " << GetTotalAt() << "(+" << manager.equip->iAt << ")" << "  방어력: " << GetTotalDf() << "(+" << manager.equip->iDf << ")" << "  체력: " << statData.iHp << "/" << statData.iMaxHp << endl;
        cout << "레벨: " << statData.iLevel << "  경험치: " << statData.iExp << "/" << statData.iLevel * 10 << endl;
    }
    void ChackRevival()
    {
        if (statData.iHp <= 0)
            statData.iHp = statData.iMaxHp;
    }
};
struct Monster
{
    const char* pNameStr;
    int iMaxHp;
    int iHp;
    int iAt;
    int iExp;
    int iItemId = 0;

    void Init(int _iMaxHp, int _iAt, int _iExp, const char* _pNameStr, int _iItemId)
    {
        iMaxHp = _iMaxHp;
        iHp = iMaxHp;
        iAt = _iAt;
        pNameStr = _pNameStr;
        iExp = _iExp;
        iItemId = _iItemId;
    }
    void PrintInfo()
    {
        cout << "=============== " << pNameStr << " ===============" << endl;
        cout << "공격력: " << iAt << "  체력: " << iHp << "/" << iMaxHp << endl;
    }
    bool Attack(Player* _player)
    {
        _player->statData.iHp -= iAt;
        if (_player->statData.iHp <= 0)
            return true;
        return false;
    }
};

struct Item
{
    ITEMTYPE itemType;
    int iId;
    bool bCanStore;
    int iCount;
    const char* cName;

    virtual bool Use()
    {
        return false;
    }

    virtual void PrintInfo()
    {

    }
};

struct Cunsum : Item
{

    virtual bool Use()
    {
        iCount--;
        return true;
    }
    virtual void PrintInfo()
    {

    }
};
struct HpPotion : Cunsum
{
    int iRecorvValue;

    void MakePotion(POTION _iSize, int _iCount)
    {
        itemType = _CONSUM;
        bCanStore = true;
        iCount = _iCount;

        switch (_iSize)
        {
        case S: iId = S; iRecorvValue = 5;   cName = "빨간 포션(소)";
            break;
        case M: iId = M; iRecorvValue = 10;  cName = "빨간 포션(중)";
            break;
        case L: iId = L; iRecorvValue = 20;  cName = "빨간 포션(대)";
            break;
        case V: iId = V; iRecorvValue = 40;  cName = "빨간 포션(왕)";
            break;
        }
    }
    virtual bool Use()
    {
        if (iCount <= 0)
            return false;

        --iCount;
        manager.player->GetHp(iRecorvValue);

        if (iCount <= 0)
            return false;

        return true;
    }
    virtual void PrintInfo()
    {
        cout << cName << " x" << iCount << "개" << endl;
    }

};

struct Equipment : Item
{
    bool isEquiped;

    virtual bool Use()
    {
        return true;
    }
    virtual void PrintInfo()
    {

    }
};

struct Inventory
{
    Item* Items[10] = {};
    int iMaxPointer = 0;

    void GetItem(Item* _item)
    {
        // 뭉쳐지는 아이템이 있는지 확인
        if (_item->bCanStore)
        {
            for (int i = 0; i < iMaxPointer; i++)
            {
                if (Items[i]->iId == _item->iId)
                {
                    Items[i]->iCount += _item->iCount;
                    return;
                }
            }
        }

        // 없으면 인벤 크기 확인
        if (iMaxPointer > 9)
        {
            cout << "소지품이 가득 찻습니다!" << endl;
            system("pause");
            return;
        }

        // 아이템 추가
        Items[iMaxPointer++] = _item;
    }
    void UseItem(int _iIndex)
    {
        --_iIndex;

        if (_iIndex < 0 || _iIndex >= iMaxPointer)
        {
            cout << "해당 슬롯은 비어있습니다." << endl;
            system("pause");
            return;
        }

        if (!Items[_iIndex]->Use())    // false면 전부 소진
        {
            if (Items[_iIndex]->itemType == _CONSUM)    // 포션일 때
            {
                for (int i = _iIndex; i < iMaxPointer; i++)
                {
                    Items[i] = Items[i + 1];
                }
                --iMaxPointer;
                cout << "아이템을 사용했습니다!" << endl;
                system("pause");
                return;
            }
            else                                        // 장비일 때
            {
                // 아이템 착용 불가
                cout << "착용이 불가능 합니다." << endl;
                system("pause");
                return;
            }

        }

        if (Items[_iIndex]->itemType == _CONSUM)
            cout << "아이템을 사용했습니다!" << endl;
        else
            cout << "아이템을 착용했습니다!" << endl;
        system("pause");
    }
    void OpenInven()
    {
        int iInput = 0;

        do
        {
            system("cls");
            cout << "======== " << "가방" << " ========" << endl;
            for (int i = 0; i < iMaxPointer; i++)
            {
                cout << "[" << i + 1 << "] ";
                Items[i]->PrintInfo();
            }
            cout << "====================" << endl;
            cout << "1.아이템 사용   2.가방 닫기 >> ";
            cin >> iInput;

            switch (iInput)
            {
            case 1:
                UsingItem();
                break;
            case 2:
                manager.MovePreProcess();
                return;
            default:
                cout << "다시 입력해 주세요." << endl;
                system("pause");
                continue;
            }

        } while (true);

    }
    void UsingItem()
    {
        int iInput = 0;

        system("cls");
        cout << "======== " << "가방" << " ========" << endl;
        for (int i = 0; i < iMaxPointer; i++)
        {
            cout << "[" << i + 1 << "] ";
            Items[i]->PrintInfo();
        }
        cout << "==================================" << endl;
        cout << "몇 번째 아이템을 사용할까요? >> ";
        cin >> iInput;

        UseItem(iInput);
    }
    int CheckEquipItem(ITEMTYPE type)
    {
        for (int i = 0; i < iMaxPointer; i++)
        {
            if (Items[i]->itemType == type && Items[i])
            {
                Equipment* ep = (Equipment*)Items[i];
                if (ep->isEquiped) return i;
            }
        }
        return -1;
    }

    void DeleteItem()
    {
        for (int i = 0; i < 10; i++)
            delete Items[i];
        delete[] Items;
    }

};

struct Armor : Equipment
{
    int iAt;

    void MakeArmor(ARMOR _rare)
    {
        itemType = _ARMOR;
        bCanStore = false;
        isEquiped = false;

        switch (_rare)
        {
        case AA: iId = AA; iAt = 5;   cName = "나무 검";
            break;
        case AB: iId = AB; iAt = 10;   cName = "철 검";
            break;
        case AC: iId = AC; iAt = 20;   cName = "금 검";
            break;
        }
    }
    virtual bool Use()
    {
        // 같은 종류의 아이템을 착용 여부
        int index = manager.inven->CheckEquipItem(itemType);
        if (index != -1)  // 있다!
        {
            Item* tem = manager.inven->Items[index];
            ((Equipment*)tem)->isEquiped = false;
        }

        manager.equip->iAt = iAt;
        isEquiped = true;
        return true;
    }
    virtual void PrintInfo()
    {
        cout << cName << (isEquiped ? "  [착용 중]" : " ") << endl;
    }

};
struct Weapon : Equipment
{
    int iDf;

    void MakeWeapon(WEAPON _rare)
    {
        itemType = _WEAPON;
        bCanStore = false;
        isEquiped = false;

        switch (_rare)
        {
        case WA: iId = WA; iDf = 5;   cName = "천 갑옷";
            break;
        case WB: iId = WB; iDf = 10;   cName = "철 갑옷";
            break;
        case WC: iId = WC; iDf = 20;   cName = "금 갑옷";
            break;
        }
    }
    virtual bool Use()
    {
        // 같은 종류의 아이템을 착용 여부
        int index = manager.inven->CheckEquipItem(itemType);
        if (index != -1)  // 있다!
        {
            Item* tem = manager.inven->Items[index];
            ((Equipment*)tem)->isEquiped = false;
        }

        manager.equip->iDf = iDf;
        isEquiped = true;
        return true;
    }
    virtual void PrintInfo()
    {
        cout << cName << (isEquiped ? "  [착용 중]" : " ") << endl;
    }
};


#pragma endregion


#pragma region FUNC

bool ReadFileData();
bool SaveFileData(const Player*);

Player* MakePlayer();
Monster* MakeMonster();

void ShowMainMenu();
void ShowVillageMenu(Player*);

void GoToHunt(Player*);
bool AttackAtoB(Player*, Monster*);
bool AttackAtoB(Monster*, Player*);

void GetItem(int, int = 0);

#pragma endregion







void main()
{
    manager.process = MAIN;
    manager.inven = new Inventory();
    manager.equip = new EquipmentInven();

    cout << "텍스트 알피지!" << endl;
    system("pause");
    system("cls");    

    while (true)
    {
        switch (manager.process)
        {
        case MAIN:                                   // 시작 메뉴
            ShowMainMenu();
            break;
        case VILLAGE:                                // 마을
            ShowVillageMenu(manager.player);
            break;
        case HUNT:                                   // 사냥
            GoToHunt(manager.player);
            manager.player->ChackRevival();
            break;
        case INVEN:                                  // 가방
            manager.inven->OpenInven();
            break;
        case LOGOUT:                                 // 로그아웃
            cout << "월드를 떠납니다..." << endl;
            return;
        }
    }

    manager.DeleteManager();
    manager.inven->DeleteItem();
    delete manager.inven;
    delete manager.equip;
}









#pragma region FuncDef

bool ReadFileData()
{
    StatData data = {};

    FILE* pFile = nullptr;
    errno_t err = fopen_s(&pFile, "../Data/SaveFile.txt", "rb");  // 상대 경로 vcx 한 칸 뒤로

    if (0 == err)
    {
        fread(&data, sizeof(StatData), 1, pFile);

        fclose(pFile);

        if (data.iAt == 0)
        {
            cout << "저장된 데이터가 없거나, 불러오는 과정에서 오류가 있습니다!" << endl;
            system("pause");
            return false;
        }

        manager.SetPlayer(new Player());
        manager.player->statData = data;
        manager.player->SetJob(data.job);

        cout << "불러오기 성공!" << endl;
        system("pause");
        manager.MoveProcess(VILLAGE);
        return true;
    }

    cout << "저장한 데이터가 없거나, 불러오는 과정에서 오류가 있습니다!" << endl;
    system("pause");
    return false;
}
bool SaveFileData()
{
    if (manager.player == nullptr)
    {
        cout << "저장할 데이터가 없습니다." << endl;
        system("pause");
        manager.MoveProcess(MAIN);
        return false;
    }

    FILE* pFile = nullptr;
    errno_t err = fopen_s(&pFile, "../Data/SaveFile.txt", "wb");  // 상대 경로 vcx 한 칸 뒤로

    if (0 == err)
    {
        fwrite(&(manager.player->statData), sizeof(StatData), 1, pFile);

        fclose(pFile);

        cout << "저장 성공!" << endl;
        system("pause");
        manager.MoveProcess(MAIN);
        return true;
    }

    cout << "저장 과정에서 이상이 있습니다. 그냥 즐기다가 캐릭터 버리세요!" << endl;
    system("pause");
    manager.MoveProcess(MAIN);

    return false;
}

Player* MakePlayer()
{
    Player* player = new Player();
    int iInput = 0;

    do
    {
        system("cls");
        cout << "===== 캐릭터 생성 =====" << endl;
        cout << "1.전사  2.마법사  3.궁수  >> ";
        cin >> iInput;

        switch (iInput)
        {
        case WARRIOR:
            player->Init(200, 5);
            player->SetJob(WARRIOR);
            break;
        case MAGE:
            player->Init(100, 10);
            player->SetJob(MAGE);
            break;
        case ACHER:
            player->Init(50, 15);
            player->SetJob(ACHER);
            break;
        default:
            cout << "다시 입력해 주세요." << endl;
            system("pause");
            continue;
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
        cout << "1.주황버섯  2.뿔버섯  3.머쉬맘  4.전 단계  >> ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            monster->Init(5, 1, 1, "주황버섯", 0);
            break;
        case 2:
            monster->Init(20, 5, 5, "뿔버섯", 1);
            break;
        case 3:
            monster->Init(50, 10, 20, "머쉬맘", 2);
            break;
        case 4:
            manager.MovePreProcess();
            delete monster;
            monster = nullptr; 
            break;
        default:
            cout << "다시 입력해 주세요." << endl;
            system("pause");
            continue;
        }

        break;

    } while (true);

    return monster;
}

void ShowMainMenu()
{
    int iInput = 0;

    do
    {
        system("cls");

        cout << "=============================메뉴 창=============================" << endl;
        cout << "1.캐릭터 생성  2.저장하기  3.불러오기  4.게임입장  5.게임종료 >> ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            manager.SetPlayer(MakePlayer());
            manager.MoveProcess(VILLAGE);
            break;
        case 2: 
            SaveFileData();
            break;
        case 3: 
            ReadFileData();
            break;
        case 4:
            if(manager.player != nullptr)
                manager.MoveProcess(VILLAGE);
            else {
                cout << "캐릭터를 먼저 생성해 주세요!" << endl;
                system("pause");
                continue;
            }
            break;
        case 5: 
            manager.MoveProcess(LOGOUT); 
            break;
        default:
            cout << "다시 입력해 주세요." << endl;
            system("pause");
            continue;
        }

        break;

    } while (true);

}
void ShowVillageMenu(Player* p)
{
    int iInput = 0;
    do
    {
        system("cls");

        p->PrintInfo();
        cout << "1.사냥  2.가방  3.메뉴 >> ";
        cin >> iInput;

        switch (iInput)
        {
        case 1: manager.MoveProcess(HUNT); break;
        case 2: manager.MoveProcess(INVEN); break;
        case 3: manager.MoveProcess(MAIN); break;
        default:
            cout << "다시 입력해 주세요." << endl;
            system("pause");
            continue;
        }

        break;

    } while (true);
}

void GoToHunt(Player* player)
{
    int iInput = 0;
    Monster* monster = MakeMonster();

    do
    {
        if (monster == nullptr)
            break;

        system("cls");
        player->PrintInfo();
        monster->PrintInfo();
        cout << "1.공격  2.(마을로)도망 >> ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            if (AttackAtoB(player, monster))
            {
                player->GetExp(monster->iExp);  // 경험치 보상

                GetItem(monster->iItemId, 1);
                GetItem(monster->iItemId + 100);
                GetItem(monster->iItemId + 200);

                system("cls");
                cout << "승리!" << endl;
                cout << "마을로 돌아갑니다." << endl;
                system("pause");
                manager.MoveProcess(VILLAGE);
                break;
            }
            else if (AttackAtoB(monster, player))
            {
                system("cls");
                cout << "패배..." << endl;
                cout << "마을로 돌아갑니다." << endl;
                system("pause");
                manager.MoveProcess(VILLAGE);
                break;
            }
            continue;
        case 2:
            cout << "마을로 도망갑니다!" << endl;
            system("pause");
            manager.MoveProcess(VILLAGE);
            break;
        case 3:
            manager.MovePreProcess();
            break;
        default:
            cout << "다시 입력해 주세요." << endl;
            system("pause");
            continue;
        }

        break;

    } while (true);

    delete monster;
    monster = nullptr;
}
bool AttackAtoB(Player* player, Monster* monster)
{
    monster->iHp -= player->GetTotalAt();
    if (monster->iHp <= 0)
        return true;
    return false;
}
bool AttackAtoB(Monster* monster, Player* player)
{
    player->statData.iHp -= ((monster->iAt - player->GetTotalDf()) < 0 ? 0 : (monster->iAt - player->GetTotalDf()));
    if (player->statData.iHp <= 0)
        return true;
    return false;
}

void GetItem(int _iId, int _iCount)
{
    if (0 <= _iId &&  100 > _iId)
    {
        HpPotion* po = new HpPotion();
        po->MakePotion((POTION)_iId, _iCount);
        manager.inven->GetItem(po);
    }    
    else if (100 <= _iId && 200 > _iId)
    {
        Armor* po = new Armor();
        po->MakeArmor((ARMOR)_iId);
        manager.inven->GetItem(po);
    }
    else if (200 <= _iId && 300 > _iId)
    {
        Weapon* po = new Weapon();
        po->MakeWeapon((WEAPON)_iId);
        manager.inven->GetItem(po);
    }

}

#pragma endregion