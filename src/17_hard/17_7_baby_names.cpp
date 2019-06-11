// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

using vsi = vector<pair<string, int> >;
using vss = vector<pair<string, string> >;




template <typename K, typename V>
class UF{ // union find data structure
public:
	UF(K key, V val) : _key(key), _val(val), _parent(nullptr){ }

	UF* find(){
		UF* curr = this;
		while(curr->_parent!=nullptr) curr = curr->_parent;
		if(_parent!=nullptr) _parent = curr; // speed up search next time
		return curr;
	}

	void unite(UF* other){
		other->find()->_parent = find();
	}

	void normalize(){ /*_parent =*/ find(); } // automatically normalizes
	bool isRoot() { return _parent == nullptr; }

	K& getKey(){ return _key; }
	V& getVal(){ return _val; }

private:
	K _key;
	V _val;
	UF* _parent;
};


using UFsi = UF<string, int>;



vsi unifyNames(vsi nameFreq, vss nameEq){
	map<string, UFsi> _map;
	for(auto& e:nameFreq) {
	    _map.insert(make_pair(e.first, UFsi(e.first, e.second)));
	}
	
	for(auto& e:nameEq){
		auto uf1 = _map.find(e.first); // iterator
		auto uf2 = _map.find(e.second);
		if(uf1!=end(_map) && uf2!=end(_map)){
		     uf1->second.unite(&(uf2->second));
		}
	}

	for(auto& ep:_map){
		UFsi& e = ep.second;
		if(!e.isRoot()) {
			e.find()->getVal() += e.getVal(); // give it to parent
			e.getVal() = 0;
		}
	}

	vsi res;
	for(auto& ep:_map){
		UFsi& e = ep.second;
		if(e.isRoot()) {
			res.push_back(make_pair(e.getKey(), e.getVal()));
		}
	}

	return res;
}




int main()
{
	cout << "Unify baby names: " << endl;

	vsi nameFreq = {
		{"John",  15},
		{"Jon",   12},
		{"Chris", 13},
		{"Kris" ,  4},
		{"Christopher", 19}
	};

	vss nameEq = {
		{"Jon", "John"}, 
		{"John", "Johnny"}, 
		{"Chris", "Kris"}, 
		{"Chris", "Christopher"}
	};

	vsi res = unifyNames(nameFreq, nameEq);
	
	for(auto& e : res) cout << e.first << "\t -> " << e.second << endl;
	cout << endl;

	return 0;
}