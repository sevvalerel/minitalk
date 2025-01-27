Minitalk, iki ayrı program olan client ve server arasında sinyaller (SIGUSR1 ve SIGUSR2) kullanarak mesaj iletimi yapan bir projedir. Proje, 42 okulunun işlem yönetimi ve sinyal işlemleri konusundaki temel anlayışı geliştirmek amacıyla tasarlanmıştır.

Server, çalıştırıldığında kendi işlem kimliğini (PID) ekrana yazdırır ve client tarafından gönderilecek mesajları bekler. Client ise, kullanıcıdan aldığı mesajı sunucuya iletmek için belirtilen sunucu PID’sine sinyaller gönderir.

Mesaj iletimi sırasında:

Her bir karakter, ASCII tablosundaki ikilik (binary) karşılığında bitlere ayrılarak sunucuya gönderilir.
SIGUSR1 sinyali 1 bitini, SIGUSR2 sinyali ise 0 bitini temsil eder.
Sunucu, aldığı sinyalleri birleştirerek karaktere dönüştürür ve ekrana yazdırır.
Bu proje, işlem (process) yönetimi, sinyal kullanımı ve senkronizasyon gibi konularda pratik bir deneyim sunar.
