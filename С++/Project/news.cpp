#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
// #include <openssl/sha.h> // Удаляем!
#include <iomanip>
#include <map>

// --- Минималистичная реализация SHA-256 (public domain) ---
#include <cstring>
#include <cstdint>

namespace simple_sha256 {
    typedef uint8_t  uint8;
    typedef uint32_t uint32;
    typedef uint64_t uint64;

    inline uint32 rotr(uint32 x, uint32 n) { return (x >> n) | (x << (32 - n)); }

    void sha256(const uint8* data, size_t len, uint8* out) {
        static const uint32 K[64] = {
            0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
            0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
            0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
            0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
            0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
            0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
            0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
            0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
        };
        uint32 h[8] = {
            0x6a09e667,0xbb67ae85,0x3c6ef372,0xa54ff53a,
            0x510e527f,0x9b05688c,0x1f83d9ab,0x5be0cd19
        };
        uint8 buf[64];
        uint64 total = len;
        size_t i = 0;
        while (len >= 64) {
            uint32 w[64];
            for (int j = 0; j < 16; ++j) {
                w[j] = (data[4*j]<<24) | (data[4*j+1]<<16) | (data[4*j+2]<<8) | (data[4*j+3]);
            }
            for (int j = 16; j < 64; ++j) {
                uint32 s0 = rotr(w[j-15],7) ^ rotr(w[j-15],18) ^ (w[j-15]>>3);
                uint32 s1 = rotr(w[j-2],17) ^ rotr(w[j-2],19) ^ (w[j-2]>>10);
                w[j] = w[j-16] + s0 + w[j-7] + s1;
            }
            uint32 a=h[0],b=h[1],c=h[2],d=h[3],e=h[4],f=h[5],g=h[6],h_=h[7];
            for (int j=0;j<64;++j) {
                uint32 S1 = rotr(e,6)^rotr(e,11)^rotr(e,25);
                uint32 ch = (e&f)^((~e)&g);
                uint32 temp1 = h_+S1+ch+K[j]+w[j];
                uint32 S0 = rotr(a,2)^rotr(a,13)^rotr(a,22);
                uint32 maj = (a&b)^(a&c)^(b&c);
                uint32 temp2 = S0+maj;
                h_=g; g=f; f=e; e=d+temp1; d=c; c=b; b=a; a=temp1+temp2;
            }
            h[0]+=a; h[1]+=b; h[2]+=c; h[3]+=d;
            h[4]+=e; h[5]+=f; h[6]+=g; h[7]+=h_;
            data+=64; len-=64;
        }
        memcpy(buf, data, len);
        buf[len++] = 0x80;
        if (len > 56) {
            memset(buf+len, 0, 64-len);
            uint32 w[16];
            for (int j=0;j<16;++j)
                w[j]=(buf[4*j]<<24)|(buf[4*j+1]<<16)|(buf[4*j+2]<<8)|(buf[4*j+3]);
            for (int j=16;j<64;++j) w[j]=0;
            uint32 a=h[0],b=h[1],c=h[2],d=h[3],e=h[4],f=h[5],g=h[6],h_=h[7];
            for (int j=0;j<64;++j) {
                uint32 S1 = rotr(e,6)^rotr(e,11)^rotr(e,25);
                uint32 ch = (e&f)^((~e)&g);
                uint32 temp1 = h_+S1+ch+K[j]+w[j%16];
                uint32 S0 = rotr(a,2)^rotr(a,13)^rotr(a,22);
                uint32 maj = (a&b)^(a&c)^(b&c);
                uint32 temp2 = S0+maj;
                h_=g; g=f; f=e; e=d+temp1; d=c; c=b; b=a; a=temp1+temp2;
            }
            h[0]+=a; h[1]+=b; h[2]+=c; h[3]+=d;
            h[4]+=e; h[5]+=f; h[6]+=g; h[7]+=h_;
            memset(buf, 0, 56);
            len = 0;
        }
        memset(buf+len, 0, 56-len);
        uint64 bits = total*8;
        for (int i=0;i<8;++i)
            buf[63-i] = bits>>(8*i);
        uint32 w[16];
        for (int j=0;j<16;++j)
            w[j]=(buf[4*j]<<24)|(buf[4*j+1]<<16)|(buf[4*j+2]<<8)|(buf[4*j+3]);
        for (int j=16;j<64;++j) w[j]=0;
        uint32 a=h[0],b=h[1],c=h[2],d=h[3],e=h[4],f=h[5],g=h[6],h_=h[7];
        for (int j=0;j<64;++j) {
            uint32 S1 = rotr(e,6)^rotr(e,11)^rotr(e,25);
            uint32 ch = (e&f)^((~e)&g);
            uint32 temp1 = h_+S1+ch+K[j]+w[j%16];
            uint32 S0 = rotr(a,2)^rotr(a,13)^rotr(a,22);
            uint32 maj = (a&b)^(a&c)^(b&c);
            uint32 temp2 = S0+maj;
            h_=g; g=f; f=e; e=d+temp1; d=c; c=b; b=a; a=temp1+temp2;
        }
        h[0]+=a; h[1]+=b; h[2]+=c; h[3]+=d;
        h[4]+=e; h[5]+=f; h[6]+=g; h[7]+=h_;
        for (int i=0;i<8;++i) {
            out[4*i+0] = (h[i]>>24)&0xff;
            out[4*i+1] = (h[i]>>16)&0xff;
            out[4*i+2] = (h[i]>>8)&0xff;
            out[4*i+3] = (h[i])&0xff;
        }
    }
}

