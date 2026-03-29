#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map> 
#include <stdexcept>    

class BaseItem {
public:
    std::string name;
    int id;

    BaseItem(std::string n, int i) : name(n), id(i) {}
    virtual ~BaseItem() = default; 
    virtual void use() = 0;      
};

class Weapon : public BaseItem {
public:
    int damage;
    Weapon(std::string n, int i, int d) : BaseItem(n, i), damage(d) {}

    void use() override {
        std::cout << name << " kullanıldı! Verilen hasar: " << damage << "\n";
    }
};
template <typename T>
class AdvancedInventory {
private:
    std::unordered_map<int, std::unique_ptr<T>> storage;

public:
    void addItem(std::unique_ptr<T> item) {
        if (!item) throw std::invalid_argument("Boş nesne eklenemez!");
        int id = item->id;
        storage[id] = std::move(item);
    }

    void useItem(int id) {
        if (storage.find(id) != storage.end()) {
            storage[id]->use();
        } else {
            std::cout << "Eşya bulunamadı!\n";
        }
    }

    void showStatus() {
        std::cout << "Envanterdeki toplam eşya sayısı: " << storage.size() << "\n";
    }
};

int main() {
    try {
        AdvancedInventory<BaseItem> myHeroInventory;
      
        auto sword = std::make_unique<Weapon>("Excalibur", 101, 55);
        myHeroInventory.addItem(std::move(sword));

        myHeroInventory.showStatus();
        myHeroInventory.useItem(101);

    } catch (const std::exception& e) {
        std::cerr << "Hata oluştu: " << e.what() << std::endl;
    }

    return 0;
}
