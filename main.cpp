#include <chrono>
#include <iostream>
#include <stdlib.h>

float halfByDivision(float x);
float halfByMultiplication(float x);
float divide(float x, float y);
float divideByMultiplication(float x, float y);
float multiply(float x, float y);

int main() {
  // Setup for testing
  typedef std::chrono::high_resolution_clock Clock;
  constexpr size_t TestNumberCount = 100'000;
  float inputs[TestNumberCount] = {};
  float divider[TestNumberCount] = {};
  float sum = 0;

  for (size_t i = 0; i < TestNumberCount; i++) {
    inputs[i] = rand();
    divider[i] = rand();
  }

  // Compare divide and mul by constant
  auto start = Clock::now();
  for (size_t i = 0; i < TestNumberCount; i++) {
    sum += halfByDivision(inputs[i]);
  }
  auto end = Clock::now();

  std::cout << "Sum of halfByDivision: " << sum << std::endl;
  std::chrono::nanoseconds ns =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "Elapsed time: " << ns.count() << "ns \n";
  std::cout << (TestNumberCount / (double)ns.count()) << " ops/ns" << std::endl;

  sum = 0;
  start = Clock::now();
  for (size_t i = 0; i < TestNumberCount; i++) {
    sum += halfByMultiplication(inputs[i]);
  }
  end = Clock::now();

  std::cout << "Sum of halfByMultiplication: " << sum << std::endl;
  ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "Elapsed time: " << ns.count() << "ns \n";
  std::cout << (TestNumberCount / (double)ns.count()) << " ops/ns" << std::endl;

  // Compare divide and mul by variable number
  sum = 0;
  start = Clock::now();
  for (size_t i = 0; i < TestNumberCount; i++) {
    sum += multiply(inputs[i], divider[i]);
  }
  end = Clock::now();

  std::cout << "Sum of multiply: " << sum << std::endl;
  ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "Elapsed time: " << ns.count() << "ns \n";
  std::cout << (TestNumberCount / (double)ns.count()) << " ops/ns" << std::endl;

  sum = 0;
  start = Clock::now();
  for (size_t i = 0; i < TestNumberCount; i++) {
    sum += divide(inputs[i], divider[i]);
  }
  end = Clock::now();

  std::cout << "Sum of divide: " << sum << std::endl;
  ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "Elapsed time: " << ns.count() << "ns \n";
  std::cout << (TestNumberCount / (double)ns.count()) << " ops/ns" << std::endl;

  sum = 0;
  start = Clock::now();
  for (size_t i = 0; i < TestNumberCount; i++) {
    sum += divideByMultiplication(inputs[i], divider[i]);
  }
  end = Clock::now();

  std::cout << "Sum of divideByMultiplication: " << sum << std::endl;
  ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "Elapsed time: " << ns.count() << "ns \n";
  std::cout << (TestNumberCount / (double)ns.count()) << " ops/ns" << std::endl;

  // Convert long to float constant
  long longValue = 1056964608;
  float *floatValue = (float *)&longValue;
  printf("float: %f\n", *floatValue);

  // Listing example of how to use multiply instead of divide
  // Normal division
  float numeratorOne = 17;
  float denominatorOne = 8;
  float fractionOne = divide(numeratorOne, denominatorOne);
  std::cout << "fractionOne: " << fractionOne << std::endl;

  // Equivalent multiplication
  float numeratorTwo = 17;
  float denominatorTwo = 0.125f;
  float fractionTwo = multiply(numeratorTwo, denominatorTwo);
  std::cout << "fractionTwo: " << fractionTwo << std::endl;

  return 0;
}

float halfByDivision(float x) { return x / 2.f; }

float halfByMultiplication(float x) { return x * 0.5f; }

float divide(float x, float y) { return x / y; }

float divideByMultiplication(float x, float y) { return x * (1.f / y); }

float multiply(float x, float y) { return x * y; }
