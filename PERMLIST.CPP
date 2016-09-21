#include "LIST.CPP"
 
void print_entry(int &x)
{
   cout << x << " ";
}
 
void process_permutation(List < int > &permutation)
/* 
 
Pre:  permutation contains a permutation in linked form.
Post: The permutation has been printed to the terminal.
 
*/
{
   permutation.traverse(print_entry);
   cout << endl;
}
 
void permute(int new_entry, int degree, List<int> &permutation)
/* 
 
Pre:  permutation contains a permutation with entries in positions 1 
     through new_entry - 1.
Post: All permutations with degree entries, built from the given
      permutation, have been constructed and processed.
Uses: permute recursively, process_permutation, and List functions.
 
*/
{
   for (int current = 0; current < permutation.size() + 1; current++) {
      permutation.insert(current, new_entry);
      if (new_entry == degree)
         process_permutation(permutation);
      else
         permute(new_entry + 1, degree, permutation);
      permutation.remove(current, new_entry);
   }
}
 
void main()
/* 
 
Pre:  None.
Post: All permutations of a user supplied degree are printed to the terminal.
 
*/
{
   int degree;
   List<int> permutation;
   cout << "Number of elements to permute? ";
   cin >> degree;
   if (degree < 1)
      cout << "Number must be at least 1." << endl;
   else permute(1, degree, permutation);
}
