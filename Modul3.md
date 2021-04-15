# Modul 3
Modul 3

Identitas Pembuat : Riffat Dzahabi, 6702181030, Ponpin-Corp
Judul Modul : Praktikum Sistem kendali PID Kasus P

Maksud dan tujuan dari praktikum ini adalah :
1. Mahasiswa dapat memahami fungsi dan cara kerja PID pada motor DC
2. Mahasiswa dapat membuat program sistem kendali berbasis PID dengan error yang
dihubungkan dengan konstanta proporsional

Teknik kendali PID adalah pengendali yang merupakan gabungan antara aksi kendali
proporsional ditambah aksi kendali integral ditambah aksi kendali derivatif/turunan (Ogata,1996). PID merupakan kependekan dari proportional integral derivative. Kombinasi ketiga jenis aksi kendali ini bertujuan untuk saling melengkapi kekurangan kekurangan dari masing masing aksi kendali. 

Sistem kendali PID ini bertujuan untuk menentukan paramater aksi kendali Proportional,
Integratif, Derivatif pada robot line follower. Proses ini dapat dilakukan dengan cara trial and
error . Keunggulan cara ini plant tidak perlu diidentifikasi dan membuat model matematis plant.
Hanya dengan cara mencoba memberikan konstanta P-I-D pada formula PID ehingga di peroleh
hasil yang optimal, dengan mengacu pada karakteristik masing-masing kontrol P-I-D.

Sensor	    Error	Set Point	     Analog Value
1	2	3	4	5	6			             Motor Kiri	Motor Kanan
1	1	0	0	0	0	-2	  120	              200	40
0	1	1	0	0	0	-1	  120	              160	80
0	0	1	1	0	0	0   	120	              120	120
0	0	0	1	1	0	1	    120	              80	160
0	0	0	0	1	1	2	    120	              200	40
1	0	0	0	0	0	-2	  120               200	40
0	1	0	0	0	0	-1	  120               160	80
0	0	1	0	0	0	0	    120	              120	120
0	0	0	1	0	0	0	    120               120	120
0	0	0	0	1	0	1	    120               80	160
0	0	0	0	0	1	2	    120	              40	200
