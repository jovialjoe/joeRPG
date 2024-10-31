#include <gtest/gtest.h>

#include "../header/fightEncounter.hpp"
#include "../header/enemy.hpp"

TEST(FightEncounterSuite, Constructor) {
    FightEncounter testEncounters("Moving forward in your journey, you can either travel through the Red Sand Desert or Begaritt Mountains.",
    "Red Sand Desert",
    "Begaritt Mountains",
    "As you navigate over sand dunes and through desert storms, you are attacked by a Sand Worm!",
    "As you hike over the Begaritt Mountains, you hear a screech and find yourself ambushed by a Griffin!",
    new Enemy("Sand Worm", "Ram", "Bite", 26, 4),
    new Enemy("Griffin", "Claw", "Screech", 20, 5),
    1);

    ASSERT_TRUE(testEncounters.getPrompt() == "Moving forward in your journey, you can either travel through the Red Sand Desert or Begaritt Mountains.");
    ASSERT_TRUE(testEncounters.getChoice1() == "Red Sand Desert");
    ASSERT_TRUE(testEncounters.getChoice2() == "Begaritt Mountains");
    ASSERT_TRUE(testEncounters.getResponse1() == "As you navigate over sand dunes and through desert storms, you are attacked by a Sand Worm!");
    ASSERT_TRUE(testEncounters.getResponse2() == "As you hike over the Begaritt Mountains, you hear a screech and find yourself ambushed by a Griffin!");
    ASSERT_EQ(testEncounters.getDifficulty(), 1);

    ASSERT_TRUE(testEncounters.getEnemy1().getName() == "Sand Worm");
    ASSERT_TRUE(testEncounters.getEnemy1().getMove1Name() == "Ram");
    ASSERT_TRUE(testEncounters.getEnemy1().getMove2Name() == "Bite");
    ASSERT_EQ(testEncounters.getEnemy1().getMaxHP(), 26);
    ASSERT_EQ(testEncounters.getEnemy1().getHP(), 26);
    ASSERT_EQ(testEncounters.getEnemy1().getATK(), 4);

    ASSERT_TRUE(testEncounters.getEnemy2().getName() == "Griffin");
    ASSERT_TRUE(testEncounters.getEnemy2().getMove1Name() == "Claw");
    ASSERT_TRUE(testEncounters.getEnemy2().getMove2Name() == "Screech");
    ASSERT_EQ(testEncounters.getEnemy2().getMaxHP(), 20);
    ASSERT_EQ(testEncounters.getEnemy2().getHP(), 20);
    ASSERT_EQ(testEncounters.getEnemy2().getATK(), 5);
}