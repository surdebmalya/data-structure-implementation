class Solution{
   public:
   static bool comp(int a, int b){
       int setA = __builtin_popcount(a);
       int setB = __builtin_popcount(b);
       if(setA>setB) return true;
       else return false; // setA<=setB
    //   return __builtin_popcount(a)>__builtin_popcount(b);
   }
   void sortBySetBitCount(int arr[], int n)
   {
       stable_sort(arr,arr+n,comp);
   }
};