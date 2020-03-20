#include "init.hpp"

void initTable(unsigned char table[3][162]){
    for (int i=0;i<162;i++){
        table[0][i] = i;
        table[1][i] = i;
    }

    table[1][0] = 0;
    table[1][1] = 1;
    table[1][2] = 2;
    table[1][3] = 3;
    table[1][4] = 4;
    table[1][5] = 66;
    table[1][6] = 6;
    table[1][7] = 7;
    table[1][8] = 8;
    table[1][9] = 36;  //18;
    table[1][10] = 68;
    table[1][11] = 38; //69
    table[1][12] = 12;
    table[1][13] = 74; //22
    table[1][14] = 14;
    table[1][15] = 15;
    table[1][16] = 16;
    table[1][17] = 96;
    table[1][18] = 9; //36
    table[1][19] = 98; //37
    table[1][20] = 72;
    table[1][21] = 42;
    table[1][22] = 13; //74
    table[1][23] = 102; //75
    table[1][24] = 24;
    table[1][25] = 52; //104
    table[1][26] = 84; //44
    table[1][27] = 45; //54
    table[1][28] = 28;
    table[1][29] = 90; //108
    table[1][30] = 30;
    table[1][31] = 110;
    table[1][32] = 32;
    table[1][33] = 33;
    table[1][34] = 65;
    table[1][35] = 35;
    table[1][36] = 18; //9
    table[1][37] = 19; //98
    table[1][38] = 69; //11
    table[1][39] = 39;
    table[1][40] = 80;
    table[1][41] = 81; //50
    table[1][42] = 21;
    table[1][43] = 83; //101
    table[1][44] = 26; //84
    table[1][45] = 54; //27
    table[1][46] = 77; //86
    table[1][47] = 87;
    table[1][48] = 48;
    table[1][49] = 49;
    table[1][50] = 41; //81
    table[1][51] = 51;
    table[1][52] = 104; //25
    table[1][53] = 105; //114
    table[1][54] = 27; //45
    table[1][55] = 107;
    table[1][56] = 56;
    table[1][57] = 57;
    table[1][58] = 116; //89
    table[1][59] = 117;
    table[1][60] = 60;
    table[1][61] = 122;
    table[1][62] = 93;
    table[1][63] = 63;
    table[1][64] = 64;
    table[1][65] = 34;
    table[1][66] = 5;
    table[1][67] = 67;
    table[1][68] = 10;
    table[1][69] = 11; //38
    table[1][70] = 70;
    table[1][71] = 71;
    table[1][72] = 20;
    table[1][73] = 100; //82
    table[1][74] = 22; //13
    table[1][75] = 23; //102
    table[1][76] = 76;
    table[1][77] = 86; //46
    table[1][78] = 78;
    table[1][79] = 79;
    table[1][80] = 40;
    table[1][81] = 50; //41
    table[1][82] = 73; //100
    table[1][83] = 101; //43
    table[1][84] = 44; //26
    table[1][85] = 106;
    table[1][86] = 46; //77
    table[1][87] = 47;
    table[1][88] = 88;
    table[1][89] = 58; //116
    table[1][90] = 108; //29
    table[1][91] = 109; //118
    table[1][92] = 92;
    table[1][93] = 62;
    table[1][94] = 94;
    table[1][95] = 95;
    table[1][96] = 17;
    table[1][97] = 97;
    table[1][98] = 37; //19
    table[1][99] = 99;
    table[1][100] = 82; //73
    table[1][101] = 43; //83
    table[1][102] = 75; //23
    table[1][103] = 103;
    table[1][104] = 25; //52
    table[1][105] = 114; //53
    table[1][106] = 85;
    table[1][107] = 55;
    table[1][108] = 29; //90
    table[1][109] = 118; //91
    table[1][110] = 31;
    table[1][111] = 111;
    table[1][112] = 112;
    table[1][113] = 113;
    table[1][114] = 53; //105
    table[1][115] = 115;
    table[1][116] = 89; //58
    table[1][117] = 59;
    table[1][118] = 91; //109
    table[1][119] = 119; 
    table[1][120] = 120;
    table[1][121] = 121;
    table[1][122] = 61;
    table[1][123] = 123;
    table[1][124] = 124;
    table[1][125] = 125;
    table[1][126] = 126;
    table[1][127] = 127;//end of original tabelau
    
    table[1][128] = 128;//
    table[1][129] = 136;//
    table[1][130] = 144;//
    table[1][132] = 160;//
    table[1][136] = 129;//
    table[1][140] = 161;//
    table[1][144] = 130;//
    table[1][160] = 132;//
    table[1][161] = 140;//

    for (int i=0;i<162;i++){
        table[2][i]=table[1][i];
    }

    table[2][9] = 18;
    table[2][11] = 69;
    table[2][13] = 22;
    table[2][18] = 36;
    table[2][19] = 37;
    table[2][22] = 74;
    table[2][23] = 75;
    table[2][25] = 104;
    table[2][26] = 44;
    table[2][27] = 54;
    table[2][29] = 108;
    table[2][36] = 9;
    table[2][37] = 98;
    table[2][38] = 11;
    table[2][41] = 50;
    table[2][43] = 101;
    table[2][44] = 84;
    table[2][45] = 27;
    table[2][46] = 86;
    table[2][50] = 81;
    table[2][52] = 25;
    table[2][53] = 114;
    table[2][54] = 45;
    table[2][58] = 89;
    table[2][69] = 38;
    table[2][73] = 82;
    table[2][74] = 13;
    table[2][75] = 102;
    table[2][77] = 46;
    table[2][81] = 41;
    table[2][82] = 100;
    table[2][83] = 43;
    table[2][84] = 26;
    table[2][86] = 77;
    table[2][89] = 116;
    table[2][90] = 29;
    table[2][91] = 118;
    table[2][98] = 19;
    table[2][100] = 73;
    table[2][101] = 83;
    table[2][102] = 23;
    table[2][104] = 52;
    table[2][105] = 53;
    table[2][108] = 90;
    table[2][109] = 91;
    table[2][114] = 105;
    table[2][116] = 58;
    table[2][118] = 109;
}

