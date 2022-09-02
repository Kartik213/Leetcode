class Solution {
public:
    void removespace(string &s){
        int n=s.length();
        if(n==0)return ;
        int i=0,j=n-1,k=0;
        while(i<n && s[i]==' '){
            i++;
        }
        while(j>=0 && s[j]==' '){
            j--;
        }
        for(int t=i;t<=j;t++){   
            if(isalnum(s[t])){
                s[k++]=s[t];
            }
            else{
                s[k++]=s[t];
                while(t+1<=j && s[t+1]==' '){
                    t++;
                }
            }
        }
       s.erase(k,n-k) ;     
    }
    void reverse(string &s,int x,int y){   
        int i=x,j=y;
        while(i<j){
            swap(s[i],s[j]);
            i++;j--;    
        }   
    }
    string reverseWords(string s) {
        removespace(s);
        int n=s.length();
        int i=0,j=n-1;
        reverse(s,i,j);
        while(i<n){
            int j=i;
            while(j<n && s[j]!=' '){
                j++;
            }
            reverse(s,i,j-1);
            i=j+1;
        }
        
        return s;
     }
    
};