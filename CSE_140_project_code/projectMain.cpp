#include <iostream>

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <cctype>

#include "DecoderC.c"

using namespace std;

int pc = 0;
int total_clock_cycles = 0;
int nextpc = pc + 4;
int alu_zero = 0;
char* retreival = new char[100];
int jump_target = 0;
int branch_target = 0;
int dialga = 0;
int fourteenthSavior = 0;
int fifteenthSavior = 0;

//char * retreival = malloc(sizeof(64*100));

int registerfile[32] = { 0 };
int d_mem[32] = { 0 };
int alu_op[4] = {0};



string Fetch(string fileuNameu);
int Execute(string instructions);
int ExecuteI(string instructionI, string OperationI, string fullInstructionI);
int ExecuteR(string instructionR, string OperationR, string fullInstructionR);
int ExecuteJ(string instructionJ, string OperationJ, string fullInstructionJ);
int Mem(int memLocation);
int Writeback(int memLocation, int regVal);
int saveRegValues(int savingvale, string regRequester);
int getRegValues(string regRequester);
int BitwiseOr(int rt, int rs);
int BitwiseAnd(int rt, int rs);

ifstream readFile("sample_part1.txt");

int main(int argc, const char * argv[])
{
//Initialize the starting variables
    //hex to regular values
    int fileNumber = 2;

    string fileuNameu;
    cout << "Please enter the file you would like to read: ";
    cin >> fileuNameu;
    cout << endl;


    if(fileuNameu == "sample_part1.txt"){
        int hexloader = 0;
        hexloader = 0x20;
        //std::cin >> std::hex >> hexloader;
        //hexloader << hex << hexloader;'
        //hexloader = 32;
        hexloader = hexloader;
        saveRegValues(hexloader, "$t1");
        hexloader = 0x5;
        //std::cin >> std::hex >> hexloader;
        //hexloader = 5;
        hexloader = hexloader;
        saveRegValues(hexloader, "$t2");
        hexloader = 0x70;
        //std::cin >> std::hex >> hexloader;
        //hexloader = 112;
        hexloader = hexloader;
        saveRegValues(hexloader, "$s0");
        hexloader = 0x70;
        //std::cin >> std::hex >> hexloader;
        //hexloader = 0x112;
        hexloader = hexloader/4;
        Writeback(hexloader, 0x5);
        hexloader = 0x74;
        //std::cin >> std::hex >> hexloader;
        //hexloader = 116;
        hexloader = hexloader/4;
        //Writeback(0x10, 29);
        Writeback(hexloader, 0x10);
    }else if(fileuNameu == "sample_part2.txt"){
        int hexloader = 0;

        hexloader = 0x20;
        hexloader = hexloader;
        saveRegValues(hexloader, "$s0");

        hexloader = 0x5;
        hexloader = hexloader;
        saveRegValues(hexloader, "$a0");

        hexloader = 0x2;
        hexloader = hexloader;
        saveRegValues(hexloader, "$a1");

        hexloader = 0xa;
        hexloader = hexloader;
        saveRegValues(hexloader, "$a3");
    }


    for(int i = 0; i < 10; i=i){
    //This gets the string to execute (fetch)===============================
    string currentCommand;
    currentCommand = Fetch(fileuNameu);
    //=======================================================================

    //This sets it up, and sends it to the decoder=============================
    //char* retreivalfailure = new char[5000];
    string retreival;

    char* ranger[5000];
    string ravali = "";
    char* ctran = new char[32];
    std::copy(currentCommand.begin(), currentCommand.end(), ctran);
    ctran[currentCommand.size()] = '\0';
    //ravali.append((string)Decode(ctran));
    retreival = Decode(ctran);
    //Decode(ctran);
    delete[] ctran;
    //cout << "current instruction on cpp side" << endl << retreival << endl << endl;
    string fourteenSavString = "";

    if(total_clock_cycles == 13){
        for(int i  = 0; i < retreival.size(); i++){
            //cout << i << " : " << retreival[i] << endl;
        }
    }

    if(total_clock_cycles == 14){
        fourteenthSavior = retreival.size();
        cout << "Retreival size: " << fourteenthSavior << endl;
        for(int i = 0; i < retreival.size(); i++){
            //retreival.pop(i);
            if(i >=0 && i <= 198 ){
                //get rid of binary ahhhh
            }else{
                fourteenSavString += retreival[i];
                
            }

        }
        retreival = fourteenSavString;
        for(int i = 0; i < retreival.size(); i++){
            //cout << i << " : " << retreival[i] << endl;
        }
        fourteenthSavior = 0;
    }

    if(total_clock_cycles >= 15){
        /*
        fourteenthSavior = retreival.size();
        cout << "Retreival size: " << fourteenthSavior << endl;
        for(int i = 0; i < retreival.size(); i++){
            //retreival.pop(i);
            if(i >=18 && i <= 221 ){
                //get rid of binary ahhhh
            }else{
                fourteenSavString += retreival[i];
                
            }

        }
        //retreival = fourteenSavString;
        retreival = "" + retreival;
        for(int i = 0; i < retreival.size(); i++){
            cout << i << " : " << retreival[i] << endl;
        }
        fourteenthSavior = -6;
        fifteenthSavior = 1;
        */
       fourteenSavString = "";
       fourteenthSavior = retreival.size();
        cout << "Retreival size: " << fourteenthSavior << endl;
        for(int i = 0; i < retreival.size(); i++){
            //retreival.pop(i);
            if(i >=0 && i <= 198 ){
                //get rid of binary ahhhh
            }else{
                fourteenSavString += retreival[i];
                
            }

        }
        retreival = fourteenSavString;
        for(int i = 0; i < retreival.size(); i++){
            //cout << i << " : " << retreival[i] << endl;
        }
        fourteenthSavior = 0;
    }
    //cout << retreival << endl;
    //if(total_clock_cycles < 14){
    Execute(retreival);
    //}

    
    total_clock_cycles++;
    cout << "pc is modified to " << pc << endl;
    cout << "total clock cycles: " << total_clock_cycles << endl;

    //cout << "trying to get a specific value" << endl << retreival[6] << retreival[7] << retreival[8] << retreival[16] << retreival[22]<< retreival[24];


    //retreival guide:
    //first 5 are for the buffer
    //16 is last n on instruction
    //22 is the :
    //24 should be instruction

    //Guide to what instruction types and operations they are
    /*
        LW  -   I
        SW  -   I
        BEQ -   I
        ADD -   R
        SUB -   R
        AND -   R
        OR  -   R
        SLT -   R
        NOR -   R
        J   -   J
    */
    //===========================================================================
    if(dialga == 1){
        break;
    }

    }
    cout << endl;
    cout << "Program has ended" << endl;
    cout << "total execution time is " << total_clock_cycles << " cycles." << endl;
}

