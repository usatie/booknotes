fn let_example() -> u32 {
    let x = 100;
    let mut y = 20;
    let z: u32 = 5;
    let w;
    y *= x + z;
    w = 8;
    y + w
}

// println! is not a function but a macro
// Which is the same as Python2, why Python3 chose function? why rust chose macro?
fn hello(v: u32) {
    println!("Hello World!: v = {}", v);
}

fn add(x: u32, y: u32) -> u32 {
    x + y
}

fn my_func1() {
    let n = add(10, 5);
    hello(n)
}

fn is_even(v: u32) -> bool {
    if v % 2 == 0 {
        true
    } else {
        false
    }
}

fn pred(v: u32) -> Option<u32> {
    if v == 0 {
        None
    } else {
        Some(v - 1)
    }
}

fn print_pred(v: u32) {
    match pred(v) {
        Some(w) => {
            println!("pred({}) = {}", v, w);
        }
        None => {
            println!("pred({}) is undefined", v);
        }
    }
}

fn even_odd() {
    for n in 0..10 {
        println!("{} is {}", n, if is_even(n) { "even" } else { "odd" });
    }
}

fn even_odd2() {
    let mut n = 0;
    loop {
        println!("{} is {}", n, if is_even(n) { "even" } else { "odd" });
        n += 1;
        if n >= 10 {
            break;
        }
    }
}

fn mul(x: &mut u64, y: &u64) {
    *x *= *x * *y;
}

fn my_func2() {
    let mut n = 10;
    let m = 20;
    println!("n = {}, m = {}", n, m);
    mul(&mut n, &m);
    println!("n = {}, m = {}", n, m);
}

fn app_n(f: fn(u64) -> u64, mut n: u64, mut x: u64) -> u64 {
    loop {
        if n == 0 {
            return x;
        }
        x = f(x);
        n -= 1;
    }
}

fn mul2(x: u64) -> u64 {
    x * 2
}

fn my_func3() {
    println!("app_n(mul2, 4, 3) = {}", app_n(mul2, 4, 3));
}

fn mul_x(x: u64) -> Box<dyn Fn(u64) -> u64> {
    Box::new(move |y| x * y)
}

fn my_func4() {
    let mut f = mul_x(3);
    println!("f(5) = {}", f(5));
    f = Box::new(mul2);
    println!("f(5) = {}", f(5));
}

fn main() {
    _ = let_example();
    my_func1();
    _ = is_even(10);
    print_pred(10);
    even_odd();
    even_odd2();
    my_func2();
    my_func3();
    my_func4();
}
