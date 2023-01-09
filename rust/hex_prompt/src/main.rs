use rand::Rng;
use std::cmp::Ordering;
use std::io::{self, Write};

fn main() {
    let secret_number = rand::thread_rng().gen_range(0..=255);

    println!(
        "What is {} in decimal?",
        format!("{:#X}", secret_number)
    );

    loop {
        print!("> ");
        io::stdout().flush().unwrap();

        let mut guess = String::new();

        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Wrong."),
            Ordering::Greater => println!("Wrong."),
            Ordering::Equal => {
                break;
            }
        }
    }
}
