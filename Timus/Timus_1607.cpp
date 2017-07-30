/*
*       simply do the process in each step if the passanger offer more than driver want
*       But if u see in bottle neck  the passanger may offer than driver want in last step so it's a tricky step
*
*
* 
*/

#include <iostream>


using namespace std;

int main(void){
	int a,b,c,d;

	cin>>a>>b>>c>>d;

	int i=0;
	while(1){

		if(a+(i*b) >= c-(d*i)){ 
			printf("%d",(a+(i*b)));
			break;
		}

		if(a+((i+1)*b) >= c-(d*i)){ 
			printf("%d",(c-(d*i)));
			break;
		}
		i++;
	}

	return 0;
}