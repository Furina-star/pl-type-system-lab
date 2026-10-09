/// Demonstrate different runtime type behaviors in Rust. (Static, Strong)

fn add_one(n: i32) -> i32 {
    n + 1
}

fn main() {

    // Demonstrate type coercion 
    println!("1. int + string");
    let x: i32 = 5;
    let y: i32 = "3".parse().unwrap();
    println!("   {}", x + y);

    // Demonstrate reassigning to a different type
    println!("2. reassign (same type only)");
    let mut v = 10;
    println!("   {}", v);
    v = 20;
    println!("   {}", v);

    // Demonstrate function with correct type
    println!("3. function with correct type");
    println!("   {}", add_one(4));

    // Demonstrate int + float (explicit cast)
    println!("4. int + float (explicit cast)");
    let f: f64 = 2.5;
    println!("   {}", x as f64 + f);
}