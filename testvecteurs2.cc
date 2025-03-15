#include "Vecteurs.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	Vecteur v1(7);
	Vecteur v2({1.2, 5, 789, 78});
	Vecteur v3(5, 4, 3);

	
	cout<<"v1, v2 et v3 : "<<v1<<", "<<v2<<", "<<v3<<endl;
	cout<<endl;
	
	Vecteur v4(v1);
	Vecteur v5(v4);
	v4.set_coord(6, 1);
	
	
	cout<<"Comparaisons :"<<endl;
	
	if(v1==v4) cout<<"v1==v4"<<endl;
	else cout<<"v1!=v4"<<endl;
	
	if(v1==v5) cout<<"v1==v5"<<endl;
	else cout<<"v1!=v5"<<endl;
	
	if(v1==v3) cout<<"v1==v3"<<endl;
	else cout<<"v1!=v3"<<endl;
	cout<<endl;
	
	v3+=v1;
	Vecteur v7(v5+v4);
	Vecteur v8(v2+v3);
	Vecteur v9(-v2);
	Vecteur v10(v3-v2);
	Vecteur v11(v3 + v9);
	
	cout<<"Additions :"<<endl;
	cout<<"v3+v1 = "<<v3<<endl;
	cout<<"v5+v4 = "<<v7<<endl;
	cout<<"v2+v3 = "<<v8<<endl;
	cout<<"-v2 = "<<v9<<endl;
	cout<<"v3-v2 = "<<v10<<endl;
	cout<<"v3-v2 = "<<v11<<endl;
	v3-=v4;
	cout<<"v3 + v1 - v4 ="<<v3<<endl;
	cout<<endl;
	
	v3*=2;
	
	Vecteur v12(2*v4);
	Vecteur v13(v2*1.5);
	Vecteur v14(v4/2);
	Vecteur v15(v2/1.5);
	Vecteur v16(v2/0);
	
	cout<<"Mult. scalaires : "<<v3<<","<<v12<<", "<<v13<<", "<<v14<<", "<<v15<<", "<<v16<<endl;
	cout<<endl;
	
	Vecteur e4(~v4);
	Vecteur e2(~v2);
	Vecteur e1(~v1);
	Vecteur e5({45, -89, 4614, -7988, 0, 7});
	e5 = ~e5;
	
	cout<<"Unitaires : "<<e1<<", "<<e2<<", "<<e4<<", "<<e5<<endl;
	cout<<endl;
	
	
	
	
	return 0;
}
