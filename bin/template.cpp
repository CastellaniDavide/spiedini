int zeriDestra, totDestra, zeriSinistra, totSinistra, pDestra, pSinistra, sol;
int solve(int N, int K, int s[]) {
    pDestra = 0, pSinistra = 0, sol = 0;
    
    for(int i=0; i<N; i++) {
        if (s[i] == 0)
            zeriDestra++;
        totDestra += s[i];
    }
    if (totDestra < K)
        return zeriDestra;

    while (pDestra<N) {
        while (pSinistra<N && totSinistra+totDestra>K) {
            if(s[pSinistra] == 0)
                zeriDestra--;
            totDestra -= s[pSinistra++];
        }
        
        if (pSinistra==N && totSinistra+totDestra>K)
            break;
            
        if (pDestra<=pSinistra && zeriDestra+zeriSinistra>sol)
            sol = zeriDestra+zeriSinistra;
            
        if (s[pDestra] == 0)
            zeriSinistra++;
        totSinistra += s[pDestra++];
    }
    return sol;
}