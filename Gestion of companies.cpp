#include <iostream>
#include <vector>
using namespace std;

// clasa Angajat liniile 7 - 199

class Angajat
{
    string nume;
    string prenume;
    int varsta;
    string data_ang;
    int salariu;
    bool is_manager; // un angajat este manager peste toti ceilalti din acelasi departament
    int id_ang;
    static int id;
public:
    //Constructori
    Angajat();
    Angajat(string nume, string prenume, int varsta, string data_ang, int salariu, bool is_manager, int id_ang);
    Angajat(const Angajat & alfa);

    //Operatori
    friend istream & operator >>(istream & in, Angajat & alfa);
    virtual istream & VirtualRead(istream & in);
    friend ostream & operator <<(ostream & out, const Angajat & alfa);
    virtual ostream & VirtualWrite(ostream & out) const;
    Angajat & operator =(const Angajat & alfa);
    bool operator ==(const Angajat & alfa);
    bool operator !=(const Angajat & alfa);

    //Metode publice
    void set_id_ang(int x);
    int get_id_ang();
    static int get_id();
    void id_increment();
    void increment();
    int get_salary();
    virtual ~Angajat();
};

int Angajat :: id = 1;       // setam valoarea static
Angajat* aux_angajat;       // pointer auxiliar folosit in program

//Constructori

Angajat :: Angajat()
{
    this -> nume = "";
    this -> prenume = "";
    this -> varsta = 0;
    this -> data_ang = "";
    this -> salariu = 0;
    this -> is_manager = false;
    this -> id_ang = 0;
}

Angajat :: Angajat(string nume, string prenume, int varsta, string data_ang, int salariu, bool is_manager, int id_ang)
{
    this -> nume = nume;
    this -> prenume = prenume;
    this -> varsta = varsta;
    this -> data_ang = data_ang;
    this -> salariu = salariu;
    this -> is_manager = is_manager;
    this -> id_ang = id_ang;
}

Angajat :: Angajat(const Angajat & alfa)
{
    this -> nume = alfa.nume;
    this -> prenume = alfa.prenume;
    this -> varsta = alfa.varsta;
    this -> data_ang = alfa.data_ang;
    this -> salariu = alfa.salariu;
    this -> is_manager = alfa.is_manager;
    this -> id_ang = alfa.id_ang;
}

Angajat :: ~Angajat()
{
    this -> nume = "";
    this -> prenume = "";
    this -> varsta = 0;
    this -> data_ang = "";
    this -> salariu = 0;
    this -> is_manager = false;
    this -> id_ang = 0;
}

// Operatori

istream & operator >>(istream & in, Angajat & alfa)
{
    alfa.VirtualRead(in);
    return in;
}

istream & Angajat :: VirtualRead(istream & in)
{
    cout << "Introduceti numele angajatului:";
    in >> this -> nume;
    cout << "\n";
    cout << "Introduceti prenumele angajatului:";
    in >> this -> prenume;
    cout << "\n";
    cout << "Introduceti varsta angajatului:";
    in >> this -> varsta;
    cout << "\n";
    cout << "Introduceti data angajarii:";
    in >> this -> data_ang;
    cout << "\n";
    cout << "Introduceti salariul angajatului:";
    in >> this -> salariu;
    cout << "\n";
    cout << "Este manager angajatul pe departamentul sau?(1 - DA, 0 - NU):";
    in >> this -> is_manager;
    cout << "\n";
    if(this -> id_ang == 0)
    {
        this -> id_ang = this -> get_id();
        this -> id_increment();
    }
    cout << "Id-ul angajatului este " << this -> id_ang << "\n";
    return in;
}

ostream & operator <<(ostream & out, const Angajat & alfa)
{
    alfa.VirtualWrite(out);
    return out;
}

ostream & Angajat :: VirtualWrite(ostream & out) const
{
    cout << "Numele angajatului este " << this -> nume << "\n";
    cout << "Prenumele angajatului este " << this -> prenume << "\n";
    cout << "Id-ul angajatului este " << this -> id_ang << "\n";
    cout << "Varsta angajatului este " << this -> varsta << "\n";
    cout << "Data angajarii angajatului este " << this -> data_ang << "\n";
    cout << "Salariul angajatului (brut) este " << this -> salariu << "\n";
    if(this -> is_manager == false)cout << "Salariatul nu este seful departamentului din care face parte" << "\n";
    else cout << "Salariatul este seful departamentului din care face parte";
    return out;
}

Angajat & Angajat :: operator =(const Angajat & alfa)
{
    if(this != &alfa)
    {
        this -> nume = alfa.nume;
        this -> prenume = alfa.prenume;
        this -> varsta = alfa.varsta;
        this -> data_ang = alfa.data_ang;
        this -> salariu = alfa.salariu;
        this -> is_manager = alfa.is_manager;
        this -> id_ang = alfa.id_ang;
    }
    return *this;
}

