#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int LSOne(int idx) { // extract least significant set bit
	return idx & (-idx);
}

class BIT {
private:
	int size;
	vi f, ft;
public:
	BIT(int n) {
		size = n;
		f.resize(n+1, 0);
		ft.resize(n+1, 0);
	}

	void update(int pos, int val) {
		f[pos] += val;
		while (pos <= size) {
			ft[pos] += val;
			pos += LSOne(pos) ;
		}
	}

	int read(int pos) {
		int ret = 0;
		while (pos>0) {
			ret += ft[pos];
			pos -= LSOne(pos);
		}
		return ret;
	}

	int readSingle(int pos) {
		return f[pos];
	}

	void printft(){
		cout<<"Size: "<<size<<endl;
		for(auto v: ft) {
			cout<<v<<" ";
		}
		cout<<endl;
	}

	void printfreq(){
		cout<<"Size: "<<size<<endl;
		for(auto v: f) {
			cout<<v<<" ";
		}
		cout<<endl;
	}

};

int main(){
	//freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vi A = {1, 0, 2, 1, 1, 3, 0, 4, 2, 5, 2, 2, 3, 1, 0, 2};
	
	BIT ftree(16);

	// verify that the Internal vectors are right number of zeros
	// ftree.printft(); 
	// ftree.printfreq();

	int idx=1;
	for(auto a: A) {
		ftree.update(idx, a);
		idx += 1;
	}

	// verify the final Ftree looks like this
	ftree.printft();
	vi final = {1, 1, 2, 4, 1, 4, 0, 12, 2, 7, 2, 11, 3, 4, 0, 29};

	// verify the final freq looks like A
	ftree.printfreq();

	//cout<<"hello world!"<<endl;

	return 0;
	
}