Advanced Inventory System (C++)

Bu proje, C++ dilinde nesne yönelimli programlama (OOP) prensiplerini kullanarak geliştirilmiş basit ama güçlü bir envanter (inventory) sistemidir. Akıllı işaretçiler (smart pointers), şablonlar (templates) ve STL veri yapıları kullanılarak modern C++ teknikleri uygulanmıştır.

Proje Amacı

Bu projenin amacı:

* Nesne yönelimli programlama yapısını göstermek
* Template (şablon) kullanımını öğretmek
* Smart pointer (unique_ptr) ile bellek yönetimini güvenli hale getirmek
* Basit bir oyun envanter sistemi mantığını modellemek

Kullanılan Teknolojiler

* C++ (Modern C++ - C++11 ve sonrası)
* STL (Standard Template Library)
* unique_ptr (Akıllı işaretçi)
* unordered_map (Hash map veri yapısı)

Sınıflar ve Yapı

1. BaseItem (Soyut Sınıf)

* Tüm eşyaların temel sınıfıdır
* name ve id bilgilerini tutar
* use() fonksiyonu saf sanal (pure virtual) olarak tanımlanmıştır

2. Weapon (Türetilmiş Sınıf)

* BaseItem sınıfından kalıtım alır
* Ek olarak damage (hasar) özelliğine sahiptir
* use() fonksiyonunu override ederek özel davranış tanımlar

3. AdvancedInventory (Template Sınıf)

* Generic (genel) bir envanter yapısıdır
* unordered_map ile eşyaları ID’ye göre saklar
* unique_ptr kullanarak otomatik bellek yönetimi sağlar

Temel Fonksiyonlar

addItem()

* Envantere yeni eşya ekler
* Boş (nullptr) nesne eklenmesini engeller

useItem()

* Verilen ID’ye sahip eşyayı kullanır
* Eşya yoksa kullanıcıyı bilgilendirir

showStatus()

* Envanterdeki toplam eşya sayısını gösterir

Program Akışı

1. Envanter oluşturulur
2. Bir Weapon nesnesi (örnek: Excalibur) oluşturulur
3. Envantere eklenir
4. Envanter durumu gösterilir
5. Eşya kullanılır

Örnek Çıktı

Envanterdeki toplam eşya sayısı: 1
Excalibur kullanıldı! Verilen hasar: 55

Öne Çıkan Özellikler

* Bellek sızıntısı yok (unique_ptr sayesinde)
* Genişletilebilir yapı (yeni item türleri kolayca eklenebilir)
* Template kullanımı ile esnek tasarım
* Exception handling ile hata kontrolü

Geliştirme Önerileri

* Zırh (Armor), iksir (Potion) gibi yeni item türleri eklenebilir
* Envanter listeleme (tüm itemları gösterme) özelliği eklenebilir
* Kaydetme / yükleme sistemi (dosya işlemleri) eklenebilir
* Kullanıcıdan input alarak dinamik envanter yönetimi yapılabilir

Derleme ve Çalıştırma

Kod aşağıdaki gibi derlenebilir:

g++ main.cpp -o inventory
./inventory

Notlar

* Kod C++11 veya daha yeni bir standart gerektirir
* Smart pointer kullanımı sayesinde manuel delete işlemi gerekmez

Bu proje, modern C++ öğrenenler için pratik ve anlaşılır bir örnek sunar.



Geliştiren @kagaanself
