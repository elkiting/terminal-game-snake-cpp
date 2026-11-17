# Cacing Nokia (Terminal-Based Snake Game in C++)

## Deskripsi Singkat Project

Game klasik Cacing Nokia berbasis terminal (*Command Line Interface*) yang dibuat menggunakan bahasa C++ dan library `ncurses`. Pemain mengendalikan ular untuk mengumpulkan makanan guna meningkatkan skor sambil menghindari dinding, rintangan internal, serta memanfaatkan portal teleportasi dan makanan spesial.

---

## Kelompok dan Anggota

* **Nama Kelompok:** token limit
* **Anggota:**
  1. Elvan khoirun annan
  2. Raihan Rahmad
  3. Alita Patricia

---

## Latar Belakang

Game Snake klasik seperti di ponsel Nokia lawas sangat ikonik karena mekanismenya sederhana namun menantang. Proyek ini dibuat untuk menghadirkan kembali nostalgia permainan tersebut ke dalam lingkungan terminal, sekaligus memodifikasinya dengan fitur modern seperti portal dan efek *shrink* agar permainan tidak monoton dan lebih seru dimainkan.

---

## Tujuan Game

* **Bagi Pemain:** Melatih ketangkasan, fokus, dan refleks dalam mengambil keputusan cepat saat kecepatan ular terus meningkat, serta meraih skor setinggi mungkin.
* **Secara Teknis:** Mengimplementasikan konsep dasar pemrograman terstruktur dan logika algoritma C++ ke dalam bentuk aplikasi interaktif berbasis teks.

---

## Genre Game

* **Arcade / Classic Action** (Berbasis Teks / *Terminal-based*)

---

## Konsep Gameplay

* Pemain menggerakkan kepala ular di dalam arena menggunakan tombol panah (*Arrow Keys*).
* Pemain harus memakan item yang muncul di arena untuk menambah skor dan level kecepatan, sambil mencegah kepala ular menabrak batas dinding luar, rintangan di dalam arena, maupun badan ular itu sendiri.
* Permainan berakhir (*Game Over*) jika terjadi tabrakan.

---

## Fitur Game

* **Antarmuka Berwarna:** Membedakan elemen arena dengan warna kontras (ular hijau dengan kepala kuning, makanan merah, rintangan ungu, portal biru).
* **Sistem Makanan Ganda:**
  * **Makanan Biasa:** Menambah **+10 poin** dan memanjangkan tubuh ular sebanyak 1 segmen.
  * **Makanan Spesial:** Muncul secara acak dengan batas waktu (*timer* 30 *tick*), memberikan **+25 poin**, dan memendekkan ekor ular sebanyak 2 segmen (*shrink*) untuk memberi ruang gerak lebih luas.
* **Portal Teleportasi Dua Arah:** Sepasang portal di sisi kiri dan kanan arena yang memindahkan ular secara instan ke portal pasangannya dengan mempertahankan arah gerak.
* **Rintangan Internal:** Blok dinding statis di dalam arena yang menambah tingkat kesulitan manuver.
* **Progresi Kecepatan Otomatis:** Semakin tinggi skor, jeda waktu (*delay*) pergerakan ular semakin kecil sehingga laju ular makin cepat dan level meningkat.
* **HUD Real-time:** Menampilkan informasi **Skor**, **Panjang Ular**, dan **Level Kecepatan** secara langsung di bagian atas bingkai.
