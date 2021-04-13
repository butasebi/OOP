#include <iostream>
using namespace std;
// Clasa nod (pentru lista simplu inlantuita)
class Nod
{
    int info;
    Nod * next;
    static int ct;                //ct retine numarul total de noduri citite de program
public:
    friend istream & operator >>(istream & in, Nod & alfa);
    friend ostream & operator <<(ostream & out, const Nod & alfa);
    Nod & operator =(const Nod & alfa);
    Nod();
    Nod(int x);                     // primeste informatie
    Nod(int x, Nod & alfa);         // primeste informatie si nodul next
    Nod(const Nod & alfa);          // copy-constructor
    void set_info(int x);
    void set_next(Nod & node);
    void set_next(Nod* node);
    void increment();
    int get_info();
    Nod* get_next();
    static int get_ct();                         // metoda publica de obtinere a lui ct
    virtual ~Nod();
};

int Nod :: ct = 0;

istream & operator >>(istream & in, Nod & alfa)
{
    alfa.increment();
    cout << "Introduceti informatia nodului:";
    in >> alfa.info;
    return in;
}

ostream & operator <<(ostream & out, const Nod & alfa)
{
    out << "\n" << "Informatia din nod este:" << alfa.info << "\n";
    out << "Adresa urmatorului nod este:" << alfa.next << "\n";
    return out;
}

Nod & Nod :: operator =(const Nod & alfa)
{
    if(this != &alfa)
    {
        this -> info = 0;
        if(this -> next != NULL)this -> next = NULL;      //destructorul
        this -> info = alfa.info;
        this -> next = alfa.next;            //copy-constructorul
    }
    return *this;
}

Nod :: Nod()
{
    this -> info = 0;
    this -> next = NULL;
}

Nod :: Nod(int x)
{
    this -> info = x;
    this -> next = NULL;
}

Nod :: Nod(int x, Nod &alfa)
{
    this -> info = x;
    this -> next = &alfa;
}

Nod :: Nod(const Nod & alfa)
{
    this -> info = alfa.info;
    this -> next = alfa.next;
}

Nod :: ~Nod()
{
    this -> info = 0;
    if(this -> next != NULL)this -> next = NULL;
}

void Nod :: increment()
{
    ct ++;
}

int Nod :: get_ct()
{
    return ct;
}

int Nod :: get_info()
{
    return this -> info;
}

Nod* Nod :: get_next()
{
    return this -> next;
}

void Nod :: set_info(int x)
{
    this -> info = x;
}

void Nod :: set_next(Nod & node)
{
    this -> next = & node;
}

void Nod :: set_next(Nod* node)
{
    this -> next = node;
}

// Clasa nod dublu (pentru lista dublu inlantuita)
class Nod_dublu : public Nod
{
    Nod* ante;
public:
    friend istream & operator >>(istream & in, Nod_dublu & node);
    friend ostream & operator <<(ostream & out, const Nod_dublu & node);
    Nod_dublu & operator =(const Nod_dublu & node);
    Nod_dublu();
    Nod_dublu(int x);                         //constructor cu info
    Nod_dublu(int x, Nod & next);             //constructor cu info si nod next
    Nod_dublu(int x, Nod & next, Nod & ante); //constructor cu info, nod next si nod ante
    Nod_dublu(const Nod_dublu & alfa);        //copy-cosntructor
    void set_ante(Nod_dublu & node);
    void set_ante(Nod* node);
    void set_ante_null();
    Nod* get_ante();
    ~Nod_dublu();
};

istream & operator >>(istream & in, Nod_dublu & node)
{
    in >> (Nod&) node;
    return in;
}

ostream & operator <<(ostream & out, const Nod_dublu & node)
{
    out << (Nod&) node;
    out << "Adresa nodului anterior este:" << node.ante << "\n";
    return out;
}

Nod_dublu & Nod_dublu :: operator =(const Nod_dublu & node)
{
    if(this != &node)
    {
        Nod :: operator=(node);
        this -> ante = node.ante;
    }
    return *this;
}

Nod_dublu :: Nod_dublu() : Nod()
{
    this -> ante = NULL;
}

Nod_dublu :: Nod_dublu(int x) : Nod(x)
{
    this -> ante = NULL;
}

Nod_dublu :: Nod_dublu(int x, Nod & next) : Nod(x, next)
{
    this -> ante = NULL;
}

