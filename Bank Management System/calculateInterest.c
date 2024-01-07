#include "main.h"

// Function to calculate simple interest
float calculateInterest(float time, float principalAmount, int rate)
{
    // Simple Interest formula
    float simpleInterest = (rate * time * principalAmount) / 100.0;
    return simpleInterest;
}
