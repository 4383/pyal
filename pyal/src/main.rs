extern crate hyper_tls;
extern crate hyper;
use std::io::{self, Write};
use hyper::Client;
use hyper::rt::{self, Future, Stream};
use hyper_tls::HttpsConnector;


fn main() {
    println!("hellp, world!");
    let https = HttpsConnector::new(4).unwrap();
    let uri = "https://api.github.com/repos/cpython/python/branches".parse()
        .unwrap();
    let client = Client::builder().build::<_, hyper::Body>(https);
    rt::run(client
        .get(uri)
        .map(|res| {
            println!("Response: {}", res.status());
        })
        .map_err(|err| {
            println!("Error: {}", err);
        }));
    println!("test");
}
