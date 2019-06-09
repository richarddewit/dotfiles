# Patches for California (GNOME 3 calendar)

When installing `california` from AUR, you now get the error:

> ==> ERROR: Failure while downloading https://src.fedoraproject.org/cgit/rpms/california.git/plain/0002-Build-with-evolution-data-server-3.13.90.patch Aborting... Error downloading sources: california

This is because the package is declared "dead":

> Package retired as it has a dead upstream and it's broken by latest API/ABI changes in evolution-data-server (#1702954)

*Source: https://src.fedoraproject.org/rpms/california/blob/master/f/dead.package*

The 2 files in this folder are what's missing from the installation PKGBUILD

- **0002-Build-with-evolution-data-server-3.13.90.patch**
- **california-0.4.0-libical-3.0.patch**

To use these files, simply let the sources in PKGBUILD point to:

```shell
	'https://raw.githubusercontent.com/richarddewit/dotfiles/master/california/0002-Build-with-evolution-data-server-3.13.90.patch'
	'https://raw.githubusercontent.com/richarddewit/dotfiles/master/california/california-0.4.0-libical-3.0.patch'
```

You can do this like so (I use `yay` as AUR package manager):

```shell
$ cd /tmp
$ yay -G california
$ cd california
$ vim PKGBUILD
# Now paste over the 2 file URLs, save and quit
$ makepkg -si
```
