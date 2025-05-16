# Python program demonstrating type system, scopes, and closures

def create_counter():
    count = 0  # This variable is in the closure's scope
    
    def increment():
        nonlocal count  # Explicitly declare we're using the outer scope
        count += 1
        return count
    
    return increment

# Dynamic typing demonstration
def process_data(data):
    if isinstance(data, (int, float)):
        return data * 2
    elif isinstance(data, str):
        return data.upper()
    else:
        return "Unknown type"

# Test the programs
if __name__ == "__main__":
    # Closure demonstration
    counter = create_counter()
    print("Counter values:", [counter() for _ in range(3)])
    
    # Dynamic typing demonstration
    test_values = [42, "hello", 3.14, True]
    print("\nDynamic typing results:")
    for value in test_values:
        result = process_data(value)
        print(f"Input: {value} ({type(value).__name__}) -> Output: {result} ({type(result).__name__})") 