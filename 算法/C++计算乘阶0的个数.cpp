class Solution {
public:
    /*
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
    long long  trailingZeros(long long n) {
        // unsigned long long int l=1;
        // if(n%2==0){
        //     n=n+1;
        // }
        // // write your code here, try to do it without arithmetic operators.
        // for(int i=0;i<n;i++){
        //     l=l*(i+1);
        //     cout<<l<<"   "<<sizeof(l)<<endl;
        // }
        // cout<<l<<endl;
       
        // int num=0;
        // while (l>0){
        //     if(l%5==0){
        //         num++;
                
        //     }
        //     else{
        //         break;
        //     }
        //     l=l/10;
        
        // }
       
        
        // return num;
         long long int rvl = 0;  
        while(n > 0){  
            rvl += n/5;  
            n = n/5;  
        }  
        return rvl;  
        
    }
};