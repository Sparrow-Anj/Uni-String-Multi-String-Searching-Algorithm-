#include<iostream>
#include<vector>

using namespace std ;

void calculateZ_Array(string& tex_pat , vector<int>& z_array){
    
    int l = 0 ;
    int r = 0 ;
    
    z_array[0] = 0 ;
    
    for(int i = 1 ; i<tex_pat.length() ; i++){
        
        if(i > r){ // When you are out of the z box so you start comparing
            l = r = i ; // setting all of them at the same index
            
            while(r < tex_pat.length() and tex_pat[r] == tex_pat[r-l]){ // checking prefix match r - l = 0 (l == r) & r++
                r ++ ;
            }
            z_array[i] = r - l ; // finding the length of z box or the prefix which is matched
            r-- ;
        }
        else{
            // We are operating inside the box
            
            int k1 = i - l ; // we will get back to its original value that we are going to copy from z_array
            
            if(z_array[k1]  < r - i + 1) { // checking whether this value is not crossing z box
                z_array[i] = z_array[k1] ;
            }
            else{ // if boundry is crosses then we will check for more matches
                l = i ;
                while(r < tex_pat.length() and tex_pat[r] == tex_pat[r-l]){
                    r ++ ;
                }
                z_array[i] = r - l ;
                r-- ;
            }
        }
    }
}


vector<size_t>Z_ARRAY(string text , string pattern){
    
    string tex_pat(pattern + "$" + text) ;
    
    vector<int>z_array(tex_pat.length()) ;
    
    calculateZ_Array(tex_pat , z_array) ;
    
    vector<size_t>result ;
    
    for(int i = 0 ; i<z_array.size() ; i++){
        if(z_array[i] == pattern.length()){
            result.push_back(i - pattern.length() - 1 );
        }
    }
    
    return result ;
}

