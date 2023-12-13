fn fact(n: u32) -> u32 {
    match n {
        0 => std::process::exit(1),
        1 => 1,
        _ => n * fact(n - 1),
    }
}

fn main() {
    for i in 1..12 {
        println!("{}", fact(i));
    }
}
