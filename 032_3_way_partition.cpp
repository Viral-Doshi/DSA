class Solution{   
public:
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        int n = array.size();
        vector<int> final(n);
        int p1 = 0, p2 = 0, p3 = 0;
        for(int i = 0; i < n; i++){
            if (array[i] < a){
                p2++;
                p3++;
            }
            else if (array[i] <=b)
                p3++;
        }
        for(int i = 0; i < n; i++){
            if (array[i] < a){
                final[p1] = array[i];
                p1++;
            }
            else if (array[i] <= b){
                final[p2] = array[i];
                p2++;
            }
            else{
                final[p3] = array[i];
                p3++;
            }
        }
        for(int i = 0; i < n; i++)
            array[i] = final[i];
    }

};


int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        
        vector<int> array(N);
        unordered_map<int,int> ump;
        
        for(int i=0;i<N;i++){
            cin>>array[i];
            ump[array[i]]++;
        }
        
        int a,b;
        cin>>a>>b;
        
        vector<int> original = array;

        int k1=0,k2=0,k3=0;
        int kk1=0;int kk2=0;int kk3=0;
        
        for(int i=0; i<N; i++)
        {
            if(original[i]>b)
                k3++;
            else if(original[i]<=b and original[i]>=a)
                k2++;
            else if(original[i]<b)
                k1++;
        }
        
        Solution ob;
        ob.threeWayPartition(array,a,b);
      
        for(int i=0;i<k1;i++)
        {
            if(array[i]<b)
            kk1++;
        }
        
        for(int i=k1;i<k1+k2;i++)
        {
            if(array[i]<=b and array[i]>=a)
            kk2++;
            
        }
        
        for(int i=k1+k2;i<k1+k2+k3;i++)
        {
            if(array[i]>b)
            kk3++;
        }
        bool ok = 0;
        if(k1==kk1 and k2 ==kk2 and k3 == kk3)
            ok = 1;
        
        for(int i=0;i<array.size();i++)
            ump[array[i]]--;
        
        for(int i=0;i<array.size();i++)
            if(ump[array[i]]!=0)
                ok=0;
        
        if(ok)
            cout<<1<<endl;
        else
            cout<<0<<endl;
        
    }
    
    return 0;
}