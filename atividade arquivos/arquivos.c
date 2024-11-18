#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FAVORITOS 100
#define MAX_VIDEOS 1000
#define MAX_USUARIOS 1000
#define MAX_NOME 100

struct Video {
    int id;
    char nome[MAX_NOME];
    char genero[MAX_NOME];
};

struct Usuario {
    int id;
    char nome[MAX_NOME];
    int favoritos[MAX_FAVORITOS];
};

void lerStr(char *str, int tam);
void inicializarDados(struct Video videos[], struct Usuario usuarios[], int tamVideos, int tamFavoritos);
void cadastrarVideo(struct Video videos[], int tam);
void cadastrarUsuario(struct Usuario usuarios[], int tam);
void exibirVideo(int idVideo);
void exibirUsuario(int idUsuario, int tamFavoritos);
void exibirUsuariosEVideos(int tamFavoritos);
void atualizarVideo(int idVideo);
void atualizarUsuario(int idUsuario, int tamFavoritos);
void excluirVideo(int idVideo);
void excluirUsuario(int idUsuario);
void relatorioFavoritos(int tamFavoritos);
void relatorioVideosCadastrados(int tamFavoritos);

int main() {
    struct Video videos[MAX_VIDEOS];
    struct Usuario usuarios[MAX_USUARIOS];
    int opcao;
    inicializarDados(videos, usuarios, MAX_VIDEOS, MAX_FAVORITOS);

    do {
        printf("\nO QUE VOCE DESEJA FAZER?\n");
        printf("1 - Cadastrar video\n");
        printf("2 - Cadastrar usuario\n");
        printf("3 - Exibir video especifico\n");
        printf("4 - Exibir usuario especifico\n");
        printf("5 - Exibir todos os usuarios e videos\n");
        printf("6 - Atualizar dados de um video\n");
        printf("7 - Atualizar dados de um usuario\n");
        printf("8 - Excluir video\n");
        printf("9 - Excluir usuario\n");
        printf("10 - Relatorio de videos favoritos\n");
        printf("11 - Relatorio de videos cadastrados\n");
        printf("0 - Fechar programa\n");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: {
                cadastrarVideo(videos, MAX_VIDEOS);
                break;
            }
            case 2: {
                cadastrarUsuario(usuarios, MAX_USUARIOS);
                break;
            }
            case 3: {
                int idVideo;
                printf("\nDigite o ID do video: ");
                scanf("%d", &idVideo);
                exibirVideo(idVideo);
                break;
            }
            case 4: {
                int idUsuario;
                printf("\nDigite o ID do usuario: ");
                scanf("%d", &idUsuario);
                exibirUsuario(idUsuario, MAX_FAVORITOS);
                break;
            }
            case 5: {
                exibirUsuariosEVideos(MAX_FAVORITOS);
                break;
            }
            case 6: {
                int idVideo;
                printf("\nDigite o ID do video: ");
                scanf("%d", &idVideo);
                getchar();
                atualizarVideo(idVideo);
                break;
            }
            case 7: {
                int idUsuario;
                printf("\nDigite o ID do usuario: ");
                scanf("%d", &idUsuario);
                getchar();
                atualizarUsuario(idUsuario, MAX_FAVORITOS);
                break;
            }
            case 8: {
                int idVideo;
                printf("\nDigite o ID do video que deseja excluir: ");
                scanf("%d", &idVideo);
                excluirVideo(idVideo);
                break;
            }
            case 9: {
                int idUsuario;
                printf("\nDigite o ID do usuario que deseja excluir: ");
                scanf("%d", &idUsuario);
                excluirUsuario(idUsuario);
                break;
            }
            case 10: {
                relatorioFavoritos(MAX_FAVORITOS);
                break;
            }
            case 11: {
                relatorioVideosCadastrados(MAX_FAVORITOS);
                break;
            }
            case 0: {
                printf("Encerrando o programa.\n");
                break;
            }
            default: {
                printf("Opcao invalida.\n");
                break;
            }
        }
    } while(opcao != 0);

    return 0;
}

void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void inicializarDados(struct Video videos[], struct Usuario usuarios[], int tamVideos, int tamFavoritos) {
    for(int i = 0; i < tamVideos; ++i) {
        videos[i].id = 0;
        usuarios[i].id = 0;
        for(int j = 0; j < tamFavoritos; ++j) {
            usuarios[i].favoritos[j] = 0;
        }
    }
}

