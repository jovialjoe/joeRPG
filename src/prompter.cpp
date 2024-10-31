#include "../header/prompter.hpp"

#include "../header/enemy.hpp"
#include "../header/player.hpp"
#include "../header/fightSystem.hpp"
#include "../header/fightEncounter.hpp"
#include "../header/helperFunctions.hpp"

using std::cout;
using std::endl;

Prompter::Prompter() {
    //Easy (1) difficulty fightEncounters
    //Enemies should have 20-40 HP and 3-6 ATK
    fightEncounterList.push_back(FightEncounter("Moving forward in your journey, you can either travel through the Red Sand Desert or Begaritt Mountains.",
    "Red Sand Desert",
    "Begaritt Mountains",
    "As you navigate over sand dunes and through desert storms, you are attacked by a Sand Worm!",
    "As you hike over the Begaritt Mountains, you hear a screech and find yourself ambushed by a Griffin!",
    new Enemy("Sand Worm", "Ram", "Bite", 26, 4),
    new Enemy("Griffin", "Claw", "Screech", 20, 5),

    1));
    fightEncounterList.push_back(FightEncounter("Moving forward in your journey, you can either travel through the Miharo Glowworm Cave or the Forbidden Temple Ruins.",
    "Miharo Glowworm Cave",
    "Forbidden Temple Ruins",
    "As you creep through the cave, illuminated by hundreds of glowworms, you are attacked by a Taniwha Dragon!",
    "As you explore the ruins of the ancient temple, you hear a hiss and find yourself ambushed by a Naga Serpent!",
    new Enemy("Taniwha Dragon", "Impale", "Strike", 25, 4),
    new Enemy("Naga Serpent", "Pierce", "Scrape", 21, 5),
    1));
    fightEncounterList.push_back(FightEncounter("Moving forward in your journey, you can either travel through the Unelma Archipelago Path or the Haunted Lake of Yurei.",
    "Unelma Archipelago Path",
    "Haunted Lake of Yurei",
    "As you stroll across a myriad of islands, you are attacked by a Taniwha Dragon!",
    "As you swim across the cursed lake of lost souls, you hear a splash and find yourself ambushed by a Funayurei Demon!",
    new Enemy("Selma Serpentine", "Ravage", "Crush", 30, 3),
    new Enemy("Funayurei Demon", "Douse", "Slash", 27, 5),
    1));
    fightEncounterList.push_back(FightEncounter("Moving forward in your journey, you can either travel through the Lhotse Mountain Trail or the Cenote Encantado.",
    "Lhotse Mountain Trail",
    "Cenote Encantado",
    "As you trek through the trecherous Himalayan path, you are attacked by a Yeti Beast!",
    "As you dive into the crystal clear water of the Cenote, you hear a splash and find yourself ambushed by a Ahuizotl Monster!",
    new Enemy("Yeti Beast", "Trample", "Bash", 35, 3),
    new Enemy("Ahuizotl Monster", "Flood", "Smack", 24, 6),
    1));
    

    //Medium (2) difficulty fightEncounters
    //Enemies should have 50-70 HP and 7-10 ATK
    fightEncounterList.push_back(FightEncounter("Along your journey, you encounter a dungeon. You decide to enter it and while exploring it, you come across an old chest that seems to be stained. Do you open it? ",
    "Yes",
    "No, it looks suspicious",
    "As you reach for the lid of the chest, the chest reveals rows of teeth and a disgusting tounge! It's a mimic! You quickly pull your hand back after having almost lost it! You are now fighting the Mimic!",
    "You walk past that old chest and turn the corner. You see a promising room in front of you and you walk past a strange statue... You walk past and swear it had moved! You quickly turn around and it begins to fly, ready to attack! You must defeat the Gargoyle!",
    new Enemy("Mimic", "Bite", "Lick", 55, 10),
    new Enemy("Gargoyle", "Tackle", "Stone Claw", 63, 7),
    2));

    fightEncounterList.push_back(FightEncounter("On your expedition, you hear a rustle amongst the trees. Your curiosity lures you to the origin of the noise and you notice the shadow of a figure hiding behind a tree. Will you approach it?",
    "Yes",
    "No, make a run for it",
    "You approach the mysterious figure and realize it has the heads of a lion and goat! Hiding behind the tree was a Chimera! You must now fight for your life against the Chimera!",
    "Though you quickly try to make a run for it, you immediately feel someone's hands grab onto you! It is a Banshee! You must now fight for your life against the Banshee!",
    new Enemy("Chimera", "Pounce", "Blow Fire", 70, 7),
    new Enemy("Banshee", "Strangle", "Haunt", 60, 10),
    2));

    fightEncounterList.push_back(FightEncounter("During your travels, you hear a woman's voice crying out for help! You wonder why there is a lone woman in this realm. Will you be offering her your support? ",
    "Yes",
    "No, you must stay focused",
    "While you walk towards the lone woman, you see a plethora of snakes sprouting from her head! It's a Gorgon! She instantly tries to turn you into stone! You are now fighting the Gorgon!",
    "You continue along your journey but run into the lone woman yet again. Despite your efforts to run past it, you sense dark magic hindering you! You are now fighting the Empusa!",
    new Enemy("Gorgon", "Intoxicate", "Petrify", 65, 8),
    new Enemy("Empusa", "Dark Magic", "Energy Blade", 60, 9),
    2));

    fightEncounterList.push_back(FightEncounter("Along your path, you decide to obtain a refill of water from a nearby waterfall. All of a sudden, you see the water turn a glowing red. Will you still touch the water?",
    "Yes",
    "No, it seems dangerous",
    "Just as you bring your hands to the water, the body of water reveals a glowing red spirit! You recognize it as the evil spirited Vaatu! You will now duel Vaatu!",
    "You carry on with your path, hoping to find another body of water. Suddenly, you notice the glowing red light following you! It's an Asura! You will now duel the Asura!",
    new Enemy("Vaatu", "Mystical Fusion", "Dark Energy", 68, 8),
    new Enemy("Asura", "Evil Charm", "Cast Spell", 55, 10),
    2));

    //Hard (3) difficulty fightEncounters
    //Enemies should have 80-100 HP and 10-15 ATK
    fightEncounterList.push_back(FightEncounter("As you travel through the Great Forest, you spot your long missed childhood friend from your home village! You wonder why she is here. She runs towards for a hug. What do you do?",
    "Hug her",
    "Attack her",
    "As you embrace, your childhood friend's appearance distorts and becomes monsterous. You have been tricked! The monster stabs you with its glowing appendage, but you feel no pain. The monster had fed on your soul and became stronger than before! You now face the Wandering Vagrant!",
    "You question what is in front of you and assume it is a trick. You attack the mirage of your friend and the fake fades to reveal itself to be a deceptful Incubi! You prepare to fight!",
    new Enemy("Empowered Wandering Vagrant", "Deathly Gaze", "Soul Pierce", 100, 10),
    new Enemy("Incubi", "Seduction", "Soul Siphon", 88, 14),
    3));

    fightEncounterList.push_back(FightEncounter("After such battles, you enter a vacant cabin as an attempt to recuperate. You take a look in the mirror and notice another face beside your reflection! What will you do?",
    "Ask who they are",
    "Attack them",
    "The strange figure opens its mouth to answer and reveals its blood-stained teeth. Horns begin to emerge from its heads as it attempts to hunt your soul! You can feel its sorcery take over your body! Now, you must stand up to the Skinwalker",
    "You rapidly turn around to attack the strange figure. Just as you attempt to attack it, you hear a piercing weep and find yourself unable to move! The weeping begins to paralyze your body! Now, you must stand up against La Llorona!",
    new Enemy("Skinwalker", "Fatal Sorcery", "Soul Hunt", 99, 11),
    new Enemy("La Llorona", "Perilous Lure", "Discordant Weep", 90, 13),
    3));

    fightEncounterList.push_back(FightEncounter("Amidst your journey, you decide to set up camp for the night and begin to light a fire. You successfully light a campfire but notice the fire growing bigger and bigger! The fire now begins to take the form of a strange being! What will you do?",
    "Attempt to put out the fire",
    "Run as fast as you can",
    "You quickly try to put out the fire, however, this further enrages the fiery being! It grows larger and attempts to blow fire at you! You can feel the hairs of your eyebrows being singed! You will now be defending yourself against Typhon!",
    "Your attempts to run away were to no avail as the raging fire follows you! Within the fire is a beastly figure with glowing eyes! As it follows you, your body begins to feel a hex controlling your every thought! You will now be defending yourself against the Ifrit!",
    new Enemy("Typhon", "Fire Surge", "Storm Outrage", 98, 12),
    new Enemy("Ifrit", "Mortal Scorge", "Perception Hex", 94, 13),
    3));

    fightEncounterList.push_back(FightEncounter("In your wanderings, you notice that your body is covered in old blood and stains of Earth. You decide to take a jump into a nearby lake for a refresher. Whilst deep in the water of the lake, you lock eyes with two glowing eyes! What will you do?",
    "Strike them whilst underwater",
    "Promptly swim away",
    "You make your best attempt to strike the enigmatic beast but find yourself being controlled by a sudden whirlpool! The enigmatic beast emerges to be a colossal sea monster who can manipulate the waters! Thus, begins your battle with the Leviathan!",
    "Though you strive to swim away as fast as possible, the enigmatic beast captures you with its long, powerful tentacles! You find yourself unable to properly move your body whilst in its grasp! Thus, begins your battle with the Kraken!",
    new Enemy("Leviathan", "Whirpool", "Typhoon", 95, 12),
    new Enemy("Kraken", "Tentacle Grasp", "Poison Ink", 89, 14),
    3));
}