bool Angajat :: operator ==(const Angajat & alfa)
{
    if(this -> nume == alfa.nume && this -> prenume == alfa.prenume && this -> varsta == alfa.varsta && this -> data_ang == alfa.data_ang && this -> salariu == alfa.salariu && this -> is_manager == alfa.is_manager)return true;
    return false;
}

bool Angajat :: operator !=(const Angajat & alfa)
{
    if(this -> nume == alfa.nume && this -> prenume == alfa.prenume && this -> varsta == alfa.varsta && this -> data_ang == alfa.data_ang && this -> salariu == alfa.salariu && this -> is_manager == alfa.is_manager)return false;
    return true;
}

//Metode publice

void Angajat :: id_increment()
{
    this -> id = this -> id + 1;
}

int Angajat :: get_id()
{
    return id;
}

int Angajat :: get_id_ang()
{
    return this -> id_ang;
}

int Angajat :: get_salary()
{
    return this -> salariu;
}

void Angajat :: set_id_ang(int x)
{
    this -> id_ang = x;
}

// Clasa Departament liniile 203 - 424

class Departament
{
    string denumire;
    int nr_ang;
    vector <Angajat> Lista_ang;
    int id_dep;
    static int id;
    int chelt_salarii;
public:
    //Constructori
    Departament();
    Departament(const Departament & alfa);
    virtual ~Departament();

    //Operatori
    friend istream & operator >>(istream & in, Departament & alfa);
    virtual istream & VirtualRead(istream & in);
    friend ostream & operator <<(ostream & out, const Departament & alfa);
    virtual ostream & VirtualWrite(ostream & out) const;
    Departament & operator =(const Departament & alfa);
    bool operator ==(const Departament & alfa);
    bool operator !=(const Departament & alfa);

    //Metode publice
    static int get_id();
    void id_increment();
    void add_angajat(Angajat* & alfa);
    void remove_ang(int aidi, bool & found);
    int get_chelt_salarii();
    void set_chelt_salarii(int x);
    void set_id_dep(int x);
    int get_id_dep();
    int get_nr_ang();
    virtual void revizuire_dep();
};

int Departament :: id = 1;       // setam valoarea static
Departament* aux_departament;    // pointer auxiliar folosit in program

//Constructori

Departament :: Departament()
{
    this -> denumire = "";
    this -> nr_ang = 0;
    this -> chelt_salarii = 0;
    this -> id_dep = 0;
}

Departament :: Departament(const Departament & alfa)
{
    this -> denumire = alfa.denumire;
    this -> nr_ang = alfa.nr_ang;
    this -> chelt_salarii = alfa.chelt_salarii;
    for(int i = 0; i < alfa.nr_ang; i ++)
        this -> Lista_ang.push_back(alfa.Lista_ang[i]);
}

Departament :: ~Departament()
{
    this -> denumire = "";
    this -> nr_ang = 0;
    this -> chelt_salarii = 0;
    this -> id_dep = 0;
    while(!this -> Lista_ang.empty())
        this -> Lista_ang.pop_back();
}

//Operatori

istream & operator >>(istream & in, Departament & alfa)
{
    alfa.VirtualRead(in);
    return in;
}

istream & Departament :: VirtualRead(istream & in)
{
    if(this -> id_dep == 0)
    {
        this -> id_dep = this -> get_id();
        this -> id_increment();
    }
    cout << "Introduceti denumirea departamentului:";
    in >> this -> denumire;
    cout << "\n";
    cout << "Introduceti numarul de angajati:";
    in >> this -> nr_ang;
    cout << "\n";
    for(int i = 0; i < this -> nr_ang; i ++)
    {
        Angajat aux;
        aux.set_id_ang(this -> id_dep * 100 + i + 1); // primele 2 cifre repr id_dep iar ultimele 2 repr id_ang
        in >> aux;                                    //ex: angajatul cu id 1412 face parte din departamentul cu id 14 si are id ul de angajat 12
        this -> Lista_ang.push_back(aux);
        this -> chelt_salarii = this -> chelt_salarii + aux.get_salary();
    }
    cout << "\n";
    cout << "Id-ul departamentului introdus este " << this -> id_dep << "\n"; // trebuie ca HRManager sa stie id-urile pentru a sterge ang dupa ele
    return in;
}

ostream & operator <<(ostream & out, const Departament & alfa)
{
    alfa.VirtualWrite(out);
    return out;
}

ostream & Departament :: VirtualWrite(ostream & out) const
{
    out << "Denumirea departamentului este " << this -> denumire << "\n";
    out << "ID - ul departamentului este " << this -> id_dep << "\n";
    out << "Numarul angajatilor departamentului este " << this -> nr_ang << " iar acestia sunt:" << "\n";
    for(int i = 0; i < this -> nr_ang; i ++)
    {
        out << this -> Lista_ang[i];
        if(i != this -> nr_ang - 1)out << "\n";
    }
    return out;
}

