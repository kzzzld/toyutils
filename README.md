# toyutils

I'm trying to create some coreutils packages myself using C for fun and learning.

## Tools

- [cp](./src/cp)
- [pwd](./src/pwd)

## Build

To build, you have to be able to execute gcc and just.

```bash
just build
```

Or, if you are a Nix user (btw), you can just use Nix-Shell.

```bash
nix-shell --run "just build"
```
