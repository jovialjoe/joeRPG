#include <gtest/gtest.h>

#include "../header/equipment/armor.hpp"
#include "../header/equipment/weapon.hpp"

TEST(WeaponTestSuite, Constructor) {
    Weapon testWeapon(42, "Cool Sword", "Strike", "Big Strike");

    ASSERT_EQ(testWeapon.getAttackPoints(), 42);
    ASSERT_TRUE(testWeapon.getWeaponName() == "Cool Sword");
    ASSERT_TRUE(testWeapon.getMove1() == "Strike");
    ASSERT_TRUE(testWeapon.getMove2() == "Big Strike");
}

TEST(WeaponTestSuite, ChangeAttackPoints) {
    Weapon testWeapon(42, "Cool Sword", "Strike", "Big Strike");

    testWeapon.changeAttackPoints(69-42);

    ASSERT_EQ(testWeapon.getAttackPoints(), 69);
}

TEST(ArmorTestSuite, Constructor) {
    Armor testArmor(42, "Cool Armor");

    ASSERT_EQ(testArmor.getHealthPoints(), 42);
    ASSERT_TRUE(testArmor.getArmorName() == "Cool Armor");
}

TEST(ArmorTestSuite, ChangeHealthPoints) {
    Armor testArmor(42, "Cool Armor");

    testArmor.changeHealthPoints(69-42);

    ASSERT_EQ(testArmor.getHealthPoints(), 69);
}