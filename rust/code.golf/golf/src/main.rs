use std::env; // to access arguments

// code.golf functions begin here:

//fn twelve_days() {}
//fn bottles_of_beer() {}

fn abundant() {
    for i in 0..201 {
        if (1..i).into_iter().filter(|x| i % x == 0).sum::<u64>() > i {
            println!("{i}");
        }
    }
}

fn abundant_long() {
    for i in 0..1001 {
        if (1..i).into_iter().filter(|x| i % x == 0).sum::<u64>() > i {
            println!("{i}");
        }
    }
}

//fn arabic_roman() {}
//fn arrows() {}
//fn ascii_table() {}
//fn bf() {}
//fn catalan_numbers() {}
//fn catalan_const() {}
//fn christmas_tree() {}

fn collatz() {
    fn calculator(n: u64, iteration: &mut u64) -> u64 {
        *iteration += 1;
        match n {
            0 | 1 => 1,
            n if n % 2 == 0 => calculator(n / 2, iteration),
            _ => calculator(n * 3 + 1, iteration),
        };
        *iteration - 1
    }

    for i in 1..1001 {
        let mut count: u64 = 0;
        println!("{}", calculator(i, &mut count));
    }
}

//fn css_colors() {}
//fn cubes() {}
//fn diamonds() {}

fn divisors() {
    for i in 1u64..101 {
        (1..=i)
            .into_iter()
            .filter(|&x| i % x == 0)
            .for_each(|m| print!("{m} "));
        println!();
    }
}

fn emirp() {
    fn prime(n: u64) -> bool {
        (1..n / 2)
            .into_iter()
            .filter(|x| n % x == 0)
            .collect::<Vec<u64>>()
            .len()
            < 2
    }
    for i in 1..1001 {
        let rv: u64 = i
            .to_string()
            .chars()
            .rev()
            .collect::<String>()
            .parse()
            .unwrap();

        if rv != i && prime(i) && prime(rv) {
            println!("{i}");
        }
    }
}

fn emirp_long() {
    fn prime(n: u64) -> bool {
        (1..n / 2)
            .into_iter()
            .filter(|&x| n % x == 0)
            .collect::<Vec<u64>>()
            .len()
            < 2
    }
    for i in 1..10001 {
        let rv: u64 = i
            .to_string()
            .chars()
            .rev()
            .collect::<String>()
            .parse()
            .unwrap();

        if rv != i && prime(i) && prime(rv) {
            println!("{i}");
        }
    }
}

//fn emojify() {}

fn evil() {
    for i in 1u8..51 {
        if i.count_ones() % 2 == 0 {
            println!("{i}")
        }
    }
}

fn evil_long() {
    for i in 1u64..1001 {
        if i.count_ones() % 2 == 0 {
            println!("{i}")
        }
    }
}

fn fibonacci() {
    fn fib(n: u32) -> u32 {
        match n {
            0 => 0,
            1 => 1,
            _ => fib(n - 1) + fib(n - 2),
        }
    }
    for i in 0..31 {
        println!("{}", fib(i));
    }
}

fn fizzbuzz() {
    for i in 1u16..101 {
        let mut out = String::new();

        if i % 3 == 0 {
            out += "Fizz"
        }
        if i % 5 == 0 {
            out += "Buzz"
        }

        if out.is_empty() {
            println!("{i}")
        } else {
            println!("{out}")
        }
    }
}

fn foofizzbuzzbar() {
    for i in 1u16..1001 {
        let mut out = String::new();

        if i % 2 == 0 {
            out += "Foo"
        }
        if i % 3 == 0 {
            out += "Fizz"
        }
        if i % 5 == 0 {
            out += "Buzz"
        }
        if i % 7 == 0 {
            out += "Bar"
        }

        if out.is_empty() {
            println!("{i}")
        } else {
            println!("{out}")
        }
    }
}

//fn fractions() {}
//fn g_o_l() {}

fn happy() {
    fn dc(n: u32, vec: Vec<u32>) -> Vec<u32> {
        n.to_string()
            .chars()
            .map(|d| d.to_digit(10).unwrap().pow(2))
            .fold(0, |acc, elem| acc * 10 + elem)
    }
    for i in 1u32..201 {
        let mut ints = vec![i];
        println!("{}", dc(i, &mut ints));
    }
}

