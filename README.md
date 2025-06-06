# Project Report

Project ini Dibuat bedasarkan konsep 2d platformer dengan mekanik berpindah realm:
<hr>

## First Commit:
Apa yang ditambahkan:
1. Semacam Tester untuk platform, player dengan ground serta logika untuk 2d platformer
2. Setiap bagian code sudah ditaruh dan dijelaskan (bisa dilihat dari comment yang ada dari kode cpp)
3. Belum diimplementasikan GameState karena ini masih tester untuk platformer
4. Menggunakan Vector untuk menyimpan platform biar bisa banyak initiasi platform
5. Menggunakan logic collision serta set boundaries untuk Teleport player ke ujung map jika sudah menyampai ujung mapnya.

## Second Commit:
Apa yang ditambahkan:
1. Membuat Dissapearring platform yang akan muncul dan tidak muncul dalam spesific waktu (menggunakan fungsi clock dari SFML).
2. Membuat logic untuk class Platform.hpp dan DisappearPlatform.hpp dan bisa memakai vector untuk menyimpan jenis platform yang berbeda tersebut.
3. Mengubah logic collision agar memperhatikan yang mana platform yang active

## Third Commit:
Apa yang ditambahkan:
1. Membuat Realm.hpp dengan Enum class (memakai key = value) di sini Dark dan Light;
2. Membuat RealmPlatform hpp dan Cpp dengan logic mereka.
3. Membenarkan Fungsi di Main untuk menghandle Realm, serta BG diubah bedasarkan Realm player berada. 
4. Tadi out of bounds sempet hilang tapi udah di restore lagi.