Departament & Departament :: operator =(const Departament & alfa)
{
    if(this != &alfa)
    {
        while(!this -> Lista_ang.empty())this -> Lista_ang.pop_back();
        this -> denumire = alfa.denumire;
        this -> nr_ang = alfa.nr_ang;
        this -> chelt_salarii = 0;
        for(int i = 0; i < alfa.nr_ang; i ++)
            this -> Lista_ang.push_back(alfa.Lista_ang[i]);
    }
    return *this;
}

bool Departament :: operator ==(const Departament & alfa)
{
    if(alfa.nr_ang == this -> nr_ang && alfa.denumire == this -> denumire)
    {
        for(int i = 0; i < this -> nr_ang; i ++)
            if(this -> Lista_ang[i] != alfa.Lista_ang[i])return false;
        return true;
    }
    return false;
}

bool Departament :: operator !=(const Departament & alfa)
{
    if(alfa.nr_ang == this -> nr_ang && alfa.denumire == this -> denumire)
    {
        for(int i = 0; i < this -> nr_ang; i ++)
            if(this -> Lista_ang[i] != alfa.Lista_ang[i])return true;
        return false;
    }
    return true;
}

//Metode publice

void Departament :: remove_ang(int aidi, bool & found)
{
    for(auto it = this -> Lista_ang.begin(); it < this -> Lista_ang.end(); it ++)
        if(it -> get_id_ang() == aidi)
        {
            this -> Lista_ang.erase(it);
            found = true;
            this -> nr_ang --;
            break;
        }
}

void Departament :: add_angajat(Angajat* & alfa)
{
    this -> nr_ang ++;
    alfa -> set_id_ang(this -> id_dep * 100 + this -> nr_ang);
    this -> Lista_ang.push_back(*alfa);
}

int Departament :: get_chelt_salarii()
{
    return this -> chelt_salarii;
}

void Departament :: set_chelt_salarii(int x)
{
    this -> chelt_salarii = x;
}

void Departament :: set_id_dep(int x)
{
    this -> id_dep = x;
}

int Departament :: get_id_dep()
{
    return this -> id_dep;
}

int Departament :: get_nr_ang()
{
    return this -> nr_ang;
}

void Departament :: revizuire_dep()
{
    this -> chelt_salarii = 0;
    for(int i = 0; i < this -> nr_ang; i ++)
    {
        this -> Lista_ang[i].set_id_ang(this -> id_dep * 100 + i + 1);
        this -> chelt_salarii = this -> chelt_salarii + this -> Lista_ang[i].get_salary();
    }
}

int Departament :: get_id()
{
    return id;
}

void Departament :: id_increment()
{
    id ++;
}

// Clasa Departament_fara_imp (fara impozit) care mosteneste clasa Departament liniile 428 - 497

class Departament_fara_imp : public Departament
{
    int impozit_red;    // cat % din impozit e redus
public:
    //Constructori
    Departament_fara_imp();
    Departament_fara_imp(const Departament_fara_imp & alfa);
    virtual ~Departament_fara_imp();

    //Operatori
    virtual istream & VirtualRead(istream & in);
    virtual ostream & VirtualWrite(ostream & out);
    Departament_fara_imp & operator =(const Departament_fara_imp & alfa);

    //Metode publice
    void revizuire_dep();
};

//Constructori

Departament_fara_imp ::Departament_fara_imp() : Departament()
{
    this -> impozit_red = 0;
}

Departament_fara_imp :: Departament_fara_imp(const Departament_fara_imp & alfa) : Departament(alfa)
{
    this -> impozit_red = alfa.impozit_red;
}

Departament_fara_imp :: ~Departament_fara_imp()
{
    this -> impozit_red = 0;
}

//Operatori

Departament_fara_imp & Departament_fara_imp :: operator =(const Departament_fara_imp & alfa)
{
    if(this != &alfa)
    {
        Departament :: operator=(alfa);
        this -> impozit_red = alfa.impozit_red;
    }
    return *this;
}

istream & Departament_fara_imp :: VirtualRead(istream & in)
{
    Departament :: VirtualRead(in);
    cout << "Introduceti cate procente din impozit are reduse departamentul:";
    in >> this -> impozit_red;
    this -> set_chelt_salarii((this -> get_chelt_salarii() * (100 - this -> impozit_red)) / 100);
    return in;
}
ostream & Departament_fara_imp :: VirtualWrite(ostream & out)
{
    Departament :: VirtualWrite(out);
    out << "\n";
    out << "Departamentul are " << this -> impozit_red << "% din impozit redus!";
    return out;
}

// Metode publice

void Departament_fara_imp :: revizuire_dep()
{
    Departament :: revizuire_dep();
    this -> set_chelt_salarii((this -> get_chelt_salarii() * (100 - this -> impozit_red)) / 100);
}

// Clasa Companie liniile 501 - 805

