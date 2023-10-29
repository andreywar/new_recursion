#pragma once
#include <iostream>
using namespace std;

void hanoy(int disks_count, int first_kernel, int second_kernel, int third_kernel)
{
    if (disks_count == 0)
        return;
    hanoy(disks_count - 1, first_kernel, third_kernel, second_kernel);
    cout << first_kernel << " -- > " << third_kernel << endl;
    hanoy(disks_count - 1, second_kernel, first_kernel, third_kernel);
    return;
}

int hanoy_definition()
{
    cout << "Enter count of disks: ";
    int disks_count;
    cin >> disks_count;
    hanoy(disks_count, 1, 2, 3);
    cout << endl;
    return 0;
}