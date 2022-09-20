
#include <stdio.h>
#include <string.h>
//#include "projectMain.cpp"



char* RValues(int searcher){
char instructions[100] = "";
char opera[100];
if(searcher == 32){
    strcat(instructions,"Operation: add\n");
    //strcat(instructions, "Instruction Type: R\n");
}else if(searcher == 33){
    strcat(instructions,"Operation: addu\n");
}else if(searcher == 36){
   strcat(instructions,"Operation: and\n");
}else if(searcher == 13){
    strcat(instructions,"Operation: break\n");
}else if(searcher == 26){
    strcat(instructions,"Operation: div\n");
}else if(searcher == 27){
    strcat(instructions,"Operation: divu\n");
}else if(searcher == 9){
    strcat(instructions,"Operation: jalr\n");
}else if(searcher == 8){
    strcat(instructions,"Operation: jr\n");
}else if(searcher == 16){
    strcat(instructions,"Operation: mfhi\n");
}else if(searcher == 18){
    strcat(instructions,"Operation: mflo\n");
}else if(searcher == 17){
    strcat(instructions,"Operation: mthi\n");
}else if(searcher == 19){
    strcat(instructions, "Operation: mtlo\n");
}else if(searcher == 24){
    strcat(instructions, "Operation: mult\n");
}else if(searcher == 25){
    strcat(instructions, "Operation: multu\n");
}else if(searcher == 39){
    strcat(instructions, "Operation: nor\n");
}else if(searcher == 37){
    strcat(instructions, "Operation: or\n");
}else if(searcher == 0){
    strcat(instructions, "Operation: sll\n");
}else if(searcher == 4){
    strcat(instructions, "Operation: sllv\n");
}else if(searcher == 42){
    strcat(instructions, "Operation: slt\n");
}else if(searcher == 43){
    strcat(instructions, "Operation: sltu\n");
}else if(searcher == 3){
    strcat(instructions, "Operation: sra\n");
}else if(searcher == 7){
    strcat(instructions, "Operation: srav\n");
}else if(searcher == 2){
    strcat(instructions, "Operation: srl\n");
}else if(searcher == 6){
    strcat(instructions, "Operation: srlv\n");
}else if(searcher == 34){
    strcat(instructions, "Operation: sub\n");
}else if(searcher == 35){
    strcat(instructions, "Operation: subu\n");
}else if(searcher == 12){
    strcat(instructions, "Operation: syscall\n");
}else if(searcher == 38){
    strcat(instructions, "Operation: xor\n");
}

char* Itran = new char[320];
strcat(Itran, instructions);

return Itran;
}

char* IValues(int searcher){
char instructions[100] = "";
if(searcher == 8){
    strcat(instructions, "Operation: addi\n");
}else if(searcher == 9){
    strcat(instructions, "Operation: addiu\n");
}else if(searcher == 12){
    strcat(instructions, "Operation: andi\n");
}else if(searcher == 4){
    strcat(instructions, "Operation: beq\n");
}else if(searcher == 100){
    strcat(instructions, "Operation: bgez\n");
}else if(searcher == 7){
    strcat(instructions, "Operation: bgtz\n");
}else if(searcher == 6){
    strcat(instructions, "Operation: blez\n");
}else if(searcher == 1){
    strcat(instructions, "Operation: bltz\n");
}else if(searcher == 5){
    strcat(instructions, "Operation: bne\n");
}else if(searcher == 32){
    strcat(instructions, "Operation: lb\n");
}else if(searcher == 36){
    strcat(instructions, "Operation: lbu\n");
}else if(searcher == 33){
    strcat(instructions, "Operation: lh\n");
}else if(searcher == 37){
    strcat(instructions, "Operation: lhu\n");
}else if(searcher == 15){
    strcat(instructions, "Operation: lui\n");
}else if(searcher == 35){
    strcat(instructions, "Operation: lw\n");
}else if(searcher == 49){
    strcat(instructions, "Operation: lwel\n");
}else if(searcher == 13){
    strcat(instructions, "Operation: ori\n");
}else if(searcher == 40){
    strcat(instructions, "Operation: sb\n");
}else if(searcher == 10){
    strcat(instructions, "Operation: slti\n");
}else if(searcher == 11){
    strcat(instructions, "Operation: sltiu\n");
}else if(searcher == 41){
    strcat(instructions, "Operation: sh\n");
}else if(searcher == 43){
    strcat(instructions, "Operation: sw\n");
}else if(searcher == 57){
    strcat(instructions, "Operation: swel\n");
}else if(searcher == 14){
    strcat(instructions, "Operation: xori\n");
}

char* Itran = new char[320];
strcat(Itran, instructions);

return Itran;
}