Nod_dublu :: Nod_dublu(int x, Nod & next, Nod & ante) : Nod(x, next)
{
    this -> ante = & ante;
}

Nod_dublu :: Nod_dublu(const Nod_dublu & alfa) : Nod(alfa)
{
    this -> ante = alfa.ante;
}

Nod_dublu :: ~Nod_dublu()
{
    if(this -> ante != NULL)this -> ante = NULL;
}

void Nod_dublu :: set_ante(Nod_dublu & node)
{
    this -> ante = & node;
}

void Nod_dublu :: set_ante(Nod * node)
{
    this -> ante = node;
}

void Nod_dublu :: set_ante_null()
{
    this -> ante = NULL;
}

Nod* Nod_dublu :: get_ante()
{
    return this -> ante;
}

//Clasa Lista Dublu Inlantuita (LDI), lista care contine noduri duble ale clasei Nod_dublu
class LDI
{
    Nod_dublu* Lista;    //lista propriu-zisa
    int n;               //lungimea listei
public:
    friend istream & operator >>(istream & in, LDI & Lista_dubla);
    friend ostream & operator <<(ostream & out, const LDI & Lista_dubla);
    virtual istream & VirtualRead(istream & in);
    virtual ostream & VirtualWrite(ostream & out)const;
    LDI & operator=(const LDI & Lista_dubla);
    LDI();                              //constructor simplu
    LDI(Nod_dublu & node);              //constructor de initializare cu un nod dublu (parametrizat)
    LDI(const LDI & Lista_dubla);       // copy-constructor
    int get_n() const;                  // fara const da eroare la operatorul << deoarece apeleaza const si nu este sigur
                                        //daca functia va incerca sau nu sa ii modifice valoarea constanta
    Nod_dublu & get_nod(int i) const;     //getter pe al i-lea nod din lista de noduri duble
    void LBBS();                    // Lower Bound Binary Search (pentru sortare)
    void swap_nodes(int a, int b);          // functie folosita pentru sortare
    virtual ~LDI();
};

istream & operator >>(istream & in, LDI & Lista_dubla)
{
    Lista_dubla.VirtualRead(in);
    return in;
}

istream & LDI :: VirtualRead(istream & in)
{
    cout << "Introduceti numarul de noduri din lista:";
    in >> this -> n;
    this -> Lista = new Nod_dublu[this -> n];              //alocam spatiu sa citim n elemente
    for(int i = 0; i < this -> n; i ++)
    {
        in >> this -> Lista[i];
        if(i != 0)this -> Lista[i].set_ante(this -> Lista[i - 1]);
        if(i != this -> n - 1)this -> Lista[i].set_next(this -> Lista[i + 1]);
    }
    return in;
}

ostream & operator <<(ostream & out, const LDI & Lista_dubla)
{
    Lista_dubla.VirtualWrite(out);
    return out;
}

ostream & LDI :: VirtualWrite(ostream & out)const
{
    out << "Lungimea listei este:" << this -> n << "\n";
    for(int i = 0; i < this -> n; i ++)
        out << this -> Lista[i];
    return out;
}

LDI & LDI :: operator=(const LDI & Lista_dubla)
{
    if(this != &Lista_dubla)
    {
        if(this -> Lista != NULL)delete [] this -> Lista;  //destructorul
        this -> n = Lista_dubla.n;
        this -> Lista = new Nod_dublu[this -> n];
        for(int i = 0; i < n; i ++)
            this -> Lista[i] = Lista_dubla.Lista[i];
    }
    return *this;
}

LDI :: LDI()
{
    this -> Lista = NULL;
    n = 0;
}

LDI :: LDI(Nod_dublu & node)
{
    this -> Lista = new Nod_dublu;
    this -> Lista[0] = node;
    n = 1;
}

LDI :: LDI(const LDI & Lista_dubla)
{
    this -> n = Lista_dubla.n;
    this -> Lista = new Nod_dublu[this -> n];
    for(int i = 0; i < n; i ++)
        this -> Lista[i] = Lista_dubla.Lista[i];
}

int LDI :: get_n() const
{
    return this -> n;
}

Nod_dublu & LDI :: get_nod(int i) const
{
    return this -> Lista[i];
}