class Companie
{
    string denumire;
    int nr_dep;
    vector <Departament*> Lista_dep;
    int id_comp;
    static int id;
    int chelt_salarii_comp;
public:
    //Constructori
    Companie();
    Companie(const Companie & alfa);
    virtual ~Companie();

    //Operatori
    friend istream & operator >>(istream & in, Companie & alfa);
    friend ostream & operator <<(ostream & out, const Companie & alfa);
    virtual istream & VirtualRead(istream & in);
    virtual ostream & VirtualWrite(ostream & out) const;
    bool operator ==(const Companie & alfa);
    bool operator !=(const Companie & alfa);
    Companie & operator =(const Companie & alfa);
    Companie operator +(const Companie & alfa);

    //Metode publice
    int get_id_comp();
    static int get_id();
    void increment_id();
    int nr_ang_dep(int aidi);
    int get_nr_ang();
    void add_departament(Departament* & alfa);
    void add_angajat(Angajat* & alfa, int aidi, bool & found);
    int get_total_cost();
    void set_total_cost(int x);
    void set_id_comp(int x);
    void remove_dep(int aidi, bool & found);
    void remove_ang(int aidi, bool & found);
    void search_min_n(int n, bool & found);
    void revizuire_comp();
};

Companie* aux_companie;     //pointer auxiliar folosit in program
int Companie :: id = 1;     //initializare static

//Constructori

Companie :: Companie()
{
    this -> denumire = "";
    this -> nr_dep = 0;
    this -> chelt_salarii_comp = 0;
}

Companie :: Companie(const Companie & alfa)
{
    this -> denumire = alfa.denumire;
    this -> id_comp = alfa.id_comp;
    this -> nr_dep = alfa.nr_dep;
    for(int i = 0; i < this -> nr_dep; i ++)
        this -> Lista_dep.push_back(alfa.Lista_dep[i]);
    this -> chelt_salarii_comp = alfa.chelt_salarii_comp;
}

Companie :: ~Companie()
{
    this -> denumire = "";
    while(this -> nr_dep > 0)
    {
        this -> Lista_dep.pop_back();
        this -> nr_dep = this -> nr_dep - 1;
    }
    this -> id_comp = 0;
    this -> chelt_salarii_comp = 0;
}

//Operatori

istream & operator >>(istream & in, Companie & alfa)
{
    alfa.VirtualRead(in);
    return in;
}

istream & Companie :: VirtualRead(istream & in)
{
    this -> id_comp = this -> get_id();
    this -> increment_id();
    cout << "Introduceti denumirea companiei:";
    in >> this -> denumire;
    cout << "\n";
    cout << "Introduceti numarul de departamente din subordinea companiei:";
    in >> this -> nr_dep;
    cout << "\n";
    for(int i = 0; i < this -> nr_dep; i ++)
    {
        Departament* aux;
        string aux1;
        cout << "Departamentul pe care il introduceti este scutit de impozit(DA, NU)?:";
        in >> aux1;
        if(aux1 == "DA")
        {
            aux = new Departament_fara_imp();
            aux -> set_id_dep(this -> id_comp * 100 + i + 1);
            in >> *aux;
        }
        else
        {
            aux = new Departament();
            aux -> set_id_dep(this -> id_comp * 100 + i + 1);
            in >> *aux;
        }
        this -> Lista_dep.push_back(aux);
        this -> chelt_salarii_comp = this -> chelt_salarii_comp + aux -> get_chelt_salarii();
    }
    cout << "\n";
    cout << "Id-ul companiei citite este " << this -> id_comp << "\n"; // trebuie ca HRManager sa stie id-urile pentru a sterge ang dupa ele
    return in;
}

ostream & operator <<(ostream & out, const Companie & alfa)
{
    alfa.VirtualWrite(out);
    return out;
}

ostream & Companie :: VirtualWrite(ostream & out) const
{
    out << "Denumirea companiei este " << this -> denumire << "\n";
    out << "ID -ul companiei este " << this -> id_comp << "\n";
    out << "Costul total al salariilor (dupa scutirea de impozit daca e cazul) este " << this -> chelt_salarii_comp << "\n";
    out << "Compania detine " << this -> nr_dep << " departamente\n";
    for(int i = 0; i < this -> nr_dep; i ++)
    {
        out << *this -> Lista_dep[i];
        if(i != this -> nr_dep - 1)out << "\n";
    }
    return out;
}

bool Companie :: operator ==(const Companie & alfa)
{
    if(this -> denumire == alfa.denumire && this -> nr_dep == alfa.nr_dep && this -> chelt_salarii_comp == alfa.chelt_salarii_comp)
    {
        for(int i = 0; i < this -> nr_dep; i ++)
            if(this -> Lista_dep[i] != alfa.Lista_dep[i])return false;
        return true;
    }
    return false;
}

