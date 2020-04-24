// ParallelComputing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h> // Using this to get Sleep()
#include <omp.h> // This include is for OpenMP
#include <stdio.h>

int main()
{
    int i, displayData, inputData;
    const int scale = 254; // some scalar value
    int data[10000]; // our data to operate on

    displayData = 0;
    inputData = 0;

    // simple example of OpenMP parallel for loop to initialize data
#pragma omp parallel for private(i)
    for (i = 0; i < 10000; i++)
    {
        // Gets thread ID
        int id = omp_get_thread_num();
        data[i] = id;
        printf("Value data at %d: %d\n", i, data[i]);
    }

    // Showing the default max threads
    printf("Max thread count is: %d\n", omp_get_max_threads());

    // Request 100 threads
    omp_set_num_threads(100);

    // Check to see the max we were able to get
    printf("Max thread count is: %d\n", omp_get_max_threads());


    // OpenMP Parallel section, not using a loop. Also shows how to use the shared construct for data coherency
#pragma omp parallel shared(displayData, inputData)
    {
        int id = omp_get_thread_num();
        printf("Thread ID: %d\n", id);
        data[id] = 250;

        // Sets the code below to only run in one thread, includes an implicit barrier
#pragma omp single
        {
            for (int j = 0; j < 10000; j++)
            {
                printf("Data value at %d is: %d\n", j, data[j]);
            }
        }

// Barrier to sync all threads to do some logic (like after initializing data)
#pragma omp barrier
        if (id == 63)
        {
            data[0]++;
        }
        else
        {
            data[id]--;
        }

        // Another single section to print out the results only once
#pragma omp single
        {
            for (int j = 0; j < 100; j++)
            {
                printf("Data value at %d is: %d\n", j, data[j]);
            }
        }

        /* //This logic was removed for the example
        //This shows how threads can do independent work and share data
        // OpenMP handles locking and sharing data between threads
        if(id == 0)
        {
            printf("Waiting on data to do work...\n");
            while(inputData == 0)
            {
                Sleep(5);
            }
            displayData += inputData;
            printf("Did some computation!\n");
        }
        else
        {
            Sleep(2500);
            inputData = 100;
            while(displayData == 0)
            {
                Sleep(5);
            }
            printf("Results: %d\n", displayData);
        }
        
        */
    }


    // Large parallel for, indicating the value of i is privtate
#pragma omp parallel for private(i)
    for (i = 0; i < 10000; i++)
    {
        int id = omp_get_thread_num();
        if (i % 3 == 0)
        {
            data[i] = scale*i+796;
        }
        if (i % 2 == 1)
        {
            data[i] += 17;
            data[i] *= 2;
        }
        else
        {
            data[i] -= 27;
            data[i] *= 4;
        }
        for (int j = 0; j < 1000 * i; j++)
        {
            if (j % 2 == 0)
            {
                data[i]--;
            }
            else
            {
                data[i] -= 2;
            }
        }
        printf("Value data at %d: %d. Computed on thread: %d\n", i, data[i], id);
    }
}


