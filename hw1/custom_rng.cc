#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <omp.h>
using namespace std;
/** Custom random number generator based of "Ran" routine in Numerical Recipes
 * by Press et al. */
class custom_rng {
    public:
        unsigned long a,b,c;
        custom_rng(unsigned long seed) : b(4101842887655102017L), c(1) {
            if(sizeof(unsigned long)<8) {
                fputs("Error: 'unsigned long' type too short\n",stderr);
                exit(1);
            }
            a=seed^b;int64();
            b=a;int64();
            c=b;int64();
        }
        unsigned long int64() {
            a=a*2862933555777941757L+7046029254386353087L;
            b^=b>>17;b^=b<<31;b^=b>>8;
            c=4294957665U*(c&0xffffffff)+(c>>32);
            unsigned long d=a^(a<<21);
            d^=d>>35;d^=d<<4;
            return (d+b)^c;
        }
        inline double doub() {
            return 5.42101086242752217E-20*int64();
        }
};
/*
int main() {
double sum=0;
double two=0;
double three=0;
double four=0;
double fiveormore=0;

clock_t time_req;
time_req=clock();
int threads=omp_set_num_threads(4);
for (int k=0; k<threads;k++)
    {rng[k]=custom_rng(k);}

#pragma omp parallel num_threads(4)
{
#pragma omp for reduction (+:sum)
for (int i=1;i<10;i++) 
    { 
        int to=omp_get_thread_num(); 
        double draw=0;
        double add=0;
        double counter=0;
        double money=-250;
    	

        // Create an array of pointers to random number generators
        

        // Create random number generators, each with a different initial seed
            // Generate the numbers
            
    	while (add<1){
    	draw=rng[to];
    	add=add+draw;
    	counter=counter+1;
    	//printf("%g %g\n",counter,draw);
    	}

    	money= money + counter*100;
    	sum+=money;
    	//printf("draws: %g, final val: %g, earnings: %g \n",counter,add,money);
        // Delete random number generators
        
        
        if (counter==2) two=two+1;
        else if (counter==3) three=three+1;
        else if (counter==4) four= four+1;
        else if (counter>4) fiveormore=fiveormore+1;
        
        if (i==1000000000) printf("%d",d);
	}
}
        printf("two draws: %g, three draws: %g, four draws: %g, five+ draws: %g, total money: $%g\n",two,three,four,fiveormore,sum);
        time_req = clock() - time_req;
        cout<< "it took "<< (float)time_req/CLOCKS_PER_SEC<< " seconds" << endl;
        //printf("Threads: %d\n",d);
        return 0;
}
*/
int main() {
int sum=0;
double two=0;
double three=0;
double four=0;
double fiveormore=0;

clock_t time_req;
time_req=clock();

// for (int k=0; k<threads;k++)
// {rng[k]=new custom_rng(k)}
custom_rng** c= new custom_rng
#pragma omp parallel num_threads(4)
    {
    #pragma omp for reduction (+:sum)
    for (int i=1;i<1000000000;i++) 
        { 
            int d=omp_get_thread_num(); 
            double draw=0;
            double add=0;
            double counter=0;
            double money=-250;
            

            // Create a pointer to random number generators
            custom_rng* c;

            // Create random number generators, each with a different initial seed
            c=new custom_rng(time(0)*i);

                // Generate the numbers
                
            while (add<1){
            draw=c->doub();
            add+=draw;
            counter=counter+1;
            //printf("%g %g\n",counter,draw);
            }

            money+=counter*100;
            sum+=money;
            //printf("draws: %g, final val: %g, earnings: %g \n",counter,add,money);
            // Delete random number generators
            delete c;
            
            if (counter==2) two=two+1;
            else if (counter==3) three=three+1;
            else if (counter==4) four= four+1;
            else if (counter>4) fiveormore=fiveormore+1;
            
            if (i==1000000000) printf("%d",d);
        }
    }   
        printf("two draws: %g, three draws: %g, four draws: %g, five+ draws: %g, total money: $%g\n",two,three,four,fiveormore,sum);
        time_req = clock() - time_req;
        cout<< "it took "<< (float)time_req/CLOCKS_PER_SEC<< " seconds" << endl;
        //printf("Threads: %d\n",d);
        return 0;
}