struct User {
    std::string username;
    std::string password_hash;
    bool is_admin;
    bool is_blocked = false;
    int failed_attempts = 0;
    time_t block_until = 0;
};

struct News {
    std::string title;
    std::string content;
};

std::vector<User> users;
std::vector<News> news_list;

// Многоязычность
enum class Lang { RU, EN };
Lang current_lang = Lang::RU;
std::map<std::string, std::string> msg_ru = {
    {"registration", "РЕГИСТРАЦИЯ"},
    {"login", "ВХОД"},
    {"main_menu", "ГЛАВНОЕ МЕНЮ"},
    {"user_menu", "МЕНЮ ПОЛЬЗОВАТЕЛЯ"},
    {"add_news", "ДОБАВИТЬ НОВОСТЬ"},
    {"edit_news", "РЕДАКТИРОВАТЬ НОВОСТЬ"},
    {"delete_news", "УДАЛИТЬ НОВОСТЬ"},
    {"delete_user", "УДАЛИТЬ ПОЛЬЗОВАТЕЛЯ"},
    {"search_news", "ПОИСК НОВОСТЕЙ"},
    {"news_feed", "ЛЕНТА НОВОСТЕЙ"},
    {"goodbye", "ДО СВИДАНИЯ!"},
    {"blocked", "Пользователь временно заблокирован. Попробуйте позже."},
    {"confirm_delete", "Вы уверены? (y/n): "},
    {"user_blocked", "Пользователь заблокирован."},
    {"user_unblocked", "Пользователь разблокирован."},
    {"block_user", "БЛОКИРОВАТЬ ПОЛЬЗОВАТЕЛЯ"},
    {"unblock_user", "РАЗБЛОКИРОВАТЬ ПОЛЬЗОВАТЕЛЯ"},
    {"language", "ЯЗЫК | Language"},
    {"select_language", "Выберите язык (1-Русский, 2-English): "}
};
std::map<std::string, std::string> msg_en = {
    {"registration", "REGISTRATION"},
    {"login", "LOGIN"},
    {"main_menu", "MAIN MENU"},
    {"user_menu", "USER MENU"},
    {"add_news", "ADD NEWS"},
    {"edit_news", "EDIT NEWS"},
    {"delete_news", "DELETE NEWS"},
    {"delete_user", "DELETE USER"},
    {"search_news", "SEARCH NEWS"},
    {"news_feed", "NEWS FEED"},
    {"goodbye", "GOODBYE!"},
    {"blocked", "User temporarily blocked. Try later."},
    {"confirm_delete", "Are you sure? (y/n): "},
    {"user_blocked", "User blocked."},
    {"user_unblocked", "User unblocked."},
    {"block_user", "BLOCK USER"},
    {"unblock_user", "UNBLOCK USER"},
    {"language", "LANGUAGE"},
    {"select_language", "Select language (1-Russian, 2-English): "}
};
std::string msg(const std::string& key) {
    if (current_lang == Lang::RU) return msg_ru[key];
    return msg_en[key];
}