Prompter::~Prompter() {
    for(int i = 0; i < fightEncounterList.size(); i++) {
        delete fightEncounterList.at(i).getEnemy1Destroy();
        delete fightEncounterList.at(i).getEnemy2Destroy();
    }
}

bool Prompter::runFightEncounter(int distance, Player&player) {
    int difficulty, chosenEncounter, playerChoice;
    FightSystem fightDriver;

    if(distance <= 10) {
        difficulty = 3;
    } else if(distance <= 20) {
        difficulty = 2;
    } else {
        difficulty = 1;
    }

    while(true) {
        int randomNum = helperGenerateRandomInteger(0,(fightEncounterList.size()/3)-1);
        randomNum += (fightEncounterList.size()/3)*(difficulty-1);

        if(fightEncounterList.at(randomNum).getDifficulty() == difficulty) {
            chosenEncounter = randomNum;
            break;
        }
    }

    while(true) {
        helperPrintLargerSpacer();
        cout << fightEncounterList.at(chosenEncounter).getPrompt() << endl << endl; //output prompt

        cout << "1. " << fightEncounterList.at(chosenEncounter).getChoice1() << endl;
        cout << "2. " << fightEncounterList.at(chosenEncounter).getChoice2() << endl;

        if(!(std::cin >> playerChoice)) {
            throw std::runtime_error("prompter playerChoice cin_error");
        }
        
        if(playerChoice != 1 && playerChoice != 2) {
            cout << "Invalid, please enter a proper choice number..." << endl;
            helperWait(2.5);
        } else {
            break;
        }
    }

    helperPrintLargerSpacer();

    if (playerChoice == 1) {
        cout << fightEncounterList.at(chosenEncounter).getResponse1() << endl;
        helperWait(2.5);
        if(!(fightDriver.fighting(fightEncounterList.at(chosenEncounter).getEnemy1(), player))) {
            return false;
        }
    } else {
        cout << fightEncounterList.at(chosenEncounter).getResponse2() << endl;
        helperWait(2.5);
        if(!(fightDriver.fighting(fightEncounterList.at(chosenEncounter).getEnemy2(), player))) {
            return false;
        }
    }
    return true;
}