int Execute(string instructions){
    cout << "your instruction type is: " << instructions[24+fourteenthSavior] << endl;
    string instructiontypeholder;
    instructiontypeholder = instructions[24+fourteenthSavior]; //holds the instruction type
    string operationtypeholder = "";
    int count = 0;
    for(int i =0; i < 10; i = i){ //this will loop through until it finds the break and says thats the end of the instructions

        if(isalpha(instructions[43+count])){
            operationtypeholder = operationtypeholder + instructions[43+count+(fourteenthSavior*2) + fifteenthSavior];
            if(total_clock_cycles == 15){
                //operationtypeholder = operationtypeholder + instructions[43+count+(fourteenthSavior*2)+1];
            }
        }else{
            break;
        }
        count = count + 1;
    }
    if(instructiontypeholder == "R" || instructiontypeholder == "I"){
        cout << "the operation is: "<< operationtypeholder << endl; 
    }
    //cout << "the operation is: "<< operationtypeholder << endl; 
    if(instructiontypeholder == "I"){
        //cout << "cpp recognizes this as an I function" << endl;
        ExecuteI(instructiontypeholder, operationtypeholder, instructions);
    }else if(instructiontypeholder == "R"){
        //cout << "cpp recognizes this as an R function" << endl;
        ExecuteR(instructiontypeholder, operationtypeholder, instructions);
    }else if(instructiontypeholder == "J"){
        //cout << "cpp recognizes this as an J function" << endl;
        ExecuteJ(instructiontypeholder, operationtypeholder, instructions);
    }
    return 0;
}

