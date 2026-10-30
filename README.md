# toyutils

I'm trying to create some coreutils packages myself using C for fun and learning.

> [!NOTE]
> This is a toy project.

## Tools

- [cp](./src/cp)
- [pwd](./src/pwd)
- [echo](./src/echo)
- [ls](./src/ls)
- [yes](./src/yes)
- [cat](./src/cat)
- [touch](./src/touch)
- [mkdir](./src/mkdir)

## Build

To build, you have to be able to execute gcc and just.

```bash
just build
```

<hr>

Or, if you are a Nix user (btw), you can just use Nix-Shell.

```bash
nix-shell --run "just build"
```

<hr>

To install dependencies using Homebrew, you can run

```bash
brew bundle
```
