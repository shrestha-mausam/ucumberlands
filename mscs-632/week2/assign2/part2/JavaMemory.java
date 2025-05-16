// Java program demonstrating garbage collection
import java.util.ArrayList;
import java.util.List;

public class JavaMemory {

    static class MemoryDemo {
        private List<Integer> data;
        private static int instanceCount = 0;
        private final int id;
    
        public MemoryDemo() {
            this.data = new ArrayList<>();
            this.id = ++instanceCount;
            System.out.println("Created MemoryDemo instance " + id);
        }
    
        public void addData(int value) {
            data.add(value);
        }
    
        public void printData() {
            System.out.println("Data in instance " + id + ": " + data);
        }
    
        @Override
        protected void finalize() {
            System.out.println("Garbage collecting MemoryDemo instance " + id);
        }
    }

    public static void main(String[] args) {
        // Create and use objects
        MemoryDemo demo1 = new MemoryDemo();
        demo1.addData(1);
        demo1.addData(2);
        demo1.printData();

        // Create another object
        MemoryDemo demo2 = new MemoryDemo();
        demo2.addData(3);
        demo2.addData(4);
        demo2.printData();

        // Set references to null to make objects eligible for garbage collection
        demo1 = null;
        demo2 = null;

        // Request garbage collection (note: this is just a suggestion to the JVM)
        System.gc();

        // Create a large number of objects to demonstrate garbage collection
        System.out.println("\nCreating many objects to demonstrate garbage collection:");
        for (int i = 0; i < 1000; i++) {
            MemoryDemo temp = new MemoryDemo();
            temp.addData(i);
            // temp will be eligible for garbage collection after each iteration
        }

        // Request garbage collection again
        System.gc();

        // Sleep to allow time for garbage collection to occur
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
} 