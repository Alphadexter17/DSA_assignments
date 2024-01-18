#include <iostream>
using namespace std;

struct student{
		int roll;
		string name;
		float sgpa;
};

class DataBase{
	int n;
	
	public:
	DataBase(int num){ 
		n=num;
	}
	struct student DB[50];
		
	void getinfo();
	void showinfo(int a);	
	void srchsgpa();
	bool is_substring(string S, string s);
	void binsrch();
	void sortrn();
	void sortnm();
	int partition(int low, int high);
	void quicksort(int low, int high);	
};

void DataBase::getinfo(){								//INPUT DATA
	for(int i=0;i<n;i++){
		cout<<"\n---------------------------------\n";
		cout<<"For Student: "<<i+1<<endl;
		cout<<"Enter Roll. No: "; cin>> DB[i].roll; 
		cout<<"Enter Name: "; cin>> DB[i].name; 
		cout<<"Enter SGPA: "; cin>> DB[i].sgpa; 
	}
}

void DataBase::showinfo(int a){							//OUTPUT DATA
	cout<<"\nROLL NO.     SGPA     NAME\n";
	for(int i=0;i<a;i++){
		cout<<"---------------------------------\n";
		cout<<DB[i].roll<<"        "<<DB[i].sgpa<<"     "<<DB[i].name<<endl;
	}
}
	
void DataBase::srchsgpa(){								//LINEAR SEARCH ON SGPA
	cout<<"---------------------------------\n";
	float s;
	cout<<"Enter SGPA to be searched: "; cin>>s;
	cout<<endl;
	int flag=1;
	for(int i=0;i<n;i++){
		if(DB[i].sgpa==s){ 
			cout << "\n-------MATCH FOUND-------";
			cout<<"\nSGPA: "<<DB[i].sgpa;
			cout<<"\nName: "<<DB[i].name;
			cout<<"\nRoll No. "<<DB[i].roll<<endl;
			flag=0;
		}	
	}
	if(flag==1) cout<<"Sorry! No similar matches found\n";
}	

bool DataBase::is_substring(string S, string s){					//CHECKING FOR SUBSTRING
	if(S.find(s)>(S.length()-s.length())) return false;
	else return true;
}

void DataBase::binsrch() {							 	//BINARY SEARCH ON NAME
	string k;
	cout<<"---------------------------------";
	cout<<"\nEnter search key: "; cin>>k;
	bool success = false;
	int low = 0; int high = n; 
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (is_substring(DB[mid].name,k)==true) {
			success = true;
			cout << "\n-------MATCH FOUND-------";
			cout<<"\nName: "<<DB[mid].name;
			cout<<"\nRoll No. "<<DB[mid].roll;
			cout<<"\nSGPA: "<<DB[mid].sgpa<<endl;
			break;
		} else if (DB[mid].name > k) high = mid - 1;
		else low = mid + 1;
	}
	if (success==false) cout << "ITEM NOT FOUND";
}

void DataBase::sortrn(){								//BUBBLE SORT ON ROLL NO.
	for(int j=0;j<n;j++){
		for(int i=0;i<n-j-1;i++){
			if(DB[i].roll>DB[i+1].roll){
				swap(DB[i],DB[i+1]);
			}
		}	
	}
}	

void DataBase::sortnm(){								//INSERTION SORT ON NAME
	for(int i=0; i<n; i++){
		student temp=DB[i]; int j=i-1;
		while(j>=0 && DB[j].name>temp.name){
			DB[j+1]=DB[j];
			j--;
		}
		DB[j+1]=temp;
	}
}

int DataBase::partition(int low, int high){						//PARTITION FUNCTION
	student pivot = DB[low];
	int k = high;
	for (int i = high; i > low; i--) {
		if (DB[i].sgpa < pivot.sgpa){
			swap(DB[i], DB[k]);
			k--;
		}
	}
	swap(DB[low], DB[k]);
	return k;
}

void DataBase::quicksort(int low, int high){						//QUICK SORT ON SGPA
	if (low < high) {
		int p = partition(low, high);

		quicksort(low, p - 1);
		quicksort(p + 1, high);
	}
}

int main(){
	int N,C,flag=0;
	cout<<"Enter Number of Student Entries: "; cin>>N;
	DataBase obj = DataBase(N);
	obj.getinfo();
	cout<<"\n---------------------------------\n";
	cout<<"Choose what you want to do\n";
	cout<<"\n1.Sort According to Roll No.\n2.Sort According to Name\n3.List of Top 10 Students\n4.Search with SGPA\n5.Search with Name"<<endl;
	while(flag==0){
		cout<<"\nEnter Choice Code: "; cin>>C;
		if(C==1){
			obj.sortrn(); obj.showinfo(N); 
		} else if(C==2){
			obj.sortnm(); obj.showinfo(N); 
		} else if(C==3){
			obj.quicksort(0,N-1); obj.showinfo(5); 
		} else if(C==4){
			obj.srchsgpa(); 
		} else if(C==5){
			obj.binsrch(); 
		} else{
			cout<<"Enter Valid Choice\n";
		}
	}
}