char* RFunctions(char *jokerPersona5){

//=================================================

char instructions[100] = "";

//===================================================

//printf("Instruction Type : R\n");
strcat(instructions, "Instruction Type: R\n");

    int bignum =0; 
    int multiplier = 1;

    for(int i =31; i>=26 ; i--){
        bignum += multiplier * (jokerPersona5[i]-48);
        multiplier = multiplier * 2;
    }

    //RValues(bignum);
    strcat(instructions, RValues(bignum));

    int smallnum = 0;
    multiplier = 1;
    for(int i =10; i>=6 ; i--){
        smallnum += multiplier * (jokerPersona5[i]-48);
        multiplier = multiplier * 2;
    }

    //printf("Rs: $%d\n", smallnum);
    char temporaryIn1[13];
    sprintf(temporaryIn1, "Rs: $%d\n", smallnum);
    strcat(instructions, temporaryIn1);

    smallnum = 0;
    multiplier = 1;
    for(int i =15; i>=11 ; i--){
        smallnum += multiplier * (jokerPersona5[i]-48);
        multiplier = multiplier * 2;
    }

    //printf("Rt: $%d\n", smallnum);
    char temporaryIn2[12];
    sprintf(temporaryIn2, "Rt: $%d\n", smallnum);
    strcat(instructions, temporaryIn2);

    smallnum = 0;
    multiplier = 1;
    for(int i =20; i>=16 ; i--){
        smallnum += multiplier * (jokerPersona5[i]-48);
        multiplier = multiplier * 2;
    }

    //printf("Rd: $%d\n", smallnum);
    char temporaryIn3[12];
    sprintf(temporaryIn3, "Rd: $%d\n", smallnum);
    strcat(instructions, temporaryIn3);

    smallnum = 0;
    multiplier = 1;
    for(int i =25; i>=21 ; i--){
        smallnum += multiplier * (jokerPersona5[i]-48);
        multiplier = multiplier * 2;
    }

    //printf("shamt: %d\n", smallnum);
    char temporaryIn4[12];
    sprintf(temporaryIn4, "shamt: %d\n", smallnum);
    strcat(instructions, temporaryIn4);

    //printf("Funct: %d\n", bignum);
    char temporaryIn5[12];
    sprintf(temporaryIn5, "Funct: %d\n", bignum);
    strcat(instructions, temporaryIn5);

    char* Itran = new char[320];
    
    strcat(Itran, instructions);

    

return Itran;
}

char* IFunctions(char *jokerPersona5){

//======================================
char instructions[100] = "";
//======================================


//printf("Instruction Type : I\n");
strcat(instructions, "Instruction Type: I\n");
//printf("%s", jokerPersona5);



    int bignum =0; 
    int multiplier = 1;

    for(int i =5; i>=0 ; i--){
        bignum += multiplier * (jokerPersona5[i]-48);
        multiplier = multiplier * 2;
    }

    //IValues(bignum);
    strcat(instructions, IValues(bignum));

    int smallnum = 0;
    multiplier = 1;
    for(int i =10; i>=6 ; i--){
        smallnum += multiplier * (jokerPersona5[i]-48);
        multiplier = multiplier * 2;
    }

    //printf("Rs: $%d\n", smallnum);
    char temporaryIn1[12];
    sprintf(temporaryIn1, "Rs: $%d\n", smallnum);
    strcat(instructions, temporaryIn1);

    smallnum = 0;
    multiplier = 1;
    for(int i =15; i>=11 ; i--){
        smallnum += multiplier * (jokerPersona5[i]-48);
        multiplier = multiplier * 2;
    }

    //printf("Rt: $%d\n", smallnum);
    char temporaryIn2[12];
    sprintf(temporaryIn2, "Rt: $%d\n", smallnum);
    strcat(instructions, temporaryIn2);

    smallnum = 0;
    multiplier = 1;
    for(int i =31; i>=16 ; i--){
        smallnum += multiplier * (jokerPersona5[i]-48);
        multiplier = multiplier * 2;
    }

    //printf("Immediate: %d\n", smallnum);
    char temporaryIn3[24];
    //string temporaryIn3 = ("Immediate: %d\n", smallnum);
    //strcat(temporaryIn3,("Immediate: %d\n", smallnum));
    sprintf(temporaryIn3, "Immediate: %d\n", smallnum);
    strcat(instructions, temporaryIn3);

    //printf(instructions); //instructions work up to this point!
    //strcat(mariokart, instructions);

    //======================================================
    char* Itran = new char[320];
    
    strcat(Itran, instructions);
    //======================================================

return Itran;
}

