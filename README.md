# Modul 2
Modul 2

Identitas Pembuat : Riffat Dzahabi, 6702181030, Ponpin-Corp
Judul Modu1 : Praktikum Sistem kendali PWM

Maksud dan tujuan dari praktikum ini adalah :
1. Mahasiswa dapat memahami fungsi dan cara kerja PWM pada motor DC
2. Mahasiswa dapat membuat program sistem kendali berbasis PWM

Dasar Teori Sistem Kendali PWM

  Pulse Width Modulation (PWM) adalah sebuah metode memanipulasi lebar sinyal yang dinyatakan dengan pulsa dalam satu periode, untuk mendapatkan tegangan rata-rata yang berbeda. Bebarapa contoh aplikasi PWM adalah pengontrolan daya atau tegangan yang masuk ke beban, regulator tegangan, pengendalian kecepatan motor, dan lain-lain.
  Sinyal PWM pada umumnya memiliki amplitudo dan frekuensi dasar yang tetap tetapi memiliki lebar pulsa yang bervariasi. Lebar pulsa PWM berbanding lurus dengan amplitude sinyal asli yang belum termodulasi. Oleh karena itu, sinyal PWM memiliki frekuensi gelombang yang tetap namun duty cycle bervariasi antara 0% hingga 100%.
   
Rincian Kegiatan Praktikum (Fungsi sensor pada rangkaian, cara kerja motor pada rangkaian, dll)

Kasus 1
 Sensor 1 dan 2 mendeteksi gelap, sisanya terang  Duty cycle 0% motor kiri, 50% motor kanan (nilai 10 poin).
 Sensor 2 dan 3 mendeteksi gelap, sisanya terang  Duty cycle 20% motor kiri, 50% motor kanan (nilai 10 poin).
 Sensor 3 dan 4 mendeteksi gelap, sisanya terang  Duty cycle 60% pada kedua motor (kedua motor aktif) (nilai 10 poin).
 Sensor 4 dan 5 mendeteksi gelap, sisanya terang  Duty cycle 50% motor kiri, 20% motor kanan (nilai 10 poin).
 Sensor 5 dan 6 mendeteksi gelap, sisanya terang  Duty cycle 50% Motor kiri, 0% motor kanan (nilai 10 poin).
 Semua sensor mendeteksi terang  Duty cycle kedua motor 0% (semua motor mati) (nilai 10 poin).

Kasus 2
Buatlah sub program yang dapat menyimpan kondisi terakhir dari pembacaan sensor dalam sebuah variabel dan jika hanya terdapat 1 (satu) buah nilai sensor, program harus dapat mengeksekusi kondisi terakhir yang telah disimpan pada variabel.
