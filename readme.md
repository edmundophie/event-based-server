## Benchmark
Benchmark yang digunakan untuk mengukur waktu respons rata-rata adalah ApacheBench. Sedangkan untuk mengukur memori yang digunakan dipakai ps_mem.py . ps_mem.py dipakai dalam mengukur memori karena tools tersebut mengukur berdasarkan per program bukan berdasarkan per proses seperti pada sistem tools htop. 

## Testing
1. Apache yang sudah diinstall harus di restart terlebih dahulu dengan perintah sudo service apache2 restart. 
2. Jalankan perintah ApacheBench di terminal sebagai berikut: ab -n <num_requests> -c <concurrency> <addr>:<port><path> dengan num_requests dan concurrency yang dipakai adalah 10000, addr diganti dengan localhost, port diganti dengan 80

## Hasil Test

### Apache
1. Untuk file dengan ukuran sekitar 500 Bytes, hasil tes yang didapat adalah waktu respons rata-rata adalah 900,7 ms dan memori yang terpakai saat testing dilakukan adalah 18,1 MB - 8,1 MB. Dengan 8,1 MB adalah memori yang terpakai saat server dalam keadaan idle.
2. Untuk file dengan ukuran sekitar 20 KBytes, hasil tes yang didapat adalah waktu respons rata-rata adalah 933,5 ms dan memori yang terpakai saat testing dilakukan adalah 31,1 MB - 8,1 MB. Dengan 8,1 MB adalah memori yang terpakai saat server dalam keadaan idle.

### Nginx
1. Untuk file dengan ukuran sekitar 500 Bytes, hasil tes yang didapat adalah waktu respons rata-rata adalah 1612,427 ms dan memori yang terpakai saat testing dilakukan adalah adalah 17,2 MB - 4 MB. Dengan 4 MB adalah memori yang terpakai saat server dalam keadaan idle.
2. Untuk file dengan ukuran sekitar 20 KBytes, hasil tes yang didapat adalah waktu respons rata-rata adalah 2780,195 ms dan memori yang terpakai saat testing dilakukan adalah 25,9 MB - 4 MB. Dengan 4 MB adalah memori yang terpakai saat server dalam keadaan idle.

### Server yang dikembangkan sendiri
1. Untuk file dengan ukuran sekitar 500 Bytes, hasil tes yang didapat adalah waktu respons rata-rata adalah 675,505 ms dan memori yang terpakai saat testing dilakukan adalah 43.9 MB - 425 KB. Dengan 425 KB adalah memori yang terpakai saat server dalam keadaan idle.
2. Untuk file dengan ukuran sekitar 20 KBytes, hasil tes yang didapat adalah waktu respons rata-rata adalah 1072,976 ms dan memori yang terpakai saat testing dilakukan adalah 44,4 MB - 425 KB. Dengan 425 KB adalah memori yang terpakai saat server dalam keadaan idle.

## How to run
1. Download libevent from [here](http://sourceforge.net/projects/levent/files/libevent/libevent-2.1/libevent-2.1.5-beta.tar.gz/download)
2. Install libevent:  

     ```
     $ ./configure   
     $ make    
     $ sudo make install   
     ```
3. To build and run the server, run makefile in terminal:

     ```
     $ make
     ```
4. Server is now running.  
Open your browser and go to `http://localhost:8080/[FILE_NAME.html]` 

## Configuring
1. The default html directory is in `html` folder  
2. The default port is `8080`
3. The `html_folder` and `port` can be changed in the `server.config` file

## Team Member
* Edmund (13512095)
* Kevin (13512097)
