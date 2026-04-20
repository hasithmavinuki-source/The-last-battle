#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <strings.h>


int main(void){
    int user_squad = 3 ;
    int com_squad = 3 ;
    int round = 0 ;
    srand(time(NULL));
    typedef char string[10000] ;
    string lineup =
"        MAGE              ARCHER             WARRIOR\n"
"                 _           /`.                ^\n"
"          /|    | |        /   :.              / \\\n"
"        _/_\\_  >_<        /     \\\\            | |\n"
"       .-\\-/.   |      ,;/,      ::          |.|\n"
"      /  | | \\_ |   ___:c/.(      ||         |.|\n"
"      \\ \\| |\\__(/ ,'  _|:)>>>--,- ))>       |:|        __\n"
"      /(`---')   | (  '---'\\--'` _,'||    ,_|:|_,     /  )\n"
"     / /     \\  |  `--.    \\ ,-'   ;;      (Oo      / _I_\n"
"  _.'  \\'-'  /  |      |    \\|    //        +\\ \\  || __|\n"
"  `----'`=-='   '       |     \\   ;'            \\ \\||___|\n"
"                         |_____|\\,'              \\ /.:.\\-\\\n"
"                         :     :                  |.:. /-----\\\n"
"                         |  ,  |                  |___|::oOo::|\n"
"                         | : \\ :                  /   |:<_T_>:|\n"
"                         | | : :                 |_____\\ ::: /\n"
"                         | | | |                  | |  \\ \\:/\n"
"                         | | |_`.                 | |   | |\n"
"                         '--`                     \\ /   | \\___\n"
"                                                   / |   \\_____\\\n"
"                                                   `-'\n";
    printf("%s", lineup);

    typedef enum { ALIVE , DEAD} status;
    typedef struct {char role[15] ;int life ; int attack_power ;status still_alive ; }characteristics;
    characteristics team_user[] = {{"Mage", 20 , 10 , ALIVE}, {"Warrior", 25 , 8 , ALIVE}, {"Archer", 20 , 7 , ALIVE}};
    characteristics team_com[] = {{"Mage", 20 , 10 , ALIVE}, {"Warrior", 25 , 8 , ALIVE}, {"Archer", 20 , 7 , ALIVE}};

    bool until_game_end = true ;

    while(until_game_end){
        char user_fighter[15] = "" ;
        printf("\n=== YOUR TURN ===\n");
        printf("Select a fighter for this round (Mage|Warrior|Archer): ");
        fgets(user_fighter , sizeof(user_fighter), stdin);
        user_fighter[strcspn(user_fighter , "\n")] = '\0' ;
        if (strcasecmp(user_fighter,"Mage") != 0 && strcasecmp(user_fighter,"Warrior") != 0 && strcasecmp(user_fighter,"Archer") != 0){
            printf("Invalid Input.");
            continue ;
        }
        if ((strcasecmp(user_fighter , team_user[0].role) == 0) && team_user[0].still_alive == DEAD){
            printf("This fighter is already dead!\n");
            continue;

        }
        else if ((strcasecmp(user_fighter , team_user[1].role) == 0) && team_user[1].still_alive == DEAD){
            printf("This fighter is already dead!\n");
            continue;
        }
        else if ((strcasecmp(user_fighter , team_user[2].role) == 0) && team_user[2].still_alive == DEAD){
            printf("This fighter is already dead!\n");
            continue; 
        }
        
        printf("Computer is choosing its fighter ....\n");
        sleep(2);
        int rand_num ;
        do{
        rand_num = rand() % (3);
        }while(team_com[rand_num].still_alive== DEAD);
        char com_fighter[15] ; 
        strcpy(com_fighter,team_com[rand_num].role) ;
        round ++ ;
        
        printf("ROUND %d\n%s ✘ %s\n",round ,user_fighter,com_fighter);

        switch(rand_num){
            case 0 :
                if (strcasecmp(user_fighter,"Mage") == 0){
                    team_user[0].life -= team_com[0].attack_power ;
                    printf("Team user's mage life 10--\n");
                    printf("Team user's mage life = %d\n", team_user[0].life);
                    team_com[0].life -= team_user[0].attack_power ;
                    printf("Team com's mage life 10--\n");
                    printf("Team com's mage life = %d\n", team_com[0].life);
                    if (team_user[0].life <= 0){
                        printf("Team User's Mage is dead ..):\n");
                        team_user[0].still_alive = DEAD ;
                        user_squad -- ;
                    }
                    

                }
                else if (strcasecmp(user_fighter,"Warrior") == 0){
                    team_user[1].life -= team_com[0].attack_power ;
                    printf("Team user's Warrior life 10--\n");
                    printf("Team user's Warrior life = %d\n", team_user[1].life);
                    team_com[0].life -= team_user[1].attack_power ;
                    printf("Team com's Mage life 8--\n");
                    printf("Team com's mage life = %d\n", team_com[0].life);
                    if (team_user[1].life <= 0){
                        printf("Team User's Warrior is dead .. ):\n");
                        team_user[1].still_alive = DEAD ;
                        user_squad -- ;

                    }

                }
                else if (strcasecmp(user_fighter,"Archer") == 0){
                    team_user[2].life -= team_com[0].attack_power ;
                    printf("Team user's Archer life 10--\n");
                    printf("Team user's Archer life = %d\n", team_user[2].life);
                    team_com[0].life -= team_user[2].attack_power ;
                    printf("Team com's Mage life 7--\n");
                    printf("Team com's Mage life = %d\n", team_com[0].life);
                    if (team_user[2].life <= 0){
                        printf("Team User's Archer is dead .. ):\n");
                        team_user[2].still_alive = DEAD ;
                        user_squad -- ;
                    }

                }
                if (team_com[0].life <= 0){
                        printf("Team Com's Mage is dead .. ):\n");
                        team_com[0].still_alive = DEAD ;
                        com_squad -- ;
                }
                break ;
            case 1 :
                if (strcasecmp(user_fighter,"Mage") == 0){
                    team_user[0].life -= team_com[1].attack_power ;
                    printf("Team user's mage life 8--\n");
                    printf("Team user's mage life = %d\n", team_user[0].life);
                    team_com[1].life -= team_user[0].attack_power ;
                    printf("Team com's Warrior life 10--\n");
                    printf("Team com's Warrior life = %d\n", team_com[1].life);
                    if (team_user[0].life <= 0){
                        printf("Team User's Mage is dead .. ):\n");
                        team_user[0].still_alive = DEAD ;
                        user_squad -- ;
                    }    

                }
                else if (strcasecmp(user_fighter,"Warrior") == 0){
                    team_user[1].life -= team_com[1].attack_power ;
                    printf("Team user's Warrior life 8--\n");
                    printf("Team user's Warrior life = %d\n", team_user[1].life);
                    team_com[1].life -= team_user[1].attack_power ;
                    printf("Team com's Warrior life 8--\n");
                    printf("Team com's Warrior life = %d\n", team_com[1].life);
                    if (team_user[1].life <= 0){
                        printf("Team User's Warrior is dead .. ):\n");
                        team_user[1].still_alive = DEAD ;
                        user_squad -- ;
                    }

                }
                else if (strcasecmp(user_fighter,"Archer") == 0){
                    team_user[2].life -= team_com[1].attack_power ;
                    printf("Team user's Archer life 8--\n");
                    printf("Team user's Archer life = %d\n", team_user[2].life);
                    team_com[1].life -= team_user[2].attack_power ;
                    printf("Team com's Warrior life 7--\n");
                    printf("Team com's Warrior life = %d\n", team_com[1].life);
                    if (team_user[2].life <= 0){
                        printf("Team User's Archer is dead .. ):\n");
                        team_user[2].still_alive = DEAD ;
                        user_squad -- ;
                    }

                }
                if (team_com[1].life <= 0){
                        printf("Team Com's Warrior is dead .. ):\n"); 
                        team_com[1].still_alive = DEAD ;
                        com_squad -- ;
                }
                break ;
            case 2 :
                if (strcasecmp(user_fighter,"Mage") == 0){
                    team_user[0].life -= team_com[2].attack_power ;
                    printf("Team user's mage life 7--\n");
                    printf("Team user's mage life = %d\n", team_user[0].life);
                    team_com[2].life -= team_user[0].attack_power ;
                    printf("Team com's Archer life 10--\n");
                    printf("Team com's Archer life = %d\n", team_com[2].life);
                    if (team_user[0].life <= 0){
                        printf("Team User's Mage is dead .. ):\n");
                        team_user[0].still_alive = DEAD ;
                        user_squad -- ;
                    }

                }
                else if (strcasecmp(user_fighter,"Warrior") == 0){
                    team_user[1].life -= team_com[2].attack_power ;
                    printf("Team user's Warrior life 7--\n");
                    printf("Team user's Warrior life = %d\n", team_user[1].life);
                    team_com[2].life -= team_user[1].attack_power ;
                    printf("Team com's Archer life 8--\n");
                    printf("Team com's Archer life = %d\n", team_com[2].life);
                    if (team_user[1].life <= 0){
                        printf("Team User's Warrior is dead .. ):\n");
                        team_user[1].still_alive = DEAD ;
                        user_squad -- ;
                    }

                }
                else if (strcasecmp(user_fighter,"Archer") == 0){
                    team_user[2].life -= team_com[2].attack_power ;
                    printf("Team user's Archer life 7--\n");
                    printf("Team user's Archer life = %d\n", team_user[2].life);
                    team_com[2].life -= team_user[2].attack_power ;
                    printf("Team com's Archer life 7--\n");
                    printf("Team com's Archer life = %d\n", team_com[2].life);
                    if (team_user[2].life <= 0){
                        printf("Team User's Archer is dead .. ):\n");
                        team_user[2].still_alive = DEAD ;
                        user_squad -- ;
                    }

                }
                if (team_com[2].life <= 0){
                        printf("Team Com's Archer is dead .. ):\n");
                        team_com[2].still_alive = DEAD ;
                        com_squad -- ;
                }
                break ;
        }
        sleep(1);
        if (user_squad <= 0 && com_squad<= 0){
            printf("It's a draw !\n");
            until_game_end = false ;
        }
        else if(user_squad <= 0){
            printf("You lose ! Computer won !!\n");
            until_game_end = false ;
        }
        else if(com_squad <= 0) {
            printf("You Won!\n");
            until_game_end = false ;
        }

        
    }

    
    return 0 ;
}