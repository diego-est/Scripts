fn evil(n: u16) -> bool {
    n.count_ones() % 2 == 0
}

fn main() {
    for i in 0..1001 {
        if evil(i) {
            println!("{i}");
        }
    }
}
