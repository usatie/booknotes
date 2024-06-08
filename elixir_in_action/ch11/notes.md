# 11.1 OTP applications
## 11.1.1 Creating applications with the mix tool
- `application resource file`
  1. The application name and version, and description
  2. A list of application modules
  3. A list of application dependencies (which must be applications themselves)
  4. An optional application-callback module
```
$ mix new hello_world --sup
$ cd hello_world
$ iex -S mix
Application.started_application()
$ cat mix.exs
```
