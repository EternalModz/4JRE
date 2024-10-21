// Credit to aMsk
namespace mc_boost {
    template<typename T>
    class shared_ptr {
    public:
        shared_ptr(T* p) {
            ptr = p;
            cnt = 0;
        }

        shared_ptr(T* p, uint32_t c) {
            ptr = p;
            cnt = c;
        }

        shared_ptr() {
            ptr = 0;
            cnt = 0;
        }

        T* operator->() const { return ptr; }
        T& operator[](int i) const { return ptr[i]; }

        T* get() const { return ptr; }
    private:
        T* ptr;
        uint32_t cnt;
    };
}

class Packet {
public:
    uint64_t time;
    uint8_t unk_1;
    uint8_t unk_2;
    uint8_t unk_3;
    uint8_t unk_4;
    void* vtbl;
};

class ClientPacketListener {
public:
    void send(mc_boost::shared_ptr<struct Packet> packet) {
        Call<void>(0xA15C84, this, packet);
    }
};

class MineGame {
public:
    static MineGame* getInstance() {
        return Call<MineGame*>(0xACA1C8);
    }

    struct ClientPacketListener* getConnection(int i) {
        return Call<struct ClientPacketListener*>(0xAF3328, this, i);
    }
};

class ServerboundMovePlayerPacket : public Packet {
public:

    ServerboundMovePlayerPacket(double x, double y, double z, float yaw, float pitch, bool isOnGround, bool isFlying) {
        Call<void>(0x58DE1C, this, x, y, z, yaw, pitch, isOnGround, isFlying);
    }
};

void PacketSend()
{
    ClientPacketListener* listener = MineGame::getInstance()->getConnection(0);
    listener->send(new ServerboundMovePlayerPacket(25, 30, 35, 180, 90, true, false));
}
