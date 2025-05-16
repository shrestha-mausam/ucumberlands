// JavaScript program demonstrating type system, scopes, and closures

// Closure demonstration
function createCounter() {
    let count = 0;  // Block-scoped variable
    
    return function() {
        count += 1;
        return count;
    };
}

// Type coercion demonstration
function processData(data) {
    // JavaScript's type coercion
    if (typeof data === 'number') {
        return data * 2;
    } else if (typeof data === 'string') {
        return data.toUpperCase();
    } else {
        return "Unknown type";
    }
}

// Test the programs
console.log("Counter values:");
const counter = createCounter();
console.log([counter(), counter(), counter()]);

console.log("\nType coercion results:");
const testValues = [42, "hello", 3.14, true];
testValues.forEach(value => {
    const result = processData(value);
    console.log(`Input: ${value} (${typeof value}) -> Output: ${result} (${typeof result})`);
}); 