// Заменяем функцию sha256:
std::string sha256(const std::string& str) {
    unsigned char hash[32];
    simple_sha256::sha256(reinterpret_cast<const unsigned char*>(str.c_str()), str.size(), hash);
    std::stringstream ss;
    for (int i = 0; i < 32; ++i)
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    return ss.str();
}

// Логирование
void log_action(const std::string& username, const std::string& action) {
    std::ofstream fout("actions.log", std::ios::app);
    time_t now = time(nullptr);
    fout << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S")
         << " [" << username << "] " << action << "\n";
}

std::string to_lower(const std::string& s) {
    std::string res = s;
    std::transform(res.begin(), res.end(), res.begin(), ::tolower);
    return res;
}

void print_frame(const std::string& title) {
    system("cls");
    std::cout << "\n========================================\n";
    std::cout << "|| " << title;
    for (size_t i = 0; i < 36 - title.size(); ++i) std::cout << " ";
    std::cout << "||\n";
    std::cout << "========================================\n";
}

void load_users() {
    std::ifstream fin("users.db");
    if (!fin) return;
    std::string line;
    while (std::getline(fin, line)) {
        std::istringstream iss(line);
        User u;
        int admin;
        if (iss >> u.username >> u.password_hash >> admin) {
            u.is_admin = admin;
            iss >> u.is_blocked >> u.failed_attempts >> u.block_until;
            users.push_back(u);
        }
    }
}

void save_users() {
    std::ofstream fout("users.db");
    for (const auto& u : users)
        fout << u.username << " " << u.password_hash << " " << u.is_admin
             << " " << u.is_blocked << " " << u.failed_attempts << " " << u.block_until << "\n";
}

void load_news() {
    std::ifstream fin("news.db");
    if (!fin) return;
    std::string title, content;
    while (std::getline(fin, title) && std::getline(fin, content)) {
        news_list.push_back({title, content});
    }
}

void save_news() {
    std::ofstream fout("news.db");
    for (const auto& n : news_list)
        fout << n.title << "\n" << n.content << "\n";
}

bool username_exists(const std::string& username) {
    std::string uname = to_lower(username);
    for (const auto& u : users)
        if (to_lower(u.username) == uname) return true;
    return false;
}

bool is_valid_username(const std::string& username) {
    if (username.size() < 3 || username.size() > 20) return false;
    for (char c : username)
        if (!std::isalnum(c) && c != '_') return false;
    return true;
}

bool is_valid_password(const std::string& password) {
    if (password.size() < 6) return false;
    bool has_upper = false, has_lower = false, has_digit = false;
    for (char c : password) {
        has_upper |= std::isupper(c);
        has_lower |= std::islower(c);
        has_digit |= std::isdigit(c);
    }
    return has_upper && has_lower && has_digit;
}

void register_user() {
    system("cls");
    std::string username, password, password2;
    print_frame(msg("registration"));
    while (true) {
        std::cout << "Enter username: ";
        std::cin >> username;
        if (!is_valid_username(username)) {
            std::cout << "[!] Invalid username! Only letters, digits, _ (3-20 chars)\n";
            continue;
        }
        if (username_exists(username)) {
            std::cout << "[!] User already exists!\n";
            continue;
        }
        break;
    }
    while (true) {
        std::cout << "Enter password: ";
        std::cin >> password;
        std::cout << "Repeat password: ";
        std::cin >> password2;
        if (password != password2) {
            std::cout << "[!] Passwords do not match!\n";
            continue;
        }
        if (!is_valid_password(password)) {
            std::cout << "[!] Password must be >=6 chars, contain upper/lowercase and digit.\n";
            continue;
        }
        break;
    }
    bool is_admin = users.empty();
    users.push_back({username, sha256(password), is_admin});
    save_users();
    log_action(username, "register");
    std::cout << "\n[+] Registration successful!\n";
    std::cout << "Press ENTER to continue...";
    std::cin.ignore(); std::cin.get();
}