int ExecuteI(string instructionI, string OperationI, string fullInstructionI){
    //cout << endl << endl << "this is what we got: " << endl << instructionI << endl << OperationI << endl << fullInstructionI;
    //above code proves that values get here correctly
    //We already know its an I instruction here, so honestly instructionI is kinda useless
    //determine which I operation we have an need to exectue, since there are so few we can just list them

    //find the rest of the values of I =====================================================
    //For RS==============================================================================================
    int count = 43;
    int rsNum = 0;
    string RSsearch = "";
    //cout << fullInstructionI[43] << fullInstructionI[44];
    
    for(int i = 0; i < 10; i=i){
        RSsearch = "";
        RSsearch = RSsearch + fullInstructionI[count-1] + fullInstructionI[count];
        if(RSsearch == "Rs"){
            rsNum = count+3;
            break;
        }
        //cout << RSsearch << endl;
        count = count + 1;
    }
    //cout << "Is this where i am?" << fullInstructionI[rsNum-1] << fullInstructionI[rsNum] << endl; 
    //its bootiful! :)
    string rs = "";
    rs = rs + fullInstructionI[rsNum];
    for(int i = 0; i < 10; i = i){
        rsNum = rsNum + 1;
        if(isdigit(fullInstructionI[rsNum])){
            rs = rs + fullInstructionI[rsNum];
        }else{
            break;
        }
    }
    cout << "This is rs: " << rs << endl;
    //For Rt===============================================================================================
        count = rsNum;
        int rtNum = 0;
        string rtSearch = "";
        for(int i = 0; i<10; i=i){
            rtSearch = "";
            rtSearch = rtSearch + fullInstructionI[count-1] + fullInstructionI[count];
            if(rtSearch == "Rt"){
                rtNum = count + 3;
                break;
            }
            count = count + 1;
        }
        string rt = "";
        rt = rt + fullInstructionI[rtNum];
        for(int i = 0; i < 10; i = i){
            rtNum = rtNum + 1;
            if(isdigit(fullInstructionI[rtNum])){
                rt = rt + fullInstructionI[rtNum];
            }else{
                break;
            }
        }
        cout << "This is rt: " << rt << endl;
    //Immediate =========================================================================================
        count = rtNum;
        int ImmediateNum = 0;
        string ImmediateSearch = "";
        for(int i = 0; i<10; i=i){
            ImmediateSearch = "";
            ImmediateSearch = ImmediateSearch + fullInstructionI[count-1] + fullInstructionI[count];
            if(ImmediateSearch == "te"){
                ImmediateNum = count + 3;
                break;
            }
            count = count + 1;
        }
        string Immediate = "";
        Immediate = Immediate + fullInstructionI[ImmediateNum];
        for(int i = 0; i < 10; i = i){
            ImmediateNum = ImmediateNum + 1;
            if(isdigit(fullInstructionI[ImmediateNum])){
                Immediate = Immediate + fullInstructionI[ImmediateNum];
            }else{
                break;
            }
        }
        cout << "This is Immediate: " << Immediate << endl;
    //======================================================================================

    if(OperationI == "lw"){
        //lw destination register, immediate(memory)
        // rt, immediate(rs)
        //first load rs of memory plus immediate (div by 4 for the actual number), save it to rt
        int rsVal = getRegValues(rs);
        rsVal = rsVal + (stoi(Immediate)/4); // (stoi(Immediate)/4);
        int valFromMem = Mem(rsVal);
        int rtVal = saveRegValues(valFromMem,rt);
        cout << "loaded from Mem: " << rsVal << " to register: $" << rtVal << endl;
        cout << "number loaded was: " << valFromMem << endl;
        
    }else if(OperationI == "sw"){
        //first get value from rt, then that value is save into the address of the memory of rs+Immediate
        int rtVal = getRegValues(rt);
        int rsVal = getRegValues(rs) + (stoi(Immediate)/4);
        Writeback(rsVal, rtVal);
        cout << "your word is: " << rtVal << endl;
        cout << "saved word to: " << rsVal << endl;
    }else if(OperationI == "beq"){
        //first get values of rt and rs, if they are equal you jump (immediate * 4) places ahead of current pc.
        int rtVal = getRegValues(rt);
        int rsVal = getRegValues(rs);
        if(rtVal == rsVal){
            pc = pc + (stoi(Immediate)*4); //no need for *4 since its already in bits.
            branch_target = pc;
            cout << "pc now same as branch target: " << pc << endl;
        }
    }   
    return 0;
}

