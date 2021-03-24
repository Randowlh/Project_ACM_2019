 double *ans=malloc(n*sizeof(double*));
    *result_count=n;
    double eps=epsilon;
    int ff=0;
    for(int i=0;i<n;i++){
        int mix=i;
        for(int j=i+1;j<n;j++){
            double tt=fabs(matrix[j][i])-fabs(matrix[i][i]);
            if(tt<0)
                mix=j;
        }
        for(int j=0;j<n+1;j++){
            double tmp=matrix[i][j];
            matrix[i][j]=matrix[mix][j];
            matrix[mix][j]=tmp; 
        }
        if(fabs(matrix[i][i])<eps){
            ff=1;
        }
        for(int j=i+1;j<n;j++){
            double tmp=matrix[j][i]/matrix[i][i];
            for(int k=i;k<n+1;k++)
                matrix[k][j]-=tmp*matrix[i][j];
        }
    }
    if(ff){
        isMethodApplicable=0;
        errorMessage="The system has no diagonal dominance for this method. Method of the Gauss-Seidel is not applicable.";
        return ans;
    }
    // for(int i=1;i<=50;i++){
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++)
            matrix[i][n]-=matrix[j][n]*matrix[i][j];
        matrix[i][n]/=matrix[i][i];
    }
    for(int i=0;i<n;i++)
        ans[i]=matrix[i][n];
    // }
    return ans;   