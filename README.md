# Çizgi İzleyen Robot
Bu proje, beyaz bir zemin üzerindeki siyah çizgileri algılayarak bu çizgi boyunca hareket eden otonom bir çizgi izleyen robot sistemini içermektedir. Robot, başlangıç noktası (A noktası) ile hedef noktası (B noktası) arasında çizgiyi takip ederek ilerlemek üzere tasarlanmıştır. Proje, temel robotik prensipleri uygulamalı olarak göstermek amacıyla okul projesi kapsamında geliştirilmiştir.

## Özellikler

* Çizgi algılama (IR sensörler)
* Gerçek zamanlı yön kontrolü
* Basit ve modüler tasarım
* Kolay geliştirilebilir yapı

## Kullanılan Bileşenler

* Arduino Uno mikrodenetleyici
* DC motorlar
* TCRT5000 IR Sensörü
* L298N Motor Sürücü
* Robot Şase ve Tekerlek Seti
* Güç kaynağı

## Kullanılan Dil ve IDE
* Programlama Dili: C/C++ 
* Geliştirme Ortamı: VS Code üzerinden PlatformIO
  
## Kurulum
1. Gerekli donanım bağlantılarını yapınız.
2. Yazılımı bir IDE yardımı ile mikrodenetleyiciye yükleyiniz.
3. Robotu çizgi üzerine yerleştirerek çalıştırınız.

## Çalışma Prensibi

Robot, sensörlerden aldığı veriye göre çizginin konumunu belirler ve motor hızlarını ayarlayarak çizgi üzerinde kalacak şekilde hareket eder.

## Katkı

Katkıda bulunmak isteyenler pull request gönderebilir.

## Lisans

Bu proje açık kaynaklıdır ve ilgili lisans kapsamında kullanılabilir.
