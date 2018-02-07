#include <cstdio>
#include <cstdlib>

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

//int main() {
//    int i,j;
//    double r[3];
//
//    // Create an array of pointers to random number generators
//    custom_rng* c[3];
//
//    // Create random number generators, each with a different initial seed
//    for(j=0;j<3;j++) c[j]=new custom_rng(j);
//
//    // Test the random number generators
//    for(i=0;i<4;i++) {
//
//        // Generate the numbers
//        for(j=0;j<3;j++) r[j]=c[j]->doub();
//
//        // Print the results
//        printf("%g %g %g\n",*r,r[1],r[2]);
//    }
//
//    // Delete random number generators
//    for(j=2;j>=0;j--) delete c[j];
//}

int main() {
    int i,j;
    double r[3];

    // Create an array of pointers to random number generators
    custom_rng* c[3];

    // Create random number generators, each with a different initial seed
    for(j=0;j<3;j++) c[j]=new custom_rng(j);

    // Test the random number generators
    for(i=0;i<4;i++) {

        // Generate the numbers
        for(j=0;j<3;j++) r[j]=c[j]->doub();

        // Print the results
        printf("%g %g %g\n",*r,r[1],r[2]);
    }

    // Delete random number generators
    for(j=2;j>=0;j--) delete c[j];
}
