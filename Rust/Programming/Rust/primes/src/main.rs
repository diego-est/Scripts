use num::integer::Roots;

fn is_prime(x: u128) -> bool {
    let limit = x.sqrt();
    let mut flag = true;
    
    for i in 2..=limit {
        if x%i == 0 {
            flag = false;
        }
    }
    return flag;
}

fn main() {
    let max = u128::MAX;
    for i in 2..max {
        if is_prime(i) {
            println!("{i}");
        }
    }
}
