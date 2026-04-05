#include <stdio.h>
#include <string.h>

int main()
{
    char nome[10];
    char escolha2[3]; // escolha2 = Calcular P ou R
    int escolha = 3;  // escolha = Tabela ou estequiometria
    char elem[3];
    char elem2[3];
    float massa = 0;
    float massa2 = 0;
    float massa3 = 0;
    float massaf = 0;
    int coef;
    int coef2;
    int x = 0;
    int y = 0; // x e y = Varia entre elemento e coeficiente

    while (escolha != 0)
    {
        printf("Escolha o modo de navegacao:\n1-Tabela periodica\n2-Estequiometria\n0-Encerrar programa\n");
        scanf("%d", &escolha);
        while (escolha != 0 && escolha != 1 && escolha != 2)
        {
            printf("Opcao Invalida\n");
            printf("Escolha o modo de navegacao:\n1-Tabela periodica\n2-Estequiometria\n0-Encerrar programa\n");
            scanf("%d", &escolha);
        }
        switch (escolha)
        {
        case 1:
        {
            printf("Digite o nome do elemento: ");
            scanf("%s", nome);

            if (0 == strcmp(nome, "H"))
            {
                printf("Simbolo %s\n", nome);
                printf("Hidrogenio\n");
                printf("Massa atomica 1.008 e N° Atomico 1\n");
            }

            else if (0 == strcmp(nome, "He"))
            {
                printf("Simbolo %s\n", nome);
                printf("Helio\n");
                printf("Massa atomica 4.003 e N° Atomico 2\n");
            }

            else if (0 == strcmp(nome, "Li"))
            {
                printf("Simbolo %s\n", nome);
                printf("Litio\n");
                printf("Massa atomica 6.941 e N° Atomico 3\n");
            }

            else if (0 == strcmp(nome, "B"))
            {
                printf("Simbolo %s\n", nome);
                printf("Boro\n");
                printf("Massa atomica 10.811 e N° Atomico 5\n");
            }

            else if (0 == strcmp(nome, "Be"))
            {
                printf("Simbolo %s\n", nome);

                printf("Berilio\n");
                printf("Massa atomica 9.012 e N° Atomico 4\n");
            }

            else if (0 == strcmp(nome, "C"))
            {
                printf("Simbolo %s\n", nome);
                printf("Carbono\n");
                printf("Massa atomica 12.011 e N° Atomico 6\n");
            }

            else if (0 == strcmp(nome, "N"))
            {
                printf("Simbolo %s\n", nome);
                printf("Nitrogenio\n");
                printf("Massa atomica 14.007 e N° Atomico 7\n");
            }

            else if (0 == strcmp(nome, "O"))
            {
                printf("Simbolo %s\n", nome);
                printf("Oxigenio\n");
                printf("Massa atomica 15.999 e N° Atomico 8\n");
            }

            else if (0 == strcmp(nome, "F"))
            {
                printf("Simbolo %s\n", nome);
                printf("Fluor\n");
                printf("Massa atomica 18.998 e N° Atomico 9\n");
            }

            else if (0 == strcmp(nome, "Ne"))
            {
                printf("Simbolo %s\n", nome);

                printf("Neonio\n");
                printf("Massa atomica 20.180 e N° Atomico 10\n");
            }

            else if (0 == strcmp(nome, "Na"))
            {
                printf("Simbolo %s\n", nome);
                printf("Sodio\n");
                printf("Massa atomica 22.990 e N° Atomico 11\n");
            }

            else if (0 == strcmp(nome, "Mg"))
            {
                printf("Simbolo %s\n", nome);
                printf("Magnesio\n");
                printf("Massa atomica 24.305 e N° Atomico 12\n");
            }

            else if (0 == strcmp(nome, "Al"))
            {
                printf("Simbolo %s\n", nome);
                printf("Aluminio\n");
                printf("Massa atomica 26.982 e N° Atomico 13\n");
            }

            else if (0 == strcmp(nome, "Si"))
            {
                printf("Simbolo %s\n", nome);
                printf("Silicio\n");
                printf("Massa atomica 28.086 e N° Atomico 14\n");
            }

            else if (0 == strcmp(nome, "P"))
            {
                printf("Simbolo %s\n", nome);

                printf("Fosforo\n");
                printf("Massa atomica 30.974 e N° Atomico 15\n");
            }

            else if (0 == strcmp(nome, "S"))
            {
                printf("Simbolo %s\n", nome);
                printf("Enxofre\n");
                printf("Massa atomica 32.065 e N° Atomico 16\n");
            }

            else if (0 == strcmp(nome, "Cl"))
            {
                printf("Simbolo %s\n", nome);
                printf("Cloro\n");
                printf("Massa atomica 35.453 e N° Atomico 17\n");
            }

            else if (0 == strcmp(nome, "Cl"))
            {
                printf("Simbolo %s\n", nome);
                printf("Cloro\n");
                printf("Massa atomica 35.453 e N° Atomico 17\n");
            }

            else if (0 == strcmp(nome, "Ar"))
            {
                printf("Simbolo %s\n", nome);
                printf("Argonio\n");
                printf("Massa atomica 39.948 e N° Atomico 18\n");
            }

            else if (0 == strcmp(nome, "K"))
            {
                printf("Simbolo %s\n", nome);

                printf("Potassio\n");
                printf("Massa atomica 39.098 e N° Atomico 19\n");
            }

            else if (0 == strcmp(nome, "Ca"))
            {
                printf("Simbolo %s\n", nome);
                printf("Calcio\n");
                printf("Massa atomica 40.078 e N° Atomico 20\n");
            }

            else if (0 == strcmp(nome, "Sc"))
            {
                printf("Simbolo %s\n", nome);
                printf("Escandio\n");
                printf("Massa atomica 44.956 e N° Atomico 21\n");
            }

            else if (0 == strcmp(nome, "Ti"))
            {
                printf("Simbolo %s\n", nome);
                printf("Titanio\n");
                printf("Massa atomica 47.867 e N° Atomico 22\n");
            }

            else if (0 == strcmp(nome, "V"))
            {
                printf("Simbolo %s\n", nome);
                printf("Vanadio\n");
                printf("Massa atomica 50.942 e N° Atomico 23\n");
            }

            else if (0 == strcmp(nome, "Cr"))
            {
                printf("Simbolo %s\n", nome);

                printf("Cromo\n");
                printf("Massa atomica 51.996 e N° Atomico 24\n");
            }

            else if (0 == strcmp(nome, "Mn"))
            {
                printf("Simbolo %s\n", nome);
                printf("Manganes\n");
                printf("Massa atomica 54.938 e N° Atomico 25\n");
            }

            else if (0 == strcmp(nome, "Fe"))
            {
                printf("Simbolo %s\n", nome);
                printf("Ferro\n");
                printf("Massa atomica 55.845 e N° Atomico 26\n");
            }

            else if (0 == strcmp(nome, "Co"))
            {
                printf("Simbolo %s\n", nome);
                printf("Cobalto\n");
                printf("Massa atomica 58.933 e N° Atomico 27\n");
            }

            else if (0 == strcmp(nome, "Ni"))
            {
                printf("Simbolo %s\n", nome);
                printf("Niquel\n");
                printf("Massa atomica 58.693 e N° Atomico 28\n");
            }

            else if (0 == strcmp(nome, "Cu"))
            {
                printf("Simbolo %s\n", nome);

                printf("Cobre\n");
                printf("Massa atomica 63.546 e N° Atomico 29\n");
            }

            else if (0 == strcmp(nome, "Zn"))
            {
                printf("Simbolo %s\n", nome);
                printf("Zinco\n");
                printf("Massa atomica 65.409 e N° Atomico 30\n");
            }

            else if (0 == strcmp(nome, "Ga"))
            {
                printf("Simbolo %s\n", nome);
                printf("Galio\n");
                printf("Massa atomica 69.723 e N° Atomico 31\n");
            }

            else if (0 == strcmp(nome, "Ge"))
            {
                printf("Simbolo %s\n", nome);
                printf("Germanio\n");
                printf("Massa atomica 72.640 e N° Atomico 32\n");
            }

            else if (0 == strcmp(nome, "As"))
            {
                printf("Simbolo %s\n", nome);
                printf("Arsenio\n");
                printf("Massa atomica 74.922 e N° Atomico 33\n");
            }

            else if (0 == strcmp(nome, "Se"))
            {
                printf("Simbolo %s\n", nome);

                printf("Selenio\n");
                printf("Massa atomica 78.960 e N° Atomico 34\n");
            }

            else if (0 == strcmp(nome, "Br"))
            {
                printf("Simbolo %s\n", nome);
                printf("Bromo\n");
                printf("Massa atomica 79.904 e N° Atomico 35\n");
            }

            else if (0 == strcmp(nome, "Kr"))
            {
                printf("Simbolo %s\n", nome);
                printf("Criptonio\n");
                printf("Massa atomica 83.798 e N° Atomico 36\n");
            }

            else if (0 == strcmp(nome, "Rb"))
            {
                printf("Simbolo %s\n", nome);
                printf("Rubidio\n");
                printf("Massa atomica 85.468 e N° Atomico 37\n");
            }

            else if (0 == strcmp(nome, "Sr"))
            {
                printf("Simbolo %s\n", nome);
                printf("Estroncio\n");
                printf("Massa atomica 87.62 e N° Atomico 38\n");
            }

            else if (0 == strcmp(nome, "Y"))
            {
                printf("Simbolo %s\n", nome);

                printf("Itrio\n");
                printf("Massa atomica 88.906 e N° Atomico 39\n");
            }

            else if (0 == strcmp(nome, "Zr"))
            {
                printf("Simbolo %s\n", nome);
                printf("Zirconio\n");
                printf("Massa atomica 91.224 e N° Atomico 40\n");
            }

            else if (0 == strcmp(nome, "Nb"))
            {
                printf("Simbolo %s\n", nome);
                printf("Niobio\n");
                printf("Massa atomica 92.906 e N° Atomico 41\n");
            }

            else if (0 == strcmp(nome, "Mo"))
            {
                printf("Simbolo %s\n", nome);
                printf("Molibdenio\n");
                printf("Massa atomica 95.940 e N° Atomico 42\n");
            }

            else if (0 == strcmp(nome, "Tc"))
            {
                printf("Simbolo %s\n", nome);
                printf("Tecnesio\n");
                printf("Massa atomica 98 e N° Atomico 43\n");
            }

            else if (0 == strcmp(nome, "Ru"))
            {
                printf("Simbolo %s\n", nome);

                printf("Rutenio\n");
                printf("Massa atomica 101.07 e N° Atomico 44\n");
            }

            else if (0 == strcmp(nome, "Rh"))
            {
                printf("Simbolo %s\n", nome);
                printf("Rodio\n");
                printf("Massa atomica 102.905 e N° Atomico 45\n");
            }

            else if (0 == strcmp(nome, "Pd"))
            {
                printf("Simbolo %s\n", nome);
                printf("Paladio\n");
                printf("Massa atomica 106.420 e N° Atomico 46\n");
            }

            else if (0 == strcmp(nome, "Ag"))
            {
                printf("Simbolo %s\n", nome);
                printf("Prata\n");
                printf("Massa atomica 107.868 e N° Atomico 47\n");
            }

            else if (0 == strcmp(nome, "Cd"))
            {
                printf("Simbolo %s\n", nome);
                printf("Prata\n");
                printf("Massa atomica 112.411 e N° Atomico 48\n");
            }

            else if (0 == strcmp(nome, "In"))
            {
                printf("Simbolo %s\n", nome);

                printf("Indio\n");
                printf("Massa atomica 114.818 e N° Atomico 49\n");
            }

            else if (0 == strcmp(nome, "Sn"))
            {
                printf("Simbolo %s\n", nome);
                printf("Estanho\n");
                printf("Massa atomica 118.710 e N° Atomico 49\n");
            }

            else if (0 == strcmp(nome, "Sb"))
            {
                printf("Simbolo %s\n", nome);
                printf("Estanho\n");
                printf("Massa atomica 121.760 e N° Atomico 51\n");
            }

            else if (0 == strcmp(nome, "Te"))
            {
                printf("Simbolo %s\n", nome);
                printf("Telurio\n");
                printf("Massa atomica 127.600 e N° Atomico 52\n");
            }

            else if (0 == strcmp(nome, "I"))
            {
                printf("Simbolo %s\n", nome);
                printf("Iodo\n");
                printf("Massa atomica 126.904 e N° Atomico 53\n");
            }

            else if (0 == strcmp(nome, "Xe"))
            {
                printf("Simbolo %s\n", nome);

                printf("Xenonio\n");
                printf("Massa atomica 131.293 e N° Atomico 54\n");
            }

            else if (0 == strcmp(nome, "Cs"))
            {
                printf("Simbolo %s\n", nome);
                printf("Cesio\n");
                printf("Massa atomica 132.905 e N° Atomico 55\n");
            }

            else if (0 == strcmp(nome, "Ba"))
            {
                printf("Simbolo %s\n", nome);
                printf("Bario\n");
                printf("Massa atomica 137.327 e N° Atomico 56\n");
            }

            else if (0 == strcmp(nome, "La"))
            {
                printf("Simbolo %s\n", nome);
                printf("Lantanio\n");
                printf("Massa atomica 138.905 e N° Atomico 57\n");
            }

            else if (0 == strcmp(nome, "Ce"))
            {
                printf("Simbolo %s\n", nome);
                printf("Cerio\n");
                printf("Massa atomica 140.116 e N° Atomico 58\n");
            }

            else if (0 == strcmp(nome, "Pr"))
            {
                printf("Simbolo %s\n", nome);

                printf("Praseodimio\n");
                printf("Massa atomica 140.907 e N° Atomico 59\n");
            }

            else if (0 == strcmp(nome, "Nd"))
            {
                printf("Simbolo %s\n", nome);
                printf("Neodimio\n");
                printf("Massa atomica 144.242 e N° Atomico 60\n");
            }

            else if (0 == strcmp(nome, "Pm"))
            {
                printf("Simbolo %s\n", nome);
                printf("Promecio\n");
                printf("Massa atomica 145.000 e N° Atomico 61\n");
            }

            else if (0 == strcmp(nome, "Sm"))
            {
                printf("Simbolo %s\n", nome);
                printf("Samario\n");
                printf("Massa atomica 150.360 e N° Atomico 62\n");
            }

            else if (0 == strcmp(nome, "Eu"))
            {
                printf("Simbolo %s\n", nome);
                printf("Europio\n");
                printf("Massa atomica 151.964 e N° Atomico 63\n");
            }

            else if (0 == strcmp(nome, "Gd"))
            {
                printf("Simbolo %s\n", nome);

                printf("Gadolinio\n");
                printf("Massa atomica 157.250 e N° Atomico 64\n");
            }

            else if (0 == strcmp(nome, "Tb"))
            {
                printf("Simbolo %s\n", nome);
                printf("Terbio\n");
                printf("Massa atomica 158.925 e N° Atomico 65\n");
            }

            else if (0 == strcmp(nome, "Dy"))
            {
                printf("Simbolo %s\n", nome);
                printf("Disprosio\n");
                printf("Massa atomica 162.500 e N° Atomico 66\n");
            }
            else if (0 == strcmp(nome, "Ho"))
            {
                printf("Simbolo %s\n", nome);
                printf("Holmio\n");
                printf("Massa atomica 164.930 e N° Atomico 67\n");
            }

            else if (0 == strcmp(nome, "Er"))
            {
                printf("Simbolo %s\n", nome);
                printf("Erbio\n");
                printf("Massa atomica 167.259 e N° Atomico 68\n");
            }

            else if (0 == strcmp(nome, "Tm"))
            {
                printf("Simbolo %s\n", nome);
                printf("Tulio\n");

                printf("Massa atomica 168.934 e N° Atomico 69\n");
            }

            else if (0 == strcmp(nome, "Yb"))
            {
                printf("Simbolo %s\n", nome);
                printf("Iterbio\n");
                printf("Massa atomica 173.040 e N° Atomico 70\n");
            }

            else if (0 == strcmp(nome, "Lu"))
            {
                printf("Simbolo %s\n", nome);
                printf("Lutecio\n");
                printf("Massa atomica 174.967 e N° Atomico 71\n");
            }

            else if (0 == strcmp(nome, "Hf"))
            {
                printf("Simbolo %s\n", nome);
                printf("Hafnio\n");
                printf("Massa atomica 178.490 e N° Atomico 72\n");
            }

            else if (0 == strcmp(nome, "Ta"))
            {
                printf("Simbolo %s\n", nome);
                printf("Tantalo\n");
                printf("Massa atomica 180.947 e N° Atomico 73\n");
            }

            else if (0 == strcmp(nome, "W"))
            {
                printf("Simbolo %s\n", nome);
                printf("Tungstenio\n");

                printf("Massa atomica 183.840 e N° Atomico 74\n");
            }

            else if (0 == strcmp(nome, "Re"))
            {
                printf("Simbolo %s\n", nome);
                printf("Renio\n");
                printf("Massa atomica 186.207 e N° Atomico 75\n");
            }

            else if (0 == strcmp(nome, "Os"))
            {
                printf("Simbolo %s\n", nome);
                printf("Osmio\n");
                printf("Massa atomica 190.230 e N° Atomico 76\n");
            }

            else if (0 == strcmp(nome, "Ir"))
            {
                printf("Simbolo %s\n", nome);
                printf("Iridio\n");
                printf("Massa atomica 192.217 e N° Atomico 77\n");
            }
            else if (0 == strcmp(nome, "Pt"))
            {
                printf("Simbolo %s\n", nome);
                printf("Platina\n");
                printf("Massa atomica 195.084 e N° Atomico 78\n");
            }

            else if (0 == strcmp(nome, "Au"))
            {
                printf("Simbolo %s\n", nome);
                printf("Ouro\n");
                printf("Massa atomica 196.967 e N° Atomico 79\n");
            }

            else if (0 == strcmp(nome, "Hg"))
            {
                printf("Simbolo %s\n", nome);
                printf("Mercurio\n");
                printf("Massa atomica 200.590 e N° Atomico 80\n");
            }

            else if (0 == strcmp(nome, "Tl"))
            {
                printf("Simbolo %s\n", nome);
                printf("Talio\n");
                printf("Massa atomica 204.383 e N° Atomico 81\n");
            }

            else if (0 == strcmp(nome, "Pb"))
            {
                printf("Simbolo %s\n", nome);
                printf("Chumbo\n");
                printf("Massa atomica 207.200 e N° Atomico 82\n");
            }

            else if (0 == strcmp(nome, "Bi"))
            {
                printf("Simbolo %s\n", nome);
                printf("Bismuto\n");
                printf("Massa atomica 208.980 e N° Atomico 83\n");
            }

            else if (0 == strcmp(nome, "Po"))
            {
                printf("Simbolo %s\n", nome);
                printf("Polonio\n");
                printf("Massa atomica 209.000 e N° Atomico 84\n");
            }

            else if (0 == strcmp(nome, "At"))
            {
                printf("Simbolo %s\n", nome);
                printf("Astato\n");
                printf("Massa atomica 210.000 e N° Atomico 85\n");
            }

            else if (0 == strcmp(nome, "Rn"))
            {
                printf("Simbolo %s\n", nome);
                printf("Radonio\n");
                printf("Massa atomica 222.000 e N° Atomico 86\n");
            }

            else if (0 == strcmp(nome, "Fr"))
            {
                printf("Simbolo %s\n", nome);
                printf("Francio\n");
                printf("Massa atomica 223.000 e N° Atomico 87\n");
            }

            else if (0 == strcmp(nome, "Ra"))
            {
                printf("Simbolo %s\n", nome);
                printf("Radio\n");
                printf("Massa atomica 226.000 e N° Atomico 88\n");
            }

            else if (0 == strcmp(nome, "Ac"))
            {
                printf("Simbolo %s\n", nome);
                printf("Actinio\n");
                printf("Massa atomica 227.000 e N° Atomico 89\n");
            }

            else if (0 == strcmp(nome, "Th"))
            {
                printf("Simbolo %s\n", nome);
                printf("Torio\n");
                printf("Massa atomica 232.038 e N° Atomico 90\n");
            }

            else if (0 == strcmp(nome, "Pa"))
            {
                printf("Simbolo %s\n", nome);
                printf("Protactinio\n");
                printf("Massa atomica 231.035 e N° Atomico 91\n");
            }

            else if (0 == strcmp(nome, "U"))
            {
                printf("Simbolo %s\n", nome);
                printf("Uranio\n");
                printf("Massa atomica 238.028 e N° Atomico 92\n");
            }

            else if (0 == strcmp(nome, "Np"))
            {
                printf("Simbolo %s\n", nome);
                printf("Neptunio\n");
                printf("Massa atomica 237.000 e N° Atomico 93\n");
            }

            else if (0 == strcmp(nome, "Pu"))
            {
                printf("Simbolo %s\n", nome);
                printf("Plutonio\n");
                printf("Massa atomica 244.000 e N° Atomico 94\n");
            }

            else if (0 == strcmp(nome, "Am"))
            {
                printf("Simbolo %s\n", nome);
                printf("Americio\n");
                printf("Massa atomica 243.000 e N° Atomico 95\n");
            }

            else if (0 == strcmp(nome, "Cm"))
            {
                printf("Simbolo %s\n", nome);
                printf("Curio\n");
                printf("Massa atomica 247.000 e N° Atomico 96\n");
            }

            else if (0 == strcmp(nome, "Bk"))
            {
                printf("Simbolo %s\n", nome);
                printf("Berquelio\n");
                printf("Massa atomica 247.000 e N° Atomico 97\n");
            }

            else if (0 == strcmp(nome, "Cf"))
            {
                printf("Simbolo %s\n", nome);
                printf("Californio\n");
                printf("Massa atomica 251.000 e N° Atomico 98\n");
            }

            else if (0 == strcmp(nome, "Es"))
            {
                printf("Simbolo %s\n", nome);
                printf("Einsteinio\n");
                printf("Massa atomica 252.000 e N° Atomico 99\n");
            }

            else if (0 == strcmp(nome, "Fm"))
            {
                printf("Simbolo %s\n", nome);
                printf("Fermio\n");
                printf("Massa atomica 257.000 e N° Atomico 100\n");
            }

            else if (0 == strcmp(nome, "Md"))
            {
                printf("Simbolo %s\n", nome);
                printf("Mendelévio\n");
                printf("Massa atomica 258.000 e N° Atomico 101\n");
            }

            else if (0 == strcmp(nome, "No"))
            {
                printf("Simbolo %s\n", nome);
                printf("Nobelio\n");
                printf("Massa atomica 259.000 e N° Atomico 102\n");
            }

            else if (0 == strcmp(nome, "Lr"))
            {
                printf("Simbolo %s\n", nome);
                printf("Laurencio\n");
                printf("Massa atomica 262.000 e N° Atomico 103\n");
            }

            else if (0 == strcmp(nome, "Rf"))
            {
                printf("Simbolo %s\n", nome);
                printf("Rutherfórdio\n");
                printf("Massa atomica 267.000 e N° Atomico 104\n");
            }

            else if (0 == strcmp(nome, "Db"))
            {
                printf("Simbolo %s\n", nome);
                printf("Dúbnio\n");
                printf("Massa atomica 270.000 e N° Atomico 105\n");
            }

            else if (0 == strcmp(nome, "Sg"))
            {
                printf("Simbolo %s\n", nome);
                printf("Seabórgio\n");
                printf("Massa atomica 271.000 e N° Atomico 106\n");
            }

            else if (0 == strcmp(nome, "Bh"))
            {
                printf("Simbolo %s\n", nome);
                printf("Bóhrio\n");
                printf("Massa atomica 270.000 e N° Atomico 107\n");
            }

            else if (0 == strcmp(nome, "Hs"))
            {
                printf("Simbolo %s\n", nome);
                printf("Hássio\n");
                printf("Massa atomica 277.000 e N° Atomico 108\n");
            }

            else if (0 == strcmp(nome, "Mt"))
            {
                printf("Simbolo %s\n", nome);
                printf("Meitnério\n");
                printf("Massa atomica 278.000 e N° Atomico 109\n");
            }

            else if (0 == strcmp(nome, "Ds"))
            {
                printf("Simbolo %s\n", nome);
                printf("Darmstádio\n");
                printf("Massa atomica 281.000 e N° Atomico 110\n");
            }

            else if (0 == strcmp(nome, "Rg"))
            {
                printf("Simbolo %s\n", nome);
                printf("Roentgênio\n");
                printf("Massa atomica 282.000 e N° Atomico 111\n");
            }

            else if (0 == strcmp(nome, "Cn"))
            {
                printf("Simbolo %s\n", nome);
                printf("Copernício\n");
                printf("Massa atomica 285.000 e N° Atomico 112\n");
            }

            else if (0 == strcmp(nome, "Nh"))
            {
                printf("Simbolo %s\n", nome);
                printf("Nihônio\n");
                printf("Massa atomica 286.000 e N° Atomico 113\n");
            }

            else if (0 == strcmp(nome, "Fl"))
            {
                printf("Simbolo %s\n", nome);
                printf("Fleróvio\n");
                printf("Massa atomica 289.000 e N° Atomico 114\n");
            }

            else if (0 == strcmp(nome, "Mc"))
            {
                printf("Simbolo %s\n", nome);
                printf("Moscóvio\n");
                printf("Massa atomica 290.000 e N° Atomico 115\n");
            }

            else if (0 == strcmp(nome, "Lv"))
            {
                printf("Simbolo %s\n", nome);
                printf("Livermório\n");
                printf("Massa atomica 293.000 e N° Atomico 116\n");
            }

            else if (0 == strcmp(nome, "Ts"))
            {
                printf("Simbolo %s\n", nome);
                printf("Tenessino\n");
                printf("Massa atomica 294.000 e N° Atomico 117\n");
            }
            else if (0 == strcmp(nome, "Og"))
            {
                printf("Simbolo %s\n", nome);
                printf("Oganessônio\n");
                printf("Massa atomica 294.000 e N° Atomico 118\n");
            }

            else if (0 == strcmp(nome, "La"))
            {
                printf("Simbolo %s\n", nome);
                printf("Lantânio\n");
                printf("Massa atomica 138.905 e N° Atomico 57\n");
            }

            else if (0 == strcmp(nome, "Ce"))
            {
                printf("Simbolo %s\n", nome);
                printf("Cério\n");
                printf("Massa atomica 140.116 e N° Atomico 58\n");
            }

            else if (0 == strcmp(nome, "Pr"))
            {
                printf("Simbolo %s\n", nome);
                printf("Praseodímio\n");
                printf("Massa atomica 140.907 e N° Atomico 59\n");
            }

            else if (0 == strcmp(nome, "Nd"))
            {
                printf("Simbolo %s\n", nome);
                printf("Neodímio\n");
                printf("Massa atomica 144.242 e N° Atomico 60\n");
            }

            else if (0 == strcmp(nome, "Pm"))
            {
                printf("Simbolo %s\n", nome);
                printf("Promécio\n");
                printf("Massa atomica 145.000 e N° Atomico 61\n");
            }

            else if (0 == strcmp(nome, "Sm"))
            {
                printf("Simbolo %s\n", nome);
                printf("Samário\n");
                printf("Massa atomica 150.360 e N° Atomico 62\n");
            }

            else if (0 == strcmp(nome, "Eu"))
            {
                printf("Simbolo %s\n", nome);
                printf("Európio\n");
                printf("Massa atomica 151.964 e N° Atomico 63\n");
            }

            else if (0 == strcmp(nome, "Gd"))
            {
                printf("Simbolo %s\n", nome);
                printf("Gadolínio\n");
                printf("Massa atomica 157.250 e N° Atomico 64\n");
            }

            else if (0 == strcmp(nome, "Tb"))
            {
                printf("Simbolo %s\n", nome);
                printf("Térbio\n");
                printf("Massa atomica 158.925 e N° Atomico 65\n");
            }

            else if (0 == strcmp(nome, "Dy"))
            {
                printf("Simbolo %s\n", nome);
                printf("Disprósio\n");
                printf("Massa atomica 162.500 e N° Atomico 66\n");
            }

            else if (0 == strcmp(nome, "Ho"))
            {
                printf("Simbolo %s\n", nome);
                printf("Hólmio\n");
                printf("Massa atomica 164.930 e N° Atomico 67\n");
            }

            else if (0 == strcmp(nome, "Er"))
            {
                printf("Simbolo %s\n", nome);
                printf("Érbio\n");
                printf("Massa atomica 167.259 e N° Atomico 68\n");
            }

            else if (0 == strcmp(nome, "Tm"))
            {
                printf("Simbolo %s\n", nome);
                printf("Túlio\n");
                printf("Massa atomica 168.934 e N° Atomico 69\n");
            }

            else if (0 == strcmp(nome, "Yb"))
            {
                printf("Simbolo %s\n", nome);
                printf("Itérbio\n");
                printf("Massa atomica 173.040 e N° Atomico 70\n");
            }

            else if (0 == strcmp(nome, "Lu"))
            {
                printf("Simbolo %s\n", nome);
                printf("Lutécio\n");
                printf("Massa atomica 174.967 e N° Atomico 71\n");
            }

            else if (0 == strcmp(nome, "Ac"))
            {
                printf("Simbolo %s\n", nome);
                printf("Actínio\n");
                printf("Massa atomica 227.000 e N° Atomico 89\n");
            }

            else if (0 == strcmp(nome, "Th"))
            {
                printf("Simbolo %s\n", nome);
                printf("Tório\n");
                printf("Massa atomica 232.038 e N° Atomico 90\n");
            }

            else if (0 == strcmp(nome, "Pa"))
            {
                printf("Simbolo %s\n", nome);
                printf("Protactínio\n");
                printf("Massa atomica 231.035 e N° Atomico 91\n");
            }

            else if (0 == strcmp(nome, "U"))
            {
                printf("Simbolo %s\n", nome);
                printf("Urânio\n");
                printf("Massa atomica 238.028 e N° Atomico 92\n");
            }

            else if (0 == strcmp(nome, "Np"))
            {
                printf("Simbolo %s\n", nome);
                printf("Neptúnio\n");
                printf("Massa atomica 237.000 e N° Atomico 93\n");
            }

            else if (0 == strcmp(nome, "Pu"))
            {
                printf("Simbolo %s\n", nome);
                printf("Plutônio\n");
                printf("Massa atomica 244.000 e N° Atomico 94\n");
            }

            else if (0 == strcmp(nome, "Am"))
            {
                printf("Simbolo %s\n", nome);
                printf("Amerício\n");
                printf("Massa atomica 243.000 e N° Atomico 95\n");
            }

            else if (0 == strcmp(nome, "Cm"))
            {
                printf("Simbolo %s\n", nome);
                printf("Cúrio\n");
                printf("Massa atomica 247.000 e N° Atomico 96\n");
            }

            else if (0 == strcmp(nome, "Bk"))
            {
                printf("Simbolo %s\n", nome);
                printf("Berquélio\n");
                printf("Massa atomica 247.000 e N° Atomico 97\n");
            }

            else if (0 == strcmp(nome, "Cf"))
            {
                printf("Simbolo %s\n", nome);
                printf("Califórnio\n");
                printf("Massa atomica 251.000 e N° Atomico 98\n");
            }

            else if (0 == strcmp(nome, "Es"))
            {
                printf("Simbolo %s\n", nome);
                printf("Einstênio\n");
                printf("Massa atomica 252.000 e N° Atomico 99\n");
            }

            else if (0 == strcmp(nome, "Fm"))
            {
                printf("Simbolo %s\n", nome);
                printf("Férmio\n");
                printf("Massa atomica 257.000 e N° Atomico 100\n");
            }

            else if (0 == strcmp(nome, "Md"))
            {
                printf("Simbolo %s\n", nome);
                printf("Mendelévio\n");
                printf("Massa atomica 258.000 e N° Atomico 101\n");
            }

            else if (0 == strcmp(nome, "No"))
            {
                printf("Simbolo %s\n", nome);
                printf("Nobélio\n");
                printf("Massa atomica 259.000 e N° Atomico 102\n");
            }

            else if (0 == strcmp(nome, "Lr"))
            {
                printf("Simbolo %s\n", nome);
                printf("Laurêncio\n");
                printf("Massa atomica 262.000 e N° Atomico 103\n");
            }
            printf("\n");
            break;
        }
        case 2:
        {

            massa = 0;

            massa2 = 0;
            massa3 = 0;
            massaf = 0;
            x = 0;
            y = 0; // x e y = Varia entre elemento e coeficiente

            // Reagente

            while (0 != strcmp(elem, "2") && 0 != strcmp(elem, "0"))
            {

                while (x == 0)
                {
                    printf("Insira o elemento ou digite 2 para partir para o produto:\n");
                    scanf("%s", elem);

                    x = 1;
                }

                while (x == 1 && 0 != strcmp(elem, "2"))
                {

                    printf("Insira o coeficiente:\n");
                    scanf("%d", &coef);

                    if (0 == strcmp(elem, "H"))
                    {
                        massa += coef * 1.008;
                    }
                    else if (0 == strcmp(elem, "He"))
                    {
                        massa += coef * 4.003;
                    }

                    else if (0 == strcmp(elem, "Li"))
                    {
                        massa += coef * 6.941;
                    }
                    else if (0 == strcmp(elem, "Be"))
                    {
                        massa += coef * 9.012;
                    }
                    else if (0 == strcmp(elem, "B"))
                    {
                        massa += coef * 10.811;
                    }
                    else if (0 == strcmp(elem, "C"))
                    {
                        massa += coef * 12.011;
                    }
                    else if (0 == strcmp(elem, "N"))
                    {
                        massa += coef * 14.007;
                    }
                    else if (0 == strcmp(elem, "O"))
                    {
                        massa += coef * 15.999;
                    }
                    else if (0 == strcmp(elem, "F"))
                    {
                        massa += coef * 18.998;
                    }
                    else if (0 == strcmp(elem, "Ar"))
                    {
                        massa += coef * 39.948;
                    }
                    else if (0 == strcmp(elem, "K"))
                    {
                        massa += coef * 39.098;
                    }
                    else if (0 == strcmp(elem, "Ca"))
                    {
                        massa += coef * 40.078;
                    }

                    else if (0 == strcmp(elem, "Sc"))
                    {
                        massa += coef * 44.956;
                    }
                    else if (0 == strcmp(elem, "Ti"))
                    {
                        massa += coef * 47.867;
                    }
                    else if (0 == strcmp(elem, "V"))
                    {
                        massa += coef * 50.942;
                    }
                    else if (0 == strcmp(elem, "Cr"))
                    {
                        massa += coef * 51.996;
                    }
                    else if (0 == strcmp(elem, "Mn"))
                    {
                        massa += coef * 54.938;
                    }
                    else if (0 == strcmp(elem, "Fe"))
                    {
                        massa += coef * 55.845;
                    }
                    else if (0 == strcmp(elem, "Co"))
                    {
                        massa += coef * 58.933;
                    }
                    else if (0 == strcmp(elem, "Ni"))
                    {
                        massa += coef * 58.693;
                    }
                    else if (0 == strcmp(elem, "Cu"))
                    {
                        massa += coef * 63.546;
                    }
                    else if (0 == strcmp(elem, "Zn"))
                    {
                        massa += coef * 65.409;
                    }

                    else if (0 == strcmp(elem, "Ga"))
                    {
                        massa += coef * 69.723;
                    }
                    else if (0 == strcmp(elem, "Ge"))
                    {
                        massa += coef * 72.640;
                    }
                    else if (0 == strcmp(elem, "As"))
                    {
                        massa += coef * 74.922;
                    }
                    else if (0 == strcmp(elem, "Se"))
                    {
                        massa += coef * 78.960;
                    }
                    else if (0 == strcmp(elem, "Br"))
                    {
                        massa += coef * 79.904;
                    }
                    else if (0 == strcmp(elem, "Kr"))
                    {
                        massa += coef * 83.798;
                    }
                    else if (0 == strcmp(elem, "Rb"))
                    {
                        massa += coef * 85.468;
                    }
                    else if (0 == strcmp(elem, "Sr"))
                    {
                        massa += coef * 87.620;
                    }
                    else if (0 == strcmp(elem, "Y"))
                    {
                        massa += coef * 88.906;
                    }
                    else if (0 == strcmp(elem, "Zr"))
                    {
                        massa += coef * 91.224;
                    }

                    else if (0 == strcmp(elem, "Nb"))
                    {
                        massa += coef * 92.906;
                    }
                    else if (0 == strcmp(elem, "Mo"))
                    {
                        massa += coef * 95.940;
                    }
                    else if (0 == strcmp(elem, "Tc"))
                    {
                        massa += coef * 98.000;
                    }
                    else if (0 == strcmp(elem, "Ru"))
                    {
                        massa += coef * 101.070;
                    }
                    else if (0 == strcmp(elem, "Rh"))
                    {
                        massa += coef * 102.905;
                    }
                    else if (0 == strcmp(elem, "Pd"))
                    {
                        massa += coef * 106.420;
                    }
                    else if (0 == strcmp(elem, "Ag"))
                    {
                        massa += coef * 107.868;
                    }
                    else if (0 == strcmp(elem, "Cd"))
                    {
                        massa += coef * 112.411;
                    }
                    else if (0 == strcmp(elem, "In"))
                    {
                        massa += coef * 114.818;
                    }
                    else if (0 == strcmp(elem, "Sn"))
                    {
                        massa += coef * 118.710;
                    }

                    else if (0 == strcmp(elem, "Sb"))
                    {
                        massa += coef * 121.760;
                    }
                    else if (0 == strcmp(elem, "Te"))
                    {
                        massa += coef * 127.600;
                    }
                    else if (0 == strcmp(elem, "I"))
                    {
                        massa += coef * 126.904;
                    }
                    else if (0 == strcmp(elem, "Xe"))
                    {
                        massa += coef * 131.293;
                    }
                    else if (0 == strcmp(elem, "Cs"))
                    {
                        massa += coef * 132.905;
                    }
                    else if (0 == strcmp(elem, "Ba"))
                    {
                        massa += coef * 137.327;
                    }
                    else if (0 == strcmp(elem, "Hf"))
                    {
                        massa += coef * 178.490;
                    }
                    else if (0 == strcmp(elem, "Ta"))
                    {
                        massa += coef * 180.948;
                    }
                    else if (0 == strcmp(elem, "W"))
                    {
                        massa += coef * 183.840;
                    }
                    else if (0 == strcmp(elem, "Re"))
                    {
                        massa += coef * 186.207;
                    }

                    else if (0 == strcmp(elem, "Os"))
                    {
                        massa += coef * 190.230;
                    }
                    else if (0 == strcmp(elem, "Ir"))
                    {
                        massa += coef * 192.217;
                    }
                    else if (0 == strcmp(elem, "Pt"))
                    {
                        massa += coef * 195.084;
                    }
                    else if (0 == strcmp(elem, "Au"))
                    {
                        massa += coef * 196.967;
                    }
                    else if (0 == strcmp(elem, "Hg"))
                    {
                        massa += coef * 200.590;
                    }
                    else if (0 == strcmp(elem, "Tl"))
                    {
                        massa += coef * 204.383;
                    }
                    else if (0 == strcmp(elem, "Pb"))
                    {
                        massa += coef * 207.200;
                    }
                    else if (0 == strcmp(elem, "Bi"))
                    {
                        massa += coef * 208.980;
                    }
                    else if (0 == strcmp(elem, "Po"))
                    {
                        massa += coef * 210.000;
                    }
                    else if (0 == strcmp(elem, "At"))
                    {
                        massa += coef * 210.000;
                    }

                    else if (0 == strcmp(elem, "Rn"))
                    {
                        massa += coef * 220.000;
                    }
                    else if (0 == strcmp(elem, "Fr"))
                    {
                        massa += coef * 223.000;
                    }
                    else if (0 == strcmp(elem, "Ra"))
                    {
                        massa += coef * 226.000;
                    }
                    else if (0 == strcmp(elem, "Rf"))
                    {
                        massa += coef * 261.000;
                    }
                    else if (0 == strcmp(elem, "Db"))
                    {
                        massa += coef * 262.000;
                    }
                    else if (0 == strcmp(elem, "Sg"))
                    {
                        massa += coef * 266.000;
                    }
                    else if (0 == strcmp(elem, "Bh"))
                    {
                        massa += coef * 264.000;
                    }
                    else if (0 == strcmp(elem, "Hs"))
                    {
                        massa += coef * 277.000;
                    }
                    else if (0 == strcmp(elem, "Mt"))
                    {
                        massa += coef * 268.000;
                    }
                    else if (0 == strcmp(elem, "Ds"))
                    {
                        massa += coef * 271.000;
                    }

                    else if (0 == strcmp(elem, "Rg"))
                    {
                        massa += coef * 272.000;
                    }
                    else if (0 == strcmp(elem, "Cn"))
                    {
                        massa += coef * 277.000;
                    }
                    else if (0 == strcmp(elem, "Nh"))
                    {
                        massa += coef * 286.000;
                    }
                    else if (0 == strcmp(elem, "Fl"))
                    {
                        massa += coef * 289.000;
                    }
                    else if (0 == strcmp(elem, "Mc"))
                    {
                        massa += coef * 288.000;
                    }
                    else if (0 == strcmp(elem, "Lv"))
                    {
                        massa += coef * 293.000;
                    }
                    else if (0 == strcmp(elem, "Ts"))
                    {
                        massa += coef * 294.000;
                    }
                    else if (0 == strcmp(elem, "Og"))
                    {
                        massa += coef * 294.000;
                    }
                    else if (0 == strcmp(elem, "La"))
                    {
                        massa += coef * 138.905;
                    }
                    else if (0 == strcmp(elem, "Ce"))
                    {
                        massa += coef * 140.116;
                    }

                    else if (0 == strcmp(elem, "Pr"))
                    {
                        massa += coef * 140.908;
                    }
                    else if (0 == strcmp(elem, "Nd"))
                    {
                        massa += coef * 144.242;
                    }
                    else if (0 == strcmp(elem, "Pm"))
                    {
                        massa += coef * 145.000;
                    }
                    else if (0 == strcmp(elem, "Sm"))
                    {
                        massa += coef * 150.360;
                    }
                    else if (0 == strcmp(elem, "Eu"))
                    {
                        massa += coef * 151.964;
                    }
                    else if (0 == strcmp(elem, "Gd"))
                    {
                        massa += coef * 157.250;
                    }
                    else if (0 == strcmp(elem, "Tb"))
                    {
                        massa += coef * 158.925;
                    }
                    else if (0 == strcmp(elem, "Dy"))
                    {
                        massa += coef * 162.500;
                    }
                    else if (0 == strcmp(elem, "Ho"))
                    {
                        massa += coef * 164.930;
                    }
                    else if (0 == strcmp(elem, "Er"))
                    {
                        massa += coef * 167.259;
                    }

                    else if (0 == strcmp(elem, "Tm"))
                    {
                        massa += coef * 168.934;
                    }
                    else if (0 == strcmp(elem, "Yb"))
                    {
                        massa += coef * 173.040;
                    }
                    else if (0 == strcmp(elem, "Lu"))
                    {
                        massa += coef * 174.967;
                    }
                    else if (0 == strcmp(elem, "Ac"))
                    {
                        massa += coef * 227.000;
                    }
                    else if (0 == strcmp(elem, "Th"))
                    {
                        massa += coef * 232.038;
                    }
                    else if (0 == strcmp(elem, "Pa"))
                    {
                        massa += coef * 231.035;
                    }
                    else if (0 == strcmp(elem, "U"))
                    {
                        massa += coef * 238.029;
                    }
                    else if (0 == strcmp(elem, "Np"))
                    {
                        massa += coef * 237.000;
                    }
                    else if (0 == strcmp(elem, "Pu"))
                    {
                        massa += coef * 244.000;
                    }
                    else if (0 == strcmp(elem, "Am"))
                    {
                        massa += coef * 243.000;
                    }

                    else if (0 == strcmp(elem, "Cm"))
                    {
                        massa += coef * 247.000;
                    }
                    else if (0 == strcmp(elem, "Bk"))
                    {
                        massa += coef * 247.000;
                    }
                    else if (0 == strcmp(elem, "Cf"))
                    {
                        massa += coef * 251.000;
                    }
                    else if (0 == strcmp(elem, "Es"))
                    {
                        massa += coef * 252.000;
                    }
                    else if (0 == strcmp(elem, "Fm"))
                    {
                        massa += coef * 257.000;
                    }
                    else if (0 == strcmp(elem, "Md"))
                    {
                        massa += coef * 258.000;
                    }
                    else if (0 == strcmp(elem, "No"))
                    {
                        massa += coef * 259.000;
                    }
                    else if (0 == strcmp(elem, "Lr"))
                    {
                        massa += coef * 262.000;
                    }

                    printf("Massa do reagente: ");
                    printf("%.4f\n", massa);

                    x = 0;
                }
            }

            // Produto
            while (0 == strcmp(elem, "2") && 0 != strcmp(elem2, "0"))
            {

                while (y == 0)
                {
                    printf("Insira o elemento ou digite 0 para calcular a massa:\n");
                    scanf("%s", elem2);

                    y = 1;
                }

                while (y == 1 && 0 != strcmp(elem2, "0"))
                {
                    printf("Insira o coeficiente:\n");
                    scanf("%d", &coef2);

                    if (0 == strcmp(elem2, "H"))
                    {
                        massa2 += coef2 * 1.008;
                    }
                    else if (0 == strcmp(elem2, "He"))
                    {
                        massa2 += coef2 * 4.003;
                    }
                    else if (0 == strcmp(elem2, "Li"))
                    {

                        massa2 += coef2 * 6.941;
                    }
                    else if (0 == strcmp(elem2, "Be"))
                    {
                        massa2 += coef2 * 9.012;
                    }
                    else if (0 == strcmp(elem2, "B"))
                    {
                        massa2 += coef2 * 10.811;
                    }
                    else if (0 == strcmp(elem2, "C"))
                    {
                        massa2 += coef2 * 12.011;
                    }
                    else if (0 == strcmp(elem2, "N"))
                    {
                        massa2 += coef2 * 14.007;
                    }
                    else if (0 == strcmp(elem2, "O"))
                    {
                        massa2 += coef2 * 15.999;
                    }
                    else if (0 == strcmp(elem2, "F"))
                    {
                        massa2 += coef2 * 18.998;
                    }
                    else if (0 == strcmp(elem2, "Ar"))
                    {
                        massa2 += coef2 * 39.948;
                    }
                    else if (0 == strcmp(elem2, "K"))
                    {
                        massa2 += coef2 * 39.098;
                    }
                    else if (0 == strcmp(elem2, "Ca"))
                    {
                        massa2 += coef2 * 40.078;
                    }
                    else if (0 == strcmp(elem2, "Sc"))
                    {
                        massa2 += coef2 * 44.956;
                    }
                    else if (0 == strcmp(elem2, "Ti"))
                    {
                        massa2 += coef2 * 47.867;
                    }
                    else if (0 == strcmp(elem2, "V"))
                    {
                        massa2 += coef2 * 50.942;
                    }
                    else if (0 == strcmp(elem2, "Cr"))
                    {
                        massa2 += coef2 * 51.996;
                    }
                    else if (0 == strcmp(elem2, "Mn"))
                    {
                        massa2 += coef2 * 54.938;
                    }
                    else if (0 == strcmp(elem2, "Fe"))
                    {
                        massa2 += coef2 * 55.845;
                    }
                    else if (0 == strcmp(elem2, "Co"))
                    {
                        massa2 += coef2 * 58.933;
                    }
                    else if (0 == strcmp(elem2, "Ni"))
                    {
                        massa2 += coef2 * 58.693;
                    }
                    else if (0 == strcmp(elem2, "Cu"))
                    {
                        massa2 += coef2 * 63.546;
                    }
                    else if (0 == strcmp(elem2, "Zn"))
                    {
                        massa2 += coef2 * 65.409;
                    }
                    else if (0 == strcmp(elem2, "Ga"))
                    {
                        massa2 += coef2 * 69.723;
                    }
                    else if (0 == strcmp(elem2, "Ge"))
                    {
                        massa2 += coef2 * 72.640;
                    }
                    else if (0 == strcmp(elem2, "As"))
                    {
                        massa2 += coef2 * 74.922;
                    }
                    else if (0 == strcmp(elem2, "Se"))
                    {
                        massa2 += coef2 * 78.960;
                    }
                    else if (0 == strcmp(elem2, "Br"))
                    {
                        massa2 += coef2 * 79.904;
                    }
                    else if (0 == strcmp(elem2, "Kr"))
                    {
                        massa2 += coef2 * 83.798;
                    }
                    else if (0 == strcmp(elem2, "Rb"))
                    {
                        massa2 += coef2 * 85.468;
                    }
                    else if (0 == strcmp(elem2, "Sr"))
                    {
                        massa2 += coef2 * 87.620;
                    }
                    else if (0 == strcmp(elem2, "Y"))
                    {
                        massa2 += coef2 * 88.906;
                    }
                    else if (0 == strcmp(elem2, "Zr"))
                    {
                        massa2 += coef2 * 91.224;
                    }
                    else if (0 == strcmp(elem2, "Nb"))
                    {
                        massa2 += coef2 * 92.906;
                    }
                    else if (0 == strcmp(elem2, "Mo"))
                    {
                        massa2 += coef2 * 95.940;
                    }
                    else if (0 == strcmp(elem2, "Tc"))
                    {
                        massa2 += coef2 * 98.000;
                    }
                    else if (0 == strcmp(elem2, "Ru"))
                    {
                        massa2 += coef2 * 101.070;
                    }
                    else if (0 == strcmp(elem2, "Rh"))
                    {
                        massa2 += coef2 * 102.905;
                    }
                    else if (0 == strcmp(elem2, "Pd"))
                    {
                        massa2 += coef2 * 106.420;
                    }
                    else if (0 == strcmp(elem2, "Ag"))
                    {
                        massa2 += coef2 * 107.868;
                    }
                    else if (0 == strcmp(elem2, "Cd"))
                    {
                        massa2 += coef2 * 112.411;
                    }
                    else if (0 == strcmp(elem2, "In"))
                    {
                        massa2 += coef2 * 114.818;
                    }
                    else if (0 == strcmp(elem2, "Sn"))
                    {
                        massa2 += coef2 * 118.710;
                    }
                    else if (0 == strcmp(elem2, "Sb"))
                    {
                        massa2 += coef2 * 121.760;
                    }
                    else if (0 == strcmp(elem2, "Te"))
                    {
                        massa2 += coef2 * 127.600;
                    }
                    else if (0 == strcmp(elem2, "I"))
                    {
                        massa2 += coef2 * 126.904;
                    }
                    else if (0 == strcmp(elem2, "Xe"))
                    {
                        massa2 += coef2 * 131.293;
                    }
                    else if (0 == strcmp(elem2, "Cs"))
                    {
                        massa2 += coef2 * 132.905;
                    }
                    else if (0 == strcmp(elem2, "Ba"))
                    {
                        massa2 += coef2 * 137.327;
                    }
                    else if (0 == strcmp(elem2, "Hf"))
                    {
                        massa2 += coef2 * 178.490;
                    }
                    else if (0 == strcmp(elem2, "Ta"))
                    {
                        massa2 += coef2 * 180.948;
                    }
                    else if (0 == strcmp(elem2, "W"))
                    {
                        massa2 += coef2 * 183.840;
                    }
                    else if (0 == strcmp(elem2, "Re"))
                    {
                        massa2 += coef2 * 186.207;
                    }
                    else if (0 == strcmp(elem2, "Os"))
                    {
                        massa2 += coef2 * 190.230;
                    }
                    else if (0 == strcmp(elem2, "Ir"))
                    {
                        massa2 += coef2 * 192.217;
                    }
                    else if (0 == strcmp(elem2, "Pt"))
                    {
                        massa2 += coef2 * 195.084;
                    }
                    else if (0 == strcmp(elem2, "Au"))
                    {
                        massa2 += coef2 * 196.967;
                    }
                    else if (0 == strcmp(elem2, "Hg"))
                    {
                        massa2 += coef2 * 200.590;
                    }
                    else if (0 == strcmp(elem2, "Tl"))
                    {
                        massa2 += coef2 * 204.383;
                    }
                    else if (0 == strcmp(elem2, "Pb"))
                    {
                        massa2 += coef2 * 207.200;
                    }
                    else if (0 == strcmp(elem2, "Bi"))
                    {
                        massa2 += coef2 * 208.980;
                    }
                    else if (0 == strcmp(elem2, "Po"))
                    {
                        massa2 += coef2 * 210.000;
                    }
                    else if (0 == strcmp(elem2, "At"))
                    {
                        massa2 += coef2 * 210.000;
                    }
                    else if (0 == strcmp(elem2, "Rn"))
                    {
                        massa2 += coef2 * 220.000;
                    }
                    else if (0 == strcmp(elem2, "Fr"))
                    {
                        massa2 += coef2 * 223.000;
                    }
                    else if (0 == strcmp(elem2, "Ra"))
                    {
                        massa2 += coef2 * 226.000;
                    }
                    else if (0 == strcmp(elem2, "Rf"))
                    {
                        massa2 += coef2 * 261.000;
                    }
                    else if (0 == strcmp(elem2, "Db"))
                    {
                        massa2 += coef2 * 262.000;
                    }
                    else if (0 == strcmp(elem2, "Sg"))
                    {
                        massa2 += coef2 * 266.000;
                    }
                    else if (0 == strcmp(elem2, "Bh"))
                    {
                        massa2 += coef2 * 264.000;
                    }
                    else if (0 == strcmp(elem2, "Hs"))
                    {
                        massa2 += coef2 * 277.000;
                    }
                    else if (0 == strcmp(elem2, "Mt"))
                    {
                        massa2 += coef2 * 268.000;
                    }
                    else if (0 == strcmp(elem2, "Ds"))
                    {
                        massa2 += coef2 * 271.000;
                    }
                    else if (0 == strcmp(elem2, "Rg"))
                    {
                        massa2 += coef2 * 272.000;
                    }
                    else if (0 == strcmp(elem2, "Cn"))
                    {
                        massa2 += coef2 * 277.000;
                    }
                    else if (0 == strcmp(elem2, "Nh"))
                    {
                        massa2 += coef2 * 286.000;
                    }
                    else if (0 == strcmp(elem2, "Fl"))
                    {
                        massa2 += coef2 * 289.000;
                    }
                    else if (0 == strcmp(elem2, "Mc"))
                    {
                        massa2 += coef2 * 288.000;
                    }
                    else if (0 == strcmp(elem2, "Lv"))
                    {
                        massa2 += coef2 * 293.000;
                    }
                    else if (0 == strcmp(elem2, "Ts"))
                    {
                        massa2 += coef2 * 294.000;
                    }
                    else if (0 == strcmp(elem2, "Og"))
                    {
                        massa2 += coef2 * 294.000;
                    }
                    else if (0 == strcmp(elem2, "La"))
                    {
                        massa2 += coef2 * 138.905;
                    }
                    else if (0 == strcmp(elem2, "Ce"))
                    {
                        massa2 += coef2 * 140.116;
                    }
                    else if (0 == strcmp(elem2, "Pr"))
                    {
                        massa2 += coef2 * 140.908;
                    }
                    else if (0 == strcmp(elem2, "Nd"))
                    {
                        massa2 += coef2 * 144.242;
                    }
                    else if (0 == strcmp(elem2, "Pm"))
                    {
                        massa2 += coef2 * 145.000;
                    }
                    else if (0 == strcmp(elem2, "Sm"))
                    {
                        massa2 += coef2 * 150.360;
                    }
                    else if (0 == strcmp(elem2, "Eu"))
                    {
                        massa2 += coef2 * 151.964;
                    }
                    else if (0 == strcmp(elem2, "Gd"))
                    {
                        massa2 += coef2 * 157.250;
                    }
                    else if (0 == strcmp(elem2, "Tb"))
                    {
                        massa2 += coef2 * 158.925;
                    }
                    else if (0 == strcmp(elem2, "Dy"))
                    {
                        massa2 += coef2 * 162.500;
                    }
                    else if (0 == strcmp(elem2, "Ho"))
                    {
                        massa2 += coef2 * 164.930;
                    }
                    else if (0 == strcmp(elem2, "Er"))
                    {
                        massa2 += coef2 * 167.259;
                    }
                    else if (0 == strcmp(elem2, "Tm"))
                    {
                        massa2 += coef2 * 168.934;
                    }
                    else if (0 == strcmp(elem2, "Yb"))
                    {
                        massa2 += coef2 * 173.040;
                    }
                    else if (0 == strcmp(elem2, "Lu"))
                    {
                        massa2 += coef2 * 174.967;
                    }
                    else if (0 == strcmp(elem2, "Ac"))
                    {
                        massa2 += coef2 * 227.000;
                    }
                    else if (0 == strcmp(elem2, "Th"))
                    {
                        massa2 += coef2 * 232.038;
                    }
                    else if (0 == strcmp(elem2, "Pa"))
                    {
                        massa2 += coef2 * 231.035;
                    }
                    else if (0 == strcmp(elem2, "U"))
                    {
                        massa2 += coef2 * 238.029;
                    }
                    else if (0 == strcmp(elem2, "Np"))
                    {
                        massa2 += coef2 * 237.000;
                    }
                    else if (0 == strcmp(elem2, "Pu"))
                    {
                        massa2 += coef2 * 244.000;
                    }
                    else if (0 == strcmp(elem2, "Am"))
                    {
                        massa2 += coef2 * 243.000;
                    }
                    else if (0 == strcmp(elem2, "Cm"))
                    {
                        massa2 += coef2 * 247.000;
                    }
                    else if (0 == strcmp(elem2, "Bk"))
                    {
                        massa2 += coef2 * 247.000;
                    }
                    else if (0 == strcmp(elem2, "Cf"))
                    {
                        massa2 += coef2 * 251.000;
                    }
                    else if (0 == strcmp(elem2, "Es"))
                    {
                        massa2 += coef2 * 252.000;
                    }
                    else if (0 == strcmp(elem2, "Fm"))
                    {
                        massa2 += coef2 * 257.000;
                    }
                    else if (0 == strcmp(elem2, "Md"))
                    {
                        massa2 += coef2 * 258.000;
                    }
                    else if (0 == strcmp(elem2, "No"))
                    {
                        massa2 += coef2 * 259.000;
                    }
                    else if (0 == strcmp(elem2, "Lr"))
                    {
                        massa2 += coef2 * 262.000;
                    }

                    printf("Massa do produto: ");
                    printf("%.4f\n", massa2);
                    y = 0;
                }
            }

            while (0 != strcmp(escolha2, "P") && 0 != strcmp(escolha2, "R"))
            {
                printf("Digite P para calcular o produto ou R para calcular o reagente:\n");
                scanf("%s", escolha2);

                if (0 != strcmp(escolha2, "P") && 0 != strcmp(escolha2, "R"))
                {
                    printf("Digite algo valido\n");
                }
            }

            if (0 == strcmp(escolha2, "R"))
            {

                printf("Informe a massa do produto em Kg:\n");
                scanf("%f", &massa3);
                massaf = (massa3 * massa) / massa2;
            }
            else if (0 == strcmp(escolha2, "P"))
            {
                printf("Informe a massa do reagente em Kg:\n");
                scanf("%f", &massa3);
                massaf = (massa3 * massa2) / massa;
            }

            printf("A massa final eh: %.4f Kg\n\n", massaf);
        }
        }
    }
}