bool Companie :: operator !=(const Companie & alfa)
{
    if(this -> denumire == alfa.denumire && this -> nr_dep == alfa.nr_dep && this -> chelt_salarii_comp == alfa.chelt_salarii_comp)
    {
        for(int i = 0; i < this -> nr_dep; i ++)
            if(this -> Lista_dep[i] != alfa.Lista_dep[i])return true;
        return false;
    }
    return true;
}

Companie & Companie :: operator =(const Companie & alfa)
{
    if(this != & alfa)
    {
        while(this -> nr_dep > 0)
        {
            this -> Lista_dep.pop_back();
            this -> nr_dep = this -> nr_dep - 1;
        }
        this -> denumire = alfa.denumire;
        this -> id_comp = alfa.id_comp;
        this -> nr_dep = alfa.nr_dep;
        for(int i = 0; i < this -> nr_dep; i ++)
            this -> Lista_dep.push_back(alfa.Lista_dep[i]);
        this -> chelt_salarii_comp = alfa.chelt_salarii_comp;
    }
    return *this;
}

Companie Companie :: operator +(const Companie & alfa)
{
        Companie aux;
        aux.denumire = this -> denumire + "_" + alfa.denumire;
        aux.nr_dep = this -> nr_dep + alfa.nr_dep;
        for(int i = 0; i < this -> nr_dep; i ++)
            aux.Lista_dep.push_back(this -> Lista_dep[i]);
        for(int i = 0; i < alfa.nr_dep; i ++)
            aux.Lista_dep.push_back(alfa.Lista_dep[i]);
        aux.chelt_salarii_comp = this -> chelt_salarii_comp + alfa.chelt_salarii_comp;
        aux.id_comp = this -> id_comp;
        return aux;
}

//Metode publice

int Companie :: get_id_comp()
{
    return this -> id_comp;
}

int Companie :: get_id()
{
    return id;
}

void Companie :: increment_id()
{
        id = id + 1;
}

void  Companie :: search_min_n(int n, bool & found)
{
    for(int i = 0; i < this -> nr_dep; i ++)
        if(this -> Lista_dep[i] -> get_nr_ang() >= n)
        {
            found = true;
            cout << *this -> Lista_dep[i] << "\n";
        }
}

void Companie :: remove_ang(int aidi, bool & found)
{
    for(int i = 0; i < this -> nr_dep; i ++)
        if(this -> Lista_dep[i] -> get_id_dep() == aidi / 100)
        {
            this -> Lista_dep[i] -> remove_ang(aidi, found);
            if(found == true)this -> Lista_dep[i] -> revizuire_dep();
            break;
        }
}

void Companie :: remove_dep(int aidi, bool & found)
{
    for(auto it = this -> Lista_dep.begin(); it < this -> Lista_dep.end(); it ++)
    {
        Departament* aux = *it;
        if(aux -> get_id_dep() == aidi)
        {
            this -> Lista_dep.erase(it);
            this -> nr_dep --;
            found = true;
            break;
        }
    }
}

int Companie :: get_nr_ang()
{
    int aux = 0;
    for(int i = 0; i < this -> nr_dep; i ++)
        aux = aux + this -> Lista_dep[i] -> get_nr_ang();
    return aux;
}

int Companie :: nr_ang_dep(int aidi)
{
    for(int i = 0; i < this -> nr_dep; i ++)
        if(this -> Lista_dep[i] -> get_id_dep() == aidi)
            return this -> Lista_dep[i] -> get_nr_ang();
    return -1;
}

void Companie :: revizuire_comp()
{
    this -> chelt_salarii_comp = 0;
    for(int i = 0; i < this -> nr_dep; i ++)
    {
        this -> Lista_dep[i] -> set_id_dep(this -> id_comp * 100 + i + 1);
        this -> Lista_dep[i] -> revizuire_dep();
        this -> chelt_salarii_comp = this -> chelt_salarii_comp + this -> Lista_dep[i] -> get_chelt_salarii();
    }
}

int Companie ::  get_total_cost()
{
    return this -> chelt_salarii_comp;
}

void Companie :: set_id_comp(int x)
{
    this -> id_comp = x;
}

void Companie :: set_total_cost(int x)
{
    this -> chelt_salarii_comp = x;
}

void Companie :: add_departament(Departament* & alfa)
{
    this -> nr_dep ++;
    this -> Lista_dep.push_back(alfa);
}

void  Companie :: add_angajat(Angajat* & alfa, int aidi, bool & found)
{
    for(int i = 0; i < this -> nr_dep; i ++)
        if(this -> Lista_dep[i] -> get_id_dep() == aidi)
        {
            found = true;
            this -> Lista_dep[i] -> add_angajat(alfa);
            this -> Lista_dep[i] -> revizuire_dep();
        }
}

// Clasa HRManager liniile 809 - 1101

class HRManager
{
    string nume;
    string prenume;
    int varsta;
    int nr_comp;
    vector <Companie> ListaComp;
public:
    //Constructori
    HRManager();
    HRManager(const HRManager & alfa);
    HRManager(string nume, string prenume, int varsta);
    virtual ~HRManager();

