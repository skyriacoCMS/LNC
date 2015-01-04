#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

int  addition(std::vector<int> num1,std::vector<int> num2,std::vector<int> & res){



  int sz1 = num1.size();
  int sz2 = num2.size();

  res.clear();


  if(sz1 >= sz2){
 
    for(int i = 0; i < sz2; i++){
      res.push_back(0);
      int sum = num1[i] + num2[i];
      res[i] = (res[i] + sum) % 10;
      if( res[i] + sum >= 10){
	res.push_back(0);
	res[i+1] = (res[i] +  sum) / 10;
      }
    }


    for(int i = sz2; i < sz1 ; i++){
      res.push_back(0); 
      int sum =  res[i] + num1[i];
      res[i] = (sum) % 10;
      if(sum >= 10){
	res.push_back(0);
	res[i+1] = sum / 10;
	
      } 
      
    }
    
  }else{

    
    for(int i = 0; i < sz1; i++){
      res.push_back(0);
      int sum = num1[i] + num2[i];
      res[i] = (res[i] + sum) % 10;
      if( res[i] + sum >= 10){
	res.push_back(0);
	res[i+1] = (res[i] +  sum) / 10;
      }
    }


    for(int i = sz1; i < sz2 ; i++){
      res.push_back(0); 
      int sum =  res[i] + num2[i];
      res[i] = (sum) % 10;
      if(sum >= 10){
	res.push_back(0);
	res[i+1] = sum / 10;
	
      } 
      
    }

  }

  //erasing the zero elements that the algo might add in the beginning of the number
  int k =0;

  while(k  == 0 && res.size()){
    if(res[res.size() - 1 ] == 0){
      res.erase(res.begin() + res.size() - 1);
      
    }else{
      k = 1; 
     
    }
    


  }
  
  return 0;

}

int subtraction(std::vector<int> num1,std::vector<int> num2,std::vector<int> & res){
  
  int sz1 = num1.size();
  int sz2 = num2.size();

  return 0; 
}


int division(std::vector<int> num1,std::vector<int> num2,std::vector<int> & res){

  return 0; 
}


int multiplication(std::vector<int> num1,std::vector<int> num2,std::vector<int> & res){
  
  int sz1 = num1.size();
  int sz2 = num2.size();

  res.clear();

  if(sz1 >= sz2){
 
    for(int i =0; i < sz1; i++){
      res.push_back(0);
      for(int k = 0; k <sz2 ; k++){
	res.push_back(0);
	int mul = num1[i]*num2[k];
	int sum = ( res[ i + k ]  + mul );
	res[ i + k ] = sum % 10;
	if( sum  >= 10 ){
	  res[i + k + 1 ] = res[i + k + 1 ] + sum/10; 
	}
      }
    }

  }else{
        
    for(int i =0; i < sz2; i++){
      res.push_back(0);
      for(int k = 0; k <sz1 ; k++){
	res.push_back(0);
	int mul = num1[i]*num2[k];
	int sum = ( res[ i + k ]  + mul );
	res[ i + k ] = sum % 10;
	if( sum  >= 10 ){
	  res[i + k + 1 ] = res[i + k + 1] +  sum/10; 
	}
      }
    }
  }



    //erasing the zero elements that the algo might add in the beginning of the number
  int k =0;

  while(k  == 0 && res.size()){
    if(res[res.size() - 1 ] == 0){
      res.erase(res.begin() + res.size() - 1);
      
    }else{
      k = 1; 
     
    }
    


  }
  


 
  return 0;


}




int main(){

  vector<int> testt,m1,m2;
  vector<int>  ad1; 
  vector<int>  ad2; 
  vector<int>  resss; 
  


  ad1.push_back(0); 
  ad1.push_back(3);
 
  ad2.push_back(0); 
  ad2.push_back(1); 
  resss.clear();  

  multiplication(ad2,ad1,resss);
  for(int i =0; i < resss.size(); i++)cout<<resss[resss.size() - i -1];
  cout<<endl;

  
  //FAKTORIAL CALCULATION
  vector<int> res; 
  res.push_back(1);

  int fact_conv = 1; 

  for(int i = 1; i < 51; i++){
    vector<int> cur; 
    cur.clear();
    
    fact_conv = fact_conv*i; 
    cur.push_back(i % 10 );
    cur.push_back(i / 10 );
    
    cout<<" current :"<< endl;
    for(int j = 0; j < cur.size(); j++)cout<<cur[cur.size() - 1 -j];
    cout<<"   ";
    vector<int> out; 

    multiplication(res,cur,out); 

    res = out;
    for(int k =0; k < res.size(); k ++ ) cout<<res[res.size() - k - 1];
    cout<<"    conv: ";
    
    cout<<fact_conv<<endl;




  }

  return 0;
}

