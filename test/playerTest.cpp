#include <gtest/gtest.h>

#include "../header/player.hpp"
#include "../header/equipment/weapon.hpp"
#include "../header/equipment/armor.hpp"

TEST(PlayerTest, ClassConstructorSwordsman) {
    Player testPlayer(1, "Jimmy");

    ASSERT_TRUE(testPlayer.getPlayerClass() == "Swordsman");
    ASSERT_TRUE(testPlayer.getName() == "Jimmy");

    ASSERT_EQ(testPlayer.getCurrentWeaponIndex(), 0);
    ASSERT_EQ(testPlayer.getCurrentArmorIndex(), 0);

    ASSERT_EQ(testPlayer.getSpecificWeaponATK(testPlayer.getCurrentWeaponIndex()), 4);
    ASSERT_EQ(testPlayer.getSpecificArmorHP(testPlayer.getCurrentArmorIndex()), 10);

    ASSERT_EQ(testPlayer.getMaxHP(), 110 + testPlayer.getSpecificArmorHP(testPlayer.getCurrentArmorIndex()));
    ASSERT_EQ(testPlayer.getHP(), 110 + testPlayer.getSpecificArmorHP(testPlayer.getCurrentArmorIndex()));
    ASSERT_EQ(testPlayer.getATK(), 5 + testPlayer.getSpecificWeaponATK(testPlayer.getCurrentWeaponIndex()));

    ASSERT_TRUE(testPlayer.getMove1Name() == "Slash");
    ASSERT_TRUE(testPlayer.getMove2Name() == "Reckless Charge");
}

TEST(PlayerTest, ClassConstructorMage) {
    Player testPlayer(2, "Jimmy");

    ASSERT_TRUE(testPlayer.getPlayerClass() == "Mage");
    ASSERT_TRUE(testPlayer.getName() == "Jimmy");

    ASSERT_EQ(testPlayer.getCurrentWeaponIndex(), 0);
    ASSERT_EQ(testPlayer.getCurrentArmorIndex(), 0);

    ASSERT_EQ(testPlayer.getSpecificWeaponATK(testPlayer.getCurrentWeaponIndex()), 5);
    ASSERT_EQ(testPlayer.getSpecificArmorHP(testPlayer.getCurrentArmorIndex()), 10);

    ASSERT_EQ(testPlayer.getMaxHP(), 75 + testPlayer.getSpecificArmorHP(testPlayer.getCurrentArmorIndex()));
    ASSERT_EQ(testPlayer.getHP(), 75 + testPlayer.getSpecificArmorHP(testPlayer.getCurrentArmorIndex()));
    ASSERT_EQ(testPlayer.getATK(), 5 + testPlayer.getSpecificWeaponATK(testPlayer.getCurrentWeaponIndex()));

    ASSERT_TRUE(testPlayer.getMove1Name() == "Fireball");
    ASSERT_TRUE(testPlayer.getMove2Name() == "Recite Incantation");
}

TEST(PlayerTestSuite, ConstructorThrow) {
    ASSERT_ANY_THROW({
        Player testPlayer(4, "Jimmy");
    });
}

TEST(PlayerTestSuite, ConstructorArcher) {
    Player testPlayer(3, "Jimmy");

    ASSERT_TRUE(testPlayer.getPlayerClass() == "Archer");
    ASSERT_TRUE(testPlayer.getName() == "Jimmy");

    ASSERT_EQ(testPlayer.getCurrentWeaponIndex(), 0);
    ASSERT_EQ(testPlayer.getCurrentArmorIndex(), 0);

    ASSERT_EQ(testPlayer.getSpecificWeaponATK(testPlayer.getCurrentWeaponIndex()), 4);
    ASSERT_EQ(testPlayer.getSpecificArmorHP(testPlayer.getCurrentArmorIndex()), 10);

    ASSERT_EQ(testPlayer.getMaxHP(), 90 + testPlayer.getSpecificArmorHP(testPlayer.getCurrentArmorIndex()));
    ASSERT_EQ(testPlayer.getHP(), 90 + testPlayer.getSpecificArmorHP(testPlayer.getCurrentArmorIndex()));
    ASSERT_EQ(testPlayer.getATK(), 5 + testPlayer.getSpecificWeaponATK(testPlayer.getCurrentWeaponIndex()));

    ASSERT_TRUE(testPlayer.getMove1Name() == "Shoot");
    ASSERT_TRUE(testPlayer.getMove2Name() == "Snipe");
}

TEST(PlayerTestSuite, EquipAndGetMoveNames) {
    Player testPlayer(3, "Jimmy");

    ASSERT_EQ(testPlayer.getMaxHP(), 100);
    ASSERT_EQ(testPlayer.getHP(), 100);
    ASSERT_EQ(testPlayer.getATK(), 9);

    ASSERT_TRUE(testPlayer.getMove1Name() == "Shoot");
    ASSERT_TRUE(testPlayer.getMove2Name() == "Snipe");

    testPlayer.equipArmor(1);
    testPlayer.equipWeapon(1);

    ASSERT_EQ(testPlayer.getCurrentArmorIndex(), 1);
    ASSERT_EQ(testPlayer.getCurrentWeaponIndex(), 1);

    ASSERT_EQ(testPlayer.getATK(), 10);
    ASSERT_EQ(testPlayer.getMaxHP(), 102);
    ASSERT_EQ(testPlayer.getHP(), 102);

    ASSERT_TRUE(testPlayer.getMove1Name() == "Fire");
    ASSERT_TRUE(testPlayer.getMove2Name() == "Execute");

    testPlayer.setHP(-10);
    testPlayer.equipArmor(0);

    ASSERT_EQ(testPlayer.getHP(), 10);
}

TEST(PlayerTestSuite, GetCurrentEquipmentName) {
    Player testPlayer(3, "Jimmy");

    ASSERT_TRUE(testPlayer.getWeaponName(testPlayer.getCurrentWeaponIndex()) == "Starter Bow");
    ASSERT_TRUE(testPlayer.getArmorName(testPlayer.getCurrentArmorIndex()) == "Sylvan Leathers");
}

TEST(PlayerTestSuite, GetEquipmentListSize) {
    Player testPlayer(3, "Jimmy");

    ASSERT_EQ(testPlayer.getWeaponListSize(), 7);
    ASSERT_EQ(testPlayer.getArmorListSize(), 7);
}