    //Operatori
    friend istream & operator >>(istream & in, HRManager & alfa);
    friend ostream & operator <<(ostream & out, const HRManager & alfa);
    virtual istream & VirtualRead(istream & in);
    virtual ostream & VirtualWrite(ostream & out) const;
    HRManager & operator =(const HRManager & alfa);

    //Metode publice
    void add_companie(Companie* & alfa);
    void add_departament(Departament* & alfa, int aidi);
    void add_angajat(Angajat* & alfa, int aidi);
    void fuse(int aidi1, int aidi2);
    int nr_ang_dep(int aidi);
    int nr_ang_comp(int aidi);
    int nr_ang();
    void remove_comp(int aidi, bool & found);
    void remove_dep(int aidi, bool & found);
    void remove_ang(int aidi, bool & found);
    void search_min_n(int n, bool & found);
};

// Constructori

HRManager :: HRManager()
{
    this -> nume = "";
    this -> prenume = "";
    this -> varsta = 0;
    this -> nr_comp = 0;
}

HRManager :: HRManager(const HRManager & alfa)
{
    this -> nume = alfa.nume;
    this -> prenume = alfa.prenume;
    this -> varsta = alfa.varsta;
    this -> nr_comp = alfa.nr_comp;
    for(int i = 1; i <= this -> nr_comp; i ++)
        this -> ListaComp.push_back(alfa.ListaComp[i]);
}

HRManager :: HRManager(string nume, string prenume, int varsta)
{
    this -> nume = nume;
    this -> prenume = prenume;
    this -> varsta = varsta;
}

HRManager :: ~HRManager()
{
    this -> nume = "";
    this -> prenume = "";
    this -> varsta = 0;
    this -> nr_comp = 0;
    while(!this -> ListaComp.empty())
        this -> ListaComp.pop_back();
}

//Operatori

istream & operator >>(istream & in, HRManager & alfa)
{
    alfa.VirtualRead(in);
    return in;
}

istream & HRManager :: VirtualRead(istream & in)
{
    cout << "Introduceti numele managerului:";
    in >> this -> nume;
    cout << "\n";
    cout << "Introduceti prenumele managerului:";
    in >> this -> prenume;
    cout << "\n";
    cout << "Introduceti varsta managerului:";
    in >> this -> varsta;
    cout << "\n";
    cout << "Introduceti numarul de companii pe care le are managerul:";
    in >> this -> nr_comp;
    for(int i = 1; i <= this -> nr_comp; i ++)
    {
        cout << "\n";
        Companie aux1;
        in >> aux1;
        this -> ListaComp.push_back(aux1);
    }
    return in;
}

ostream & operator <<(ostream & out, const HRManager & alfa)
{
    alfa.VirtualWrite(out);
    return out;
}

ostream & HRManager :: VirtualWrite(ostream & out) const
{
    out << "Numele HRManagerului este: " << this -> nume << "\n";
    out << "Prenumele HRManagerului este: " << this -> prenume << "\n";
    out << "Varsta HRManagerului este: " << this -> varsta << "\n";
    out << "Acest manager detine " << this -> nr_comp << " companii si acestea sunt:\n";
    for(int i = 0; i < this -> nr_comp; i ++)
    {
        out << this -> ListaComp[i];
        if(i != this -> nr_comp - 1)out << "\n";
    }
    return out;
}

HRManager & HRManager :: operator =(const HRManager & alfa)
{
    if(this != &alfa)
    {
        this -> nume = "";
        this -> prenume = "";
        this -> varsta = 0;         //destructor
        this -> nr_comp = 0;
        while(!this -> ListaComp.empty())
            this -> ListaComp.pop_back();

        this -> nume = alfa.nume;
        this -> prenume = alfa.prenume;
        this -> varsta = alfa.varsta;        //copy-constructor
        this -> nr_comp = alfa.nr_comp;
        for(int i = 1; i <= this -> nr_comp; i ++)
            this -> ListaComp.push_back(alfa.ListaComp[i]);
    }
    return *this;
}
// Metode publice

void HRManager :: search_min_n(int n, bool & found)
{
    for(int i = 0; i < this -> nr_comp; i ++)
        this -> ListaComp[i].search_min_n(n, found);
}

void HRManager :: remove_ang(int aidi, bool & found)
{
    for(int i = 0; i < this -> nr_comp; i ++)
        if(this -> ListaComp[i].get_id_comp() == aidi / 10000)
        {
            this -> ListaComp[i].remove_ang(aidi, found);
            if(found == true)this -> ListaComp[i].revizuire_comp();
            break;
        }
}

void HRManager :: remove_dep(int aidi, bool & found)
{
    for(int i = 0; i < this -> nr_comp; i ++)
        if(this -> ListaComp[i].get_id_comp() == aidi / 100)
        {
            this -> ListaComp[i].remove_dep(aidi, found);
            if(found == true)this -> ListaComp[i].revizuire_comp();
            break;
        }
}

