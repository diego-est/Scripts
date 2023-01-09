use serde_derive::Deserialize;
use std::fs;
use std::process::exit;
use toml;

#[derive(Deserialize)]
struct Config {
    ost: Entry,
}

#[derive(Deserialize)]
struct Entry {
    name: String,
    status: String,
    score: String,
    progress: u16,
    songs: u16,
}

fn main() {
    let filename = "test.toml";

    let contents = match fs::read_to_string(filename) {
        Ok(c) => c,
        Err(_) => {
            eprintln!("Could not read file `{}`", filename);
            exit(1);
        }
    };

    let data: Config = match toml::from_str(&contents) {
        Ok(d) => d,
        Err(_) => {
            eprintln!("Could not load data from `{}`", filename);
            exit(1);
        }
    };

    println!("{}", data.ost.name);
    println!("{}", data.ost.status);
    println!("{}", data.ost.progress);
    println!("{}", data.ost.score);
    println!("{}", data.ost.songs);
}
