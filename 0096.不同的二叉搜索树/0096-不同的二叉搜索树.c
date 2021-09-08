// https://leetcode-cn.com/problems/unique-binary-search-trees/
int getNums(int left, int right){
    if(left >= right){
        return 1;
    }
    int sum = 0;
    for(int i = left; i <= right; i++){
        sum += getNums(left, i-1) * getNums(i+1, right);
    }
    
    return sum;
}

int numTrees(int n){
    return getNums(1,n);
}