void HRManager :: remove_comp(int aidi, bool & found)
{
    for(auto it = this -> ListaComp.begin(); it < this -> ListaComp.end(); it ++)
        if(it -> get_id_comp() == aidi)
        {
            this -> ListaComp.erase(it);
            this -> nr_comp --;
            found = true;
            break;
        }
    for(int i = 0; i < this -> nr_comp; i ++)
    {
        this -> ListaComp[i].set_id_comp(i + 1);
        this -> ListaComp[i].revizuire_comp();
    }
}

int HRManager :: nr_ang()
{
    int aux;
    for(int i = 0; i < this -> nr_comp; i ++)
    {
        int aux1 = this -> nr_ang_comp(i + 1);
        if(aux1 != -1)aux = aux + aux1;
    }
    return aux;
}

int HRManager :: nr_ang_dep(int aidi)
{
    for(int i = 0; i < this -> nr_comp; i ++)
        if(this -> ListaComp[i].get_id_comp() == aidi / 100)
            return this -> ListaComp[i].nr_ang_dep(aidi);
    return -1;
}

int HRManager :: nr_ang_comp(int aidi)
{
    for(int i = 0; i < this -> nr_comp; i ++)
        if(this -> ListaComp[i].get_id_comp() == aidi)
            return this -> ListaComp[i].get_nr_ang();
    return -1;
}

void HRManager :: add_companie(Companie* & alfa)
{
    try
    {
        for(int i = 0; i < this -> nr_comp; i ++)
        if(*alfa == this -> ListaComp[i])throw(this -> ListaComp[i].get_id_comp());
        this -> nr_comp ++;
        this -> ListaComp.push_back(*alfa);
        cout << "Companie adaugata cu succes!\n";
    }
    catch (int aidi)
    {
        cout << "Compania nu a fost adaugata: compania exista deja si are ID-ul " << aidi << "\n";
    }
}

void HRManager :: add_departament(Departament* & alfa, int aidi)
{
    bool found = false;
    for(int i = 0; i < this -> nr_comp; i ++)
        if(this -> ListaComp[i].get_id_comp() == aidi)
        {
            found = true;
            //alfa -> set_id_dep(this -> ListaComp[i].get_id_comp() * 100 + alfa -> get_id_dep());
            this -> ListaComp[i].add_departament(alfa);
            this -> ListaComp[i].revizuire_comp();
            //this -> ListaComp[i].set_total_cost(this -> ListaComp[i].get_total_cost() + alfa -> get_chelt_salarii());
            break;
        }
    if(found == false)cout << "Nu exista compania cu ID-ul " << aidi << "\n";
    else cout << "Departament adaugat cu succes!\n";
}

void HRManager :: add_angajat(Angajat* & alfa, int aidi)
{
    bool found = false;
    for(int i = 0; i < this -> nr_comp; i ++)
        if(this -> ListaComp[i].get_id_comp() == aidi / 100) //daca cifra coresp companiei e aceeasi
        {
            this -> ListaComp[i].add_angajat(alfa, aidi, found);
            this -> ListaComp[i].revizuire_comp();
            break;
        }
    if(found == false)cout << "Nu exista angajatul cu ID-ul " << aidi << "\n";
    else cout << "Angajat adaugat cu succes!\n";
}

void HRManager :: fuse(int aidi1, int aidi2)
{
    int found1, found2;
    found1 = -1;
    found2 = -1;
    for(int i = 0; i < this -> nr_comp; i ++)
    {
        if(this -> ListaComp[i].get_id_comp() == aidi1)
        {
            found1 = i;
        }
        if(this -> ListaComp[i].get_id_comp() == aidi2)
        {
            found2 = i;
        }
    }
    if(found1 != -1 && found2 != -1)
    {
        this -> ListaComp[found1] = this -> ListaComp[found1] + this -> ListaComp[found2];
        while(found2 < this -> nr_comp - 1)
        {
            this -> ListaComp[found2] = this -> ListaComp[found2 + 1];
            found2 ++;
        }
        this -> nr_comp --;
        this -> ListaComp.pop_back();
    }
    else cout << "Cel putin unul dintre ID - uri este invalid!\n";
}

// Clasa Singleton pentru main() liniile 1105 - 1285

