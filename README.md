
# A Text-Based Role-Playing Game (RPG) 
 > Authors: \<[Jake Wang](https://github.com/DoubleClik)\> \<[Ashna Pradhan](https://github.com/ashnapradhan)\> \<[Chau Nguyen-Ho](https://github.com/ChauNguyenHo)\> \<[Joseph de Leon](https://github.com/jovialjoe)\>

## Project Description
 > This game allows users to choose among different playable character classes to play: such as a Swordsman, a Mage, and an Archer. Each of these playable character classes come packaged with different playstyles and weapons. Along with weapons, the player collects armor along their journey and they become stronger by equipping better armor and weapons througout the game. After selecting a character, the player is prompted with a narrative during each encounter, to proceed with their story, they must make one of two choices based upon the prompt. This will lead to a variety of events, such as combat, equipment upgrades, or heals. This repeats until the player reaches the Demon King's castle or die trying. 
 > ### Importance
 > This project is important to us because we all like video games and want to experience what it is like to program one. As players who are interested in rpgs, it's a fun learning experience to have the chance to create and design one ourselves.
 > ### Languages/Tools/Technologies
 > * C++ will be the main coding language we use to program the game
 > * cmake will help us compile the program
 > * googletest will help us create test suites
>  * Gcov and Lcov will help us review code coverage of our unit tets
>  * Valgrind will help us clean up memory leaks
 > ### Input/Output
 > * The input of the program will be the user selections made by the player. This can include character naming and class selection, attack selection, power selection, etc.
 > * The game starts with the user's input for their name and playable character class (Archer, Mage, Swordsman). From there the user will select choices by typing '1' or '2' into the terminal to proceed through the game to reach the end result of fighting and defeating the boss. 
 > * The output of the program will be the outcome of the encounters as the player chooses the routes in game. This may include decrease in character health or character powers. The end result of the game would either be the win or loss agains the boss and the choice to end the game or play again. 
 > ### Features
 > * Multiple Playable Characters that offer unique playstyles and weapons
>  * A multitude of weapons that are rewarded from good prompt choices
>  * A multitude of armor sets that help the player survive in order to reach the boss that are rewarded from good prompt choices
>  * Encounters that prompt the player to pick a choice. Will result in fight, healing, or an equipment upgrade.
>  * Turn based combat versus enemies
>  * 4 Easy enemies
>  * 4 Medium enemies
>  * 4 Hard enemies
 >
## User Interface Specification
### Navigation Diagram
![navigation diagram](https://github.com/cs100/final-project-hnguy480_jwang948_jdel238_aprad036/assets/162086940/a8bf4160-0270-4a1c-9356-4bee26420f42)

The game starts with the user choosing their character, and from there they’ll be led to the starting prompt where they’re able to choose between two random encounters. One of the encounters will be a battle that’ll lead to the random outcome and the other encounter would be the user getting a random outcome such as reward, heal, or damage. After every encounter/random outcome, the distance between the user and the final boss will decrease by a random amount. The game ends when the distance equals 0 and the user defeats the boss. The user is then given the choice to play again which redirects to the intro of the game. 



### Screen Layouts
Our screen layout can be found [here](https://docs.google.com/presentation/d/1jLVSlqnUy78NUIknS1lVQYdCeTYLW93XvH4jcUJTIqY/edit?usp=sharing) . This screen layout consists of various screens that display various game results and help the user navigate the game. 
## Class Diagram
<img width="1000" alt="Screenshot 2024-06-07 at 3 29 24 AM" src="https://github.com/cs100/final-project-hnguy480_jwang948_jdel238_aprad036/assets/165941732/d0eb7db9-3cf8-44da-b2c5-c2d1d911e516">


**UML Class Diagram SOLID Principles**

**Player**:
Previously, the class “player” was a class “character” used as a template for four other classes that would behave differently. This prior implementation violates the LSP. This violation caused us to merge these classes into a single class and use a signal variable inside “player” to signal other classes to act differently and according to the chosen player class. This approach simplifies player and playable class data storage, which will help us code the interactions of this class to other classes.

**Prompter**:
This class was split from the “game” class. We used to have the “game” class issue prompts to the user, but that violated SRP. Therefore, we split them and “prompter” class stores and outputs all encounter prompts and user actions, while the “game” class runs those prompts from “prompter” and can simply run the game. This helps with coding because it helps to compartmentalize output aspects of the game away from the “game” class and increase code readability.

**fightSystem**:
Similar to “prompter” class’ reasoning. This class was split from the “game” class for violating SRP. The game class was previously planned to run all the in-game fight logic, but now that logic of damage calculation and that affecting enemy and player HP will be moved into the “fightSystem” class. This helps with coding because it helps to compartmentalize fighting aspects of the game away from the “game” class and increase code readability. Thus, we fulfill SRP as the responsibility of managing the turn-based fight is now within a separate class.

**Enemy**: 
Enemy used to be derived from a “character” class. However, because of our old implementation, “enemy” class violated LSP. There would be other derivatives from the “character” class that would work differently from “enemy,” so this was scrapped. Now enemy is a stand-alone class and this helps with coding because tying enemy to the “character” class used for players of the game caused confusion and lacked clarity. This will also allow for smoother interactions with other classes when aspects of the Enemy object need to be changed during a fight.
 
 ## Screenshots
 <img width="621" alt="input1" src="https://github.com/cs100/final-project-hnguy480_jwang948_jdel238_aprad036/assets/165941732/3824454a-fa93-4db7-b769-86d70968cf65">
 
 Get player's name
 
 <img width="392" alt="input2" src="https://github.com/cs100/final-project-hnguy480_jwang948_jdel238_aprad036/assets/165941732/e86e13f7-2c48-4f1d-b258-3c91edb2ee4e">

 Choose player class 
 
 <img width="864" alt="input3" src="https://github.com/cs100/final-project-hnguy480_jwang948_jdel238_aprad036/assets/165941732/804fb382-3fb2-4504-b11f-aef083e3da94">

 Choose fight path
 
 <img width="614" alt="input4" src="https://github.com/cs100/final-project-hnguy480_jwang948_jdel238_aprad036/assets/165941732/0f60b676-7b0d-4b9d-b3dd-9473c02ecb03">

 Choose attack move
 
 <img width="591" alt="input5" src="https://github.com/cs100/final-project-hnguy480_jwang948_jdel238_aprad036/assets/165941732/df30d89a-caa2-4bf7-b178-80c341e28ae8">

 Take damage from the fight
 
 <img width="597" alt="input6" src="https://github.com/cs100/final-project-hnguy480_jwang948_jdel238_aprad036/assets/165941732/3bec8c6f-4224-49c2-ab03-814a463c5207">

 Travel closer to the final boss
 
 <img width="1250" alt="input7" src="https://github.com/cs100/final-project-hnguy480_jwang948_jdel238_aprad036/assets/165941732/c7e9c4ae-659d-47c7-ac7a-e7c383428810">

Health encounter for a chance to upgrade HP
 
 <img width="1020" alt="input8" src="https://github.com/cs100/final-project-hnguy480_jwang948_jdel238_aprad036/assets/165941732/49f31ace-7181-40bc-a19f-b6e49bc3e602">

 Equipment encounter for a chance to upgrade ATK
 
 <img width="326" alt="death" src="https://github.com/cs100/final-project-hnguy480_jwang948_jdel238_aprad036/assets/165941732/d36800fc-5be6-428d-926d-72643c43f162">

 Message output when player dies
 
 <img width="567" alt="win" src="https://github.com/cs100/final-project-hnguy480_jwang948_jdel238_aprad036/assets/165941732/bc8ad785-df29-457c-9edf-80a563969206">

 Message output when player wins

 ## Installation/Usage
 > To play the game, follow the following installation and running instructions.
> 1. Clone this git repository.
> 2. Run `cmake . `.
> 3. Run `make`.
> 4. Run `./bin/play`.
> 5. Play! Input `1` or `2` when prompted with 2 choices.
> 6. To play again after winning or losing, repeat from step 4.
 ## Testing
 <img width="890" alt="Screenshot 2024-06-07 at 3 41 36 AM" src="https://github.com/cs100/final-project-hnguy480_jwang948_jdel238_aprad036/assets/165941732/1327d8e4-0f8a-4137-8b64-238921887e6d">
 
> Our project was tested through unit tests made with the help of the GTest library. GCov and LCov were used to check for code coverage by unit tests. Unit-testable classes passed testing if they passed all unit tests and had near 100% code coverage.
 
