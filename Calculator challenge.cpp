#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string add(string num1, string num2) {
    string result = "";
    int carry = 0;
    int max_length = max(num1.length(), num2.length());
    num1 = string(max_length - num1.length(), '0') + num1;
    num2 = string(max_length - num2.length(), '0') + num2;

    for (int i = max_length - 1; i >= 0; i--) {
        int digit_sum = (num1[i] - '0') + (num2[i] - '0') + carry;
        result = char(digit_sum % 10 + '0') + result;
        carry = digit_sum / 10;
    }

    if (carry) {
        result = char(carry + '0') + result;
    }

    return result;
}

string subtract(string num1, string num2) {
    string result = "";
    int borrow = 0;
    int max_length = max(num1.length(), num2.length());
    num1 = string(max_length - num1.length(), '0') + num1;
    num2 = string(max_length - num2.length(), '0') + num2;

    for (int i = max_length - 1; i >= 0; i--) {
        int digit_diff = (num1[i] - '0') - (num2[i] - '0') - borrow;
        if (digit_diff < 0) {
            digit_diff += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }
        result = char(digit_diff + '0') + result;
    }

    return result;
}

string multiply(string num1, string num2) {
    string result = "0";
    int max_length = num1.length() + num2.length();
    num1 = string(max_length - num1.length(), '0') + num1;
    num2 = string(max_length - num2.length(), '0') + num2;

    for (int i = num1.length() - 1; i >= 0; i--) {
        string temp = "";
        int carry = 0;
        for (int j = num2.length() - 1; j >= 0; j--) {
            int digit_prod = (num1[i] - '0') * (num2[j] - '0') + carry;
            temp = char(digit_prod % 10 + '0') + temp;
            carry = digit_prod / 10;
        }
        if (carry) {
            temp = char(carry + '0') + temp;
        }
        temp += string(num1.length() - i - 1, '0');
        result = add(result, temp);
    }

    return result;
}

pair<string, string> divide(string num, string den) {
    string quotient = "";
    string remainder = "0";

    for (int i = 0; i < num.length(); ++i) {
        remainder += num[i];
        int digit = 0;
        while (den <= remainder) {
            remainder = subtract(remainder, den);
            digit++;
        }
        quotient += to_string(digit);
    }

    // Remove leading zeros
    quotient = quotient.erase(0, min(quotient.find_first_not_of('0'), quotient.size() - 1));
    remainder = remainder.erase(0, min(remainder.find_first_not_of('0'), remainder.size() - 1));

    return { quotient, remainder };
}

int main() {
    char choice;
    do {
        string num1, num2;
        cout << "first number: ";
        cin >> num1;
        cout << "second number: ";
        cin >> num2;

        cout << "addition: " << add(num1, num2) << endl;
        cout << "subtraction: " << subtract(num1, num2) << endl;
        cout << "multiplication: " << multiply(num1, num2) << endl;

        if (num2 != "0") {
            auto result = divide(num1, num2);
            cout << "division (quotient thingy): " << result.first << endl;
            cout << "division (remainder thingy): " << result.second << endl;
        }
        else {
            cout << "cant divide by zero." << endl;
        }

        cout << "wanna go again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
