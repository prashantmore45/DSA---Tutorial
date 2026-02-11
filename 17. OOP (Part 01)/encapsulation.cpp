/* Encapsulation is wrapping up of data & member functions (methods) in a single unit.
   It also implements data hiding.
*/


#include <iostream> 
using namespace std;

 class Student {
    private:
        string name;

    public:
        float cgpa;

        void getPercentage() {
            cout << "Percentage: " << ((12 * cgpa) - 25) << " %" << endl;
        }
 };

int main() {
    Student s1;
    s1.cgpa = 8.29;
    s1.getPercentage();
    return 0;
}