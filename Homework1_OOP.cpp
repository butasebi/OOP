#include <iostream>
#define minim_absolut -INT_MAX;
using namespace std;
class Vector
{
    int * v;            // vectorul dinamic
    int n;              //lungimea acestuia
public:
    Vector();                           //constructor de initializare
    Vector(int n, int x);               //constructor de initializare a unui vector de lungime n cu componentele avand valoarea x;
    Vector(const Vector & vec);         //copy constructor
    ~Vector();                          //destructorul
    Vector & operator =(const Vector & vec)
    {
        if(this != &vec)                            //verificam daca nu cumva incercam sa atribuim unui obiect acelasi
        {                                           //obiect deoarece o astfel de op ar produce erori
            if(this -> v != NULL)delete [] this -> v;           //destructorul
            this -> v = new int[vec.n];                         //copy-constructorul
            this -> n = vec.n;
            for(int i = 0; i < this -> n; i ++)
                this -> v[i] = vec.v[i];
        }
    }
    void set_vec(int n, int x);          //metoda publica de setare a numarului de componente a vectorului cu n si actualizarea acestora cu x
    int get_sum();                       //metoda publica de obtinere a sumei numerelor din vector
    void get_max();                      //metoda publica de obtinere a elementului maxim si pozitia sa din vector(considerand vector indexat de la 1)
    void do_sort();                      //metoda publica de sortare a vectorului

};
Vector::Vector()
{
    this -> n = 0;
}
Vector::Vector(int n, int x)
{
    this -> v = new int[n + 5];                    // aloc memorie cat sa incapa vectorul + 5 slot-uri suplimentare de siguranta
    this -> n = n;
    for(int i = 0; i < n; i ++)
        this -> v[i] = x;
}
Vector::Vector(const Vector & vec)
{
    this -> v = new int[vec.n + 5];
    this -> n = vec.n;                                           //folosesc this -> v si this -> n in aproape tot programul
    for(int i = 0; i < this -> n; i ++)                          //pentru lizibilitate
        this -> v[i] = vec.v[i];
}
Vector::~Vector()
{
    delete [] this -> v;
}
void Vector::set_vec(int n, int x)
{
    if(this -> v != NULL)delete[] this -> v;     //eliberam memoria deja alocata
    this -> v = new int[n + 5];
    this -> n = n;
    for(int i = 0; i < n; i ++)
        this -> v[i] = x;
    cout << "Vectorul a fost actualizat cu succes!\n";
}
int Vector::get_sum()
{
    //return this -> v[0] * this -> n;                 //caz particular cu toate elementele vectorului egale
    int sum = 0;
    for(int i = 0; i < this -> n; i ++)
        sum = sum + this -> v[i];
    return sum;
}
void Vector::get_max()
{
    //cout << "Elementul maxim este " << this -> v[0] << " si prima sa pozitie din vector este " << 1; //caz particular cu toate elementele vectorului egale
    int maxx = minim_absolut;
    int poz = -1;            // poz-ul are nevoie de actualizare deoarece exista cazul in care vectorul e gol
    for(int i = 0; i < this -> n; i ++)
        if(this -> v[i] > maxx)maxx = this -> v[i], poz = i + 1;
    if(poz == -1)            //poz = -1 inseamna vector gol, cum am zis si mai sus
    {
        cout << "Vectorul este gol!\n";
    }
    else                         // in caz contrar, avem vectorul si deci avem maxim si pozitie de afisat
    {
        cout << "Elementul maxim este " << maxx << " si prima pozitie din vector in care apare este " << poz << "\n";
    }
}
void Vector::do_sort()             //metoda Bubble-sort
{
    while(true)
    {
        bool changes_made = false;                 // ramane fals doar daca nu se fac schimbari, adica cand vectorul este sortat
        for(int i = 1; i < this -> n; i ++)
            if(v[i - 1] > v[i])                                    // n-am mai pus this -> pentru lizibilitate
            {
                int aux = v[i];
                v[i] = v[i - 1];                                //swap
                v[i - 1] = aux;
                changes_made = true;
            }
        if(changes_made == false)break;              //doar cand ramane fals iesim din bucla infinita
    }
    cout << "Vectorul a fost sortat!\n";
}
int n, x, op;
bool ok;
int main()
{
    cout << "Introduceti lungimea si valoarea tuturor elementelor vectorului(in aceasta ordine):";
    cin >> n >> x;
    Vector A(n, x);           // vom lucra asupra obiectului(vectorului) A
    //Vector B(n, x);
    //Vector A;                            // verificare supraincarcarea egalului si constructorului de initializare
    //A = B;
    cout << "\n";
    bool ok = true;
    while(ok)
    {
        cout << "\n" << "Introduceti 1 pentru a actualiza vectorul\n";         // un rand liber la inceput pentru aspect
        cout << "Introduceti 2 pentru a calcula suma elementelor vectorului\n";
        cout << "Introduceti 3 pentru a afla maximul si pozitia acestuia\n";
        cout << "Introduceti 4 pentru a sorta vectorul\n";
        cout << "Introduceti 10 pentru....STOP\n";
        cin >> op;             // operatia pe care o efectuam
        switch(op)
        {
        case 1:
            {
                cout << "Introduceti lungimea noua si valoarea tuturor elementelor vectorului(in aceasta ordine):";
                cin >> n >> x;
                A.set_vec(n, x);    // functia imi rezolva si afisarea asa ca nu mai este nevoie de inca un cout;
                break;
            }
        case 2:
            {
                cout << "Suma elementelor vectorului este " << A.get_sum() << "\n";
                break;
            }
        case 3:
            {
                A.get_max();
                break;
            }
        case 4:
            {
                A.do_sort();
                break;
            }
        case 10:
            ok = false;
            break;
        default:
            {
                cout << "Comanda este invalida, incercati din nou!\n";
                break;
            }
        }
        if(ok == false)break;
    }
    return 0;
}
