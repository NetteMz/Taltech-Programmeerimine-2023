#include <iostream>
#include <fstream>
#include <openssl/rsa.h>
#include <openssl/pem.h>

std::string encryptText(const sˇtd::string& plaintext, RSA* publicKey) {
    int rsaLen = RSA_size(publicKey);
    unsigned char* ciphertext = new unsigned char[rsaLen];

    int encryptedLen = RSA_public_encrypt(plaintext.length(), reinterpret_cast<const unsigned char*>(plaintext.c_str()), ciphertext, publicKey, RSA_PKCS1_PADDING);

    std::string encryptedText(reinterpret_cast<char*>(ciphertext), encryptedLen);

    delete[] ciphertext;

    return encryptedText;
}

std::string decryptText(const std::string& encryptedText, RSA* privateKey) {
    int rsaLen = RSA_size(privateKey);
    unsigned char* decryptedText = new unsigned char[rsaLen];

    int decryptedLen = RSA_private_decrypt(encryptedText.length(), reinterpret_cast<const unsigned char*>(encryptedText.c_str()), decryptedText, privateKey, RSA_PKCS1_PADDING);

    std::string plaintext(reinterpret_cast<char*>(decryptedText), decryptedLen);

    delete[] decryptedText;

    return plaintext;
}

int main() {
    // Genereeri RSA võtmepaar
     RSA* keypair = RSA_new();
    BIGNUM* bne = BN_new();
    BN_set_word(bne, RSA_F4);
    RSA_generate_key_ex(keypair, 2048, bne, NULL);

    // Salvesta avalik võti faili
    FILE* pubkeyFile = fopen("avalik_võti.pem", "wb");
    PEM_write_RSAPublicKey(pubkeyFile, keypair);
    fclose(pubkeyFile);

    // Salvesta privaatne võti faili
    FILE* privkeyFile = fopen("privaatne_võti.pem", "wb");
    PEM_write_RSAPrivateKey(privkeyFile, keypair, NULL, NULL, 0, NULL, NULL);
    fclose(privkeyFile);

    // Vabasta mälu
    RSA_free(keypair);
    BN_free(bne);

    // Laadi privaatne võti failist
    FILE* privateKeyFile = fopen("privaatne_võti.pem", "rb");
    RSA* privateKey = PEM_read_RSAPrivateKey(privateKeyFile, NULL, NULL, NULL);
    fclose(privateKeyFile);

    // Laadi avalik võti failist
    FILE* publicKeyFile = fopen("avalik_võti.pem", "rb");
    RSA* publicKey = PEM_read_RSAPublicKey(publicKeyFile, NULL, NULL, NULL);
    fclose(publicKeyFile);

    // Sisendtekst, mida soovid krüpteerida
    std::string plaintext = "Tere, see on salajane sõnum!";

    // Krüpteeri tekst
    std::string encryptedText = encryptText(plaintext, publicKey);

    // Salvesta krüpteeritud tekst faili
    std::ofstream outfile("krüpteeritud_tekst.txt", std::ios::binary);
    outfile.write(encryptedText.c_str(), encryptedText.length());
    outfile.close();

    // Dekrüpteeri tekst
    std::string decryptedText = decryptText(encryptedText, privateKey);

    // Väljasta dekrüpteeritud tekst
    std::cout << "Dekrüpteeritud tekst: " << decryptedText << std::endl;

    // Vabasta mälu
    RSA_free(privateKey);

    return 0;
}