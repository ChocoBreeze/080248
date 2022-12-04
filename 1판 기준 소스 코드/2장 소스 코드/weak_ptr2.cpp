#include <memory>
#include <iostream>

using namespace std;

struct Son;
struct Daughter;

struct Mother {
	~Mother() { cout << "Mother 해제" << endl; }
	void setSon(const shared_ptr<Son> s) { mySon = s; }
	void setDaughter(const shared_ptr<Daughter> d) { myDaughter = d; }
	shared_ptr<const Son> mySon;
	weak_ptr<const Daughter> myDaughter;
};

struct Son {
	Son(shared_ptr<Mother> m): myMother(m) {}
	~Son() { cout << "Son 해제" << endl; }
	shared_ptr<const Mother> myMother;
};

struct Daughter {
	Daughter(shared_ptr<Mother> m) : myMother(m) {}
	~Daughter() { cout << "Daughter 해제" << endl; }
	shared_ptr<const Mother> myMother;
};

int main() {
	shared_ptr<Mother> moth = shared_ptr<Mother>(new Mother);
	shared_ptr<Son> son = shared_ptr<Son>(new Son(moth));
	shared_ptr<Daughter> daugh = shared_ptr<Daughter>(new Daughter(moth));
	moth->setSon(son);
	moth->setDaughter(daugh);
	return 0;
} // Daughter 해제

/*
딸(Daughter)는 자동으로 해제되지만, 아들(Son)은 해제되지 않음.
어머니(Mother)는 아들과 std::shared_ptr를 통해 연결되고, 딸과는 std::weak_ptr를 통해서 연결됨.
*/