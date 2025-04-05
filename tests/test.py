import sys
import os

# Add the solution folder to the Python path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from solutions.solution import spiralOrder

def print_list(arr):
    print("[", end="")
    print(", ".join(map(str, arr)), end="")
    print("]")

def run_test_cases():
    test_cases = [
        [[1, 2, 3], [4, 5, 6], [7, 8, 9]],
        [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]],
        [[1, 2], [3, 4]],
        [[1]],
        [],
        [[1], [2], [3]]
    ]

    expected_results = [
        [1, 2, 3, 6, 9, 8, 7, 4, 5],
        [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7],
        [1, 2, 4, 3],
        [1],
        [],
        [1, 2, 3]
    ]

    passed = 0
    failed = 0

    for i, matrix in enumerate(test_cases):
        result = spiralOrder(matrix)
        
        print(f"Test Case {i + 1}:")
        print("Expected: ", end="")
        print_list(expected_results[i])
        print("Got:      ", end="")
        print_list(result)

        if result == expected_results[i]:
            print("✅ Passed\n")
            passed += 1
        else:
            print("❌ Failed\n")
            failed += 1

    print(f"Test Cases Passed: {passed}")
    print(f"Test Cases Failed: {failed}")
    print(f"Total Test Cases: {passed + failed}")

if __name__ == "__main__":
    run_test_cases()