//fn happy_long() {}
//fn hexdump() {}
//fn intersection() {}
//fn inventory() {}
//fn isbn() {}
//fn jacobi() {}
//fn kolakoski() {}
//fn kolakoski_seq() {}
//fn leap() {}
//fn levenshtein() {}
//fn leyland() {}
//fn looknsay() {}
//fn lucky_numbers() {}
//fn lucky_tickets() {}
//fn maze() {}
//fn morse_dec() {}
//fn morse_enc() {}
//fn music_chords() {}
//fn niven() {}
//fn niven_long() {}
//fn num_spiral() {}
//fn odious() {}
//fn odious_long() {}
//fn ordinal() {}
//fn pangram() {}
//fn pascal_triangle() {}
//fn pernicious_numbers() {}
//fn pernicious_long() {}
//fn poker() {}
//fn prime() {}
//fn prime_long() {}
//fn proximity_grid() {}
//fn qr_decoder() {}
//fn quine() {}
//fn recaman() {}
//fn repeating_decimals() {}
//fn reverse_polish() {}
//fn rpssp() {}
//fn roman_arabic() {}
//fn rule_110() {}
//fn seven_segment() {}
//fn sierpinski() {}
//fn smith() {}
//fn spelling() {}
//fn star_wars() {}
//fn sudoku() {}
//fn sudoku_v2() {}
//fn time_distance() {}
//fn tongue() {}
//fn us() {}
//fn vampire() {}
//fn van_eck() {}
//fn zodiac() {}
//fn gamma() {}
//fn lambda() {}
//fn pi() {}
//fn tau() {}
//fn phi() {}
//fn root2() {}
//fn euler() {}

fn main() {
    let args: Vec<String> = env::args().collect();
    let hole_labels: Vec<(&str, fn())> = vec![
        //("12days", twelve_days),
        //("99bottles", bottles_of_beer),
        ("abundant", abundant),
        ("abundant-long", abundant_long),
        //("arabic-to-roman", arabic_roman),
        //("arrows", arrows),
        //("ascii-table", ascii_table),
        //("brainfuck", bf),
        //("Catalan-numbers", catalan_numbers),
        //("Catalan-constant", catalan_const),
        //("christmas-tree", christmas_tree),
        ("collatz", collatz),
        //("css", css_colors),
        //("cubes", cubes),
        //("diamonds", diamonds),
        ("divisors", divisors),
        ("emirp", emirp),
        ("emirp-long", emirp_long),
        //("emojify", emojify),
        ("evil", evil),
        ("evil-long", evil_long),
        ("Fibonacci", fibonacci),
        ("FizzBuzz", fizzbuzz),
        ("FooFizzBuzzBar", foofizzbuzzbar),
        //("fractions", fractions),
        //("game-of-life", g_o_l),
        ("happy", happy),
        //("happy-long", happy_long),
        //("hexdump", hexdump),
        //("intersection", intersection),
        //("inventory-sequence", inventory),
        //("ISBN", isbn),
        //("Jacobi-symbol", jacobi),
        //("Kolakoski-constant", kolakoski),
        //("Kolakoski-sequence", kolakoski_seq),
        //("leap", leap),
        //("Levenshtein", levenshtein),
        //("Leyland", leyland),
        //("look-and-say", looknsay),
        //("lucky-numbers", lucky_numbers),
        //("lucky-tickets", lucky_tickets),
        //("maze", maze),
        //("morse-decoder", morse_dec),
        //("morse-encoder", morse_enc),
        //("musical-chords", music_chords),
        //("Niven", niven),
        //("Niven-long", niven_long),
        //("number-spiral", num_spiral),
        //("odious", odious),
        //("odious-long", odious_long),
        //("ordinal-numbers", ordinal),
        //("pangram-grep", pangram),
        //("Pascal-triangle", pascal_triangle),
        //("pernicious-numbers", pernicious_numbers),
        //("pernicious-long", pernicious_long),
        //("poker", poker),
        //("prime", prime),
        //("prime-long", prime_long),
        //("proximity-grid", proximity_grid),
        //("QR-decoder", qr_decoder),
        //("Quine", quine),
        //("Recaman", recaman),
        //("repeating-decimals", repeating_decimals),
        //("reverse-polish", reverse_polish),
        //("rock-papers-scissors-spock", rpssp),
        //("roman-to-arabic", roman_arabic),
        //("rule110", rule_110),
        //("seven-segment", seven_segment),
        //("Sierpinski-triangle", sierpinski),
        //("Smith-numbers", smith),
        //("spelling-numbers", spelling),
        //("Star-Wars-crawl", star_wars),
        //("sudoku", sudoku),
        //("sudokuv2", sudoku_v2),
        //("time-distance", time_distance),
        //("tongue-twister", tongue),
        //("US", us),
        //("vampire-numbersr", vampire),
        //("Van-Eck-sequence", van_eck),
        //("zodiac-signs", zodiac),
        //("Euler-Mascheroni", gamma),
        //("Conway", lambda),
        //("pi", pi),
        //("tau", tau),
        //("golden-ratio", phi),
        //("Pythagoras", root2),
        //("Euler", euler),
    ];
    if args.len() == 1 {
        println!("Error: No hole specified.");
        println!("The holes available are:\n");
        for i in &hole_labels {
            println!("\t{}", i.0);
        }
        panic!("To view a hole: golf {{HOLE}}");
    }

    if args.len() == 2 {
        let index = hole_labels
            .iter()
            .position(|&r| {
                return r.0
                    == args
                        .get(1)
                        .expect("This literally shouldn't be possible")
                        .as_str();
            })
            .expect("Hole not found");
        hole_labels
            .get(index)
            .expect("Error indexing hole tuples array")
            .1();
    }
    //        "-h" | "--help" | "help" => {
    //            println!("");
    //            println!("The holes available are:\n");
    //            for i in &hole_labels {
    //                println!("\t{}", i.0)
    //            }
}
