
#include <iostream>
#include <vector>
using namespace std;

class Instrument{
public:
    Instrument(){}
    virtual void makeSound() =0;
    virtual void playing() =0;
private:
    bool check;
};

void Instrument::makeSound(){cout << "To make a sound... ";}
// void Instrument::playing(){}

class Brass: public Instrument{
public:
    Brass(unsigned oneSize):size(oneSize), Instrument(){}
    virtual void makeSound(){
        Instrument::makeSound();
        cout << "blow on a mouthpiece of size " << size << endl;
    }
private:
    unsigned size = 0;
};

class Trumpet: public Brass{
public:
    Trumpet(unsigned oneSize): Brass(oneSize){}
    void playing(){
        cout << "Toot";
    }
};

class Trombone: public Brass{
public:
    Trombone(unsigned oneSize): Brass(oneSize){}
    void playing(){
        cout << "Blat";
    }
};

class StringIns: public Instrument{
public:
    StringIns(unsigned onePitch):pitch(onePitch), Instrument(){}
    virtual void makeSound(){
        Instrument::makeSound();
        cout << "bow a string with pitch " << pitch << endl;
    }
private:
    unsigned pitch;
};

class Violin: public StringIns{
public:
    Violin(unsigned onePitch):StringIns(onePitch){}
    void playing(){
        cout << "Screech";
    }
};

class Cello: public StringIns{
public:
    Cello(unsigned onePitch):StringIns(onePitch){}
    void playing(){
        cout << "Squawk";
    }
};

class Percussion: public Instrument{
public:
    Percussion(): Instrument(){}
    virtual void makeSound(){
        Instrument::makeSound();
        cout << "hit me!" <<endl;
    }
};

class Drum: public Percussion{
public:
    Drum(): Percussion(){}
    void playing(){
        cout << "Boom";
    }
};

class Cymbal: public Percussion{
public:
    Cymbal(): Percussion(){}
    void playing(){
        cout << "Crash";
    }
};


class Musician {
public:
    Musician() : instr(nullptr) {}

    void acceptInstr(Instrument* instPtr) { instr = instPtr; }

    Instrument* giveBackInstr() { 
        Instrument* result(instr); 
        instr = nullptr;
        return result;
    }

    void testPlay() const {
        if (instr) instr->makeSound(); 
        else cerr << "have no instr\n";
    }
    
    void play() const {
        if (instr) instr->playing();
        else cerr << "have no instr\n";
    }
    bool instrHave(){
        if(instr != nullptr){
            return true;
        }else{
            return false;
        }
    }

private:
    Instrument* instr;
};

class MILL{
public:
    MILL(){}
    void receiveInstr(Instrument& oneIns){
        ///size_t check = insList.size();
        for(size_t i = 0; i < insList.size();++i){
            if (insList[i] == nullptr){
                insList[i] = &oneIns;
                return;
            }
        }
        insList.push_back(&oneIns);
    }
    
    void dailyTestPlay(){
        for(size_t i =0; i < insList.size(); ++i){
            if( insList[i] != nullptr){
               insList[i] -> makeSound();
            }
        }
    }
    
    Instrument* loanOut(){
        Instrument* out = nullptr;
        for(size_t i =0; i < insList.size(); ++i){
            if( insList[i] != nullptr){
                out = insList[i];
                insList[i] = nullptr;
                break;
                ///return out;
            }
        }
        return out;
    }
private:
    vector<Instrument*> insList;
    
};

class Orch{
public:
    Orch(){}
    void addPlayer(Musician& oneMus){
        musicianList.push_back(&oneMus);
    }
    
    void play(){
        for(size_t i = 0; i < musicianList.size(); ++i){
            if (musicianList[i]->instrHave()){
                musicianList[i] -> play();
                cout << endl;
            }
            
        }
    }
    
private:
    vector<Musician*> musicianList;
    
};
// PART ONE
int main() {
//
//    cout << "Define some instruments ------------------------------------\n";
//    Drum drum;
//    Cello cello(673);
//    Cymbal cymbal;
//    Trombone tbone(4);
//    Trumpet trpt(12) ;
//    Violin violin(567) ;
//
//     // use the debugger to look at the mill
//     cout << "Define the MILL --------------------------------------------\n";
//     MILL mill;
//
//     cout << "Put the instruments into the MILL --------------------------\n";
//     mill.receiveInstr(trpt);
//     mill.receiveInstr(violin);
//     mill.receiveInstr(tbone);
//     mill.receiveInstr(drum);
//     mill.receiveInstr(cello);
//     mill.receiveInstr(cymbal);
//
//     cout << "Daily test -------------------------------------------------\n";
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//     cout << endl;
//
//     cout << "Define some Musicians---------------------------------------\n";
//     Musician harpo;
//     Musician groucho;
//
//     cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
//     groucho.testPlay();
//     cout << endl;
//     groucho.acceptInstr(mill.loanOut());
//     cout << endl;
//     groucho.testPlay();
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//
//     cout << endl << endl;
//
//    cout << "testing 3 ------------------------------" << endl;
//
//     groucho.testPlay();
//     cout << endl;
//     mill.receiveInstr(*groucho.giveBackInstr());
//     harpo.acceptInstr(mill.loanOut());
//     groucho.acceptInstr(mill.loanOut());
//     cout << endl;
//     groucho.testPlay();
//     cout << endl;
//     harpo.testPlay();
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//
//     cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";
//
//     // fifth
//     mill.receiveInstr(*groucho.giveBackInstr());
//     cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
//     mill.receiveInstr(*harpo.giveBackInstr());
//
//
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//     cout << endl;
//
//     cout << endl;
//
//    Instrument test;
//    test.makeSound();
    
    
    // The initialization phase
    
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12);
    Violin violin(567);
    
    MILL mill;
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);
    
    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;
    
    Orch orch;
    
    // THE SCENARIO
    
    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);
    
    //The orchestra performs
    cout << "orch performs\n";
    orch.play();
    
    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(mill.loanOut());
    orch.addPlayer(sue);
    
    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(mill.loanOut());
    
    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(mill.loanOut());
    orch.addPlayer(mary);
    
    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());
    
    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(mill.loanOut());
    orch.addPlayer(jody);
    
    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(mill.loanOut());
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    //Ralph joins the orchestra.
    orch.addPlayer(ralph);
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    // bob gets an instrument from the MIL2
    bob.acceptInstr(mill.loanOut());
    
    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(mill.loanOut());
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    //Morgan joins the orchestra.
    orch.addPlayer(morgan);
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
}
