#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Student {
private:
    string courseName;
    int credit;
    double examScore;
    double assignmentScore;

public:
    // Constructors
    Student() {}
    Student(string courseName, int credit, double examScore, double assignmentScore)
        : courseName(courseName), credit(credit), examScore(examScore), assignmentScore(assignmentScore) {}

    // Methods
    double calcFinalScore() {
        return (examScore * 0.6) + (assignmentScore * 0.4);
    }

    bool isPassed() {
        return calcFinalScore() >= 60;
    }

    // Getters and Setters
    string getCourseName() { return courseName; }
    int getCredit() { return credit; }
    double getExamScore() { return examScore; }
    double getAssignmentScore() { return assignmentScore; }

    void setCourseName(string name) { courseName = name; }
    void setCredit(int cr) { credit = cr; }
    void setExamScore(double score) { examScore = score; }
    void setAssignmentScore(double score) { assignmentScore = score; }
};

class Car {
protected:
    const int gasCapacity;
    int currentGas;

public:
    Car(int capacity) : gasCapacity(capacity), currentGas(capacity) {}

    void drive(int distance) {
        int gasUnits = distance / 5;
        currentGas -= gasUnits;
        if (currentGas <= 0) {
            cout << "The car traveled " << (distance - (gasUnits * 5)) << " units and ran out of gas." << endl;
        }
    }

    void fillGas() {
        currentGas = gasCapacity;
    }

    string toString() {
        return "Gas Capacity: " + to_string(gasCapacity) + ", Current Gas: " + to_string(currentGas);
    }

    // Getters and Setters
    int getGasCapacity() { return gasCapacity; }
    int getCurrentGas() { return currentGas; }
    void setCurrentGas(int gas) { currentGas = gas; }
};

class Lamborghini : public Car {
private:
    double gasInefficiency;

public:
    Lamborghini(int capacity, double inefficiency) : Car(capacity), gasInefficiency(inefficiency) {}

    void drive(int distance) {
        int gasUnits = distance / 5;
        int remainingDistance = distance - (gasUnits * 5);

        if (currentGas <= 0) {
            cout << "The car had enough gas to travel " << (distance - remainingDistance) << " units.";
            cout << "There are " << remainingDistance << " units left to travel because it ran out of gas." << endl;
            currentGas -= gasUnits;
            cout << "The car ran out of gas after traveling " << (distance - remainingDistance) << " units." << endl;
            currentGas = 0; // Ensuring that the gas doesn't go negative
        }
    }


};

double calcAverageScore(int numScores) {
    int total = 0;
    int count = 0;
    srand(time(0));

    for (int i = 0; i < numScores; i++) {
        int score = rand() % 101;
        if (score >= 40) {
            total += score;
            count++;
        }
    }

    if (count == 0)
        return 0.0;
    else
        return static_cast<double>(total) / count;
}

char toLetterScore(double score) {
    if (score >= 90)
        return 'A';
    if (score >= 80)
        return 'B';
    if (score >= 70)
        return 'C';
    if (score >= 60)
        return 'D';
        return 'F';
}

bool isPalindrome(string str) {
    if (str.length() <= 1)
        return true;
    if (str.front() != str.back())
        return false;
    return isPalindrome(str.substr(1, str.length() - 2));
}


void printCar(Car car) {
    cout << car.toString() << endl;
}

int main() {
    // Task 1
    int numScores = 5;
    double average = calcAverageScore(numScores);
    cout << "Average score: " << fixed << setprecision(2) << average << endl;

    // Task 2
    double score = 85.5;
    cout << "Letter score: " << toLetterScore(score) << endl;

    // Task 3
    Student student("Math", 3, 75.5, 80.0);
    cout << "Final score: " << student.calcFinalScore() << endl;
    cout << "Passed: " << (student.isPassed() ? "Yes" : "No") << endl;

    // Task 4
    string inputString;
    cout << "Enter a string: ";
    cin >> inputString;
    cout << inputString << " is " << (isPalindrome(inputString) ? "a palindrome." : "not a palindrome.") << endl;

    // Task 5 and 6
    // This function prints information about a Car.
    // Since Lamborghini is a subclass of Car, it can be passed to this function.
    // However, when we pass a Lamborghini object, it's treated as a Car object due to inheritance.
    // This is known as object slicing, where the derived class part of the object is "sliced" off,
    // leaving only the base class part.
    // Even though we pass a Lamborghini object, only Car-specific attributes and behavior are retained.
    // When we call toString() inside this function, it calls the Car class's toString() method.
    // However, since Lamborghini is derived from Car, it overrides the toString() method.
    // So, the overridden toString() method of the Lamborghini class is invoked due to polymorphism.
    Car myCar(50);
    Lamborghini myLambo(50, 5.0);
    printCar(myLambo); // Prints the details of the Lamborghini
    return 0;
}
