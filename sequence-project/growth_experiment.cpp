// ============================================================================
// CS32 P01 Part 2: the growth-factor experiment
//
// Implement measure_growth below. Then run   make experiment && ./experiment
// to see your results as a table.
// ============================================================================

#include "growth_experiment.h"
#include "Vector.h"

// Sets Vector<int>::growth_factor to factor, then push_backs n ints into an
// empty Vector<int>, watching what happens, and returns the GrowthStats (see
// growth_experiment.h for what each field means). Before returning, puts
// growth_factor back to the value it had when measure_growth was called.
//
// Measure by watching a real Vector<int>: push_back the elements one at a time
// and use size() and capacity() to see when the buffer grows and how many
// elements it had to copy. Do not compute the answers from the growth formula
// alone.
GrowthStats measure_growth(double factor, std::size_t n) {
    Vector<int>::growth_factor = factor;
    Vector<int> a;
    GrowthStats final;
    int reallocations = 0;
    int elements_copied = 0;
    std::size_t temp;
    for(int i = 0; i < n; i++)
    {
        temp = a.capacity();
        a.push_back(1);
        if(a.capacity() != temp)
        {
            reallocations++;
            elements_copied += a.size();
        }
    }
    final.reallocations = reallocations;
    final.elements_copied = elements_copied;
    final.final_capacity = a.capacity();
    return final;
}
