fn collatz(n: u64, count: &mut u64) -> u64 {
    *count += 1;
    match n {
        0 => std::process::exit(1),
        1 => 1,
        n if n % 2 == 0 => collatz(n / 2, count),
        _ => collatz(n * 3 + 1, count),
    };
    *count - 1
}

fn main() {
    for i in 1..1001 {
        let mut count: u64 = 0;
        println!("{}", collatz(i, &mut count));
    }
}
