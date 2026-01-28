# c_tortoise

Bu proje, C dilinde geliştirilmiş **konsol tabanlı 5x5 grid oyunudur**. Oyuncu karakteri (`@`) rastgele bir konumda başlar. Amaç, haritadaki **tüm dutları (`*`) toplayarak** oyunu kazanmaktır. Oyuncunun enerjisi hareket ettikçe azalır; çukura (`O`) düşülürse oyun anında biter.

##  Proje Amacı
Bu projenin amacı; C dilinde **2 boyutlu diziler**, döngüler, koşullu ifadeler ve kullanıcı girdisi (`scanf`) kullanarak **oyun / simülasyon mantığı** kurmayı ve `rand()` ile **rastgele yerleştirme** yapmayı öğrenmektir.

##  Oyun Elemanları
- `@` : Oyuncu
- `*` : Dut (enerji +10)
- `O` : Çukur (GAME OVER)
- `_` : Boş hücre

##  Oyun Kuralları
- Oyun 5x5 bir tahta üzerinde oynanır.
- Oyuncu başlangıçta **rastgele** bir hücreye yerleştirilir.
- Tahtaya:
  - 4 adet dut (`*`)
  - 2 adet çukur (`O`)
  rastgele ve **boş hücrelere** yerleştirilir.
- Her hareket oyuncunun enerjisini **1 azaltır**.
- Tüm dutlar yenildiğinde oyun **kazanılır**.
- Enerji 0 olursa oyun **kaybedilir**.
- Çukura düşülürse oyun **anında biter**.

##  Kontroller
- `N` : yukarı
- `S` : aşağı
- `E` : sağ
- `W` : sol

### Dut Yeme Mekaniği (Mevcut Kodun Çalışma Şekli)
- Oyuncu `Y` tuşuna basarak **dut yeme modunu** başlatır.
- Ardından dutun bulunduğu yön (`N`, `S`, `E`, `W`) girilir.
- Eğer seçilen yönde dut (`*`) varsa:
  - Oyuncu o hücreye hareket eder
  - Enerji **+10** artar
  - Dut sayısı azalır

## Çalıştırma
Bu proje konsol tabanlıdır. Kod, herhangi bir C derleyicisi (ör. GCC) veya online C compiler kullanılarak çalıştırılabilir. Program çalıştırıldığında oyun konsol üzerinden oynanır.

### GCC ile (Opsiyonel)
```bash
gcc tortoise_hare_race.c -o game
./game