int ExecuteR(string instructionR, string OperationR, string fullInstructionR){

    //find rest of values for R ===================================================
    //Find Rs ================================================================================
    int count = 43;
    int rsNum = 0;
    string RSsearch = "";
    //cout << fullInstructionI[43] << fullInstructionI[44];
    
    for(int i = 0; i < 10; i=i){
        RSsearch = "";
        RSsearch = RSsearch + fullInstructionR[count-1] + fullInstructionR[count];
        if(RSsearch == "Rs"){
            rsNum = count+3;
            break;
        }
        //cout << RSsearch << endl;
        count = count + 1;
    }
    //cout << "Is this where i am?" << fullInstructionI[rsNum-1] << fullInstructionI[rsNum] << endl; 
    //its bootiful! :)
    string rs = "";
    rs = rs + fullInstructionR[rsNum];
    for(int i = 0; i < 10; i = i){
        rsNum = rsNum + 1;
        if(isdigit(fullInstructionR[rsNum])){
            rs = rs + fullInstructionR[rsNum];
        }else{
            break;
        }
    }
    cout << "This is rs: " << rs << endl;
    //For Rt===============================================================================================
        count = rsNum;
        int rtNum = 0;
        string rtSearch = "";
        for(int i = 0; i<10; i=i){
            rtSearch = "";
            rtSearch = rtSearch + fullInstructionR[count-1] + fullInstructionR[count];
            if(rtSearch == "Rt"){
                rtNum = count + 3;
                break;
            }
            count = count + 1;
        }
        string rt = "";
        rt = rt + fullInstructionR[rtNum];
        for(int i = 0; i < 10; i = i){
            rtNum = rtNum + 1;
            if(isdigit(fullInstructionR[rtNum])){
                rt = rt + fullInstructionR[rtNum];
            }else{
                break;
            }
        }
        cout << "This is rt: " << rt << endl;
    //Rd =========================================================================================
        count = rtNum;
        int rdNum = 0;
        string rdSearch = "";
        for(int i = 0; i<10; i=i){
            rdSearch = "";
            rdSearch = rdSearch + fullInstructionR[count-1] + fullInstructionR[count];
            if(rdSearch == "Rd"){
                rdNum = count + 3;
                break;
            }
            count = count + 1;
        }
        string rd = "";
        rd = rd + fullInstructionR[rdNum];
        for(int i = 0; i < 10; i = i){
            rdNum = rdNum + 1;
            if(isdigit(fullInstructionR[rdNum])){
                rd = rd + fullInstructionR[rdNum];
            }else{
                break;
            }
        }
        cout << "This is rd: " << rd << endl;
    //shamt =========================================================================================
        count = rdNum;
        int shamtNum = 0;
        string shamtSearch = "";
        for(int i = 0; i<10; i=i){
            shamtSearch = "";
            shamtSearch = shamtSearch + fullInstructionR[count-1] + fullInstructionR[count];
            if(shamtSearch == "mt"){
                shamtNum = count + 3;
                break;
            }
            count = count + 1;
        }
        string shamt = "";
        shamt = shamt + fullInstructionR[shamtNum];
        for(int i = 0; i < 10; i = i){
            shamtNum = shamtNum + 1;
            if(isdigit(fullInstructionR[shamtNum])){
                shamt = shamt + fullInstructionR[shamtNum];
            }else{
                break;
            }
        }
        cout << "This is shamt: " << shamt << endl;

    //============================================================================

   if(OperationR == "add"){
       //all registers
       //rd = rs + rt
       alu_op[0] = 0;
        alu_op[1] = 0;
        alu_op[2] = 1;
        alu_op[3] = 0;
       int rsVal = getRegValues(rs);
       int rtVal = getRegValues(rt);
       int rdVal = rsVal + rtVal;
       saveRegValues(rdVal, rd);
       cout << "value of " << rdVal << " saved to register " << rd << endl;

   }else if(OperationR == "sub"){
       //cout << "I am subbing" << endl;
       //all registers
       //rd = rs -rt
       alu_op[0] = 0;
        alu_op[1] = 1;
        alu_op[2] = 1;
        alu_op[3] = 0;
       int rsVal = getRegValues(rs);
       int rtVal = getRegValues(rt);
       cout << "rs: " << rsVal << ". rt: " << rtVal << endl;
       //rsVal = getRegValues("$t2");
       //rtVal = getRegValues("$t1");
       int rdVal = rsVal - rtVal;
       saveRegValues(rdVal, rd);
       cout << "value of " << rdVal << " saved to register " << rd << endl;

   }else if(OperationR == "and"){
       //all registers
       //get values for rs and rt, and then preform a bitwise, saving into rd
        alu_op[0] = 0;
        alu_op[1] = 0;
        alu_op[2] = 0;
        alu_op[3] = 0;
       int rsVal = getRegValues(rs);
       int rtVal = getRegValues(rt);
       int rdVal = rsVal & rtVal;
       saveRegValues(rdVal, rd);
       cout << "value of " << rdVal << " saved to register " << rd << endl;

   }else if(OperationR == "or"){
       //all registers
       //basically same as above
       alu_op[0] = 0;
        alu_op[1] = 0;
        alu_op[2] = 0;
        alu_op[3] = 1;
       int rsVal = getRegValues(rs);
       int rtVal = getRegValues(rt);
       int rdVal = rsVal | rtVal;
       saveRegValues(rdVal, rd);
       cout << "value of " << rdVal << " saved to register " << rd << endl;

   }else if(OperationR == "slt"){
       //all registers
       // 1 is true, 0 is false
       alu_op[0] = 0;
        alu_op[1] = 1;
        alu_op[2] = 1;
        alu_op[3] = 1;
       int rsVal = getRegValues(rs);
       int rtVal = getRegValues(rt);
       if(rsVal < rtVal){
           int rdVal = 1;
           saveRegValues(rdVal, rd);
           cout << "value of " << rdVal << " saved to register " << rd << endl;
       }else{
           int rdVal = 0;
           saveRegValues(rdVal, rd);
           cout << "value of " << rdVal << " saved to register " << rd << endl;
       }
       
   }else if(OperationR == "nor"){
       //all registers
       alu_op[0] = 1;
        alu_op[1] = 1;
        alu_op[2] = 0;
        alu_op[3] = 0;
        int rsVal = getRegValues(rs);
       int rtVal = getRegValues(rt);
       int rdVal = rsVal | rtVal;
       rdVal = ~rdVal;
       saveRegValues(rdVal, rd);
       cout << "value of " << rdVal << " saved to register " << rd << endl;
   }

   else if(OperationR == "jr"){
       //saveRegValues(pc+4,"ra");
       int Immediate = getRegValues("$ra");

        int jumpLocation = Immediate;
        jump_target = jumpLocation;
        pc = jumpLocation;
        cout << "pc location now same as jump target at: " << jumpLocation << endl;
   }
   return 0;
    
}