User* authorize_user() {
    system("cls");
    std::string username, password;
    print_frame(msg("login"));
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;
    std::string hash = sha256(password);
    std::string uname = to_lower(username);
    for (auto& u : users) {
        if (to_lower(u.username) == uname) {
            time_t now = time(nullptr);
            if (u.is_blocked && now < u.block_until) {
                std::cout << "[!] " << msg("blocked") << "\n";
                log_action(u.username, "blocked login attempt");
                std::cout << "Press ENTER to continue...";
                std::cin.ignore(); std::cin.get();
                return nullptr;
            }
            if (u.password_hash == hash) {
                u.failed_attempts = 0;
                u.is_blocked = false;
                u.block_until = 0;
                save_users();
                log_action(u.username, "login success");
                std::cout << "\n[+] Login successful!\n";
                std::cout << "Press ENTER to continue...";
                std::cin.ignore(); std::cin.get();
                return &u;
            } else {
                u.failed_attempts++;
                log_action(u.username, "login failed");
                if (u.failed_attempts >= 3) {
                    u.is_blocked = true;
                    u.block_until = time(nullptr) + 60; // 1 минута блокировки
                    save_users();
                    std::cout << "[!] " << msg("blocked") << "\n";
                    std::cout << "Press ENTER to continue...";
                    std::cin.ignore(); std::cin.get();
                    return nullptr;
                }
                save_users();
                std::cout << "[!] Invalid username or password!\n";
                std::cout << "Press ENTER to continue...";
                std::cin.ignore(); std::cin.get();
                return nullptr;
            }
        }
    }
    log_action(username, "login failed (user not found)");
    std::cout << "[!] Invalid username or password!\n";
    std::cout << "Press ENTER to continue...";
    std::cin.ignore(); std::cin.get();
    return nullptr;
}

// --- NEWS MANAGEMENT ---

void add_news() {
    system("cls");
    std::cin.ignore();
    print_frame(msg("add_news"));
    std::string title, content;
    std::cout << "News title: ";
    std::getline(std::cin, title);
    std::cout << "News content: ";
    std::getline(std::cin, content);
    news_list.push_back({title, content});
    save_news();
    log_action("admin", "add news: " + title);
    std::cout << "\n[+] News added!\n";
    std::cout << "Press ENTER to continue...";
    std::cin.get();
}

void edit_news() {
    system("cls");
    print_frame(msg("edit_news"));
    if (news_list.empty()) {
        std::cout << "No news available.\n";
        std::cout << "Press ENTER to continue...";
        std::cin.ignore(); std::cin.get();
        return;
    }
    for (size_t i = 0; i < news_list.size(); ++i)
        std::cout << i+1 << ". " << news_list[i].title << "\n";
    std::cout << "Select news number to edit (0 to cancel): ";
    int idx;
    std::cin >> idx;
    if (idx <= 0 || idx > (int)news_list.size()) return;
    std::cin.ignore();
    std::string new_title, new_content;
    std::cout << "New title (leave empty to keep): ";
    std::getline(std::cin, new_title);
    std::cout << "New content (leave empty to keep): ";
    std::getline(std::cin, new_content);
    if (!new_title.empty()) news_list[idx-1].title = new_title;
    if (!new_content.empty()) news_list[idx-1].content = new_content;
    save_news();
    log_action("admin", "edit news: " + news_list[idx-1].title);
    std::cout << "[+] News updated!\n";
    std::cout << "Press ENTER to continue...";
    std::cin.get();
}