void Prompter::runHealthEncounter(Player &player) { // create 3 prompts and then scale health by player's health 
    int chanceNum = helperGenerateRandomInteger(0, 100);
    int playerChoice;
    int heal; 

    if (chanceNum >= 0 && chanceNum < 25) { // prompt #1: giant dancing mushroom
        cout << "Along your path you see a jovial looking giant mushroom dancing with much smaller mushrooms surrounding it. What do you do?\n" << endl;     // giant dancing mushroom wanna take a bite? 

        while(true) {
            cout << "1. Rush up and take a quick bite off its head!" << endl;
            cout << "2. Politely go up and ask what they're doing.." << endl;

            if (!(std::cin >> playerChoice)) {
                throw std::runtime_error("prompter playerChoice cin_error");
            }
        
            if (playerChoice != 1 && playerChoice != 2) {
                cout << "Invalid, please enter a proper choice number..." << endl;
                helperWait(2);
            } else break; 
        }

        if (playerChoice == 1) {
            heal = player.getMaxHP() * 25/100; 
            if (player.getHP() + heal > player.getMaxHP()) {
                heal = player.getMaxHP() - player.getHP();
            }

            cout << "You bit the mushroom and gained " << heal << " health points back!" << endl;
            cout << "It pauses and stares at your mournfully for a moment before regenerating itself and continues dancing.." << endl;
            player.setHP(player.getHP() + heal);
            
        } else if (playerChoice == 2) {
            heal = player.getMaxHP() * 34/100; 

            if (player.getHP() + heal > player.getMaxHP()) {
                heal = player.getMaxHP() - player.getHP();
            }
            cout << "You approached the mushroom and asked \" Pray tell what are thee doing? \" " << endl;
            cout << "In response the mushroom pauses, gives a bright smile and mummbles some incoherent words..your wounds start to heal and you suddenly feel all your stress drift away" << endl;
            cout << "You've gained " << heal << " health points back" << endl;
        }
    } 

    else if (chanceNum >= 25 && chanceNum < 50) { // prompt #2: lady of the lake
        cout << "While walking, a bright blue peaceful looking lake catches your eye. As you get closer something in the water appears to be peering back at you. Do you...\n" << endl;    

        while(true) {
            cout << "1. Loudly scream \" STOP STARING AT ME \"" << endl;
            cout << "2. Go up to the edge and stick your head in the water" << endl;

            if (!(std::cin >> playerChoice)) {
                throw std::runtime_error("prompter playerChoice cin_error");
            }
        
            if (playerChoice != 1 && playerChoice != 2) {
                cout << "Invalid, please enter a proper choice number..." << endl;
                helperWait(2);
            } else break; 
        }

        if (playerChoice == 1) {
            heal = player.getMaxHP() * 18/100; 
            if (player.getHP() + heal > player.getMaxHP()) {
                heal = player.getMaxHP() - player.getHP();
            }

            cout << "Starlted by the noise, the eyes blink two long blinks and splashes water on you!" << endl;
            cout << "The eyes disappear after that and the lake goes still..." << endl;
            cout << "You gain back " << heal << " health points!" << endl;            
        } 
        
        else if (playerChoice == 2) {

            heal = player.getMaxHP() * 40/100; 
            if (player.getHP() + heal > player.getMaxHP()) {
                heal = player.getMaxHP() - player.getHP();
            }
            cout << "Before you can stick your head in the water, a vision of a lady forms above the water and she smiles warmly" << endl;
            cout << "\"A present for you on your weary travels\"" << endl;
            helperWait(1);
            cout << "You've gained " << heal << " health points back!" << endl;
            cout << "The lady soon dissappears, leaving behind a warm feeling and renewed spirit" << endl;
         }        
    } 

    else if (chanceNum >= 50 && chanceNum < 75) { // #prompt 3: flower field
        cout << "As you gaze in the distance, you see a sun-drenched meadow with vibrant wildflowers swaying gently in the breeze. Among them, a single flower seems to lightly shimmer, pulsing with a mesmerizing glow. How do you react?\n" << endl;    

        while(true) {
            cout << "1. Kneel to examine the flower more closely?" << endl;
            cout << "2. Pluck the enchanted flower.." << endl;


            if (!(std::cin >> playerChoice)) {
                throw std::runtime_error("prompter playerChoice cin_error");
            }
        
            if (playerChoice != 1 && playerChoice != 2) {
                cout << "Invalid, please enter a proper choice number..." << endl;
                helperWait(2);
            } else break; 
        }

        if (playerChoice == 1) {
            heal = player.getMaxHP() * 25/100; 
            if (player.getHP() + heal > player.getMaxHP()) {
                heal = player.getMaxHP() - player.getHP();
            }

            cout << "As you lean in closer, the flower sprays some gold powder in your face!" << endl;
            cout << "You gain " << heal << " health points back!" << endl;            
        } 
        
        else if (playerChoice == 2) {
            heal = -6;
            cout << "It releases a toxic gas! You realized too late that it was a Belladonna flower, beautiful but deadly." << endl;
            cout << "You've lost 6 health points" << endl;
        }
    }

    else { // prompt #4: tower ruins
        cout << "In the shadow of towering ruins, you stumble upon a circle of glowing runes etched in the ground. The longer you stand within the circle the brighter the glow becomes..\n" << endl;   
        helperWait(1);

        while(true) {
            cout << "1. Stay inside the circle and wait to see what happens" << endl;
            cout << "2. Jump out of the circle as fast as you can" << endl;


            if (!(std::cin >> playerChoice)) {
                throw std::runtime_error("prompter playerChoice cin_error");
            }
        
            if (playerChoice != 1 && playerChoice != 2) {
                cout << "Invalid, please enter a proper choice number..." << endl;
                helperWait(2);
            } else break; 
        }

        if (playerChoice == 1) {
            heal = player.getMaxHP() * 34/100; 
            if (player.getHP() + heal > player.getMaxHP()) {
                heal = player.getMaxHP() - player.getHP();
            }

            cout << "The runes continue to glow brighter and brighter until everything begins to shake and you become momentarily blinded" << endl;
            cout << "Once you regain your vision you notice the runes are gone and you've gained " << heal << " health points back" << endl;

        } else if (playerChoice == 2) {
            heal = player.getMaxHP() * 16/100; 
            if (player.getHP() + heal > player.getMaxHP()) {
                heal = player.getMaxHP() - player.getHP();
            }
            cout << "As you jump out of the way, you trip and fall on your face. You hear the surrounding tower boom with laughter!" << endl;
            cout << "You've gained " << heal << " health points back!" << endl;
        }
    }    
    
    player.setHP(player.getHP() + heal);
    helperWait(3);
    cout << "You continue on your journey, intrigued by the situation you've just encountered" << endl;

}