int ExecuteJ(string instructionJ, string OperationJ, string fullInstructionJ){
    //redefine Operation J, because it be dumb
    string operationtypeholder = "";
    int countJ = 0;
    //cout << fullInstructionJ[37];
    for(int i =0; i < 10; i = i){ //this will loop through until it finds the break and says thats the end of the instructions

        if(isalpha(fullInstructionJ[37+countJ])){
            operationtypeholder = operationtypeholder + fullInstructionJ[37+countJ];
        }else{
            break;
        }
        countJ = countJ + 1;
    }
    //cout << operationtypeholder;
    cout << "the operation is: "<< operationtypeholder << endl; 
    //OperationJ = operationtypeholder;
    //find rest of values for J===================================================
    int count = 43;
    int ImmediateNum = 0;
    string Immediatesearch = "";
    //cout << fullInstructionI[43] << fullInstructionI[44];
    
    for(int i = 0; i < 10; i=i){
        Immediatesearch = "";
        Immediatesearch = Immediatesearch + fullInstructionJ[count-1] + fullInstructionJ[count];
        if(Immediatesearch == "te"){
            ImmediateNum = count+3;
            break;
        }
        //cout << RSsearch << endl;
        count = count + 1;
    }
    //cout << "Is this where i am?" << fullInstructionI[rsNum-1] << fullInstructionI[rsNum] << endl; 
    //its bootiful! :)
    string Immediate = "";
    Immediate = Immediate + fullInstructionJ[ImmediateNum];
    for(int i = 0; i < 10; i = i){
        ImmediateNum = ImmediateNum + 1;
        if(isdigit(fullInstructionJ[ImmediateNum])){
            Immediate = Immediate + fullInstructionJ[ImmediateNum];
        }else{
            break;
        }
    }
    cout << "This is Immediate: " << Immediate << endl;
    //============================================================================
    
    if(operationtypeholder == "j"){
        //the immediate is the addresss
        int jumpLocation = stoi(Immediate);
        jump_target = jumpLocation;
        //pc = jumpLocation + 4;
        jumpLocation = jumpLocation * 4;
        jumpLocation = jumpLocation - 4;
        pc = jumpLocation + 4;
        cout << "pc location now same as jump target at: \n" << jumpLocation;
    }

    if(operationtypeholder == "jal"){
        saveRegValues(pc,"$ra"); //might need to add a +4 to the pc value, but i believe its correct as this starts on 4, and not 8 like it would if it starts on 0

        cout << "$ra is set to pc number: " << pc << endl;
        int jumpLocation = stoi(Immediate);
        int jumpBonus = jumpLocation % 4;
        jump_target = jumpLocation;
        //jumpLocation = jumpLocation + jumpBonus;
        jumpLocation = jumpLocation * 4;
        jumpLocation = jumpLocation - 4;
        pc = jumpLocation + 4;
        cout << "pc location now same as jump target at: " << jumpLocation << endl;
    }

    return 0;
}

