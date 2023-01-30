struct Apple {}
struct Gold {}
struct FullStomach {}

fn get_gold(_a: Apple) -> Gold {
    Gold {}
}

fn get_full_stomach(_a: Apple) -> FullStomach {
    FullStomach {}
}

fn my_func5() {
    let a = Apple {};
    _ = get_gold(a);
    // This is compile error because apple is already moved!
    // _ = get_full_stomach(a);
}
fn main() {
    my_func5();
}
