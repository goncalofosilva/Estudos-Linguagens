#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <windows.h>
#include <ctype.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    FILE * basededados;

    //testes
    //char usernames[100][20], passwords[100][20];
    //100 utilizadores/passwords no maximo e so podem ter 20 caracteres

    int escolha = 0;
    //Igual a zero porque pode comecar com "lixo" de memoria guardado na variavel escolha e se calhar de ser 4 nem começa o programa assim garantimos que está tudo certo

    char usernameinserido[50], passwordinserida[50];
    char usernamebasededados[50], passwordbasededados[50];
    //tem de ter o 50 senao so tem 1 caractere para guardar e o
    //resto que guardar vai se sobrepor a outro codigo e crashar o programa


    //REMOVER DEPOIS:
    //usernames[0] = "goncalo";
    //passwords[0] = "123";
    //assim nao funciona, no C nao da para guardar diretamente no array
    //ou guardamos na criacao do array ex:char usernames[100][20] = {"goncalo"};
    //ou temos de usar uma funcao da libraria string.h "strcpy" string copy
    //strcpy(usernames[0], "goncalo");
    //strcpy(passwords[0], "123");

    //char e %s se for para arrays que vao receber texto
    //int e ("%d", &varivel) para arrays que vao receber sé numeros inteiros

    int totaldeutilizadores = 0; //Atualizar o totaldeutilizadores
    char dados[100];

    basededados = fopen("basededados.txt", "r");
    while(fgets(dados, 100, basededados)) {
        totaldeutilizadores++;

        //limpa a string para na proxima não trazer "lixo"
        dados[0] = '\0';
    }
    // printf("Total de utilizadores: %d", totaldeutilizadores); //%d para numeros inteiros
    fclose(basededados);


    while(escolha != 4){//ciclo while para voltar sempre ao menu ate sair do programa
        printf("1 - Registar utilizador\n");
        printf("2 - Fazer login\n");
        printf("3 - Listar utilizadores\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção(1,2,3,4): ");
        scanf(" %d", &escolha);
        /*Dar um espaço antes do %d, limpa o buffer, se o buffer estiver cheio como
        neste caso ele ira passar esta linha e continuar sempre com a mesma variavel
        escolha ao invez de pedir outravez e a substituir*/

        if (escolha == 1){
            int verificacao = 0;//garantir que a variavel verificacao começa em 0 em cada novo registro

            system("cls");
            printf("- Registrar utilizador\n");
            printf("Username: ");
            scanf("%s", usernameinserido);
            printf("Password: ");
            scanf("%s", passwordinserida);

            // NOTA: não podemos usar "a"(append) e depois fscanf
            //Além disso, não podes ler e escrever ao mesmo tempo no mesmo ponteiro

            basededados = fopen("basededados.txt", "r");
            if (basededados != NULL){
                while (fscanf(basededados, "%[^,], %s\n", usernamebasededados, passwordbasededados) != EOF) {
                        if (strcmp(usernamebasededados, usernameinserido) == 0){// == 0 devolve quando elas forem iguais se for 1 inverte a logica, devolva o contrario
                            verificacao = 1;
                            break;
                        }
                    }
                fclose(basededados);
            }
            else {
                printf("Base de dados inválida.\n");
            }


            if (verificacao == 1){ // tem de ser com 2 iguais "==" senão esta a atribuir o valor a variavel e assim esta sempre a dizer que existe
                printf("Este usuário já existe.");
            }
            else {
                basededados = fopen("basededados.txt", "a");
                fprintf(basededados, "%s, %s\n",usernameinserido, passwordinserida);
                printf("Registro efetuado com sucesso!");
                fclose(basededados);
                totaldeutilizadores++;
            }

            Sleep(2000);//Espera 2 segundos (2000 milisegundos) para continuar o codigo, libraria <windows.h>
            //Já agora podemos usar getchar(); para parar o codigo ate o utilizador dar um enter,
            //bom par quanto o utilizador tiver mesmo de ler alguma coisa antes de continuar
            system("cls");//Limpa o cmd
        }


        else if (escolha == 2){
            int loginSucesso = 0;
            int tentativas = 0;// reseta as tentativas ao voltar a fazer login

            do { //do while, ao invez do while normal, o do while primeiro executa o codigo uma vez e só depois verifica se a condição está correta.
                system("cls"); //limpa o cmd
                printf("- Fazer login (Tentativa %d de 3)\n", tentativas +1);
                printf("Username: ");
                scanf("%s", usernameinserido);
                printf("Password: ");
                scanf("%s", passwordinserida);

                basededados = fopen("basededados.txt", "r");
                if (basededados != NULL) {
                    while (fscanf(basededados, "%[^,], %s\n", usernamebasededados, passwordbasededados) != EOF) {
                        /*
                        -----Oque faz o %[^,]?-----
                        o %[^,] diz ao C para ler tudo ate a virgula(seria o username) e "deita fora" o espaço e a virgula
                        -De uma forma melhor explicada usa se %[^] e depois junto do chapeuzinho dizemos oque queremos
                        que ele não leia neste caso a virgula ou seja ele vai guardar os espaços ainda pois nao demos espaço neste caso
                        e assim é bom pois permite guardar um utilizador com espaço(Gonçalo Silva) depois para na virgula e le o resto

                        Depois o %s lê o resto até ao final da linha ou seja a password

                        -----O que faz o != EOF?-----
                        EOF significa End Of File (Fim do Ficheiro).
                        Quando o C lê um ficheiro, ele não sabe quantos utilizadores lá estão.
                        A função fscanf devolve um valor especial (o EOF) quando tenta ler algo e percebe que o ficheiro acabou.
                        while (fscanf(...) != EOF) significa: "Enquanto não chegares ao fim do ficheiro, continua a ler linha a linha".
                        Sem isto, o teu ciclo while seria infinito ou o programa crasharia ao tentar ler o que não existe.
                        */
                        if (strcmp(usernamebasededados, usernameinserido) == 0 && strcmp(passwordbasededados, passwordinserida) == 0) {
                            // || significa "ou"
                            /* em C nao se pode fazer if(nome == "Ana") pois o C compara os enderecos de memoria
                            e nao as letras, para isso temos de usar o codigo da libraria de strings
                            strcmp (STRING COMPARE) ele entra nesses endereços/moradas e compara letra por letra
                            mais explicacoes do strcmp na pasta de C */
                            loginSucesso = 1;
                            break;
                        }
                    }
                    fclose(basededados);
                }

                if (loginSucesso == 1){
                    system("cls");
                    printf("Login efetuado com sucesso.\n");
                    printf("Bem-vindo %s!", usernameinserido);
                    break; // Sai do do-while
                }
                else {
                    tentativas++;
                    if(tentativas < 3) {
                        printf("Login incorreto! Tens mais %d tentativa(s).\n", 3 - tentativas);
                        Sleep(2000);
                    }
                }
            }
            while (loginSucesso == 0 && tentativas < 3);

            if(loginSucesso == 0) {
                printf("Tentativas esgotadas, peço perdão a culpa é minha.\n");
                printf("Ass:Gonçalo Silva e Joaquim Miranda (criadores da aplicação)");
            }

            Sleep(4000);//Espera 2 segundos (2000 milisegundos) para continuar o codigo, libraria <windows.h>
            system("cls");//limpa o cmd
        }


        else if (escolha == 3){
            system("cls");
            basededados = fopen("basededados.txt", "r");
            if (basededados == NULL) {
                printf("\nERRO: Base de dados não existe!\n");
            }
            else {
                printf("- Lista de utilizadores\n");
                printf("Como ler? (Utilizadores, Passwords)\n");
                printf("\n");
                while(fgets(dados, 100, basededados)) {
                    printf("%s", dados);

                    //limpa a string para na proxima não trazer "lixo"
                    dados[0] = '\0';
                }
                fclose(basededados);
            }
            printf("\nClique Enter para continuar.");
            /*
            fflush(stdin);//limpa o caminho/buffer, pois ele ja tem enter dado no escolha guardado assim passando pelo getchar sem esperar
            getchar();

            Embora funcione em muitos compiladores Windows, o fflush(stdin) não é considerado "boa prática"
            porque o padrão da linguagem C diz que o fflush só deve ser usado para output.

            Alternativa mais segura(while):
            */
            // 1. Limpa qualquer lixo que tenha ficado no buffer (como o Enter do scanf anterior)
            while(getchar() != '\n');

            // 2. Agora que o buffer está limpo,  getchar() vai realmente
            // espera que o utilizador carregue no Enter
            getchar();
            system("cls");
        }


        else if (escolha == 4){
            system("cls");
            char confirmacao;
            printf("Tem a certeza que deseja sair? (S/N): ");
            fflush(stdin); // Limpa o buffer para o scanf não saltar
            scanf("%c", &confirmacao);

            // Para garantir que não da erro de maiusculas ou minusculas podemos adicionar estas funções:
            // toupper (converte tudo em maiusculas)
            // tolower (converte tudo em minusculas)
            confirmacao = tolower(confirmacao);

            if (confirmacao == 's'){
                system("cls");//limpa o cmd
                printf("A encerrar aplicação...\n");
            }
            else {
                escolha = 0; // resetar a escolha para ele nao sair do while
                system("cls");
            }

            // aqui não é preciso break pois o while ja fecha se for escolha = 4
        }


        else {
            printf("\nOpção inválida! Tente novamente (1 a 4).\n");

            // Este  comando "limpa" o erro do teclado
            // sem obrigar o utilizador a carregar em nada
            fflush(stdin);

            Sleep(2000);   // Espera  2 segundos (2000 milisegundos)
            system("cls"); // Limpa o cmd e volta ao menu
        }
    }
    return 0;
}
