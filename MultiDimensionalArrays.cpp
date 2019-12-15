#include <stdlib.h>
#include <stdio.h>
#include <time.h>

main(){
	int m,n;
	do{
		printf("Please enter M value of matrix MxN\n");
		scanf("%d", &m);
		printf("Please enter N value of matrix MxN\n");
		scanf("%d", &n);
		if(m<5 || n<5){
			printf("The value of M or N cannot be less than 5\n");
		}
	}
	while(m < 5);
	
	
	int f[m][n];
	int g[m][n];
	
	int i;
	int j;
	for(i=0; i<m ;i++){
		for(j=0; j<n; j++){
			g[i][j]=0;
		}
	}
	
	srand(time(0)); 
	printf("***** F matrisi *****\n");
	
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			int rndm = (rand() % 256);
			f[i][j]=rndm;
			printf("%d\t",f[i][j]);
		}
		printf("\n");
	}printf("\n");
	
	
	int v[3][3];
	int t;
	for(i=0; i < 3; i++){
		for(j=0; j<3; j++){
			printf("Please enter an intager to v[%d][%d]; ", i,j);
			scanf("%d",&t);
			v[i][j]=t;
		}
	}
	printf("\n");
	printf("***** V matrisi *****\n");

	for(i=0; i < 3; i++){
		for(j=0; j< 3; j++){
			printf("%d\t", v[i][j]);
		}
		printf("\n");
	}printf("\n");
	
	int toplam=0;
	for(i=0; i < m-2; i++){
		for(j=0; j< m-2;j++){
			for(int sa=0; sa<3; sa++){	
				for(int su=0; su<3; su++){
					toplam +=v[sa][su]*f[sa+i][su+j];
				}	
			}
			g[i+1][j+1]=toplam;
			toplam=0;
		}	
	}
	printf("***** G matrisi *****\n");

	for(i=0; i < m; i++){
		for(j=0; j< n; j++){
			printf("%d\t", g[i][j]);
		}
		printf("\n");
	}printf("\n");
	

	
	int tenpt[2][2];
	int r;
	for(i=0; i < 2; i++){
		for(j=0; j<2; j++){
			printf("Please enter an intager to tenpt[%d][%d]; ", i,j);
			scanf("%d",&r);
			tenpt[i][j]=r;
		}
	}
	
	int result=0;
	int sonuclar[500];
	int snc=0;
	int satir=0;int sutun=0;
	
	for(i=0; i < m-1; i++){
		for(j=0; j < m-1;j++){
			for(int satir=0; satir<2; satir++){	
				for(int sutun=0; sutun<2; sutun++){
					result +=tenpt[satir][sutun]*f[satir+i][sutun+j];				
				}	
			
			}
			sonuclar[snc++]= result;
			result=0;
		}	
	}
	
	// f matrisinin oluþturulan 2x2'lik tenpt matrisiyle 2x2'lik çarpýmlarýndan oluþan sonuçlarýn
	//  g matrisinin köþelerine eklenmesi
	int ct=0;
	
	for (i=0; i <m ;i++){
		for(j=0; j < n ; j++){
			if(i==0 || i==m-1){
				g[i][j]=sonuclar[ct++];
			}
			else{
				if(j == 0 || j == n-1){
					g[i][j] = sonuclar[ct++];
				}
			}
		}
	}
	
	
	//tenpt (2x2) dizisini yazdir
	printf("***** TENPT matrisi *****\n");
	
	for(i=0; i < 2; i++){
		for(j=0; j< 2; j++){
			printf("%d\t", tenpt[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	printf("***** G matrisi *****\n");	

	for(i=0; i < m; i++){
		for(j=0; j< n; j++){
			printf("%d\t", g[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
}

