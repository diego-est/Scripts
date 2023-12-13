use std::fs;
use std::iter::zip;
use std::process::exit;
use std::collections::HashMap;

#[warn(clippy::perf, clippy::unwrap_used, clippy::expect_used, clippy::pedantic)]
fn main() {
    let file_path = "data/mini.toml";
    let contents = if let Ok(c) = fs::read_to_string(file_path) {
        c
    } else {
        eprintln!("Could not read file `{file_path}`");
        exit(1);
    };

    let data: HashMap<String, String> = if let Ok(d) = toml::from_str(&contents) {
        d
    } else {
        eprintln!("Unable to load data from `{file_path}`");
        exit(1);
    };

    let test_string = "Test";
    let mut str_vec: Vec<Vec<&str>> = Vec::new();
    test_string.chars().for_each(|x| {
        let x = x.to_string();
        if let Some(value) = data.get(&x) {
            str_vec.push(value.split_terminator('\n').collect());
        }
    });
    //let sum = str_vec.iter().fold(vec!["", "", "", ""], |vec, x| {
    //    vec.iter().zip(x).map(|(j, k)| {
    //        (j, k).into_iter().collect()
    //    //    let x = j.to_string() + k;
    //    //    x.chars()
    //    })
    //});
    //let empty_vec = vec!["", "", "", ""];
    let strong = str_vec.iter().map(|x| {
        zip(x, x).next().unwrap()
    });
    println!("{strong:#?}");

}
