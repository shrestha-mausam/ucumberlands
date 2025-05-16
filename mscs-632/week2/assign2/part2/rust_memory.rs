// Rust program demonstrating ownership and borrowing
use std::vec::Vec;

struct MemoryDemo {
    data: Vec<i32>,
    id: i32,
}

impl MemoryDemo {
    // Constructor
    fn new(id: i32) -> Self {
        println!("Creating MemoryDemo instance {}", id);
        MemoryDemo {
            data: Vec::new(),
            id,
        }
    }

    // Method that takes ownership
    fn add_data(&mut self, value: i32) {
        self.data.push(value);
    }

    // Method that borrows data
    fn print_data(&self) {
        println!("Data in instance {}: {:?}", self.id, self.data);
    }

    // Method that consumes self
    fn get_sum(self) -> i32 {
        println!("Consuming instance {}", self.id);
        self.data.iter().sum()
    }
}

// Function demonstrating ownership transfer
fn ownership_demo() {
    println!("\nOwnership Demo:");
    let mut demo = MemoryDemo::new(1);
    demo.add_data(1);
    demo.add_data(2);
    
    // Transfer ownership to a new variable
    let demo2 = demo;
    // demo is no longer valid here
    // demo.add_data(3); // This would cause a compile error
    
    demo2.print_data();
}

// Function demonstrating borrowing
fn borrowing_demo() {
    println!("\nBorrowing Demo:");
    let mut demo = MemoryDemo::new(2);
    demo.add_data(1);
    demo.add_data(2);
    
    // Multiple immutable borrows
    let data1 = &demo;
    let data2 = &demo;
    data1.print_data();
    data2.print_data();
    
    // Mutable borrow
    let data3 = &mut demo;
    data3.add_data(3);
    data3.print_data();
}

// Function demonstrating lifetime
fn lifetime_demo() {
    println!("\nLifetime Demo:");
    let mut demo = MemoryDemo::new(3);
    demo.add_data(1);
    
    {
        let borrowed = &demo;
        borrowed.print_data();
    } // borrowed goes out of scope here
    
    // Can still use demo here
    demo.add_data(2);
    demo.print_data();
}

fn main() {
    println!("Rust Memory Management Demo");
    println!("--------------------------");

    // Basic ownership demonstration
    let mut demo = MemoryDemo::new(0);
    demo.add_data(1);
    demo.add_data(2);
    demo.add_data(3);
    
    // Print the data (borrowing)
    demo.print_data();
    
    // Get sum (consumes demo)
    let sum = demo.get_sum();
    println!("Sum: {}", sum);
    
    // This would cause a compile error because demo was consumed
    // demo.print_data();  // Uncomment to see the error
    
    // Demonstrate ownership transfer
    ownership_demo();
    
    // Demonstrate borrowing
    borrowing_demo();
    
    // Demonstrate lifetimes
    lifetime_demo();
} 