void cadastrarVideo(struct Video videos[], int tam) {
    char temp[MAX_NOME];
    int i = 0;
    while(i < tam && videos[i].id != 0) {
        ++i;
    }
    if(i == tam) {
        printf("\nLimite de video atingido.\n");
        return;
    }
    printf("\nCADASTRO VIDEO\n");
    printf("Video ID: ");
    scanf("%d", &videos[i].id);
    lerStr(temp, MAX_NOME);
    printf("Nome do video: ");
    lerStr(videos[i].nome, MAX_NOME);
    printf("Genero: ");
    lerStr(videos[i].genero, MAX_NOME);
    FILE *arqVideos = fopen("Videos.bin", "ab");
    if(arqVideos == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return;
    }
    if (fwrite(&videos[i], sizeof(struct Video), 1, arqVideos) != 1) {
        printf("Erro ao escrever no arquivo.\n");
    }
    fclose(arqVideos);
}

void cadastrarUsuario(struct Usuario usuarios[], int tam) {
    char temp[MAX_NOME];
    int i = 0, idVideo;
    while(i < tam && usuarios[i].id != 0) {
        ++i;
    }
    if(i == tam) {
        printf("Limite de usuarios atingido.\n");
        return;
    }
    printf("\nCADASTRO USUARIO\n");
    lerStr(temp, MAX_NOME);
    printf("Nome do usuario: ");
    lerStr(usuarios[i].nome, MAX_NOME);
    printf("ID do usuario: ");
    scanf("%d", &usuarios[i].id);
    printf("ID dos videos favoritos (Um por vez. 0 para encerrar): ");
    for(int j = 0; j < tam; ++j) {
        scanf("%d", &idVideo);
        if(idVideo == 0) {
            break;
        }
        usuarios[i].favoritos[j] = idVideo;
    }
    lerStr(temp, MAX_NOME);
    FILE *arqUsuarios = fopen("Usuarios.bin", "ab");
    if(arqUsuarios == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return;
    }
    if (fwrite(&usuarios[i], sizeof(struct Usuario), 1, arqUsuarios) != 1) {
        printf("Erro ao escrever no arquivo.\n");
    }
    fclose(arqUsuarios);
}

void exibirVideo(int idVideo) {
    struct Video video;
    int encontrado = 0;
    FILE *arqVideos = fopen("Videos.bin", "rb");
    if (arqVideos == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return;
    }
    while(fread(&video, sizeof(struct Video), 1, arqVideos)) {
        if(video.id == idVideo) {
            printf("Video encontrado.\n");
            printf("ID: %d\n", video.id);
            printf("Nome do video: %s\n", video.nome);
            printf("Genero: %s\n", video.genero);
            encontrado = 1;
            break;
        }
    }
    if(!encontrado) {
        printf("Video com o ID %d nao encontrado no arquivo.\n", video.id);
    }
    fclose(arqVideos);
}

void exibirUsuario(int idUsuario, int tam) {
    struct Usuario usuario;
    int encontrado = 0;
    FILE *arqUsuarios = fopen("Usuarios.bin", "rb");
    if (arqUsuarios == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return;
    }
    while(fread(&usuario, sizeof(struct Usuario), 1, arqUsuarios)) {
        if(usuario.id == idUsuario) {
            printf("Usuario encontrado.\n");
            printf("ID: %d\n", usuario.id);
            printf("Nome: %s\n", usuario.nome);
            printf("Videos favoritos: ");
            for(int i = 0; i < tam && usuario.favoritos[i] != 0; i++) {
                printf("%d ", usuario.favoritos[i]);
            }
            printf("\n");
            encontrado = 1;
            break;
        }
    }
    if(!encontrado) {
        printf("Usuario com o ID %d nao encontrado no arquivo.\n", usuario.id);
    }
    fclose(arqUsuarios);
}

void exibirUsuariosEVideos(int tam) {
    struct Usuario usuario;
    struct Video video;
    FILE *arqUsuarios = fopen("Usuarios.bin", "rb");
    FILE *arqVideos = fopen("Videos.bin", "rb");
    if (arqUsuarios == NULL || arqVideos == NULL) {
        printf("Erro ao abrir arquivos!\n");
        return;
    }
    printf("\nUsuarios cadastrados:\n");
    while(fread(&usuario, sizeof(struct Usuario), 1, arqUsuarios)) {
        printf("ID: %d, Nome: %s\n", usuario.id, usuario.nome);
    }
    fclose(arqUsuarios);

    printf("\nVideos cadastrados:\n");
    while(fread(&video, sizeof(struct Video), 1, arqVideos)) {
        printf("ID: %d, Nome: %s, Genero: %s\n", video.id, video.nome, video.genero);
    }
    fclose(arqVideos);
}

void atualizarVideo(int idVideo) {
    struct Video video;
    int encontrado = 0;
    FILE *arqVideos = fopen("Videos.bin", "rb+");
    if (arqVideos == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return;
    }
    while(fread(&video, sizeof(struct Video), 1, arqVideos)) {
        if(video.id == idVideo) {
            printf("Video encontrado. Insira as novas informacoes.\n");
            printf("Nome do video: ");
            lerStr(video.nome, MAX_NOME);
            printf("Genero: ");
            lerStr(video.genero, MAX_NOME);
            fseek(arqVideos, -sizeof(struct Video), SEEK_CUR);
            if (fwrite(&video, sizeof(struct Video), 1, arqVideos) != 1) {
                printf("Erro ao atualizar o arquivo.\n");
            }
            encontrado = 1;
            break;
        }
    }
    if(!encontrado) {
        printf("Video com o ID %d nao encontrado.\n", idVideo);
    }
    fclose(arqVideos);
}

