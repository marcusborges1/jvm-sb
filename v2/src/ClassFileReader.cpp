//
// Created by gabriel on 26/06/18.
//

//#include "ClassFileReader.h"

#include <JavaClass.h>
#include <string>
#include <FieldInfo.h>
#include <MethodInfo.h>
#include <AttributeInfo.h>

class ClassFileReader {

    public:
        /** @brief Faz a leitura sequencial do arquivo .Class indicado pelo parâmetro filename.
        *  @param filename ...
        *  @return JavaClass ...
        */
        static JavaClass read_class_file(const char *filename) {
            // tenta abrir o arquivo .class
            FILE *file = fopen(filename, "rb");

            // fecha o programa de leitor/exibidor caso o arquivo .class não exista
            if (file == NULL) {
                printf("File not found. Shutting down.\n");
                exit(1);
            }

            JavaClass class_file;

            class_file.magic_number = ClassFileReader::read_4_bytes(file);
            // realiza a leitura das versões no formato major.minor
            class_file.minor_version =  ClassFileReader::read_2_bytes(file);
            class_file.major_version = ClassFileReader::read_2_bytes(file);

            class_file.constant_pool_count = ClassFileReader::read_2_bytes(file); // lê quantos constat_pool existem neste arquivo
            class_file.constant_pool = (CpInfo*)malloc((class_file.constant_pool_count-1)*sizeof(CpInfo));
            CpInfo::read(file, class_file);

            class_file.access_flags = ClassFileReader::read_2_bytes(file);
            class_file.this_class = ClassFileReader::read_2_bytes(file);
            class_file.super_class = ClassFileReader::read_2_bytes(file);

            class_file.interfaces_count = ClassFileReader::read_2_bytes(file);
            class_file.interfaces = (u2*)malloc(class_file.interfaces_count*sizeof(u2));
            ClassFileReader::read_interfaces(class_file, file);

            class_file.fields_count = ClassFileReader::read_2_bytes(file);
            class_file.fields = (FieldInfo*)malloc(class_file.fields_count * sizeof(FieldInfo));
            FieldInfo::read(class_file, file);

            class_file.methods_count = read_2_bytes(file);
            class_file.methods = (MethodInfo*) malloc(class_file.methods_count * sizeof(MethodInfo));
            MethodInfo::read(class_file, file);
//
//            class_file.attributes_count = read_2_bytes(file);
//            class_file.attributes = (AttributeInfo*)malloc(class_file.attributes_count * sizeof(AttributeInfo));
//            AttributeInfo::read(class_file, file);

            return class_file;

        }


        static void read_interfaces(JavaClass class_file, FILE* file){
            for (int i = 0; i < class_file.interfaces_count ; i++) {
                class_file.interfaces[i] = ClassFileReader::read_2_bytes(file);
            }
        }

        /** @brief Lê 1 byte.
        *  @param fp ...
        *  @return uint16_t ...
        */
        static uint8_t read_1_byte(FILE* fp) {
            uint8_t bytes_read = getc(fp);
            return bytes_read;
        }

        /** @brief Lê 2 bytes.
         *  @param fp ...
         *  @return uint16_t ...
         */
        static uint16_t read_2_bytes(FILE* fp) {
            uint16_t bytes_read = getc(fp);
            bytes_read = (bytes_read << 8) | (getc(fp));
            return bytes_read;
        }

        /** @brief Lê 4 bytes.
         *  @param fp ...
         *  @return uint32_t ...
         */
        static uint32_t read_4_bytes(FILE* fp) {
            uint32_t bytes_read = getc(fp);
            bytes_read = (bytes_read << 8) | (getc(fp));
            bytes_read = (bytes_read << 8) | (getc(fp));
            bytes_read = (bytes_read << 8) | (getc(fp));
            return bytes_read;
        }

};