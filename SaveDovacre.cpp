#include <iostream>
#include <cstring>
#include "yanisLib.h"

using namespace std;

int map[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 6, 0, 1, 3, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 0, 1, 0, 1},
    {1, 4, 1, 1, 0, 0, 0, 1, 2, 1},
    {1, 0, 1, 0, 0, 0, 5, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
char pieces[10][10][30] = {
    {"Tunnel",              "Tunnel",               "Tunnel",               "Tunnel",               "Tunnel",               "Tunnel",               "Tunnel",               "Tunnel",               "Tunnel",               "Tunnel"},
    {"Tunnel", "Depart",              "Couloir humide",        "Salle vide",           "Salle vide",           "Tunnel",               "Cave sombre du Sheitan", "Passage etroit",          "Alcove sombre",          "Tunnel"},
    {"Tunnel", "Antichambre",         "Salle de pierre",       "Croisement",           "Salle effondree",      "Salle obscure",        "Tunnel",               "Passage sinueux",         "Petit reduit",           "Tunnel"},
    {"Tunnel", "Tunnel ancien",       "Salle des echos",       "Tunnel",               "Salle creuse",         "Piece poussiereuse",   "Salle de repos",         "Tunnel",               "Taniere d'ombre",        "Tunnel"},
    {"Tunnel", "Tunnel",              "Tunnel",                "Tunnel",               "Escalier delabre",     "Galerie etroite",      "Abri temporaire",        "Tunnel",               "Puit de lumiere",        "Tunnel"},
    {"Tunnel", "Ancienne forge",      "Tunnel",                "Tunnel",               "Crypte oubliee",       "Salle des gravures",   "Piece cachee",           "Tunnel",               "Chambre du Gardien",     "Tunnel"},
    {"Tunnel", "Couloir piege",       "Tunnel",                "Salle de l'eveil",     "Chambre secrete",      "Corridor effondre",    "Mine abandonee",         "Tunnel",               "Passage dissimule",      "Tunnel"},
    {"Tunnel", "Chemin detourne",     "Salle d'observation",   "Salle d'etude",        "Atelier abandonne",    "Ancien laboratoire",   "Chambre sterile",        "Tunnel",               "Salle du rituel",        "Tunnel"},
    {"Tunnel", "Reserve oubliee",     "Chambre silencieuse",   "Sanctuaire sacre",     "Entrepot maudit",      "Piece d'archives",     "Hall sans nom",          "Salle des murmures",      "Vestibule",              "Tunnel"},
    {"Tunnel",              "Tunnel",               "Tunnel",               "Tunnel",               "Tunnel",               "Tunnel",               "Tunnel",               "Tunnel",               "Tunnel",               "Tunnel"}
};


char histoires[10][10][200] = {
    {"", "", "", "", "", "", "", "", "", ""},
    {"", 
     "Ici se trouve ton point de depart... tu ne sais pas comment tu es arrive ici.", 
     "L'humidite coule sur les murs. Des traces de pas s'enfoncent dans la mousse au sol.",
     "Une piece vide... ou presque. Un vieux parchemin frosse traine dans un coin.",
     "Le silence y est pesant. Tu entends ton souffle rebondir sur les murs.",
     "", 
     "L'air est glacial. Des ossements jonchent le sol. Quelque chose t'observe... C'est Dovacre, ton tiktokeur prefere ! \n Tu l'as trouve !",
     "Tu dois te baisser pour passer. Une lueur etrange provient du bout du couloir.",
     "Une alcove creusee dans la pierre. Peut-etre un autel... ou une cachette oubliee.",
     ""},
     
    {"", 
     "Tu sens que cette piece servait autrefois de sas. Des marques anciennes gravees sur les murs.",
     "Le sol est pave de grandes dalles. Des motifs runiques s'effacent lentement.",
     "Plusieurs chemins s'offrent a toi. Choisis bien, certains ne pardonnent pas.",
     "Des blocs de pierre jonchent le sol. Un eboulement ? Ou une attaque ?",
     "Les tenebres y sont plus denses. Meme ta torche semble faiblir ici.",
     "",
     "Le passage serpente, retrecit, puis s'elargit soudainement dans un souffle froid.",
     "Un petit renfoncement, assez etroit pour s'y reposer... ou se cacher.",
     ""},
     
    {"", 
     "Les murs semblent pleurer. Une ancienne voix resonne parfois, a peine audible.",
     "Ta voix revient a toi en echo. Comme si la salle ne voulait pas que tu partes.",
     "", 
     "Tu ressens des vibrations dans le sol. Quelque chose de massif est passe ici.",
     "La poussiere vole a chacun de tes pas. Une paix oubliee regne ici.",
     "Une lumiere tamisee t'apaise. Tu pourrais presque t'endormir... presque.",
     "", 
     "Un grognement lointain. L'odeur fauve d'une bete encore presente.",
     ""},
     
    {"", "", "", "", 
     "Des marches usees menent vers l'inconnu. Chaque pas resonne comme un avertissement.",
     "Un couloir si etroit que tu dois y avancer de biais. Tu sens les murs te froler.",
     "Un endroit calme, peut-etre jadis une salle de repos pour les aventuriers.",
     "", 
     "Un puits naturel laisse entrer un rai de lumiere celeste. Tu te sens observe.",
     ""},
     
    {"", 
     "Des outils rouilles gisent au sol. Tu reconnais les restes d'une vieille forge. \nTu trouves par terre un vieux couteau, peut etre te sera-t-il util plus tard ?",
     "", "", 
     "Un cercueil ouvert trone au centre. Des chaines brisees en sortent.",
     "Des symboles sont graves sur les murs. Tu ne comprends pas, mais ils te mettent mal a l'aise.",
     "Un panneau coulisse... Derriere, un coffre et un journal date d'un siecle.",
     "", 
     "La piece est gardee par une presence invisible. Ton coeur bat plus vite ici. \nUn Skid originel t'empeche de passer, que vas-tu faire ?",
     ""},
     
    {"", 
     "Tu sens une legere pression au sol... Un piege ? Mieux vaut etre prudent.",
     "", 
     "Des fresques murales decrivent un rituel oublie. Tu ne peux detacher les yeux.",
     "Des mecanismes complexes recouvrent les murs. Cette piece est bien plus recente.",
     "Un eboulement a ecrase tout ce qui s'y trouvait. Seuls quelques objets depassent des decombres.",
     "Tu arrives dans une piece sombre mais avec des lanternes. Tu apperçoit des charriots et des rails... Il s'agit tu vieille mine. \nTu trouve une picohe sur le sol",
     "", 
     "Tu remarques une ouverture dissimulee dans le mur du fond. Ou mene-t-elle ?",
     ""},
     
    {"", 
     "Un sentier secondaire. Abandonne, mais plus sur... du moins en apparence.",
     "Des papiers et instruments trainent. Des etudes oubliees ? Ou une surveillance ancienne ?",
     "Des grimoires sont empiles dans un coin. Une magie ancienne flotte dans l'air.",
     "Des outils rouilles, du verre brise. Ce lieu a ete saccage recemment.",
     "Des experiences inachevees. Une alchimie etrange semble encore impregner l'air.",
     "Aucune poussiere, aucun bruit. Cette chambre semble hors du temps.",
     "", 
     "Des bougies consumees. Du sang seche. Un rituel a eu lieu recemment.",
     ""},
     
    {"", 
     "Des etageres effondrees, des jarres brisees. Tu sens l'odeur des vieux grimoires.",
     "Tu entends des murmures, des mots inconnus. Le silence s'alourdit.",
     "Une statue au centre de la salle semble t'observer. Tu detournes vite le regard.",
     "Des caisses empilees. Certaines tremblent... comme si elles contenaient quelque chose.",
     "Des feuillets disperses decrivent des secrets bien gardes. Trop bien, peut-etre.",
     "Tu entres dans une piece enorme. Elle est vide.",
     "Les murs suintent une substance etrange. Tu ne veux pas savoir ce que c'est.",
     "Un halo de lumiere entoure l'entree. Une sortie ? Ou une epreuve finale ?",
     ""},
     
    {"", "", "", "", "", "", "", "", "", ""}
};

int positionX = 1;
int positionY = 1;
bool couteau = false;
bool pioche = false;
bool parchemin = false;
bool finit = false;

void intro();
void menu();
void histoire();
void fin();

int main(){
    intro();
    menu();
    char entry[20];

    while(entry!="Exit"&& entry!="exit" && finit==false){
        bool positionValide = false;
        strcpy(entry, input("Action : "));
        system("cls");
        
        if(strcmp(entry, "Gauche")==0){
            if(map[positionX][positionY-1]==1){
                print("Mouvement impossible, tu fonces dans un mur !");
            }
            else{
                positionY-=1;
                positionValide = true;
            }

        }
        else if(strcmp(entry, "Droite")==0){
            if(map[positionX][positionY+1]==1){
                print("Mouvement impossible, tu fonces dans un mur !");
            }
            else{
                positionY+=1;
                positionValide = true;
            }

        }
        else if(strcmp(entry, "Bas")==0){
            if(map[positionX+1][positionY]==1){
                print("Mouvement impossible, tu fonces dans un mur !");
            }
            else{
                positionX+=1;
                positionValide = true;
            }

        }
        else if(strcmp(entry, "Haut")==0){
            if(map[positionX-1][positionY]==1){
                print("Mouvement impossible, tu fonces dans un mur !");
            }
            else{
                positionX-=1;
                positionValide = true;
            }

        }
        else if(strcmp(entry, "exit")==0 || strcmp(entry, "Exit")==0){
            system("pause");
            system("exit");
        }
        else if(strcmp(entry, "Parchemin")==0){
            positionValide = true;
            print("Voici le contenu du parchemin : \nTu as commence ta quete en position (1;1), Dovacre se trouve en (6;1) ");

        }
        else if(strcmp(entry, "Pioche")==0){
            if(!pioche){
                print("Tu ne possede pas de pioche !");
            }
            else{
                char* entryPioche = input("Choisir le mut a detruire (Haut, Bas, ...) : ");

                if(strcmp(entryPioche, "Droite")==0 && map[positionX][positionY+1]==1 && positionY+1!= 9){
                    print("Vous creusez... Vous pouvez désormais aller dnas cette direction .");
                    map[positionX][positionY+1] = 0;
                }
                else if(strcmp(entryPioche, "Gauche")==0 && map[positionX][positionY-1]==1 && positionY-1!= 9){
                    print("Vous creusez... Vous pouvez désormais aller dnas cette direction.");
                    map[positionX][positionY-1] = 0;
                }
                else if(strcmp(entryPioche, "Haut")==0 && map[positionX-1][positionY]==1 && positionX-1!= 9){
                    print("Vous creusez... Vous pouvez désormais aller dnas cette direction.");
                    map[positionX-1][positionY] = 0;
                }
                else if(strcmp(entryPioche, "Bas")==0 && map[positionX+1][positionY]==1 && positionX+1!= 9){
                    print("Vous creusez... Vous pouvez désormais aller dnas cette direction.");
                    map[positionX+1][positionY] = 0;
                }
                else{
                    print("Merci d'entrer une valeur valide.");
                }
            }

        }
        else{
            print("Merci d'entrer une action valide");
        }
        print("\n");
        if(positionValide){
            histoire();
        }
        if(map[positionX][positionY]==2){
            if(couteau){
                bool bonChoix = false;
                while(!bonChoix){
                    char* choix = input("Vous possédez un couteau, Voulez-vous l'utiliser ? (Oui/Non) : ");
                    if(strcmp(choix, "Oui")==0){
                        bonChoix = true;
                    }
                    else if (strcmp(choix, "Non")==0){
                        print("Ok, tu fais demis-tour.");
                        positionX+=1;
                        bonChoix = true;
                    }
                    else{
                        print("Merci d'entrer une valeure valide.");
                    }
                }
            }
            else{
                print("Malheuresement tu n'as pas d'arme et fait demis-tour");
                positionX+=1;
            }
        }
        else if(map[positionX][positionY]==3){
            print("Bien joué !! tu as finis le jeu");
            fin();
            finit = true;   
        }
        else if(map[positionX][positionY]==4){
            bool bonChoix = false;
            while(!bonChoix){
                char* choix = input("Veux-tu le recuperer ? (Oui/Non) : ");
                if(strcmp(choix, "Oui")==0){
                    couteau = true;
                    bonChoix = true;
                }
                else if (strcmp(choix, "Non")==0){
                    print("Ok, dommage");
                    bonChoix = true;
                }
                else{
                    print("Merci d'entrer une valeure valide.");
                }
            }
        }
        else if(map[positionX][positionY]==5){
            bool bonChoix = false;
            while(!bonChoix){
                char* choix = input("Veux-tu la recuperer ? (Oui/Non) : ");
                if(strcmp(choix, "Oui")==0){
                    pioche = true;
                    bonChoix = true;
                    print("Elle te permet de creuser un mur pour le traverser. \nPour l'utiliser, tu peux écrire 'Pioche' dans la commande et choisir la direction du mur.");
                }
                else if (strcmp(choix, "Non")==0){
                    print("Ok, dommage");
                }
                else{
                    print("Merci d'entrer une valeure valide.");
                }
            }
        }
        else if(map[positionX][positionY]==6){
            bool bonChoix = false;
            while(!bonChoix){
                char* choix = input("Veux-tu le recuperer ? (Oui/Non) : ");
                if(strcmp(choix, "Oui")==0){
                    parchemin = true;
                    bonChoix = true;
                    print("Voici son contenu : \nTu as commence ta quete en position (1;1), Dovacre se trouve en (6;1) \nTu peux ecrire 'Parchemin'§ dans la commande pour le lire a nouveau.");
                }
                else if (strcmp(choix, "Non")==0){
                    print("Ok, dommage");
                    bonChoix = true;
                }
                else{
                    print("Merci d'entrer une valeure valide.");
                }
            }
        }

        print("\n");

    }
    char* exit = input("Appuyer pour fermer...");
};

void intro() {
    print("Tu ouvres les yeux. Le sol est froid, l'air vicie te brule les narines.\n");
    print("Autour de toi, la penombre. Des murs de pierre suintants t'entourent,\n");
    print("sculptes par le temps et les secrets. Le silence est pesant... trop pesant.\n");
    print("\n");
    
    print("Tu ne te souviens plus comment tu es arrive ici.\n");
    print("Tout ce que tu sais, c'est qu'il te faudra avancer. Explorer.\n");
    print("Et survivre...\n");
    print("\n");

    print("Mais attention... chaque piece cache une histoire.\n");
    print("Chaque couloir, un choix. Chaque detour, un danger.\n");
    print("\n");

    print("Equipe seulement de ton courage (et d'une torche faiblarde),\n");
    print("tu t'appretes a affronter les mysteres du labyrinthe oublie.\n");
    print("\n");

    print("Tape une direction (Gauche, Droite, Haut, Bas) pour commencer ton periple.\n");
    print("Bonne chance, aventurier.\n");

    print("============================================\n");
    print("Regles\n");
    print("============================================\n\n");
    print("Les regles du jeu sont simples, tu es apparu dans un labyrinthe\n");
    print("inconnu ou Dovacre (le meilleur tiktokeur de tous les temps) est\n");
    print("retenu en captivite. Pour cela, tu dois te deplacer dans le labyrinthe\n");
    print("en ecrivant 'Droite', 'Gauche', 'Haut', ou 'Bas' (ps: n'oublie pas les majuscules)\n");
    print("Bonne chance !\n");
    system("pause"); 
    

}



void menu(){
    char* entry = "test";
    while(strcmp(entry, "1")==1 && strcmp(entry, "2")==1 && strcmp(entry, "3")==1){
        system("cls");
        print(R"( .d8888b.                                  8888888b.                                                      
d88P  Y88b                                 888  "Y88b                                                     
Y88b.                                      888    888                                                     
 "Y888b.    8888b.  888  888  .d88b.       888    888  .d88b.  888  888  8888b.   .d8888b 888d888 .d88b.  
    "Y88b.     "88b 888  888 d8P  Y8b      888    888 d88""88b 888  888     "88b d88P"    888P"  d8P  Y8b 
      "888 .d888888 Y88  88P 88888888      888    888 888  888 Y88  88P .d888888 888      888    88888888 
Y88b  d88P 888  888  Y8bd8P  Y8b.          888  .d88P Y88..88P  Y8bd8P  888  888 Y88b.    888    Y8b.     
 "Y8888P"  "Y888888   Y88P    "Y8888       8888888P"   "Y88P"    Y88P   "Y888888  "Y8888P 888     "Y8888  
                                                                                                          
                                                                                                          
                                                                                                          )");
        print("\n[1] Exit                              [2]Start                                   [3]Help\n\n");
        
        entry = input("Choix : ");

        if(strcmp(entry, "1")==0){
            system("exit");
        }
        else if(strcmp(entry, "2")==0){
            print("Lancement...\n");
            system("pause");
        }
        else if(strcmp(entry, "3")==0){
            system("start tiktok.com/@yanisanton09");
        }
        else{
            ("Merci d'entrer un choix valide.");
            system("pause");
        }

    }
}

void histoire(){
    cout << "Piece : " << pieces[positionX][positionY] << "\n";
    cout << histoires[positionX][positionY] << "\n";
}
void fin(){
    print("\n\nCredits :\t\t Yanis \nSous-titres :\t\t Yanis \nHistoire :\t\t Yanis & ChatGPT \nCode :\t\t Yanis \nMention special :\t\t Dovacre \nJe sais qu'il n'y a pas de sous-titres MDR XD\n\n");
}