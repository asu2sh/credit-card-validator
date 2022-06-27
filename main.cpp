#include <iostream>
#include <string>

bool isNumberString(const std::string& s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int main() {
    std::string ccNumber;
    
    std::cout << "This program uses the Luhn Algorigthm to validate a CC number." 
              << "\n The program works for all popular cards like Visa, AmericanExpress, MasterCard."
              << std::endl;
              
    std::cout << "You can enter 'exit' anytime to quit." << std::endl;
    
    while (true) {
        
        std::cout << "Please enter a CC number to validate: ";
        std::cin >> ccNumber;
        
        if (ccNumber == "exit")
            break;
        
        else if (!isNumberString(ccNumber)) {
            std::cout << "Bad input! ";
            continue;
        }
            
        int len = ccNumber.length();
        int doubleEvenSum = 0;   
        
        for (int i = len - 2; i >= 0; i = i - 2) {
            int dbl = ((ccNumber[i] - 48) * 2);
            if (dbl > 9) {
                dbl = (dbl / 10) + (dbl % 10);
            }
            doubleEvenSum += dbl;
        }
        
        for (int i = len - 1; i >= 0; i = i - 2) {
            doubleEvenSum += (ccNumber[i] - 48);
        }
        
        std::cout << (doubleEvenSum % 10 == 0 ? "Valid!" : "Invalid!") << std::endl;
        
        continue;        
    }

    return 0;
}
