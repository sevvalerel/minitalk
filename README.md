# Minitalk

## 1. Proje Açıklaması
**minitalk**, UNIX sinyallerini kullanarak bir istemci ve sunucu arasında mesaj iletimi sağlayan bir projedir. Bu proje, IPC (Inter-Process Communication) yöntemlerinden biri olan sinyal tabanlı haberleşmeyi anlamak ve uygulamak amacıyla geliştirilmiştir.

## 2. Kurallar ve Gereksinimler
- Program, iki bileşenden oluşur: **server (sunucu)** ve **client (istemci)**.
- Sunucu, bir PID (Process ID) ile başlatılır ve istemciden gelen mesajları alır.
- İstemci, belirli bir mesajı karakter bazında sunucuya iletir.
- Mesaj, yalnızca UNIX sinyalleri (`SIGUSR1` ve `SIGUSR2`) kullanılarak gönderilmelidir.
- Program, her tür ASCII karakterini desteklemelidir.

## 3. Kurulum ve Çalıştırma
1. **Depoyu klonlayın:**
   ```sh
   git clone https://github.com/kullaniciadi/minitalk.git
   cd minitalk
   ```
2. **Projeyi derleyin:**
   ```sh
   make
   ```
3. **Sunucuyu başlatın:**
   ```sh
   ./server
   ```
4. **İstemciyi çalıştırarak mesaj gönderin:**
   ```sh
   ./client <server_pid> "Merhaba, minitalk!"
   ```

## 4. Algoritma Mantığı
- **Sinyal Tabanlı Haberleşme**: İstemci, mesajın her bitini sunucuya **`SIGUSR1`** ve **`SIGUSR2`** sinyalleriyle yollar.
- **Bit Manipülasyonu**:
  - Her karakter, 8 bitlik ASCII değerine çevrilir.
  - `SIGUSR1` **(bit = 0)** ve `SIGUSR2` **(bit = 1)** sinyalleri kullanılarak sunucuya iletilir.
  - Sunucu, aldığı sinyalleri karakter dizisine dönüştürerek ekrana yazdırır.
- **İletişim Senkronizasyonu**: Sunucu, her bit alındığında istemciye bir onay sinyali göndererek veri kaybını önler.

## 5. Örnek Kullanım
### Sunucu Çalıştırma:
```sh
./server
```
Çıktı:
```
Server PID: 12345
```

### İstemci Çalıştırma:
```sh
./client 12345 "Hello, World!"
```
Sunucunun çıktısı:
```
Hello, World!
```

## 6. Hata Yönetimi
- **Geçersiz PID girildiğinde**, istemci hata mesajı döndürmelidir.
- **Sunucu çalışmıyorsa**, istemci uygun bir hata mesajı göstermelidir.
- **Desteklenmeyen karakterler veya boş mesajlar gönderilmemelidir**.

