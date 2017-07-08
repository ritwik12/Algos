/*
    Bucket sort
    ----------
    Bucket sort, or bin sort, is a sorting algorithm that works by distributing the
    elements of an array into a number of buckets. Each bucket is then sorted
    individually using insertion sort (or some other sorting algorithm, including
    bucket sort itself).

    Time complexity
    ---------------
    O(N), where N is the number of elements.

    Space complexity
    ----------------
    O(N), where N is the number of elements.
    
*/

#include <iostream>
#include <vector>
#include <array>
#include "SortingUtils.hpp"

using namespace std;
const int MAX_BUCKETS = 99999; //  maximum number of Buckets

void bucket_sort (vector<int>& values, const int order, const bool to_show_state)
{
    size_t i, j;
    array<int, MAX_BUCKETS > buckets ; //Create MAX_BUCKETS number of empty buckets  
    for (int i = 0; i < MAX_BUCKETS; ++i) 
	buckets[i] = 0;
	//Increment the number of times each element is present in the input array. 
        //Insert them in the buckets
	for (int i = 0; i < values.size(); ++i)  
	    ++buckets[values[i]];
	    //Sort using insertion sort and concatenate 
	    for (int i = 0, j = 0; j < MAX_BUCKETS; ++j)  
		for (int k = buckets[j]; k > 0; --k) 
		values[i++] = j;
		       
                if (to_show_state)
                   display_state(values);
}

int main() {
    size_t size;
    get_input_size(size);

    vector<int> values(size);
    get_input_values(values, size);

    int order;
    string order_text;
    get_order(order, order_text);

    bool to_show_state;
    get_whether_to_show_state(to_show_state);

    bucket_sort(values, order, to_show_state);

    cout << "\nThe values in " << order_text << " order are:\n";
    display_state(values);

    return 0;
}
