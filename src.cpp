/* 060 분반
교재 486 문제 8.6 (Bag만 abstract class이고 Set은 concrete class로 구현하는 것으로 수정함)
다음 조건을 모두 만족하도록 coding 완성한다.
1. Queue에 Animal 객체를 Add(), Delete()한다
1. 기존 실습코드, github, 구글 등 모든 소스 코드 이용 가능함
2. 아래 제시된 코드 기반이 아니면 0점 처리
3. 동료 학생이 제공한 소스코드에 대한 표절 검사는 plato 등에 의해 시행
4. 3,4학년이 대리 시험 치르는 경우에 적발시 홈페이지 공지 및 대학본부에 징계 요청
   (과제 및 코딩 시험 결과의 일관성 검사로 의심학생 소환하여 대면 검사 시행함)
*/
#include <iostream>
using namespace std;
#define DefaultSize 20
#define MaxQueue 20

class Point {
public:
    Point(int xp = 0, int yp = 0) : xPos(xp), yPos(yp)
    {}
    int x() { return xPos; }
    int y() { return yPos; }
    void x(int px) { xPos = px; }
    void y(int py) { yPos = py; }
    void operator += (Point p) {
        xPos += p.xPos;
        yPos += p.yPos;
    }
    void operator -= (Point p) {
        xPos -= p.xPos;
        yPos -= p.yPos;
    }
    void operator *= (Point p) {
        xPos *= p.xPos;
        yPos *= p.yPos;
    }
    int operator == (Point p) {
        return xPos == p.xPos &&yPos == p.yPos;
    }
    void Print() { cout << "xPos : " << xPos << " yPos : " << yPos << endl; }
private:
    int xPos, yPos;
};
class Animal {
public:
    Animal(Point p = Point());
    virtual void Speak() {
        cout << "Animal Speaking " << endl;
    }
    void JumpBy(int x, int y);
    void MoveTo(Point newPosition);
    friend ostream& operator << (ostream& os, Animal& a);
    bool operator == (Animal& a) { return position == a.position; }
protected:
    Point position;
    void MoveOutput();
};
ostream& operator <<(ostream& os, Animal& a) {
    a.position.Print();
    return os;
}
Animal::Animal(Point p) : position(p)
{}

void Animal::JumpBy(int x, int y) {
    position += Point(x, y);
}
void Animal::MoveTo(Point newPosition) {
    position = newPosition;
}

void Animal::MoveOutput() {
    cout << "Animal::\tposition.x() = " << position.x() << ", position.y() = " << position.y() << endl;
}
class Cattle : public Animal {
public:
    Cattle(Point p = Point(10, 10));
    void Speak() {
        JumpBy(9, 9);
        MoveOutput();
        cout << "Cattle Speaking" << endl;
    }
    void JumpBy(int x, int y) { position -= Point(x, y); }//x1 = x1 - x, y1 = y1 - y
};
Cattle::Cattle(Point p)  : Animal(p){}
class Cow : public Cattle {
public:
    Cow(Point p = Point(101, 101));
    void Speak() {
        JumpBy(9, 9);
        MoveOutput();
        cout << "Cow Speaking" << endl;
    }
    void JumpBy(int x, int y) { position *= Point(x, y); }//x1 = x1 * x, y1 = y1 * y
};
class Bull : public Cattle {
public:
    Bull(Point p = Point(106, 106));
    void Speak() {
        JumpBy(9, 9);
        MoveOutput();
        cout << "Bull Speaking" << endl;
    }
    void JumpBy(int x, int y) { position -= Point(x, y); }
};
Bull:: Bull(Point p) : Cattle(p) {}
class Cat : protected Animal {//have to use protected inheritance
public:
    Cat(Point p = Point(5, 5));
    Cat(char*) {}
    void Speak() {
        Animal::Speak();
        JumpBy(9, 9);
        MoveOutput();
        cout << "Cat Speaking " << endl;
    }
    void JumpBy(int x, int y) { position *= Point(x, y); }
};
Cat::Cat(Point p) : Animal(p) {}
class Dog : protected Animal {//have to use protected inheritance
public:
    Dog(Point p = Point(20, 20));
    void Speak() {
        Animal::Speak();
        JumpBy(9, 9);
        MoveOutput();
        cout << "Dog Speaking " << endl;
    }
    void JumpBy(int x, int y) { position += Point(x, y); }
};
class Horse : protected Animal {//have to use protected inheritance
public:
    Horse(Point p = Point(30, 30));
    void Speak() {
        Animal::Speak();
        JumpBy(9, 9);
        MoveOutput();
        cout << "Horse Speaking " << endl;
    }
    void JumpBy(int x, int y) { position += Point(x, y); }
};
Horse::Horse(Point p)  :Animal(p){}
class Chicken : protected Animal {//have to use protected inheritance
public:
    Chicken(Point p = Point(40, 40));
    void Speak() {
        Animal::Speak();
        JumpBy(9, 9);
        MoveOutput();
        cout << "Chicken Speaking " << endl;
    }
    void JumpBy(int x, int y) { position += Point(x, y); }
};
Chicken::Chicken(Point p) : Animal(p){}
Cow::Cow(Point p) : Cattle(p)
{}