char* JFunctions(char *jokerPersona5){
char instructions[100] = "";
//printf("Instruction Type : J\n");
strcat(instructions, "Instruction Type: J\n");
int bignum =0; 
    int multiplier = 1;

    for(int i =5; i>=0 ; i--){
        bignum += multiplier * (jokerPersona5[i]-48);
        multiplier = multiplier * 2;

    }
if(bignum == 2){
    //printf("Operation: j");
    //char temporaryIn1[13];
    char temporaryIn1[100];
    sprintf(temporaryIn1, "Operation: j\n");
    strcat(instructions, temporaryIn1);
}else if(bignum ==3){
    //printf("Operation: jal\n");
    //char temporaryIn1[15];
    char temporaryIn1[100];
    sprintf(temporaryIn1, "Operation: jal\n");
    strcat(instructions, temporaryIn1);
}

bignum =0;
multiplier = 1;
for(int i= 31; i >=6; i--){
    bignum += multiplier * (jokerPersona5[i]-48);
    multiplier = multiplier * 2;
}
//printf("Immediate: %d", bignum);
char temporaryIn2[23];
sprintf(temporaryIn2, "Immediate: %d", bignum);
strcat(instructions, temporaryIn2);

char* Itran = new char[320];
    
strcat(Itran, instructions);

return Itran;
}

int BinarytoNum(){
int largness = 0;
int multiplier = 1;
//char leagueofRivals[6] = *jokerPersona5;
//for(int i = leagueofRivals.length; i > 0; i++)


return 0;
}

char mariokart[300];

char* Decode(char str[32])
{

    //char str[32];
    char transfer[32];

    //printf("Input the machine code you want: \n");
    //scanf( "%s", str );

    //printf("%d", (char)str[2]-48 ); //just need to remember to get rid of the 48 to get the actual number

    int bignum =0; 
    int multiplier = 1;

    for(int i =5; i>=0 ; i--){
        transfer[i] = str[i];
        bignum += multiplier * (str[i]-48);
        multiplier = multiplier * 2;

    }
    
    //printf("%s", transfer ); //just need to remember to get rid of the 48 to get the actual number
    //printf("%d\n", bignum);
    if(bignum == 0){
        //char sendbackplease[200] = "";
        //char* gonta = new char[1000];
        //char bardok[1000];
        //strcpy(bardok,gonta);
        return RFunctions(str); //pretty much the only important part
    }else if(bignum == 2 || bignum == 3){
        //char sendbackplease[200] = "";
        //char* gonta = new char[1000];
        //char bardok[1000];
        //strcpy(bardok,gonta);
        return JFunctions(str); //pretty much the only important part
    }else{
        //char sendbackplease[200] = "";
        //strcat(sendbackplease,IFunctions(str));
        //IFunctions(str);
        //printf("yeehaw i got here \n");
        //printf(IFunctions(str));
        //printf("neepaw i yaght here \n");
        //char* gonta = new char[1000];
        //gonta = IFunctions(str);
        //char bardok[1000];
        //strcpy(bardok,gonta);

        //sprintf(gonta, "Here is gonta: %s", IFunctions(str));
        //printf("%s", gonta);

        //DecodeEnd(gonta);

        return IFunctions(str);
    }

    return 0;
}