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
	
	Vecteur v6(5, 0, -7);
	
	v3+=v1;
	Vecteur v7(v5+v4);
	Vecteur v8(v2+v3);
	Vecteur v8_2(v3 + v2);
	Vecteur v9(-v2);
	Vecteur v10(v3-v2);
	Vecteur v11(v3 + v9);
	
	cout<<"Additions :"<<endl;
	cout<<"v3+v1 = "<<v3<<endl;
	cout<<"v5+v4 = "<<v7<<endl;
	cout<<"v2+v3 = "<<v8<<endl;
	cout<<"v3+v2 = "<<v8_2<<endl;
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
	Vecteur e5({45, -89, 4614, -7988, 0, 7, 2});
	e5 = ~e5;
	
	cout<<"Unitaires : "<<e1<<", "<<e2<<", "<<e4<<", "<<e5<<endl;
	cout<<endl;
	
	
	
	double x1(v1*v2);
	double x2(v4*v5);
	double x3(v3*v4);
	double x4(v3*e5);
	
	cout<<"Produits scalaires :"<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<endl;
	cout<<endl;
	
	Vecteur v17(0, 1, 30);
	
	Vecteur v18(v17^v6);
	Vecteur v19(v18^v17);
	Vecteur v20(v17^v18);
	Vecteur v21(v20^v20);
	Vecteur v22(v2^v20);
	
	cout<<"Produits vectoriels : "<<v18<<", "<<v19<<", "<<v20<<", "<<v21<<", "<<v22<<endl;
	
	return 0;
}
