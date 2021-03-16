#include <iostream>
using namespace std;
const int minim_absolut = -INT_MAX;         //folosit in metoda get_max()
class Vector
{
    int * v;            // vectorul dinamic
    int n;              //lungimea acestuia
public:
    friend istream & operator >> (istream & in, Vector & vec);             //supraincarcarea operatorului >> (citire)
    friend ostream & operator << (ostream & out, const Vector & vec);      //supraincarcarea operatorului << (scriere)
    Vector();                           //constructor de initializare
    Vector(int n, int x);               //constructor de initializare a unui vector de lungime n cu componentele avand valoarea x;
    Vector(const Vector & vec);         //copy constructor
    Vector & operator =(const Vector & vec);    //supraincarcarea operatorului de atribuire
    void set_size(int n);                       //setter de marime
    void set_vector(int * vec, int n);
    int get_size();                             //getter de marime
    int * get_vector();                         //getter de valoare a elementelor vectorului
    void vec_actualizare(int n, int x);         //metoda publica de actualizare a numarului de componente a vectorului cu n si actualizarea acestora cu x
    int get_sum();                              //metoda publica de obtinere a sumei numerelor din vector
    void get_max();                             //metoda publica de obtinere a elementului maxim si pozitia sa din vector(considerand vector indexat de la 1)
    void do_sort();                             //metoda publica de sortare a vectorului
    ~Vector();                          //destructorul

};
//Supraincarcari operatori
istream & operator >> (istream & in, Vector & vec)
{
    cout << "\n" << "Lungimea vectorului:";
    in >> vec.n;
    cout << "\n" << "Introduceti cele " << vec.n << " elemente ale vectorului:";
    delete [] vec.v;              // eliberam memoria de siguranta
    vec.v = new int[vec.n + 5];     // aloc memorie cat sa incapa vectorul + 5 slot-uri suplimentare de siguranta
    for(int i = 0; i < vec.n; i ++)
        in >> vec.v[i];
    return in;
}
ostream & operator << (ostream & out, const Vector & vec)
{
    out << "\n" << "Lungimea vectorului: " << vec.n << "\n";
    out << "Elementele vectorului: ";
    for(int i = 0; i < vec.n; i ++)                  // citim vectorul
        out << vec.v[i] << " ";
    out << "\n";
    return out;
}
Vector & Vector :: operator =(const Vector & vec)
{
        if(this != &vec)                            //verificam daca nu cumva incercam sa atribuim unui obiect acelasi
        {                                           //obiect deoarece o astfel de operatie ar produce erori
            if(this -> v != NULL)delete [] this -> v;           //destructorul
            this -> v = new int[vec.n + 5];                         //copy-constructorul
            this -> n = vec.n;
            for(int i = 0; i < this -> n; i ++)
                this -> v[i] = vec.v[i];
        }
}
//Constructori
Vector::Vector()
{
    this -> v = NULL;
    this -> n = 0;
}
Vector::Vector(int n, int x)
{
    this -> v = new int[n + 5];
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
Vector::~Vector()                                      //destructorul
{
    delete [] this -> v;
}
//Metode publice
void Vector :: set_size(int n)
{
    this -> n = n;
    int valoare = this -> v[0];              //retinem valoarea elem vectorului inainte de stergere
    delete [] this -> v;
    this -> v = new int[n + 5];                          //resetam marimea vectorului
    for(int i = 0; i < this -> n; i ++)
        this -> v[i] = valoare;                            //reintroducem valorile corespunzatoare elementelor
}
void Vector :: set_vector(int * vec, int n)                  //primeste vectorul si marimea acestuia
{
    if(this -> v != NULL)delete [] this -> v;
    this -> n = n;
    for(int i = 0; i < this -> n; i ++)
        this -> v[i] = vec[i];
}
int Vector :: get_size()
{
    return this -> n;
}
int * Vector :: get_vector()
{
    return this -> v;
}
void Vector::vec_actualizare(int n, int x)
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
void read_and_write(int nr_obj)                     //metoda de citire, stocare si afisare a n vectori
{
    Vector * vec;
    vec = new Vector[nr_obj + 5];
    for(int i = 0; i < nr_obj; i ++)                      //citirea obiectelor si stocare lor in memorie
        cin >> vec[i];
    for(int i = 0 ; i < nr_obj; i ++)                     //afisarea obiectelor
        cout << vec[i];
    delete [] vec;                                        //eliberarea memoriei alocate obiectelor
}
int n, op, x;
bool ok;
int main()
{
    Vector A;
    //int * aux = A.get_vector();
    //for(int i = 0; i < A.get_size(); i ++)          //verificare getter vector
    //    cout << aux[i] << " ";

    //int * aux = new int[5];
    //aux[0] = 1;                                     //verificare setter vector
    //aux[1] = 2;
    //A.set_vector(aux, 2);
    //cout << A;
    bool ok = true;
    while(ok)
    {
        cout << "\n" << "Introduceti 1 pentru a actualiza sau initializa vectorul pe care o sa efectuam operatii\n";     // un rand liber la inceput pentru aspect
        cout << "Introduceti 2 pentru a calcula suma elementelor vectorului\n";
        cout << "Introduceti 3 pentru a afla maximul si pozitia acestuia\n";
        cout << "Introduceti 4 pentru a sorta vectorul\n";
        cout << "Introduceti 5 pentru a testa citirea, memorarea si afisarea a mai multi vectori\n";
        cout << "Introduceti 10 pentru....STOP\n";
        cin >> op;             // operatia pe care o efectuam
        switch(op)
        {
        case 1:
            {
                cout << "Introduceti lungimea si valoarea tuturor elementelor vectorului(in aceasta ordine):";
                cin >> n >> x;
                A.vec_actualizare(n, x);    // functia imi rezolva si afisarea asa ca nu mai este nevoie de inca un cout;
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
        case 4:                           //sortarea vectorului curent
            {
                A.do_sort();
                break;
            }
        case 5:                                     //citirea a n vectori, alocarea lor in memorie si afisarea lor!
            {
                cout << "Introduceti cati vectori vreti sa introduceti:";
                cin >> n;
                read_and_write(n);
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
