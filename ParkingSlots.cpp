#include <iostream>

using namespace std;

class Parking
{
    size_t totalSpots;
    size_t takenSpots;

public:
    Parking(){
        totalSpots=0;
        takenSpots=0;
    }

    Parking(int totalSpots){
        this->totalSpots=totalSpots;
        takenSpots=0;
    }

    Parking(int totalSpots, int takenSpots){
        while(takenSpots>totalSpots){
            cout<< "GRESHKA: Ne moje da ima poveche zaeti mesta, ot kolkoto sa poprincip. Molq vuvedete stoinostite otnovo!"<< endl;
            cout<< "Vuvedi vsichki mesta: ";
            cin>> totalSpots;
            cout<< "Vuvedi zaetite mesta: ";
            cin>> takenSpots;
        }
        this->totalSpots=totalSpots;
        this->takenSpots=takenSpots;
    }

    void takeSpot(){
        if(totalSpots>takenSpots){
            takenSpots++;
        }
        else{
            cout<< "\n Nqma svobodni mesta"<< endl;
        }
    }
    
    void freeSpot(){
        if(takenSpots>0){
            takenSpots--;
        }
        else{
            cout<< "Nqma zaeti mesta"<< endl;
        }

    }
    
    int getTotalFreeSpots() const{
        return totalSpots-takenSpots;
    }
};

int main()
{
    size_t total;
    size_t taken;
    cout<< "Vuvedi vsichki mesta: ";
    cin>> total;
    cout<< "Vuvedi zaetite mesta: ";
    cin>> taken;
    Parking p(total, taken);
    cout<< "\n Svobodnite mesta sa: "<< p.getTotalFreeSpots();
    p.takeSpot();
    cout<< "\n Svobodnite mesta, sled kato si vzel edno mqsto: "<< p.getTotalFreeSpots() << endl;
    p.freeSpot();
    cout << "\n Svobodnite mesta, sled kato si osvobodil edno mqsto: "<< p.getTotalFreeSpots()<< endl;
    return 0;
}