int DecodeEnd(char shoopadoopa[500]){
    cout << "long shot here " << shoopadoopa;
    return 0;

}

int Mem(int memLocation){//fetch from memory
    return d_mem[memLocation];
}

int Writeback(int memLocation, int regVal){
    d_mem[memLocation] = regVal;
    return 0;
}


int getRegValues(string regRequester){
    int sendey;
    if(regRequester == "$zero" || regRequester == "$0"){
        sendey = registerfile[0];
    }else if(regRequester == "$at" || regRequester == "$1"){
        sendey = registerfile[1];
    }else if(regRequester == "$v0" || regRequester == "$2"){
        sendey = registerfile[2];
    }else if(regRequester == "$v1" || regRequester == "$3"){
        sendey = registerfile[3];
    }else if(regRequester == "$a0" || regRequester == "$4"){
        sendey = registerfile[4];
    }else if(regRequester == "$a1" || regRequester == "$5"){
        sendey = registerfile[5];
    }else if(regRequester == "$a2" || regRequester == "$6"){
        sendey = registerfile[6];
    }else if(regRequester == "$a3" || regRequester == "$7"){
        sendey = registerfile[7];
    }else if(regRequester == "$t0" || regRequester == "$8"){
        sendey = registerfile[8];
    }else if(regRequester == "$t1" || regRequester == "$9"){
        sendey = registerfile[9];
    }else if(regRequester == "$t2" || regRequester == "$10"){
        sendey = registerfile[10];
    }else if(regRequester == "$t3" || regRequester == "$11"){
        sendey = registerfile[11];
    }else if(regRequester == "$t4" || regRequester == "$12"){
        sendey = registerfile[12];
    }else if(regRequester == "$t5" || regRequester == "$13"){
        sendey = registerfile[13];
    }else if(regRequester == "$t6" || regRequester == "$14"){
        sendey = registerfile[14];
    }else if(regRequester == "$t7" || regRequester == "$15"){
        sendey = registerfile[15];
    }else if(regRequester == "$s0" || regRequester == "$16"){
        sendey = registerfile[16];
    }else if(regRequester == "$s1" || regRequester == "$17"){
        sendey = registerfile[17];
    }else if(regRequester == "$s2" || regRequester == "$18"){
        sendey = registerfile[18];
    }else if(regRequester == "$s3" || regRequester == "$19"){
        sendey = registerfile[19];
    }else if(regRequester == "$s4" || regRequester == "$20"){
        sendey = registerfile[20];
    }else if(regRequester == "$s5" || regRequester == "$21"){
        sendey = registerfile[21];
    }else if(regRequester == "$s6" || regRequester == "$22"){
        sendey = registerfile[22];
    }else if(regRequester == "$s7" || regRequester == "$23"){
        sendey = registerfile[23];
    }else if(regRequester == "$t8" || regRequester == "$24"){
        sendey = registerfile[24];
    }else if(regRequester == "$t9" || regRequester == "$25"){
        sendey = registerfile[25];
    }else if(regRequester == "$k0" || regRequester == "$26"){
        sendey = registerfile[26];
    }else if(regRequester == "$k1" || regRequester == "$27"){
        sendey = registerfile[27];
    }else if(regRequester == "$gp" || regRequester == "$28"){
        sendey = registerfile[28];
    }else if(regRequester == "$sp" || regRequester == "$29"){
        sendey = registerfile[29];
    }else if(regRequester == "$fp" || regRequester == "$30"){
        sendey =  registerfile[30];
    }else if(regRequester == "$ra" || regRequester == "$31"){
        sendey = registerfile[31];
    }
    return sendey;
}