Dog::Dog(Point p) : Animal(p)
{}


class Bag {//abstract class
public:
    virtual ~Bag();
    virtual void Add(Animal);
    virtual Animal* Delete(Animal&);
    bool IsFull();
    bool IsEmpty();
    virtual bool IsDuplicate(Animal& a) = 0;//check the same or duplicate - 구현해야 함
    int Top();
    friend ostream& operator<< (ostream& stream, Bag& b);
    void Print() {
        for (int i = 0; i < Top(); i++) {
            cout << collection[i] << endl;
        }
    }
protected:
    Bag(int MaxSize = DefaultSize);
    void Full();
    void Empty();
    Animal* collection;
    int MaxSize;
    int top;
};

class Set : public Bag {
public:
    Set(int MaxSize = DefaultSize);
    ~Set();
    void Add(Animal);//no order, no duplicate
    Animal* Delete(Animal&);//no order, no duplicate
    friend ostream& operator<< (ostream& stream, Set s);
    bool IsDuplicate(Animal& a) {
        for (int i = 0; i < top; ++i) {
            if (collection[i] == a)
                return 1;
        }
        return 0;
    }
};


Bag::~Bag() {
}

bool Bag::IsFull() {
    if (top == MaxSize - 1)
        return true;
    else
        return false;
}

bool Bag::IsEmpty() {
    if (top == 0)
        return true;
    else
        return false;
}

void Bag::Full() {
    cout << "Data structure is full" << endl;
}

void Bag::Empty() {
    cout << "Data structure is empty" << endl;
}

void Bag::Add(Animal x) {
    if (IsFull())
        Full();
    else {
        collection[top] = x;
        cout << "BAG에 " << collection[top] << "이 추가되었습니다" << endl;
        top++;
    }
}

Animal* Bag::Delete(Animal& x) {
    if (IsEmpty()) {
        Empty();
        return 0;
    }
    //난수를 사용하여 임의 element를 delete
    int DeletePos = rand() % top;
    x = collection[DeletePos];
    for (int i = DeletePos; i < top - 1; ++i) {
        collection[i] = collection[i + 1];
    }
    top--;
    return &x;
}

int Bag::Top() {
    return top;
}

ostream& operator<<(ostream& stream, Bag&b) {
    cout << "ostream& operator<<(ostream& stream, Bag b) " << endl;
    for (int i = 0; i < b.Top(); i++) {
        stream << b.collection[i] << endl;
    }
    return stream;
}

Set::Set(int MaxBagSize) : Bag(MaxBagSize) {}

Set::~Set() {
}

void Set::Add(Animal x) {//to be modified
    if (IsFull())
        Full();
    else {
        if (!IsDuplicate(x))
        {
            Bag::Add(x);//반드시 사용되어야 함
            cout << "SET에 " << collection[top] << "이 추가되었습니다" << endl;
            top++;
            return;
        }
        else {
            cout << "중복된 값 입니다" << endl;
            return;
        }
    }
}


