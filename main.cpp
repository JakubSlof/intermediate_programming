#include <iostream>
//sum, dif, Hamming distance
// Declare a structure named "Vector5"
struct Vector5{
    int v;
    int w;
    int x;
    int y;
    int z;
}; 
Vector5 vector_a;
Vector5 vector_b;

Vector5 hem(Vector5 a, Vector5 b){
    return{abs((a.v-b.v)),abs((a.w-b.w)),abs((a.x-b.x)),abs((a.y-b.y)),abs((a.z-b.z))};
}
Vector5 diff(Vector5 a, Vector5 b){
    return {a.v - b.v , a.w - b.w , a.x - b.x , a.y - b.y, a.z - b.z};
}
Vector5 sum(Vector5 a, Vector5 b){
    return {a.v + b.v, a.w + b.w, a.x + b.x, a.y + b.y, a.z + b.z};
}

int main(){
vector_a = {2,3,4,5,6};
vector_b = {9,8,7,6,5};
Vector5 c = sum(vector_a,vector_b);
std::cout << "Sum of vectors: ("<<c.v<<" , "<<c.w <<" ,"<<c.x<<" , "<<c.y<<" , "<<c.z<<")"<< std::endl;
Vector5 d = diff(vector_a,vector_b);
std::cout << "Difference of vectors : ("<<d.v<<" , "<<d.w <<" , "<<d.y<<" , "<<d.z<<")"<< std::endl;  
Vector5 e = hem(vector_a,vector_b);
std::cout << "Hamming distance : ("<<e.v<<" , "<<e.w <<" , "<<e.y<<" , "<<e.z<<")"<< std::endl; 

}