int saveRegValues(int savingvale, string regRequester){
    if(regRequester == "$zero" || regRequester == "$0"){
        registerfile[0] = savingvale;
    }else if(regRequester == "$at" || regRequester == "$1"){
        registerfile[1] = savingvale;
    }else if(regRequester == "$v0" || regRequester == "$2"){
        registerfile[2] = savingvale;
    }else if(regRequester == "$v1" || regRequester == "$3"){
        registerfile[3] = savingvale;
    }else if(regRequester == "$a0" || regRequester == "$4"){
        registerfile[4] = savingvale;
    }else if(regRequester == "$a1" || regRequester == "$5"){
        registerfile[5] = savingvale;
    }else if(regRequester == "$a2" || regRequester == "$6"){
        registerfile[6] = savingvale;
    }else if(regRequester == "$a3" || regRequester == "$7"){
        registerfile[7] = savingvale;
    }else if(regRequester == "$t0" || regRequester == "$8"){
        registerfile[8] = savingvale;
    }else if(regRequester == "$t1" || regRequester == "$9"){
        registerfile[9] = savingvale;
    }else if(regRequester == "$t2" || regRequester == "$10"){
        registerfile[10] = savingvale;
    }else if(regRequester == "$t3" || regRequester == "$11"){
        registerfile[11] = savingvale;
    }else if(regRequester == "$t4" || regRequester == "$12"){
        registerfile[12] = savingvale;
    }else if(regRequester == "$t5" || regRequester == "$13"){
        registerfile[13] = savingvale;
    }else if(regRequester == "$t6" || regRequester == "$14"){
        registerfile[14] = savingvale;
    }else if(regRequester == "$t7" || regRequester == "$15"){
        registerfile[15] = savingvale;
    }else if(regRequester == "$s0" || regRequester == "$16"){
        registerfile[16] = savingvale;
    }else if(regRequester == "$s1" || regRequester == "$17"){
        registerfile[17] = savingvale;
    }else if(regRequester == "$s2" || regRequester == "$18"){
        registerfile[18] = savingvale;
    }else if(regRequester == "$s3" || regRequester == "$19"){
        registerfile[19] = savingvale;
    }else if(regRequester == "$s4" || regRequester == "$20"){
        registerfile[20] = savingvale;
    }else if(regRequester == "$s5" || regRequester == "$21"){
        registerfile[21] = savingvale;
    }else if(regRequester == "$s6" || regRequester == "$22"){
        registerfile[22] = savingvale;
    }else if(regRequester == "$s7" || regRequester == "$23"){
        registerfile[23] = savingvale;
    }else if(regRequester == "$t8" || regRequester == "$24"){
        registerfile[24] = savingvale;
    }else if(regRequester == "$t9" || regRequester == "$25"){
        registerfile[25] = savingvale;
    }else if(regRequester == "$k0" || regRequester == "$26"){
        registerfile[26] = savingvale;
    }else if(regRequester == "$k1" || regRequester == "$27"){
        registerfile[27] = savingvale;
    }else if(regRequester == "$gp" || regRequester == "$28"){
        registerfile[28] = savingvale;
    }else if(regRequester == "$sp" || regRequester == "$29"){
        registerfile[29] = savingvale;
    }else if(regRequester == "$fp" || regRequester == "$30"){
        registerfile[30] = savingvale;
    }else if(regRequester == "$ra" || regRequester == "$31"){
        registerfile[31] = savingvale;
    }else {
        cout << "oof, register miss \n";
    }
    return 0;
}

string Fetch(string fileuNameu){
    ifstream fileIn;
    string line;
    //string fileuNameu;
    //cout << "Please enter the file you would like to read: ";
    //cin >> fileuNameu;
    //cout << endl;
    //fileIn.open("sample_part1.txt");
    fileIn.open(fileuNameu);
    int breaker = 0;
    int limit = pc /4;
    string transfer;
    while(fileIn){
        getline(fileIn,line);
        //cout << line << endl;
        //transfer = stoi(line);
        if(breaker == limit){
            line.append("");
            //cout << line<<endl;
            //transfer = stoi(line);
            transfer = line;
            if(fileIn.peek() == EOF){
                dialga = 1;
            }
            break;
        }
        breaker = breaker + 1;
    }  
    fileIn.close();
    cout << transfer << endl;
   
    pc = pc + 4;
    nextpc = pc + 4;
    //cout << pc << endl;
    //cout << transfer << endl;
    return transfer;
}