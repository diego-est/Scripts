use std::io::{self, Write};
//use std::cmp::Ordering;


#[warn(clippy::perf, clippy::unwrap_used, clippy::pedantic)]
fn main() {

    let mut entry = String::new();

    print!("Enter a non-negative number x: ");
    io::stdout().flush().unwrap();
    io::stdin()
        .read_line(&mut entry)
        .expect("Failed to read line");
    let mut x: u128 = match entry.trim().parse() {
        Ok(num) => num,
        Err(_) => panic!("Not a non-negative number."),
    };
    entry = "".to_string();

    print!("Enter a positive number y: ");
    io::stdout().flush().unwrap();
    io::stdin()
        .read_line(&mut entry)
        .expect("Failed to read line");
    let mut y: u128 = match entry.trim().parse() {
        Ok(num) => num,
        Err(_) => panic!("Not a positive number."),
    };

    while x%y != 0 {
        let res = x%y;
        x = y;
        y = res;
    }
    println!("Largest common divisor: {y}");

}
