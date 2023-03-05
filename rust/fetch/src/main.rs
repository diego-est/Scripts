extern crate colored;
use colored::Colorize;

fn main() {
    let username = "Void";
    let hostname = "The Void";
    let distro = "Void Linux";
    let shell = "zsh";
    let terminal = "kitty";
    let wm = "i3";

    println!("\n  {}@{}", username.yellow().bold(), hostname.yellow().bold());
    println!("  {}~ {}", "Distro  ".green().bold(), distro.green().bold());
    println!("  {}~ {}", "Shell   ".cyan().bold(), shell.cyan().bold());
    println!("  {}~ {}", "Term    ".blue().bold(), terminal.blue().bold());
    println!("  {}~ {}", "WM      ".purple().bold(), wm.purple().bold());
    println!("  {}{}{}{}{}{}", "▅▅▅".red(), "▅▅▅".yellow(), "▅▅▅".green(), "▅▅▅".cyan(), "▅▅▅".blue(), "▅▅▅".purple());
}
