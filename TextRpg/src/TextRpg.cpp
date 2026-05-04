#include <iostream>
#include <vector>

#include "Warrior.h"
#include "Rogue.h"
#include "Mage.h"
#include "Archer.h"
#include "PotionIngredient.h"
#include "PotionRecipe.h"
#include "RPGConst.h"
#include "Slime.h"

using namespace std;

void statusInit(vector<int>& potions, int* stat) {
    while (true) {
        cout << RPGConst::Message::InitSystem::INPUT_HP_MP;
        cin >> stat[RPGConst::Status::HEALTH_POINT] >> stat[RPGConst::Status::MANA_POINT];
        if (stat[RPGConst::Status::HEALTH_POINT] > 50 && stat[RPGConst::Status::MANA_POINT] > 50)   break;
        cout << RPGConst::Message::InitSystem::LOW_HP_MP;
    }
    while (true) {
        cout << RPGConst::Message::InitSystem::INPUT_ATK_DEP;
        cin >> stat[RPGConst::Status::ATTACK_POINT] >> stat[RPGConst::Status::DEFENSE_POINT];
        if (stat[RPGConst::Status::ATTACK_POINT] > 50 && stat[RPGConst::Status::DEFENSE_POINT] > 50)   break;
        cout << RPGConst::Message::InitSystem::LOW_ATK_DEP;
    }
    
    printf("* You received %d HP Potions and %d MP Potions.\n", RPGConst::Init::HEALTH_POTION, RPGConst::Init::MANA_POTION);
    
    int choice = 1;
    while (choice > 0 && choice < 6) {
        cout << RPGConst::Message::InitSystem::START_MENU;
        cin >> choice;
        
        switch (choice) {
            case 1:
                if (potions[RPGConst::Potion::HEALTH_POTION] > 0) {
                    stat[RPGConst::Status::HEALTH_POINT] += 20;
                    printf(RPGConst::Message::InitSystem::HP_UP, --potions[RPGConst::Potion::HEALTH_POTION]);
                }else 
                    cout << RPGConst::Message::InitSystem::NOT_ENOUGH_HEALTH_POTION;
                break;
            case 2: 
                if (potions[RPGConst::Potion::MANA_POTION] > 0) {
                    stat[RPGConst::Status::MANA_POINT] += 20;
                    printf(RPGConst::Message::InitSystem::MP_UP, --potions[RPGConst::Potion::MANA_POTION]);
                }else 
                    cout << RPGConst::Message::InitSystem::NOT_ENOUGH_MANA_POTION; 
                break;
            case 3: 
                stat[RPGConst::Status::ATTACK_POINT] *= 2;
                printf(RPGConst::Message::InitSystem::DOUBLE_ATK, stat[RPGConst::Status::ATTACK_POINT]);
                break;
            case 4: 
                stat[RPGConst::Status::DEFENSE_POINT] *= 2;
                printf(RPGConst::Message::InitSystem::DOUBLE_DEF, stat[RPGConst::Status::DEFENSE_POINT]);
                break;
            case 5:
                printf(RPGConst::Message::InitSystem::CURRENT_STATUS, stat[RPGConst::Status::HEALTH_POINT] , stat[RPGConst::Status::MANA_POINT], stat[RPGConst::Status::ATTACK_POINT], stat[RPGConst::Status::DEFENSE_POINT]);
                break;
            case 0:
                printf(RPGConst::Message::InitSystem::START_GAME, stat[RPGConst::Status::HEALTH_POINT], stat[RPGConst::Status::MANA_POINT], stat[RPGConst::Status::ATTACK_POINT], stat[RPGConst::Status::DEFENSE_POINT]);
                break;
            default:
                printf(RPGConst::Message::InitSystem::WRONG_CHOICE);
                break;
        }
    }
    
}
Player* jobSelection(string username, int* stat) {
    int choice = 1;
    while (true) {
        cout << RPGConst::Message::InitSystem::CHOOSE_JOB;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << RPGConst::Message::InitSystem::CHOOSE_WARRIOR;
                stat[RPGConst::Status::HEALTH_POINT] += 20;
                return new Warrior(username, stat);
            case 2:
                cout << RPGConst::Message::InitSystem::CHOOSE_MAGE;
                stat[RPGConst::Status::MANA_POINT] += 30;
                return new Mage(username, stat);
            case 3:
                cout << RPGConst::Message::InitSystem::CHOOSE_ROGUE;
                stat[RPGConst::Status::ATTACK_POINT] += 15;
                return new Rogue(username, stat);
            case 4:
                cout << RPGConst::Message::InitSystem::CHOOSE_ARCHER;
                stat[RPGConst::Status::ATTACK_POINT] += 10;
                return new Archer(username, stat);
            default:
                cout << RPGConst::Message::InitSystem::WRONG_CHOICE;
                break;
        }
    }
}
bool battileStart(Player* player, vector<int> potions) {
    Slime slime;
    printf(RPGConst::Message::Fight::BATTLE_START, player->getName().c_str(), player->getJob().c_str(), slime.getName().c_str());
    int select = 0, choose;
    bool chooseContinue = true;
    while (true) {
        // while (chooseContinue) {
            cout << RPGConst::Message::Fight::PLAYER_TURN;
            // cin >> select;
            // if (select == 1) {
                chooseContinue = false;
                if (!player->attack(&slime)) {
                    return true;
                }
            // }
        //     else if (select == 2) {
        //         while (true) {
        //             printf("[ inventory ]\n1. HP Potion (50G) - x%d\n2. MP Potion (50G) - x%d\n3. Exit\n", potions[0], potions[1]);
        //             cin >> choose;
        //             if (choose == 1) {
        //                 if (potions[0] > 0) {
        //                     player->setHp(player->getHp() + 50 > 100 ? 100 : player->getHp() + 50);
        //                     potions[0]--;
        //                     printf(RPGConst::Message::Fight::HP_POTION_USE, potions[0]);
        //                     break;
        //                 }
        //                 cout << RPGConst::Message::InitSystem::NOT_ENOUGH_HEALTH_POTION;
        //             }else if (choose == 2) {
        //                 if (potions[1] > 0) {
        //                     player->setMp(player->getMp() + 50 > 100 ? 100 : player->getMp() + 50);
        //                     potions[1]--;
        //                     printf(RPGConst::Message::Fight::MP_POTION_USE, potions[1]);
        //                     break;
        //                 }
        //                 cout << RPGConst::Message::InitSystem::NOT_ENOUGH_MANA_POTION;
        //             }else if (choose == 3) {
        //                 chooseContinue = false;
        //                 break;
        //             }
        //             else   cout << RPGConst::Message::InitSystem::WRONG_CHOICE;
        //         }
        //     }
        // }
        // if (!chooseContinue) {
            cout << RPGConst::Message::Fight::ENEMY_TURN;
            if (!slime.attack(player)) return false;
        // }
        chooseContinue = true;
    }
}

