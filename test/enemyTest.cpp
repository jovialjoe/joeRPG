#include <gtest/gtest.h>

#include "../header/enemy.hpp"

TEST(EnemyTestSuite, Constructor) {
    Enemy testEnemy("Jimmothy", "Smack", "Slam", 50, 2);

    ASSERT_TRUE(testEnemy.getName() == "Jimmothy");
    ASSERT_TRUE(testEnemy.getMove1Name() == "Smack");
    ASSERT_TRUE(testEnemy.getMove2Name() == "Slam");

    ASSERT_EQ(testEnemy.getMaxHP(), 50);
    ASSERT_EQ(testEnemy.getHP(), 50);
    ASSERT_EQ(testEnemy.getATK(), 2);
}

TEST(EnemyTestSuite, Set) {
    Enemy testEnemy("Jimmothy", "Smack", "Slam", 50, 2);

    testEnemy.setHP(42);
    testEnemy.setATK(3);
    testEnemy.setName("Jerry");

    ASSERT_EQ(testEnemy.getMaxHP(), 50);
    ASSERT_EQ(testEnemy.getHP(), 42);
    ASSERT_EQ(testEnemy.getATK(), 3);
    ASSERT_TRUE(testEnemy.getName() == "Jerry");
}