void Prompter::runEquipmentEncounter(Player& player) {
    //Forget about using a vector of equipmentEncounters to pick one, just code in here a few simple equipment encounters that modify weapon and armor stats or offer new ones
    int chanceNum = helperGenerateRandomInteger(1, 60);
    int playerChoice;

    if (chanceNum >= 0 && chanceNum < 10) { // prompt #1: solely weapon encounter
        cout << "You encounter an old, traveling merchant who claims to have magical powers that can upgrade your weapons.\n" << endl;
        while(true) {
            cout << "1. You trust the merchant and hand him your weapons." << endl;
            cout << "2. The merchant is suspicious. You run away fast, he can't catch you!" << endl;

            if (!(std::cin >> playerChoice)) {
                throw std::runtime_error("Failed to input equipment encounter choice.");
            }
        
            if (playerChoice != 1 && playerChoice != 2) {
                cout << "Invalid, please enter a proper choice number..." << endl;
                helperWait(2);
            } else break; 
        }
        if (playerChoice == 1) {
            if (player.getCurrentWeaponIndex() != 0) {
                player.equipWeapon(player.getCurrentWeaponIndex() - 1);
                cout << "\"Hehehe... You are too naive\" the Merchant says as he vanishes into thin air." << endl;
                cout << "Don't trust random people! Your weapon has downgraded to " << player.getWeaponName(player.getCurrentWeaponIndex()) << "!" << endl;
            }
            else { //already equipped worst weapon
                cout << "\"Dang, I was going to steal your weapon but it's already the worst one! I'll spare you this time...\" the Merchant grumbles." << endl;
                cout << "Lucky you. Nothing happened to your " << player.getWeaponName(player.getCurrentWeaponIndex()) << "!" << endl;
            }
        }
        else if (playerChoice == 2) {
            if (player.getCurrentWeaponIndex() == player.getWeaponListSize() - 1) { //player has the maxed out weapon
                cout << "You run away from the merchant. He exclaims, \"You'll regret it!\"" << endl;
                cout << "Nothing happens to your weapons." << endl;
            }
            else { //gain next weapon
                player.equipWeapon(player.getCurrentWeaponIndex() + 1);
                cout << "As you run away, your weapons sharpen as they drag on the stone floor." << endl;
                cout << "You now equip " << player.getWeaponName(player.getCurrentWeaponIndex()) << "! It has " << player.getSpecificWeaponATK(player.getCurrentWeaponIndex()) << " attack points!" << endl;
            }
        }
        helperWait(3);
    }

    else if (chanceNum >= 10 && chanceNum < 20) { // prompt #2: solely weapon
        cout << "You run into a lake of water. You see something bobbing in the water, you think about grabbing it.\n" << endl;
        while (true) {
            cout << "1. You use your hand to grab the bobbing item." << endl;
            cout << "2. You ignore it and sit on the rocks to admire the view." << endl;

            if (!(std::cin >> playerChoice)) {
                throw std::runtime_error("Failed to input equipment encounter choice.");
            }
        
            if (playerChoice != 1 && playerChoice != 2) {
                cout << "Invalid, please enter a proper choice number..." << endl;
                helperWait(2);
            } else break; 
        }
        if (playerChoice == 1) {
            if (player.getCurrentWeaponIndex() == player.getWeaponListSize() - 1) { //if player has the max weapon
                cout << "As you grab the item, it resists. You pull harder..." << endl;
                helperWait(1);
                cout << "..." << endl;
                helperWait(1);
                cout << "..." << endl;
                helperWait(1);
                cout << "It's just a shoe... Looks like it got stuck under the rocks..." << endl;
            }
            else { //weapon can get better
                player.equipWeapon(player.getCurrentWeaponIndex() + 1);
                cout << "You pull the item, but not enough..." << endl;
                helperWait(1);
                cout << "Pull harder!" << endl;
                helperWait(1);
                cout << "Even more!" << endl;
                helperWait(1);
                cout << "Whoa!! So shiny! You pulled out a " << player.getWeaponName(player.getCurrentWeaponIndex()) << "!" << endl;
            }
        }
        else if (playerChoice == 2) {
            if (player.getCurrentWeaponIndex() == 0) { //player has weakest weapon
                cout << "The birds chirp and the lake shimmers. The item stops bobbing. It looks like it sank." << endl;
            }
            else { //get worse weaopn
                player.equipWeapon(player.getCurrentWeaponIndex() - 1);
                cout << "As you admire the view, the item flies out of the water. It's a fish!! It lands on the dry land. You pick it up to throw it back into the water..." << endl;
                helperWait(1);
                cout << "The fish's slime gets on your weapons. It takes a bite and then poops on it..." << endl; 
                cout << "The fish's slime transforms your weapon for the worse. You now have " << player.getWeaponName(player.getCurrentWeaponIndex()) << "... It has " << player.getSpecificWeaponATK(player.getCurrentWeaponIndex()) << " attack points." << endl;
            }
        }
        helperWait(3);
    }

    else if (chanceNum >= 20 && chanceNum < 30) { // prompt #3: Treasure boxes for armor or weapon
        cout << "You see two glowing treasure boxes on your journey. They must be very promising!\n" << endl;
        while(true) {
            cout << "1. Open the left glowing treasure box." << endl;
            cout << "2. Open the right glowing treasure box." << endl;

            if (!(std::cin >> playerChoice)) {
                throw std::runtime_error("Failed to input equipment encounter choice.");
            }
        
            if (playerChoice != 1 && playerChoice != 2) {
                cout << "Invalid, please enter a proper choice number..." << endl;
                helperWait(2);
            } else break; 
        }
        if (playerChoice == 1) { //upgrade weapon
            if (player.getCurrentWeaponIndex() != player.getWeaponListSize() - 1) { //if their weapon is not maxed out
                player.equipWeapon(player.getCurrentWeaponIndex() + 1);
                cout << "You found a new weapon! It looks better than before!" << endl;
                cout << "You got " << player.getWeaponName(player.getCurrentWeaponIndex()) << "! it has " << player.getSpecificWeaponATK(player.getCurrentWeaponIndex()) << " attack points!" << endl;
            }
            else { //weapon is maxed out
                cout << "You open the chest! ... But it looks like it's the same weapon you already have... Oh well." << endl;
            }
        }
        else if (playerChoice == 2) {
            if (player.getCurrentArmorIndex() != player.getArmorListSize() - 1) { //if their armor is not maxed out
                player.equipArmor(player.getCurrentArmorIndex() + 1);
                cout << "You found new armor! It looks better than what you have on now." << endl;
                cout << "You got " << player.getArmorName(player.getCurrentArmorIndex()) << "! it has " << player.getSpecificArmorHP(player.getCurrentArmorIndex()) << " health points!" << endl;
            }
            else { //armor is maxed out
                cout << "You open the chest! ... But it looks like it's the same armor you already have... Oh well." << endl;
            }
        }
        helperWait(3);
    }

    else if (chanceNum >= 30 && chanceNum < 40) { // prompt #4: Bright Being for armor or weapon
        cout << "You encounter a super, super bright, glowing white being, floating above you, staring right at you.\n" << endl;
        while(true) {
            cout << "1. You face the mysterious, haunting being. You stare them straight to where their eyes should be." << endl;
            cout << "2. You run away and hide from the being. Its too bright." << endl;

            if (!(std::cin >> playerChoice)) {
                throw std::runtime_error("Failed to input equipment encounter choice.");
            }
        
            if (playerChoice != 1 && playerChoice != 2) {
                cout << "Invalid, please enter a proper choice number..." << endl;
                helperWait(2);
            } else break; 
        }
        if (playerChoice == 1) {
            if (player.getCurrentWeaponIndex() != player.getWeaponListSize() - 1) { //weapon is not maxed out
                player.equipWeapon(player.getCurrentWeaponIndex() + 1);
                cout << "The glowing white being splits into 5 people. Sounds of angels bless you. It's ARTMS!!" << endl;
                cout << "They give you a signed weapon. It's called " << player.getWeaponName(player.getCurrentWeaponIndex()) << " and has " << player.getSpecificWeaponATK(player.getCurrentWeaponIndex()) << " attack points!" << endl;
            }
            else { //best weapon is equipped
                cout << "The being splits into 5. It's ARTMS! They give you a signed <DALL> album! But it has no usage... You proceed as if nothing happened." << endl;
            }
        }
        else if (playerChoice == 2) {
            if (player.getCurrentArmorIndex() != player.getArmorListSize() - 1) { //if their armor is not maxed out
                player.equipArmor(player.getCurrentArmorIndex() + 1);
                cout << "You successfully hide from the being. It flies away. You find out it was a virtual angel and it drops it's wings." << endl;
                cout << "You pick it up and it turns into " << player.getArmorName(player.getCurrentArmorIndex()) << "! You equip it. It has " << player.getSpecificArmorHP(player.getCurrentArmorIndex()) << " health points!" << endl;
            }
            else { //armor is maxed out
                cout << "You successfully hid from the being! It flies away... Stan loona!" << endl;
            }
        }
        helperWait(3);
    }
    else if (chanceNum >= 40 && chanceNum < 50) { // prompt #5: siren's cove for armor and weapon
        cout << "In the distance you hear a melodic tune, enchanted by the music, you can't help but follow it to a small cove behind a waterfall..." << endl;
        cout << "Once you enter, the music abruptly stops and you're able to snap out of your trance. You look around and find the cove to be abandoned. What do you do next?\n" << endl;

        while(true) {
            cout << "1. Explore the cove" << endl;
            cout << "2. Go back to the path you were on previously" << endl;

            if (!(std::cin >> playerChoice)) {
                throw std::runtime_error("Failed to input equipment encounter choice.");
            }
        
            if (playerChoice != 1 && playerChoice != 2) {
                cout << "Invalid, please enter a proper choice number..." << endl;
                helperWait(2);
            } else break; 
        }
        if (playerChoice == 1) {
            if ((player.getCurrentWeaponIndex() == player.getWeaponListSize() - 1) && (player.getCurrentArmorIndex() == player.getArmorListSize() - 1)) { //player has the maxed out weapon
                cout << "You found nothing." << endl;
            }
            else { //gain next weapon and armor
                player.equipWeapon(player.getCurrentWeaponIndex() + 1);
                player.equipArmor(player.getCurrentArmorIndex() + 1);
                cout << "After exploring every inch of the cove, you found a new set of armor and weapon!" << endl;
                cout << "Your weapon upgraded " << player.getWeaponName(player.getCurrentWeaponIndex()) << "!" << endl;
                cout << "Your armor upgraded " << player.getArmorName(player.getCurrentWeaponIndex()) << "!" << endl;
            }
        }
        else if (playerChoice == 2) {
            if ((player.getCurrentWeaponIndex() == player.getWeaponListSize() - 1) && (player.getCurrentArmorIndex() == player.getArmorListSize() - 1)) { //player has the maxed out weapon
                cout << "You return onto the path unscathed" << endl;
            }
            else { //gain next weapon and armor
                player.equipWeapon(player.getCurrentWeaponIndex() + 1);
                player.equipArmor(player.getCurrentArmorIndex() + 1);
                cout << "As you're walking out you see a set of armor and weapon hidden near the entrance of the cove!" << endl;
                cout << "Your weapon upgraded " << player.getWeaponName(player.getCurrentWeaponIndex()) << "!" << endl;
                cout << "Your armor upgraded " << player.getArmorName(player.getCurrentWeaponIndex()) << "!" << endl;
            }
        }
        helperWait(3);
    }
      
    else { // prompt #6: solely armor encounter at abandoned ship
        cout << "You come across a ghostly abandoned ship adrift in the fog, its hull creaking with secrets and hidden treasures. \nDo you dare to explore its darkened decks, or sail past and leave its secrets undisturbed?\n" << endl;
        while(true) {
            cout << "1. Investigate the ship's darkened decks in search of hidden treasures?" << endl;
            cout << "2. Continue your journey and leave the ship's mysteries untouched?" << endl;

            if (!(std::cin >> playerChoice)) {
                throw std::runtime_error("Failed to input equipment encounter choice.");
            }
        
            if (playerChoice != 1 && playerChoice != 2) {
                cout << "Invalid, please enter a proper choice number..." << endl;
                helperWait(2);
            } else break; 
        }
        if (playerChoice == 1) {
            if (player.getCurrentArmorIndex() == player.getArmorListSize() - 1) { //player has the maxed out weapon
                cout << "You searched the ship's darkened decks but found no treasures\n—only empty chambers and decaying wood." << endl;
                cout << "Nothing happens to your equipment." << endl;
            }
            else { //gain next armor
                player.equipArmor(player.getCurrentArmorIndex() + 1);
                cout << "Exploring the ship's darkened decks, you discover new equipment hidden among the decaying wood. Your adventure just got an upgrade!." << endl;
                cout << "You now equip " << player.getArmorName(player.getCurrentArmorIndex()) << "! It has " << player.getSpecificArmorHP(player.getCurrentArmorIndex()) << " health points!" << endl;
            }
        }
        else if (playerChoice == 2) {
                cout << "You decide to venture past the abandoned ship, leaving its secrets and potential treasures undisturbed." << endl;
                cout << "Nothing happens to your equipment." << endl;
        }
        helperWait(3);
    }
      
    helperWait(2);
    cout << "You continue your journey..." << endl;
}