void LDI :: swap_nodes(int a, int b)
{
    if(a > b)
    {
        int aux = a;
        a = b;
        b = aux;
    }
    Nod_dublu aux(this -> Lista[a]);
    this -> Lista[a] = this -> Lista[b];
    this -> Lista[b] = aux;
    for(int i = a - 1; i <= a + 1; i ++)
    {
        if(i < 0 || i >= this -> n)continue;
        if(i > 0)this -> Lista[i].set_ante(this -> Lista[i - 1]);          // restabilim legaturile intre nodurile a - 1 -> a -> a + 1
        if(i != this -> n - 1)this -> Lista[i].set_next(this -> Lista[i + 1]);
    }
    for(int i = b - 1; i <= b + 1; i ++)
    {
        if(i < 0 || i >= this -> n)continue;
        if(i > 0)this -> Lista[i].set_ante(this -> Lista[i - 1]);
        if(i != this -> n - 1)this -> Lista[i].set_next(this -> Lista[i + 1]);        // restabilim legaturile intre nodurile a - 1 -> a -> a + 1
        else this -> Lista[i].set_next(NULL);
    }
}

LDI :: ~LDI()
{
    if(this -> Lista != NULL)delete [] this -> Lista;
    n = 0;
}

//Clasa Lista Simplu Inlantuita (LSI), lista mostenita din LDI dar adaptata la o lista simplu inlantuita
class LSI : public LDI
{
public:
    virtual istream & VirtualRead(istream & in);
    virtual ostream & VirtualWrite(ostream & out)const;
    LSI & operator =(const LSI & Lista_mea);
    LSI() : LDI() {};
    LSI(const LSI & Lista_mea) : LDI(Lista_mea) {};
    LSI(Nod_dublu & node) : LDI(node){};
    ~LSI() {};
};
istream & LSI :: VirtualRead(istream & in)
{
    LDI :: VirtualRead(in);
    for(int i = 0; i < this -> get_n(); i ++)
       this -> get_nod(i).set_ante_null();
    return in;
}

ostream & LSI :: VirtualWrite(ostream & out)const
{
    out << "Lungimea listei este:" << this -> get_n() << "\n";
    for(int i = 0; i < this -> get_n(); i ++)
        out << (Nod&)this -> get_nod(i);
    return out;
}

LSI & LSI :: operator =(const LSI & Lista_mea)
{
    if(this != &Lista_mea)LDI :: operator=(Lista_mea);
    return *this;
}

void LDI :: LBBS()       //cautam cel mai mic numar mai mare decat lista_mea[poz] din intervalul [0, poz)
{
    for(int i = 0; i < this -> n; i ++)
    {
        //cautam cel mai mic numar mai mare decat lista_mea[i] din intervalul [0, i)
        int st, dr, poz;
        st = 0;
        dr = i - 1;
        poz = -1;          //pozitia din lista noastra a elementului cautat
        while(st <= dr)
        {
            int mij = (st + dr) / 2;
            if(this -> Lista[mij].get_info() > this -> Lista[i].get_info())
            {
                poz = mij;
                dr = mij - 1;
            }
            else st = mij + 1;
        }
        if(poz == -1)continue;
        this -> swap_nodes(i, poz);
        i --;
    }
}