void delete_news() {
    system("cls");
    print_frame(msg("delete_news"));
    if (news_list.empty()) {
        std::cout << "No news available.\n";
        std::cout << "Press ENTER to continue...";
        std::cin.ignore(); std::cin.get();
        return;
    }
    for (size_t i = 0; i < news_list.size(); ++i)
        std::cout << i+1 << ". " << news_list[i].title << "\n";
    std::cout << "Select news number to delete (0 to cancel): ";
    int idx;
    std::cin >> idx;
    if (idx <= 0 || idx > (int)news_list.size()) return;
    std::cout << msg("confirm_delete");
    char conf;
    std::cin >> conf;
    if (conf == 'y' || conf == 'Y') {
        log_action("admin", "delete news: " + news_list[idx-1].title);
        news_list.erase(news_list.begin() + idx - 1);
        save_news();
        std::cout << "[+] News deleted!\n";
    } else {
        std::cout << "[*] Canceled.\n";
    }
    std::cout << "Press ENTER to continue...";
    std::cin.ignore(); std::cin.get();
}

// --- USER MANAGEMENT (ADMIN) ---

void delete_user() {
    system("cls");
    print_frame(msg("delete_user"));
    for (size_t i = 0; i < users.size(); ++i)
        std::cout << i+1 << ". " << users[i].username << (users[i].is_admin ? " [admin]" : "") << "\n";
    std::cout << "Select user number to delete (0 to cancel): ";
    int idx;
    std::cin >> idx;
    if (idx <= 0 || idx > (int)users.size()) return;
    if (users[idx-1].is_admin) {
        std::cout << "[!] Cannot delete admin!\n";
        std::cout << "Press ENTER to continue...";
        std::cin.ignore(); std::cin.get();
        return;
    }
    std::cout << msg("confirm_delete");
    char conf;
    std::cin >> conf;
    if (conf == 'y' || conf == 'Y') {
        log_action("admin", "delete user: " + users[idx-1].username);
        users.erase(users.begin() + idx - 1);
        save_users();
        std::cout << "[+] User deleted!\n";
    } else {
        std::cout << "[*] Canceled.\n";
    }
    std::cout << "Press ENTER to continue...";
    std::cin.ignore(); std::cin.get();
}

void block_unblock_user(bool block) {
    system("cls");
    print_frame(block ? msg("block_user") : msg("unblock_user"));
    for (size_t i = 0; i < users.size(); ++i)
        std::cout << i+1 << ". " << users[i].username << (users[i].is_admin ? " [admin]" : "") << "\n";
    std::cout << "Select user number (0 to cancel): ";
    int idx;
    std::cin >> idx;
    if (idx <= 0 || idx > (int)users.size()) return;
    if (users[idx-1].is_admin) {
        std::cout << "[!] Cannot block/unblock admin!\n";
        std::cout << "Press ENTER to continue...";
        std::cin.ignore(); std::cin.get();
        return;
    }
    users[idx-1].is_blocked = block;
    users[idx-1].block_until = block ? (time(nullptr) + 3600) : 0; // 1 час блокировки
    users[idx-1].failed_attempts = 0;
    save_users();
    log_action("admin", std::string(block ? "block user: " : "unblock user: ") + users[idx-1].username);
    std::cout << (block ? msg("user_blocked") : msg("user_unblocked")) << "\n";
    std::cout << "Press ENTER to continue...";
    std::cin.ignore(); std::cin.get();
}

// --- NEWS SEARCH & PAGINATION ---

void search_news() {
    system("cls");
    std::cin.ignore();
    print_frame(msg("search_news"));
    std::string query;
    std::cout << "Enter search query: ";
    std::getline(std::cin, query);
    std::vector<size_t> found;
    for (size_t i = 0; i < news_list.size(); ++i) {
        std::string t = to_lower(news_list[i].title);
        std::string c = to_lower(news_list[i].content);
        std::string q = to_lower(query);
        if (t.find(q) != std::string::npos || c.find(q) != std::string::npos)
            found.push_back(i);
    }
    if (found.empty()) {
        std::cout << "No news found.\n";
        std::cout << "Press ENTER to continue...";
        std::cin.get();
        return;
    }
    for (size_t i = 0; i < found.size(); ++i)
        std::cout << i+1 << ". " << news_list[found[i]].title << "\n";
    std::cout << "Select news number to view (0 to cancel): ";
    int idx;
    std::cin >> idx;
    if (idx <= 0 || idx > (int)found.size()) return;
    const auto& n = news_list[found[idx-1]];
    std::cout << "+--------------------------------------+\n";
    std::cout << "| Title: " << n.title << "\n";
    std::cout << "|--------------------------------------\n";
    std::cout << n.content << "\n";
    std::cout << "+--------------------------------------+\n\n";
    std::cout << "Press ENTER to continue...";
    std::cin.ignore(); std::cin.get();
}

