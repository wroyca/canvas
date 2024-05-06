module canvas;

namespace canvas
{
  void
  say_hello (const string_view& n)
  {
    println("hello, {}!", n);
  }
}