void potionShop(vector<PotionRecipe> potionRecipe) {
    int select = 0;
    string search;
    
    bool isContinue = true;
    while (isContinue) {
        cout << RPGConst::Message::PotionShop::INIT;
        cin >> select;
        switch (select) {
            case 1: 
                for (PotionRecipe recipe : potionRecipe) {
                    cout << "->";
                    recipe.printRecipe();
                    cout << "\n";
                }
                cout << "Found " << potionRecipe.size() << " recipes.\n\n";
                break;
            case 2:
                cout << "Search potion name: ";
                cin >> search;
                for (PotionRecipe recipe : potionRecipe) {
                    if (recipe.getName().find(search) != string::npos) {
                        cout << "->";
                        recipe.printRecipe();
                        cout << "\n";
                    }
                }
                cout << "\n";
                break;
            case 3:
                cout << "Search ingredient: ";
                cin >> search;
                for (PotionRecipe recipe : potionRecipe) {
                    for (PotionIngredient ingredient : recipe.getIngredients()) {
                        if (ingredient.getName().find(search) != string::npos) {
                            cout << "->";
                            recipe.printRecipe();
                            cout << "\n";
                        }
                    }
                }
                break;
            case 0: isContinue = false; break;
            default: cout << RPGConst::Message::InitSystem::WRONG_CHOICE;
        }
    }
}
void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;
}
int main()
{
    int stat[RPGConst::Init::SIZE] = {0,0,0,0};
    vector<int> potions = {3,3};
    setPotion(5, &potions[0], &potions[1]);
    
    vector<PotionRecipe> potionRecipe = {
        {"HPPotion", {
                {"Herb", 1},
                {"Clear Water", 1}
        }},
        {"StaminaPotion", {
                {"Herb", 1},
                {"Berry", 1}
        }}
    };
    
    cout << RPGConst::Message::InitSystem::WELCOME;
    
    string username;
    getline(cin, username);
    
    statusInit(potions, stat);
    Player* player = jobSelection(username, stat);
    bool isGameStart = true;
    int select = 1;
    battileStart(player, potions);
    while (isGameStart) {
        cout << RPGConst::Message::MainMenu::MAIN_MENU;
        cin >> select;
        switch (select) {
            case 1: isGameStart = battileStart(player, potions); break;
            case 2: player->printInventory(); break;
            case 3: potionShop(potionRecipe); break;
            case 0:
                cout << RPGConst::Message::MainMenu::EXIT_GAME;
                isGameStart = false;    break;
            default: ;
        }
    }
    delete player;
    player = nullptr;
    return 0;
}
