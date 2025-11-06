//Roger Guilherme da SIlva CV3096611
#include <stdio.h>
#include <string.h>

#define MAX_VENDEDORES 20
#define MAX_CLIENTES 1000
#define MAX_ATENDIMENTOS 20000

typedef struct {
    char nome[50];
} Vendedor;

typedef struct {
    char nome[50];
} Cliente;

typedef struct {
    char vendedor[50];
    char cliente[50];
    int dia, mes, ano;
    int nota;
} Atendimento;


void cadastrarVendedor(Vendedor vendedores[], int *qtdVendedores);
 void cadastrarCliente(Cliente clientes[], int *qtdClientes);
 void registrarAtendimento(Vendedor vendedores[], int qtdVendedores,
                          Cliente clientes[], int qtdClientes,
                          Atendimento atendimentos[], int *qtdAtendimentos);
void gerarRelatorio(Vendedor vendedores[], int qtdVendedores,
                    Atendimento atendimentos[], int qtdAtendimentos);

int main() {
    static Vendedor vendedores[MAX_VENDEDORES];
     static Cliente clientes[MAX_CLIENTES];
     static Atendimento atendimentos[MAX_ATENDIMENTOS];

    int qtdVendedores = 0, qtdClientes = 0, qtdAtendimentos = 0;
    int opcao = 0;
    char buffer[100];

    while (opcao != 5) {
        printf("\nMENU\n");
        printf("1 - Cadastrar vendedor\n");
        printf("2 - Cadastrar cliente\n");
        printf("3 - Registrar atendimento\n");
        printf("4 - Relatorio de atendimentos\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) continue;
        if (sscanf(buffer, "%d", &opcao) != 1) {
            printf("Digita uma opcao correta\n");
            opcao = 0;
            continue;
        }

        if (opcao == 1)
            cadastrarVendedor(vendedores, &qtdVendedores);
        else if (opcao == 2)
            cadastrarCliente(clientes, &qtdClientes);
        else if (opcao == 3)
            registrarAtendimento(vendedores, qtdVendedores, clientes, qtdClientes, atendimentos, &qtdAtendimentos);
        else if (opcao == 4)
            gerarRelatorio(vendedores, qtdVendedores, atendimentos, qtdAtendimentos);
        else if (opcao == 5)
            printf("Saindo\n");
        else
            printf("ops Opcao invalida\n");
    }

    return 0;
}



 void cadastrarVendedor(Vendedor vendedores[], int *qtdVendedores) {
    int i;
    char buffer[100];

    if (*qtdVendedores >= MAX_VENDEDORES) {
        printf("muito vendedor\n");
        return;
    }

    printf("Nome do vendedor: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return;
    buffer[strcspn(buffer, "\n")] = '\0';

     for (i = 0; i < *qtdVendedores; i++) {
        if (strcmp(vendedores[i].nome, buffer) == 0) {
            printf("ja tem vendedor com esse nome\n");
            return;
        }
    }

    strncpy(vendedores[*qtdVendedores].nome, buffer, sizeof(vendedores[*qtdVendedores].nome) - 1);
     vendedores[*qtdVendedores].nome[sizeof(vendedores[*qtdVendedores].nome) - 1] = '\0';
    (*qtdVendedores)++;
    printf("Vendedor cadastrado\n");
}

void cadastrarCliente(Cliente clientes[], int *qtdClientes) {
    int i;
    char buffer[100];

    if (*qtdClientes >= MAX_CLIENTES) {
        printf("exesso de cliente\n");
        return;
    }

    printf("Nome do cliente: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return;
    buffer[strcspn(buffer, "\n")] = '\0';

    for (i = 0; i < *qtdClientes; i++) {
        if (strcmp(clientes[i].nome, buffer) == 0) {
            printf("ops esse cliente jah esta aqui.\n");
            return;
        }
    }

    strncpy(clientes[*qtdClientes].nome, buffer, sizeof(clientes[*qtdClientes].nome) - 1);
    clientes[*qtdClientes].nome[sizeof(clientes[*qtdClientes].nome) - 1] = '\0';
    (*qtdClientes)++;
    printf("Cliente cadastrado com sucesso!\n");
}

void registrarAtendimento(Vendedor vendedores[], int qtdVendedores,
                          Cliente clientes[], int qtdClientes,
                          Atendimento atendimentos[], int *qtdAtendimentos) {
    char buffer[100];
    int i, vendedorEncontrado = 0, clienteEncontrado = 0;

    if (*qtdAtendimentos >= MAX_ATENDIMENTOS) {
        printf("ops muito atendimento !\n");
        return;
    }

    if (qtdVendedores == 0 || qtdClientes == 0) {
        printf("eh necessario ter pelo menos um vendedor e um cliente cadastrados!\n");
        return;
    }

    Atendimento novo;

    
    printf("Nome do vendedor: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return;
    buffer[strcspn(buffer, "\n")] = '\0';
    for (i = 0; i < qtdVendedores; i++) {
        if (strcmp(vendedores[i].nome, buffer) == 0) {
            vendedorEncontrado = 1;
            strncpy(novo.vendedor, buffer, sizeof(novo.vendedor) - 1);
            novo.vendedor[sizeof(novo.vendedor) - 1] = '\0';
            break;
        }
    }
    if (!vendedorEncontrado) {
        printf("Vendedor nao encontrado!\n");
        return;
    }

    
    printf("Nome do cliente: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return;
    buffer[strcspn(buffer, "\n")] = '\0';
    for (i = 0; i < qtdClientes; i++) {
        if (strcmp(clientes[i].nome, buffer) == 0) {
            clienteEncontrado = 1;
            strncpy(novo.cliente, buffer, sizeof(novo.cliente) - 1);
            novo.cliente[sizeof(novo.cliente) - 1] = '\0';
            break;
        }
    }
    if (!clienteEncontrado) {
        printf("Cliente nao encontrado!\n");
        return;
    }

    
    printf("Data do atendimento (dd mm aaaa): ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return;
    if (sscanf(buffer, "%d %d %d", &novo.dia, &novo.mes, &novo.ano) != 3) {
        printf("Data invalida!\n");
        return;
    }

    
printf("Nota de satisfacao (0 a 10): ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return;
    if (sscanf(buffer, "%d", &novo.nota) != 1 || novo.nota < 0 || novo.nota > 10) {
        printf("Nota invalida!\n");
        return;
    }

    atendimentos[*qtdAtendimentos] = novo;
    (*qtdAtendimentos)++;
    printf("Atendimento registrado com sucesso!\n");
}

void gerarRelatorio(Vendedor vendedores[], int qtdVendedores,
                    Atendimento atendimentos[], int qtdAtendimentos) {
    int i, j, totalNotas, qtdNotas;
    float media;

    if (qtdAtendimentos == 0) {
        printf("Nenhum atendimento registrado.\n");
        return;
    }

    printf("\nRELATORIO DE ATENDIMENTOS\n");

    for (i = 0; i < qtdVendedores; i++) {
        totalNotas = 0;
        qtdNotas = 0;

        for (j = 0; j < qtdAtendimentos; j++) {
            if (strcmp(vendedores[i].nome, atendimentos[j].vendedor) == 0) {
                totalNotas += atendimentos[j].nota;
                qtdNotas++;
            }
        }

     if (qtdNotas > 0) {
            media = (float)totalNotas / qtdNotas;
            printf("Vendedor: %s | Atendimentos: %d | Media de notas: %.2f\n",
                   vendedores[i].nome, qtdNotas, media);
        }
    }
}