int n, ct;
int main()
{
    bool ok = true;
    while(ok == true)
    {
        cout << "Introduceti 1 pentru a citi noduri simple (fara legatura intre ele)si a le afisa\n";
        cout << "Introduceti 2 pentru a citi noduri duble (fara legatura intre ele)si a le afisa\n";
        cout << "Introduceti 3 pentru a citi liste simplu inlantuite si a le afisa\n";
        cout << "Introduceti 4 pentru a citi liste dublu inlantuite si a le afisa\n";
        cout << "Introduceti 5 pentru a afisa numarul total de noduri create in aceasta rulare\n";
        cout << "Introduceti 6 pentru a crea, citi si afisa o lista cu noduri atat simple cat si duble(UpCasting)\n";
        cout << "Introduceti 7 pentru a crea, citi si afisa o lista cu noduri atat simple cat si duble(DownCasting)\n";
        cout << "Introduceti 8 pentru a introduce o lista dublu inlantuita si a o sorta\n";
        cout << "Introduceti 10 pentru a iesi \n";
        cin >> ct;
        switch(ct)
        {
            case 1:
                {
                    cout << "Introduceti numarul de noduri simple pe care vreti sa le creati:";
                    cin >> n;
                    cout << "\n";
                    Nod* lista_mea = new Nod[n];
                    for(int i = 0; i < n; i ++)
                        cin >> lista_mea[i];
                    for(int i = 0; i < n; i ++)
                        cout << lista_mea[i];
                    break;
                }
            case 2:
                {
                    cout << "Introduceti numarul de noduri duble pe care vreti sa le creati:";
                    cin >> n;
                    cout << "\n";
                    Nod_dublu* lista_mea = new Nod_dublu[n];
                    for(int i = 0; i < n; i ++)
                        cin >> lista_mea[i];
                    for(int i = 0; i < n; i ++)
                        cout << lista_mea[i];
                    break;
                }
            case 3:
                {
                    cout << "Introduceti numarul de liste simplu inlantuite pe care vreti sa le creati:";
                    cin >> n;
                    cout << "\n";
                    LSI* lista_mea = new LSI[n];
                    for(int i = 0; i < n; i ++)
                        cin >> lista_mea[i];
                    for(int i = 0; i < n; i ++)
                        cout << lista_mea[i] << "\n";         // new line in plus pentru lizibilitate
                    break;
                }
            case 4:
                {
                    cout << "Introduceti numarul de liste dublu inlantuite pe care vreti sa le creati:";
                    cin >> n;
                    cout << "\n";
                    LDI* lista_mea = new LDI[n];
                    for(int i = 0; i < n; i ++)
                        cin >> lista_mea[i];
                    for(int i = 0; i < n; i ++)
                        cout << lista_mea[i] << "\n";         // new line in plus pentru lizibilitate
                    break;
                }
            case 5:
                {
                    cout << "Numarul total de noduri create in aceasta rulare este de " << Nod::get_ct() << " noduri!\n";
                    break;
                }
            case 6:
                {
                    cout << "Introduceti numarul total de noduri din lista:";
                    cin >> n;
                    cout << "\n";
                    Nod* *lista_mea = new Nod*[n];
                    for(int i = 0; i < n; i ++)              //read
                    {
                        string tip_nod;
                        cout << "Ce fel de nod vreti sa adaugati?(Dublu/Simplu):";
                        cin >> tip_nod;
                        cout << "\n";
                        if(tip_nod == "Dublu")
                        {
                            lista_mea[i] = new Nod_dublu;  //UpCasting
                            cin >> *lista_mea[i];
                            if(i + 1 < n)lista_mea[i] -> set_next(*lista_mea[i + 1]);
                        }
                        else
                        {
                            lista_mea[i] = new Nod;
                            cin >> *lista_mea[i];
                            if(i + 1 < n)lista_mea[i] -> set_next(*lista_mea[i + 1]);
                        }
                    }
                    for(int i = 0; i < n; i ++)        //write
                        cout << *lista_mea[i] << "\n";
                }
            case 7:
                {
                    cout << "Introduceti numarul total de noduri din lista:";
                    cin >> n;
                    cout << "\n";
                    Nod_dublu* *lista_mea = new Nod_dublu*[n];
                    for(int i = 0; i < n; i ++)              //read
                    {
                        string tip_nod;
                        cout << "Ce fel de nod vreti sa adaugati?(Dublu/Simplu):";
                        cin >> tip_nod;
                        cout << "\n";
                        if(tip_nod == "Dublu")
                        {
                            lista_mea[i] = new Nod_dublu;
                            cin >> *lista_mea[i];
                            if(i + 1 < n)lista_mea[i] -> set_next(*lista_mea[i + 1]);
                            if(i > 0)lista_mea[i] -> set_ante(*lista_mea[i - 1]);
                        }
                        else
                        {
                            lista_mea[i] = static_cast<Nod_dublu*>(new Nod);     //DownCasting
                            cin >> (Nod&)*lista_mea[i];
                            if(i + 1 < n)lista_mea[i] -> set_next(*lista_mea[i + 1]);
                        }
                    }
                    for(int i = 0; i < n; i ++)        //write
                        if(typeid(*lista_mea[i]) == typeid(Nod_dublu))
                            cout << *lista_mea[i] << "\n"; //daca nodul nu e dublu nu are rost sa afiseze adresa nodului anterior
                        else cout << (Nod&) *lista_mea[i] << "\n";
                    break;
                }
            case 8:        //sortarea prin insertie
                {
                    LDI lista_mea;
                    cin >> lista_mea;
                    lista_mea.LBBS();      // Lower Bound Binary Search
                    cout << lista_mea;
                    break;
                }
            case 10:
                {
                    ok = false;
                    break;
                }
            default:
            {
                cout << "Comanda invalida, incercati iar!\n";
                break;
            }
        }
    }
    return 0;
}