void atualizarUsuario(int idUsuario, int tam) {
    struct Usuario usuario;
    int encontrado = 0;
    FILE *arqUsuarios = fopen("Usuarios.bin", "rb+");
    if (arqUsuarios == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return;
    }
    while(fread(&usuario, sizeof(struct Usuario), 1, arqUsuarios)) {
        if(usuario.id == idUsuario) {
            printf("Usuario encontrado. Insira os novos dados.\n");
            printf("Nome do usuario: ");
            lerStr(usuario.nome, MAX_NOME);
            printf("Videos favoritos (Um por vez. 0 para encerrar): ");
            for(int i = 0; i < tam; ++i) {
                scanf("%d", &usuario.favoritos[i]);
                if(usuario.favoritos[i] == 0) {
                    break;
                }
            }
            fseek(arqUsuarios, -sizeof(struct Usuario), SEEK_CUR);
            if (fwrite(&usuario, sizeof(struct Usuario), 1, arqUsuarios) != 1) {
                printf("Erro ao atualizar o arquivo.\n");
            }
            encontrado = 1;
            break;
        }
    }
    if(!encontrado) {
        printf("Usuario com o ID %d nao encontrado.\n", idUsuario);
    }
    fclose(arqUsuarios);
}

void excluirVideo(int idVideo) {
    struct Video video;
    FILE *arqVideos = fopen("Videos.bin", "rb");
    FILE *arqTemp = fopen("TempVideos.bin", "wb");

    if (arqVideos == NULL || arqTemp == NULL) {
        printf("Erro ao abrir arquivos!\n");
        return;
    }

    int encontrado = 0;
    while(fread(&video, sizeof(struct Video), 1, arqVideos)) {
        if(video.id != idVideo) {
            fwrite(&video, sizeof(struct Video), 1, arqTemp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arqVideos);
    fclose(arqTemp);
    
    if(encontrado) {
        remove("Videos.bin");
        rename("TempVideos.bin", "Videos.bin");
        printf("Video excluido com sucesso.\n");
    } else {
        printf("Video com o ID %d nao encontrado.\n", idVideo);
    }
}

void excluirUsuario(int idUsuario) {
    struct Usuario usuario;
    FILE *arqUsuarios = fopen("Usuarios.bin", "rb");
    FILE *arqTemp = fopen("TempUsuarios.bin", "wb");

    if (arqUsuarios == NULL || arqTemp == NULL) {
        printf("Erro ao abrir arquivos!\n");
        return;
    }

    int encontrado = 0;
    while(fread(&usuario, sizeof(struct Usuario), 1, arqUsuarios)) {
        if(usuario.id != idUsuario) {
            fwrite(&usuario, sizeof(struct Usuario), 1, arqTemp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arqUsuarios);
    fclose(arqTemp);
    
    if(encontrado) {
        remove("Usuarios.bin");
        rename("TempUsuarios.bin", "Usuarios.bin");
        printf("Usuario excluido com sucesso.\n");
    } else {
        printf("Usuario com o ID %d nao encontrado.\n", idUsuario);
    }
}

void relatorioFavoritos(int tam) {
    struct Usuario usuario;
    FILE *arqUsuarios = fopen("Usuarios.bin", "rb");
    if (arqUsuarios == NULL) {
        printf("Erro ao abrir o arquivo de usuarios!\n");
        return;
    }

    printf("\nRelatorio de videos favoritos:\n");
    while(fread(&usuario, sizeof(struct Usuario), 1, arqUsuarios)) {
        printf("Usuario: %s\n", usuario.nome);
        printf("Videos favoritos: ");
        for(int i = 0; i < tam && usuario.favoritos[i] != 0; i++) {
            printf("%d ", usuario.favoritos[i]);
        }
        printf("\n");
    }
    fclose(arqUsuarios);
}

void relatorioVideosCadastrados(int tam) {
    struct Video video;
    FILE *arqVideos = fopen("Videos.bin", "rb");
    if (arqVideos == NULL) {
        printf("Erro ao abrir o arquivo de videos!\n");
        return;
    }

    printf("\nRelatorio de videos cadastrados:\n");
    while(fread(&video, sizeof(struct Video), 1, arqVideos)) {
        printf("ID: %d, Nome: %s, Genero: %s\n", video.id, video.nome, video.genero);
    }
    fclose(arqVideos);
}
