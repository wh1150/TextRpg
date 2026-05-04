#pragma once

namespace RPGConst {
	namespace Init {
		constexpr int SIZE = 4;
		constexpr int HEALTH_POTION = 5;
		constexpr int MANA_POTION = 5;
		constexpr int INVENTORY_SIZE = 10;
	}

	namespace Potion {
		
	}
	namespace Status {
		constexpr int HEALTH_POINT = 0;
		constexpr int MANA_POINT = 1;
		constexpr int ATTACK_POINT = 2;
		constexpr int DEFENSE_POINT = 3;
	}
	namespace Potion {
		constexpr int HEALTH_POTION = 0;
		constexpr int MANA_POTION = 1;
	}
	namespace Job {
		constexpr const char* WARRIOR = "Warrior";
		constexpr const char* MAGE = "Mage";
		constexpr const char* ROGUE = "Rogue";
		constexpr const char* ARCHER = "Archer";
	}
	namespace Message {
		namespace InitSystem{
			constexpr const char* WELCOME = "===========================================\n[ Dungeon Escape Text RPG ]\n==========================================\nEnter your hero's name: ";
			constexpr const char* WRONG_CHOICE = "Invalid choice. Please select a valid option.\n\n";
			constexpr const char* INPUT_HP_MP = "Enter HP and MP: ";
			constexpr const char* LOW_HP_MP = "HP or MP is too low. Try again.\n\n";
			constexpr const char* INPUT_ATK_DEP = "Enter Attack and Defense: ";
			constexpr const char* LOW_ATK_DEP = "Attack or Defense is too low. Try again.\n\n";
			constexpr const char* START_MENU = "===========================================\n< Character Upgrade >\n1. HP UP    2. MP UP    3. Attack x2\n4. Defense x2  5. Show Stats  0. Start Game\n9. Exit Game\n============================================\nChoose: ";
			constexpr const char* HP_UP = "HP increased by 20. (HP Potion used: %d left)\n\n";
			constexpr const char* NOT_ENOUGH_HEALTH_POTION = "You have no more HP potions.\n\n";
			constexpr const char* MP_UP = "MP increased by 20. (MP Potion used: %d left)\n\n";
			constexpr const char* NOT_ENOUGH_MANA_POTION = "You have no more MP potions.\n\n";
			constexpr const char* DOUBLE_ATK = "Attack multiply by 2 (current Attack : %d)\n\n";
			constexpr const char* DOUBLE_DEF = "Defense multiply by 2 (current Defense : %d)\n\n";
			constexpr const char* CURRENT_STATUS = "\n===========================================\nYou're status is . . .\nHP : %d / MP : %d\nAttack : %d / Defense : %d\n\n";
			constexpr const char* CURRENT_STATUS_AFTER_JOB = "------------------------------------\nName: %s | Job: %s | Lv.%d ( %d / %d )\nHP: %d | MP: %d | Attack: %d | Defense: %d\n------------------------------------\n\n";
			constexpr const char* START_GAME = "\nStarting the game!\n\n";
			constexpr const char* CHOOSE_JOB = "< Job Selection >\nJohn, choose your job!\n1. Warrior   2. Mage   3. Rogue   4. Archer\nChoose: ";
			constexpr const char* CHOOSE_WARRIOR = "* You became a Warrior! (HP +30)\n* Attacks with a sword!\n\n";
			constexpr const char* CHOOSE_MAGE = "* You became a Mage! (MP +30)\n* Fires a fireball!\n\n";
			constexpr const char* CHOOSE_ROGUE = "* You became a Rogue! (Attack +15)\n* Sneaks and strikes from behind!\n\n";
			constexpr const char* CHOOSE_ARCHER = "* You became a Archer! (Attack +10)\n* Shoots arrows from a distance!\n\n";
		}

		namespace Fight {
			constexpr const char* ATTACK_WARRIOR = "Swing a sword at the enemy!\n";
			constexpr const char* ATTACK_MAGE = "Fires a fireball!\n";
			constexpr const char* ATTACK_ROGUE = "Sneaks and strikes from behind!\n";
			constexpr const char* ATTACK_ARCHER = "Shoot arrow to the enemy!\n";
			constexpr const char* BATTLE_START = "[ Battle Start! ] %s(%s) vs %s\n\n";
			constexpr const char* PLAYER_TURN = "--- Player Turn ---\n";
			constexpr const char* ENEMY_TURN = "--- Enemy Turn ---\n";
			constexpr const char* LEVEL_UP = "Level up condition met\n  -> Level Up! Lv.1 -> Lv.2\n  -> HP +10, MP +5, Attack +5\n";
			constexpr const char* HP_POTION_USE = "HP Potion used! HP restored by 50 (%d -> %d)";
			constexpr const char* MP_POTION_USE = "MP Potion used! MP restored by 50 (%d -> %d)";
		}
		namespace MainMenu {
			constexpr const char* MAIN_MENU = "=== Main Menu ===\n1. Enter Dungeon\n2. Check Inventory\n3. Potion Shop\n0. Quit\n\nChoose: ";
			constexpr const char* EXIT_GAME = "Thank you for playing TextRpg!\n";
		}

		namespace PotionShop {
			constexpr const char* INIT = "=== Potion Shop ===\n1. Show all recipes\n2. Search by potion name\n3. Search by ingredient\n0. Go back\n\nChoose: ";
		}
	}
}