class Singleton
{
    static Singleton * obiect;
    Singleton(){};
public:
    static Singleton * get_instance()
    {
        if(obiect == 0)
        {
            obiect = new Singleton();
        }
        return obiect;
    }
    void solve()
    {
        HRManager a;
        bool ok = true;
        while(ok)
        {
            cout << "Introduceti 1 pentru a citi configuratia initiala\n";
            cout << "Introduceti 2 pentru a afisa configuratia actuala\n";
            cout << "Introduceti 3 pentru a adauga o companie\n";
            cout << "Introduceti 4 pentru a adauga un departament unei companii\n";
            cout << "Introduceti 5 pentru a adauga un angajat unui departament al unei companii\n";
            cout << "Introduceti 6 pentru a fuziona doua companii\n";
            cout << "Introduceti 7 pentru a afla numarul de angajati dintr-un departament\n";
            cout << "Introduceti 8 pentru a afla numarul de angajati dintr-o companie\n";
            cout << "Introduceti 9 pentru a afla numarul total de angajati\n";
            cout << "Introduceti 10 pentru a sterge o companie\n";
            cout << "Introduceti 11 pentru a sterge un departament\n";
            cout << "Introduceti 12 pentru a sterge un angajat\n";
            cout << "Introduceti 13 pentru a lista departamentele cu minim N angajati\n";
            cout << "Introduceti 15 pentru a iesi din program\n";
            int op;
            bool citit = false;
            cin >> op;
            switch(op)
            {
            case(1):
                {
                    if(citit == true)
                    {
                        cout << "Configuratia initiala a fost deja introdusa!\n";
                        break;
                    }
                    cin >> a;
                    citit = true;
                    break;
                }
            case(2):
                {
                    cout << a << "\n";
                    break;
                }
            case(3):
                {
                    aux_companie = new Companie();
                    cin >> *aux_companie;
                    a.add_companie(aux_companie);
                    break;
                }
            case(4):
                {
                    string aux;
                    cout << "Departamentul pe care il introduceti este scutit de impozit(DA, NU)?:";
                    cin >> aux;
                    if(aux == "DA")aux_departament = new Departament_fara_imp();
                    else aux_departament = new Departament();
                    cin >> *aux_departament;
                    cout << "Introduceti ID - ul companiei in care vreti sa introduceti departamentul:";
                    int aux1;
                    cin >> aux1;
                    cout << "\n";
                    a.add_departament(aux_departament, aux1);
                    break;
                }
            case(5):
                {
                    aux_angajat = new Angajat();
                    cin >> *aux_angajat;
                    cout << "Introduceti ID - ul departamentului in care vreti sa introduceti angajatul:";
                    int aux1;
                    cin >> aux1;
                    cout << "\n";
                    a.add_angajat(aux_angajat, aux1);
                    break;
                }
            case(6):
                {
                    int aux1, aux2;
                    cout << "Introduceti ID - ul primei companii:";
                    cin >> aux1;
                    cout << "\n";
                    cout << "Introduceti ID - ul celei de a 2-a companii:";
                    cin >> aux2;
                    cout << "\n";
                    a.fuse(aux1, aux2);
                    break;
                }
            case(7):
                {
                    int aux1;
                    cout << "Introduceti ID - ul departamentului:";
                    cin >> aux1;
                    aux1 = a.nr_ang_dep(aux1);
                    if(aux1 == -1) cout << "Departamentul nu exista!\n";
                    else cout << "Numarul de angajati al departamentului este " << aux1 << "\n";
                    break;
                }
            case(8):
                {
                    int aux1;
                    cout << "Introduceti ID - ul companiei:";
                    cin >> aux1;
                    aux1 = a.nr_ang_comp(aux1);
                    if(aux1 == -1) cout << "Compania nu exista!\n";
                    else cout << "Numarul de angajati al companiei este " << aux1 << "\n";
                    break;
                }
            case(9):
                {
                    cout << "Numarul total de angajati este " << a.nr_ang() << "\n";
                    break;
                }
            case(10):
                {
                    int aux1;
                    cout << "Introduceti ID -ul companiei:";
                    cin >> aux1;
                    bool found = false;
                    a.remove_comp(aux1, found);
                    if(found == false)cout << "ID invalid!\n";
                    else cout << "Companie stearsa cu succes!\n";
                    break;
                }
            case(11):
                {
                    int aux1;
                    cout << "Introduceti ID - ul departamentului:";
                    cin >> aux1;
                    bool found = false;
                    a.remove_dep(aux1, found);
                    if(found == false)cout << "ID invalid!\n";
                    else cout << "Departament sters cu succes!\n";
                    break;
                }
            case(12):
                {
                    int aux1;
                    cout << "Introduceti ID - ul angajatului:";
                    cin >> aux1;
                    bool found = false;
                    a.remove_ang(aux1, found);
                    if(found == false)cout << "ID invalid!\n";
                    else cout << "Angajat sters cu succes!\n";
                    break;
                }
            case(13):
                {
                    int n;
                    cout << "Introduceti numarul minim de angajati:";
                    cin >> n;
                    bool found = false;
                    a.search_min_n(n, found);
                    if(found == false)cout << "Nu exista astfel de departamente!\n";
                    break;
                }
            case(15):
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
    }
};

Singleton * Singleton :: obiect = 0;

int main()
{
    Singleton * rez = rez -> get_instance();
    rez -> solve();
    return 0;
}
