#include <stdio.h>
#include <string.h>


typedef struct {
    char question[256];
    char options[4][100];
    int correct_answer; // Epilogi 1 eos 4
} Question;

typedef struct {
    char name[50];
    Question questions[5];
} God;

int main() {
    int i, j, k;
    int passed;
    int correct_count;
    int answer;



    God gods[12] = {
        {
            "Dias (Zeus)",
            {
                {"Pios einai o pateras tou Dia;", {"1. Kronos", "2. Ouranos", "3. Okeanos", "4. Promitheas"}, 1},
                {"Poio einai to kyrio oplo tou Dia;", {"1. Triaina", "2. Keravnos", "3. Tokso", "4. Ropalo"}, 2},
                {"Poia itan i syzygos tou Dia;", {"1. Afroditi", "2. Athina", "3. Ira", "4. Estia"}, 3},
                {"Pou gennithike o Dias symfona me ton mytho;", {"1. Ston Olympo", "2. Stin Kriti", "3. Stin Athina", "4. Sti Dilo"}, 2},
                {"Ti symbolize o aetos gia ton Dia;", {"1. Ton topo katoikias tou", "2. To iero zoo/symbolo tis dynamis tou", "3. Ton aggeliaforo tou", "4. Ton echthro tou"}, 2}
            }
        },
        {
            "Poseidonas",
            {
                {"Poio einai to stoicheio tis fysis tou Poseidona;", {"1. I fotia", "2. I gi", "3. I thalassa", "4. O aeras"}, 3},
                {"Poio einai to charakteristiko oplo tou Poseidona;", {"1. Keravnos", "2. Triaina", "3. Spathi", "4. Aspida"}, 2},
                {"Poio zoo theoreitai iero kai syndetai me ton Poseidona;", {"1. O aetos", "2. I koukouvagia", "3. To alogo", "4. O lykos"}, 3},
                {"Pios itan o adelfos tou Poseidona pou kyriarxouse ston Kato Kosmo;", {"1. Dias", "2. Adis", "3. Kronos", "4. Apollonas"}, 2},
                {"Poia poli diagwnistike me ton Poseidona gia to onoma tis;", {"1. Sparti", "2. Korinthos", "3. Athina", "4. Argos"}, 3}
            }
        },
        {
            "Athina",
            {
                {"Pios einai o pateras tis Athinas;", {"1. Zeus", "2. Kronos", "3. Poseidonas", "4. Ouranos"}, 1},
                {"Ti symvolizei i Athina kyrios stin archaia Ellada;", {"1. Ton polemo kai tin sofia", "2. Tin agapi", "3. Tin mousiki", "4. To krasi"}, 1},
                {"Poio einai to iero zoo tis Athinas;", {"1. O aetos", "2. I koukouvagia", "3. To alogo", "4. To fidi"}, 2},
                {"Me poio doro xarise tin poli stin omofoni poli tis Athinas;", {"1. Mia pigi nerou", "2. Mia elia", "3. Enan keravno", "4. Ena spathi"}, 2},
                {"Poio einai to gnosto synonymo onoma tis pou syndeetai me tin poli tis Athinas;", {"1. Pallada", "2. Kyprida", "3. Pasifai", "4. Gorgona"}, 1}
            }
        },
        {
            "Apollonas",
            {
                {"Poios einai o rolos tou Apollona stin mythologia;", {"1. Theos tis fotias", "2. Theos tis mousikis kai tou fotos", "3. Theos tis thalassas", "4. Theos tou katokosmou"}, 2},
                {"Poia itan i didymi adelfi tou Apollona;", {"1. Athina", "2. Afroditi", "3. Artemis", "4. Estia"}, 3},
                {"Pou vriskotan to pio gnosto manteio afieromeno ston Apollona;", {"1. Stin Dodoni", "2. Stous Delfous", "3. Stin Olympia", "4. Stin Dilo"}, 2},
                {"Poio oplo xrisimopoiei sychna o Apollonas stis parastaseis;", {"1. Triaina", "2. Tokso kai veli", "3. Ropalo", "4. Spathi"}, 2},
                {"Poio doro pire apo ton Ermi gia na ftiaksei ti lyra tou;", {"1. Kelyfos chelonas", "2. Ftera", "3. Chryso kleidi", "4. Magiko kathrefti"}, 1}
            }
        },
        {
            "Artemis",
            {
                {"I Artemis einai i thea ti...", {"1. tis agrias fysis kai tou kynigiou", "2. tis agapis kai tis omorfias", "3. tou emporiou", "4. tis georgias"}, 1},
                {"Me ti syndetai astrologika i thea Artemis stin archaiotita;", {"1. Me ton Ilio", "2. Me ti Selini", "3. Me ton Dias", "4. Me ton Krono"}, 2},
                {"Poio einai to agapimeno oplo tis Artemidas;", {"1. To tokso", "2. To spathi", "3. O keravnos", "4. I triaina"}, 1},
                {"Poia zoa synodeyoun sychna tin Artemis;", {"1. Ta aloga", "2. Ta elafia kai ta skytia", "3. Ta liontaria", "4. Oi aetoi"}, 2},
                {"Poios itan o pateras tis Artemidas;", {"1. O Ouranos", "2. O Dias", "3. O Apollonas", "4. O Poseidonas"}, 2}
            }
        },
        {
            "Ares",
            {
                {"Poios einai o kyrios tomeas tis dynamis tou Are;", {"1. I eirini", "2. O polemos kai i machi", "3. I thalassa", "4. I georgia"}, 2},
                {"Poioi itan oi goneis tou Are;", {"1. O Dias kai i Ira", "2. O Kronos kai i Rea", "3. O Poseidonas kai i Amfitriti", "4. O Ouranos kai i Gi"}, 1},
                {"Poio einai to iero zoo pou syndetai me ton Are;", {"1. I koukouvagia", "2. O skylos kai o gypos", "3. To alogo", "4. To fidi"}, 2},
                {"Poia thea tis omorfias eiche desmo me ton Are;", {"1. I Athina", "2. I Afroditi", "3. I Artemis", "4. I Estia"}, 2},
                {"Poio symvolo antiprosopevei tin agriotita tou Are sto pedio tis machis;", {"1. To stachy", "2. To aima kai i fotia", "3. I gi", "4. To nero"}, 2}
            }
        },
        {
            "Afroditi",
            {
                {"I Afroditi einai i thea tis...", {"1. sofias", "2. agapis kai omorfias", "3. dikaiosynis", "4. ygeias"}, 2},
                {"Pos gennithike i Afroditi symfona me ton mytho;", {"1. Apo ti gi", "2. Apo tous afrous tis thalassas", "3. Apo enan keravno", "4. Apo ti fotia"}, 2},
                {"Poios itan o nomimos syzygos tis Afroditis;", {"1. O Are", "2. O Ifaistos", "3. O Apollonas", "4. O Ermis"}, 2},
                {"Poio pouli theoreitai iero gia tin Afroditi;", {"1. Peristeri", "2. Aetos", "3. Koukouvagia", "4. Geraki"}, 1},
                {"Poio antikeimeno tis itan gnosto gia tin omorfia kai tin gonimotita;", {"1. To magiko zoni tis", "2. To spathi tis", "3. I aspida tis", "4. To kleidi tis"}, 1}
            }
        },
        {
            "Ifaistos",
            {
                {"O Ifaistos einai o theos tis...", {"1. mousikis", "2. fotias, tis metalloyrgias kai tis technis", "3. thalassas", "4. eirinis"}, 2},
                {"Pou itan o ergastirio tou Ifaistou;", {"1. Ston Olympo mono", "2. Mesa se yifainteia kai se fysika hifsteia", "3. Ston Kato Kosmo", "4. Sto vythos tis thalassas"}, 2},
                {"Poia itan i syzygos tou Ifaistou;", {"1. I Ira", "2. I Afroditi", "3. I Athina", "4. I Estia"}, 2},
                {"Poio charakteristiko eiche sto soma tou o Ifaistos;", {"1. Itan koutsos / eiche provlima sta podia", "2. Itan aoratos", "3. Itan gigantas", "4. Eiche dio kefalia"}, 1},
                {"Poio symantiko oplo efyaxe gia ton Dias;", {"1. Tin triaina", "2. Tous keravnous", "3. To tokso", "4. To ropalo"}, 2}
            }
        },
        {
            "Ermis",
            {
                {"O Ermis einai o ageliaforos ton theon kai theos tou...", {"1. emporiou kai ton klefton", "2. tis thalassas", "3. tou polemou", "4. tis georgias"}, 1},
                {"Poio einai to charaktiristiko gnorisma sta podia tou Ermi;", {"1. Pterota sandalia", "2. Varia mpotes", "3. Xrysa nychia", "4. Alysides"}, 1},
                {"Poio mousiko organo efyaxe o Ermis se paidiki ilikia apo kelyfos chelonas;", {"1. To draylo", "2. Ti lyra", "3. Ton avlo", "4. Tin kithara"}, 2},
                {"Poio einai to antikeimeno pou kratei sto xeri tou kai onomazetai kerykeio;", {"1. Ena ravdi me dyo fidia", "2. Mia triaina", "3. Ena spathi", "4. Ena kleidi"}, 1},
                {"Poios einai o pateras tou Ermi;", {"1. O Ouranos", "2. O Dias", "3. O Kronos", "4. O Apollonas"}, 2}
            }
        },
        {
            "Dimitra",
            {
                {"I Dimitra einai i thea tis...", {"1. georgias, tis gis kai tis sporas", "2. tis nyxtas", "3. tou polemou", "4. tis mousikis"}, 1},
                {"Poia itan i kori tis Dimitras pou tin arpaxe o Adis;", {"1. I Persefoni", "2. I Ariadni", "3. I Eleni", "4. I Pandora"}, 1},
                {"Pos epidra i thlipsi tis Dimitras sti fysi otan chanei tin kori tis;", {"1. Dimiourgeitai to kalokairi", "2. Efevgetai o chemonas (i gi den karpofora)", "3. Peftei vrochi fotias", "4. Ginontai seismoi"}, 2},
                {"Poio fyto / dimitriako syndetai amesa me ti latreia tis Dimitras;", {"1. To sitari", "2. To ryzi", "3. To bambaki", "4. O kapnos"}, 1},
                {"Poio mystirio kentro latreias itan afieromeno sti Dimitra stin Attiki;", {"1. Ta Elefsinia Mystiria", "2. Ta Delfika Mystiria", "3. Ta Panathinaia", "4. Ta Olympia"}, 1}
            }
        },
        {
            "Dionyssos",
            {
                {"O Dionyssos einai o theos tou...", {"1. krasiou, tou ampeliou kai tis diaskedasis", "2. tou nomou kai tis taksis", "3. tis psychrologias", "4. tou stratou"}, 1},
                {"Poio einai to symbolo ravdi pou exoun oi akolouthoi tou (mainades kai satyroi);;", {"1. O thyrsos", "2. I triaina", "3. O keravnos", "4. To spathi"}, 1},
                {"Poia zoa synodeyoun sychna ton Dionysso;", {"1. Oi panthires kai oi tigreis", "2. Ta aloga", "3. Ta elafia", "4. Oi aetoi"}, 1},
                {"Poio theatro kai morfi technis stin archaia Athina itan afieromeno ston Dionysso;", {"1. To theatro kai i tragodia/komodia", "2. I zographiki", "3. I glyptiki", "4. I architektoniki"}, 1},
                {"Poios itan o pateras tou Dionysou;", {"1. O Dias", "2. O Poseidonas", "3. O Kronos", "4. O Ouranos"}, 1}
            }
        },
        {
            "Ira",
            {
                {"I Ira einai i vasilissa ton theon kai prostatis tis...", {"1. gamou kai tis oikogeneias", "2. tis thalassas", "3. tou emporiou", "4. tis technis"}, 1},
                {"Poios itan o syzygos tis Ira;", {"1. O Dias", "2. O Poseidonas", "3. O Adis", "4. O Apollonas"}, 1},
                {"Poio iero zoo symvolizei tin Ira kai tin omorfia tis;", {"1. To pagoni", "2. I koukouvagia", "3. O aetos", "4. To alogo"}, 1},
                {"Poia poli itan to kyrio kentro latreias tis Ira;", {"1. To Argos kai i Samos", "2. I Athina", "3. I Sparta", "4. Oi Delfoi"}, 1},
                {"Poioi itan oi goneis tis Ira;", {"1. O Kronos kai i Rea", "2. O Ouranos kai i Gi", "3. O Dias kai i Lito", "4. O Okeanos kai i Tithis"}, 1}
            }
        }
    };

    printf("========================================\n");
    printf("   KALOS IRTHATE STO QUIZ: GODS OF OLYMPUS\n");
    printf("========================================\n");
    printf("Kanonas: Prepei na apantiseis sosta kai stis 5 erotiseis\n");
    printf("kathe Theou (5/5) gia na proxoriseis ston epomeno!\n\n");

    for (i = 0; i < 12; i++) {
        passed = 0;

        while (!passed) {
            printf("\n----------------------------------------\n");
            printf("  NEOS GYROS: THEOS %d/12 -> %s\n", i + 1, gods[i].name);
            printf("----------------------------------------\n");

            correct_count = 0;

            for (j = 0; j < 5; j++) {
                printf("\nErotisi %d/5: %s\n", j + 1, gods[i].questions[j].question);
                for (k = 0; k < 4; k++) {
                    printf("%s\n", gods[i].questions[j].options[k]);
                }

                printf("I apantisi sou (1-4): ");
                scanf("%d", &answer);

                if (answer == gods[i].questions[j].correct_answer) {
                    printf("-> Sosto!\n");
                    correct_count++;
                } else {
                    printf("-> Lathos!\n");
                }
            }

            if (correct_count == 5) {
                printf("\n [!] Sygchariteria! Petyches 5/5 kai ksekleidoses ton/tin %s!\n", gods[i].name);
                passed = 1;
            } else {
                printf("\n [X] Apetyches ston gyro (Vrikes %d/5).\n", correct_count);
                printf(" Apaiteitai apolyto skor 5/5. O gyros epanalambanetai apo tin arxi...\n");
            }
        }
    }

    printf("\n========================================\n");
    printf(" TELOS PAICHNIDIOU! Nikises olous tous Theous!\n");
    printf("========================================\n");

    return 0;
}