Animal* Set::Delete(Animal& x) {//to be modified
    if (IsEmpty()) {
        Empty();
        return 0;
    }
    Bag::Delete(x);//반드시 사용되어야 함
    return &x;
}

ostream& operator<<(ostream& stream, Set s) {
    cout << "ostream& operator<<(ostream& stream, Set s) " << endl;

    for (int i = 0; i < s.Top(); i++) {
        stream << s.collection[i] << endl;
    }

    return stream;
}
Bag::Bag(int MaxBagSize) : MaxSize(MaxBagSize) {
    collection = new Animal[MaxSize];
    top = 0;
}
class Queue : public Set {
public:
    Queue(int MaxSize = DefaultSize);//To be implemented by using Set
    ~Queue();//To be implemented by using Set
    void Add(Animal);//To be implemented by using Set to support FIFO
    Animal* Delete(Animal&);//To be implemented by using Set to support FIFO
    friend ostream& operator<< (ostream& stream, Queue q);//To be implemented by using Set
};
Queue::Queue(int MaxSize)  : Set(MaxSize){}
Queue::~Queue() {}
void Queue::Add(Animal x) {//to be modified
    //FIFO, no duplicate
    Set::Add(x);//반드시 사용되어야 함

}
Animal* Queue::Delete(Animal& x) {//to be modified
    //FIFO, no duplicate
    Set::Delete(x);//반드시 사용되어야 함
    return &x;
}
ostream& operator<<(ostream& stream, Queue q) {//to be modified
    Set s = (Set)q;
    stream << s;
    return stream;
}
void RunSpeaking(Animal& data, int steps)
{
    for (int n = 0; n < 10; n++)
        data.Speak();
}

int main() {
    int select;
    Bag* bx = new Queue;//To be modified
    Animal *mixedObect[20];//To be modified
    Animal* t; //To be modified
    Animal a;
    while (1)
    {
        cout << "\nSelect command  1. Make Animal, 2: Add Animal, 3: Delete Animal, 4. Display all, 5. Run Speak, 6. Quit = > ";
        cin >> select;
        Queue* q;
        switch (select) {
        case 1://1. Make Animal
            cout << "Add a new Animal" << endl;
            mixedObect[0] = new Cow;
            mixedObect[1] = reinterpret_cast<Animal*>(new Cat);
            mixedObect[2] = reinterpret_cast<Animal*>(new Dog);
            mixedObect[3] = reinterpret_cast<Animal*>(new Horse);//implement class Horse
            mixedObect[4] = reinterpret_cast<Animal*>(new Chicken);////implement class Horse
            mixedObect[5] = new Cattle;
            mixedObect[6] = reinterpret_cast<Animal*>(new Cat);
            mixedObect[7] = reinterpret_cast<Animal*>(new Dog);
            mixedObect[8] = reinterpret_cast<Animal*>(new Horse);//implement class Horse
            mixedObect[9] = reinterpret_cast<Animal*>(new Chicken);////implement class Horse
            mixedObect[10] = new Animal;
            mixedObect[11] = new Bull;
            mixedObect[12] = NULL;
            break;
        case 2:// 2: Add Animal to Set
            for (int i = 0; i < MaxQueue; i++)
                if (!mixedObect[i]) break;
                else
                    bx->Add(*(mixedObect[i]));//dynamic binding
            break;
        case 3: //3 : Delete Animal from Set
            while (!bx->IsEmpty())
            {
                t = bx->Delete(a);
                cout << " The deleted animal is ";
                cout << *t;
                RunSpeaking(*t, 100);
            }
            break;
        case 4://4. Display all - queue에 add, delete 전후로 4번을 실행하여 검사함
            cout << "4. Display:: ";
            q = dynamic_cast<Queue*>(bx);//down casting
            cout << *q << endl;
            break;
        case 5://5. Run Speak
            for (int i = 0; i < MaxQueue; i++)
                if (!mixedObect[i]) break;
                else
                    RunSpeaking(*mixedObect[i], i);
            break;


        default:
            exit(0);
            break;
        }
    }
    system("pause");
    return 0;
}