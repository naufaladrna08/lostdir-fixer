# LOST.DIR Fixer

Sebenarnya ini cuma untuk rename file JPG, PNG dan TIFF yang ada
di LOST.DIR. Ada artikel yang bilang kalau LOST.DIR buat ngerec-
overynya salah satunya dengan rename. Nah ini adalah cara otoma-
tisnya soalnya kalau manual kan capek.

Cara kerja:

```bash
lostdir-renamer LOST.DIR
```

Cara compile:

```bash
mkdir build && cd build
cmake ../
```

Dependensi di Ubuntu:

```bash
sudo apt install build-essential cmake -y
```
