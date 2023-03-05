fn abundant(n: u64) -> bool {
    (1..n).into_iter().filter(|&x| n % x == 0).sum::<u64>() > n
}

fn main() {
    for i in 0..1001 {
        if abundant(i) {
            println!("{i}");
        }
    }
}