void show_news() {
    system("cls");
    print_frame(msg("news_feed"));
    if (news_list.empty()) {
        std::cout << "No news available.\n";
        std::cout << "Press ENTER to continue...";
        std::cin.ignore(); std::cin.get();
        return;
    }
    const int page_size = 5;
    int page = 0;
    int total_pages = (news_list.size() + page_size - 1) / page_size;
    while (true) {
        system("cls");
        print_frame(msg("news_feed") + " [" + std::to_string(page+1) + "/" + std::to_string(total_pages) + "]");
        int start = page * page_size;
        int end = std::min((int)news_list.size(), start + page_size);
        for (int i = start; i < end; ++i)
            std::cout << (i+1) << ". " << news_list[i].title << "\n";
        std::cout << "n-next, p-prev, number to view, 0-cancel: ";
        std::string cmd;
        std::cin >> cmd;
        if (cmd == "n" && page+1 < total_pages) page++;
        else if (cmd == "p" && page > 0) page--;
        else if (cmd == "0") return;
        else {
            int idx = std::stoi(cmd);
            if (idx > 0 && idx <= (int)news_list.size()) {
                const auto& n = news_list[idx-1];
                std::cout << "+--------------------------------------+\n";
                std::cout << "| Title: " << n.title << "\n";
                std::cout << "|--------------------------------------\n";
                std::cout << n.content << "\n";
                std::cout << "+--------------------------------------+\n\n";
                std::cout << "Press ENTER to continue...";
                std::cin.ignore(); std::cin.get();
            }
        }
    }
}

// --- LANGUAGE SELECTION ---

void select_language() {
    system("cls");
    print_frame(msg("language"));
    std::cout << msg("select_language");
    int l;
    std::cin >> l;
    if (l == 1) current_lang = Lang::RU;
    else if (l == 2) current_lang = Lang::EN;
}

// --- MAIN MENU ---

int main() {
    load_users();
    load_news();
    select_language();
    while (true) {
        system("cls");
        print_frame(msg("main_menu"));
        std::cout << " 1. Register\n 2. Login\n 3. Search news\n 4. Language\n 0. Exit\n";
        std::cout << "----------------------------------------\n";
        std::cout << "Select option: ";
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            register_user();
        } else if (choice == 2) {
            User* user = authorize_user();
            if (!user) continue;
            while (true) {
                system("cls");
                print_frame(msg("user_menu"));
                if (user->is_admin)
                    std::cout << " 1. Add news\n 2. View news\n 3. Edit news\n 4. Delete news\n 5. Delete user\n 6. Block user\n 7. Unblock user\n 8. Search news\n 0. Logout\n";
                else
                    std::cout << " 1. View news\n 2. Search news\n 0. Logout\n";
                std::cout << "----------------------------------------\n";
                std::cout << "Select option: ";
                int c;
                std::cin >> c;
                if (c == 0) break;
                if (user->is_admin && c == 1) add_news();
                else if (user->is_admin && c == 2) show_news();
                else if (user->is_admin && c == 3) edit_news();
                else if (user->is_admin && c == 4) delete_news();
                else if (user->is_admin && c == 5) delete_user();
                else if (user->is_admin && c == 6) block_unblock_user(true);
                else if (user->is_admin && c == 7) block_unblock_user(false);
                else if (user->is_admin && c == 8) search_news();
                else if (!user->is_admin && c == 1) show_news();
                else if (!user->is_admin && c == 2) search_news();
            }
        } else if (choice == 3) {
            search_news();
        } else if (choice == 4) {
            select_language();
        } else if (choice == 0) break;
    }
    system("cls");
    print_frame(msg("goodbye"));
    return 0;
}