void initBoard(unsigned char board[height][width]){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            board[i][j] = 0;
        }
    }
    for(int j=0;j<width;j++){
        board[0][j] = 128;
        board[height-1][j] = 128; // pipe
    }

    gsl_rng *r = gsl_rng_alloc(gsl_rng_mt19937);//ran3,r250,mt19937
    gsl_rng_set(r,time(NULL));
    int randX = 0;
    int randY = 0;
    int randDir = 0;

    for (int i=0;i<leftDens;i++){
        randX = gsl_rng_uniform_int(r,20) + 1;
        randY = gsl_rng_uniform_int(r,height-2) + 1;
        randDir = gsl_rng_uniform_int(r,6);

        while(bitCheck(board[randY][randX],randDir) == 1){
            randX = gsl_rng_uniform_int(r,20) +1;
            randY = gsl_rng_uniform_int(r,height-2) + 1;  
            randDir = gsl_rng_uniform_int(r,6);
        }
        bitSet(board[randY][randX],randDir);
    }

    for (int i=0;i<rightDens;i++){
        randX = gsl_rng_uniform_int(r,20)+width-21;
        randY = gsl_rng_uniform_int(r,height-2) + 1;
        randDir = gsl_rng_uniform_int(r,6);

        while(bitCheck(board[randY][randX],randDir) == 1){
            randX = gsl_rng_uniform_int(r,20)+width-21;
            randY = gsl_rng_uniform_int(r,height-2) + 1;  
            randDir = gsl_rng_uniform_int(r,6);
        }
        bitSet(board[randY][randX],randDir);
    }
}

void initBlankBoard(unsigned char board[height][width]){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            board[i][j] = 0;
        }
    }
}

bool bitCheck(unsigned char& node, int direction){
    return node & (1 << direction); 
}

void bitSet(unsigned  char&  node , int pos){
    node |= (1 << pos);
}

void bitClear(unsigned char& node, int pos){
    node &= !(1 << pos);
}