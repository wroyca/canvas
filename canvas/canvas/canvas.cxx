import canvas;

int
main (int argc, char* argv[])
{
  using namespace canvas;

  if (argc < 2)
    {
      println (cerr, "error: missing name");
      return 1;
    }

  canvas::say_hello (argv[1]);
}
