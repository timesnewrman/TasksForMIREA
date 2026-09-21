#include <iostream>
#include <bits/stdc++.h>

int n;
    std::cin >> n;
    std::cout << '\n' << '\n';
   
    b = 1;
    int c = 1;
   
    for (int i = 1; i <= n; ++i){
        b *= i;
        c = b * c;
    }
   
    std::cout << c;
   
    return 0;
