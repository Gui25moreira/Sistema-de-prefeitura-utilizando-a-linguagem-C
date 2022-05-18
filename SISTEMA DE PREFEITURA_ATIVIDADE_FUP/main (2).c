#include <stdio.h>
#include <stdlib.h>

typedef struct{
    long long int cpf;
    char nome[50];
    char sexo;
    char end[200];
    float imposto;
    float impostoPago;


}Usuario;

typedef struct{
    long long int cnpj;
    char razao_social[100];
    char nome_fantasia[100];
    char end[200];
    float imposto;
    float impostoPago;

}Empresa;



void menu(){
    printf("---------------SISTEMA_IMPOSTO-------------\n");
    printf("(1)* CADASTRAR USUARIO\n");
    printf("(2)* CADASTRAR EMPRESA\n");
    printf("(3)* BUSCAR DADOS DO USUARIO\n");
    printf("(4)* BUSCAR DADOS DA EMPRESA\n");
    printf("(5)* TOTAL DE IMPOSTOS PAGOS\n");
    printf("(6)* QUANTIDADE DE EMPRESAS CADASTRADAS\n");
    printf("(7)* QUANTIDADE DE USUARIOS CADASTRADOS\n");
    printf("(8)* GERAR RELATORIO DE USUARIOS EM TEXTO\n");
    printf("(9)* GERAR RELATORIO DE EMPRESAS EM TEXTO\n");
    printf("(0)* SAIR DO SISTEMA\n");
    printf("\n");

}

void iniciarUsuario(Usuario usuario[], int quant_usuario){
    int i=0;
    for(i=0;i<quant_usuario;i++){
        usuario[i].cpf =-1;
    }
}

void iniciarEmpresa(Empresa empresa[], int quant_empresa){
    int i=0;
    for(i=0;i<quant_empresa;i++){
        empresa[i].cnpj =-1;
    }
}


int cadUsuario(Usuario usuario[], int quant_usuario){
    int cadastrou =0;
    int verificar =0;
    int i =0;
    int j=0;

    long long int aux=0;


        for(i =0;i<quant_usuario;i++){


            if(usuario[i].cpf == -1){

                    printf("INFORME O CPF (DIGITE -1 PARA CANCELAR)\n");
                    scanf("%lld", &usuario[i].cpf);


                    if(usuario[i].cpf == -1){
                        cadastrou =2;
                        i=quant_usuario;
                    }else{

                         aux = usuario[i].cpf;

                         for(j=0 ;j<quant_usuario;j++){
                            if(j != i){

                            if(usuario[j].cpf == aux){
                            usuario[i].cpf = -1;
                            printf("USUARIO JA CADASTRADO\n");
                            verificar = 1;
                            i = quant_usuario;
                            j= quant_usuario;

                                }

                            }

                    }


                    if(verificar == 0){
                    printf("INFORME O NOME\n" );
                    scanf(" %[^\n]", usuario[i].nome);
                    printf("INFORME O SEXO (M)-MASCULINO OU (F)-FEMININO\n");
                    usuario[i].sexo = getche();
                    printf("\n");
                    printf("INFORME O ENDERECO\n");
                    scanf(" %[^\n]", usuario[i].end);
                    printf("INFORME O IMPOSTO\n");
                    scanf("%f", &usuario[i].imposto);
                    usuario[i].impostoPago =0;
                    cadastrou=1;
                    break;

                    }
                    }








            }
        }

    return cadastrou;
}

int cadEmpresa(Empresa empresa[], int quant_empresa){
    int cadastrou =0;
    int verificar =0;
    int i =0;
    int j=0;
    long long int aux=0;


        for(i =0;i<quant_empresa;i++){


            if(empresa[i].cnpj == -1){
                    printf("INFORME O CNPJ (DIGITE -1 PARA CANCELAR)\n");
                    scanf("%lld", &empresa[i].cnpj);


                    if(empresa[i].cnpj == -1){
                        cadastrou = 2;
                        i = quant_empresa;
                    }else{
                        aux = empresa[i].cnpj;


                    for(j=0 ;j<quant_empresa;j++){
                            if(j != i){

                            if(empresa[j].cnpj == aux){
                            empresa[i].cnpj = -1;
                            printf("EMPRESA JA CADASTRADO\n");
                            verificar = 1;
                            i = quant_empresa;
                            j= quant_empresa;

                                }

                            }

                    }


                    if(verificar == 0){
                    printf("INFORME A RAZAO SOCIAL\n" );
                    scanf(" %[^\n]", empresa[i].razao_social);
                    printf("INFORME O NOME FANTASIA\n" );
                    scanf(" %[^\n]", empresa[i].nome_fantasia);
                    printf("INFORME O ENDERECO\n");
                    scanf(" %[^\n]", empresa[i].end);
                    printf("INFORME O IMPOSTO\n");
                    scanf("%f", &empresa[i].imposto);
                    empresa[i].impostoPago =0;
                    cadastrou=1;
                    break;

                    }
                    }



            }
        }

    return cadastrou;
}

void imprimirUsuario(Usuario usuario[], int quant_usuario, long long int cpf){

    int i=0;

    long long int aux_div=0;
    for(i =0;i<quant_usuario;i++){
        if(usuario[i].cpf == cpf){

            aux_div =cpf/10000000000;


            printf("---------USUARIO----------\n");
            if(aux_div ==0){
                printf("CPF: 0%lld\n", usuario[i].cpf);
            }else{
                 printf("CPF: %lld\n", usuario[i].cpf);
            }

            printf("NOME: %s\n",usuario[i].nome);
            printf("SEXP: %c\n", usuario[i].sexo);
            printf("ENDERECO: %s\n", usuario[i].end);
            printf("IMPOSTO : %.2f\n", usuario[i].imposto);
            printf("--------------------------\n");
             // '->' e não '.', pois raiz é um pointer

            printf("\n");
               }
    }
}
void imprimirEmpresa(Empresa empresa[], int quant_empresa, long long int cnpj){
    int i=0;
    long long int aux_div=0;
    for(i =0;i<quant_empresa;i++){
        if(empresa[i].cnpj == cnpj){
           aux_div =cnpj/10000000000000;


            printf("---------EMPRESA----------\n");
            if(aux_div == 0){
                printf("CNPJ: 0%lld\n", empresa[i].cnpj);
            }else{
                printf("CNPJ: %lld\n", empresa[i].cnpj);
            }

            printf("RAZAO SOCIAL: %s\n",empresa[i].razao_social);
            printf("NOME FANTASIA: %s\n", empresa[i].nome_fantasia);
            printf("ENDERECO: %s\n", empresa[i].end);
            printf("IMPOSTO : %.2f\n", empresa[i].imposto);
            printf("--------------------------\n");


            printf("\n");
               }
    }
}

int buscarUsuario(Usuario usuario[], int quant_usuario, long long int cpf){
    int i =0;
    int buscado =0;
    if(cpf == -1){
        buscado =2;
    }else{
        for(i=0;i<quant_usuario;i++){
        if(usuario[i].cpf==cpf){
           buscado =1;
        }
        }

    }

    return buscado;
}

int buscarEmpresa(Empresa empresa[], int quant_empresa, long long int cnpj){
    int i =0;
    int buscado =0;
    if(cnpj == -1){
            buscado =2;
    }else{
        for(i=0;i<quant_empresa;i++){
        if(empresa[i].cnpj==cnpj){
           buscado =1;
        }
    }
    }

    return buscado;
}




int totalEmpresaCadastradas(Empresa empresa[], int quant_empresa){
    int i=0;
    int total_empresa =0;
    for(i =0;i<quant_empresa;i++){
        if(empresa[i].cnpj != -1){
            total_empresa++;
        }
    }
    return total_empresa;
}

int totalUsuarioCadastradas(Usuario usuario[], int quant_usuario){
    int i=0;
    int total_usuario =0;
    for(i =0;i<quant_usuario;i++){
        if(usuario[i].cpf != -1){
            total_usuario++;
        }
    }
    return total_usuario;
}

void totalImposto(Usuario usuario[], Empresa empresa[], int quant_usuario, int quant_empresa){
    int i=0;

    float somaDebitosUsuario =0.0;
    float somaDebitosEmpresa =0.0;
    for(i =0;i<quant_usuario;i++){
        if(usuario[i].cpf != -1){
            somaDebitosUsuario+=usuario[i].impostoPago;
        }

        if(empresa[i].cnpj != -1){
            somaDebitosEmpresa+=empresa[i].impostoPago;
        }
    }


    float somaDebitosCidade = somaDebitosUsuario + somaDebitosEmpresa;

    printf("TOTAL DE IMPOSTOS PAGOS PELOS (USUARIOS) : %.2f\n", somaDebitosUsuario);
    printf("TOTAL DE IMPOSTOS PAGOS PELAS (EMPRESAS) : %.2f\n", somaDebitosEmpresa);
    printf("TOTAL DE IMPOSTOS ARRECADADOS PELA (CIDADE) :%.2f\n", somaDebitosCidade);

    printf("\n");
}


int pagarImpostoUsuario(Usuario usuario[], int quant_usuario, long long int cpf){
    int i=0;
    float desc =0.0;
    int pagou =0;
    char op;
    for(i =0; i<quant_usuario;i++){
        if(usuario[i].cpf == cpf){
                printf("VOCE DESEJA REALIZAR PAGAMENTO (S)-SIM/(N)-NAO\n");
                op = getche();
                printf("\n");
                if(op == 's' || op == 'S'){
                    usuario[i].impostoPago += usuario[i].imposto;
                    pagou = 1;
                    break;


                }
        }

    }
    return pagou;
}

int pagarImpostoEmpresa(Empresa empresa[], int quant_empresa, long long int cnpj){
    int i=0;
    float desc =0.0;
    int pagou =0;
    char op;
    for(i =0; i<quant_empresa;i++){
        if(empresa[i].cnpj == cnpj){
                printf("VOCE DESEJA REALIZAR PAGAMENTO (S)-SIM/(N)-NAO\n");
                op = getche();
                printf("\n");
                if(op == 's' || op == 'S'){
                    empresa[i].impostoPago += empresa[i].imposto;
                    pagou = 1;
                    break;


                    }


              }


         }


     return pagou;
    }

int atualizarImpostoUsuario(Usuario usuario[], int quant_usuario, long long int cpf){
    int i=0;
    int atualizou =0;


    for(i=0;i<quant_usuario;i++){
        if(usuario[i].cpf == cpf){
            printf("INFORME O NOVO VALOR\n");
            scanf("%f", &usuario[i].imposto);
            atualizou =1;
            break;
        }
    }

return atualizou;

}

int atualizarImpostoEmpresa(Empresa empresa[], int quant_empresa, long long int cnpj){
    int i=0;
    int atualizou =0;


    for(i=0;i<quant_empresa;i++){
        if(empresa[i].cnpj == cnpj){
            printf("INFORME O NOVO VALOR\n");
            scanf("%f", &empresa[i].imposto);
            atualizou =1;
            break;
        }
    }

return atualizou;

}

int gerarRelatorioTxtUsuario(Usuario usuario[], int quant_usuario, int total_usuarios_cad){
    int i=0;
    int j=0;
    int gerou =0;
    long long int aux_div=0;
    FILE *arqSaida = fopen("relatorioUsuario.txt", "w");
    for(i=0;i<quant_usuario;i++){

                for(j=0;j<total_usuarios_cad;j++){
                    aux_div =usuario[i].cpf/10000000000;

                    fprintf(arqSaida,"--------------USUARIO-------------\n");
                    if(aux_div == 0){
                        fprintf(arqSaida,"CPF: 0%lld\n", usuario[i].cpf);
                    }else{
                        fprintf(arqSaida,"CPF : %lli\n", usuario[i].cpf);
                    }

                    fprintf(arqSaida,"NOME : %s\n", usuario[i].nome);
                    fprintf(arqSaida,"SEXO : %c\n", usuario[i].sexo);
                    fprintf(arqSaida,"ENDERECO : %s\n", usuario[i].end);
                    fprintf(arqSaida,"IMPOSTO : %.2f\n", usuario[i].imposto);
                    fprintf(arqSaida,"TOTAL IMPOSTO PAGO : %.2f\n", usuario[i].impostoPago);
                    fprintf(arqSaida,"----------------------------------\n");
                    fprintf(arqSaida,"\n");
                    i++;
                    gerou=1;
                    }
                    fclose(arqSaida);

            }
        return gerou;
    }

    int gerarRelatorioTxtEmpresa(Empresa empresa[], int quant_empresa, int total_empresas_cad){
    int i=0;
    int j=0;
    int gerou =0;
    long long int aux_div=0;


    FILE *arqSaida = fopen("relatorioEmpresa.txt", "w");

    for(i=0;i<quant_empresa;i++){

                for(j=0;j<total_empresas_cad;j++){
                    aux_div =empresa[i].cnpj/10000000000000;



                    fprintf(arqSaida,"--------------EMPRESA-------------\n");
                    if(aux_div == 0){
                        fprintf(arqSaida,"CNPJ : 0%lld\n", empresa[i].cnpj);
                    }else{
                        fprintf(arqSaida,"CNPJ : %lld\n", empresa[i].cnpj);
                    }

                    fprintf(arqSaida,"RAZAO SOCIAL : %s\n", empresa[i].razao_social);
                    fprintf(arqSaida,"NOME FANTASIA : %s\n", empresa[i].nome_fantasia);
                    fprintf(arqSaida,"ENDERECO : %s\n", empresa[i].end);
                    fprintf(arqSaida,"IMPOSTO : %.2f\n", empresa[i].imposto);
                    fprintf(arqSaida,"TOTAL IMPOSTO PAGO: %.2f\n", empresa[i].impostoPago);
                    fprintf(arqSaida,"----------------------------------\n");
                    fprintf(arqSaida,"\n");
                    i++;
                    gerou=1;
                    }
                    fclose(arqSaida);

            }
        return gerou;
    }



int main()
{

    long long int cpf;
    long long int cnpj;
    int quant_usuario =100;
    int quant_empresa =50;
    int cadastrou=0;
    int buscou=0;
    int pagou=0;
    int atualizou=0;
    int gerou=0;
    int total_usuario =0;
    int total_empresa =0;
    int total_empresa_restantes=0;
    int total_usuario_restantes=0;
    char op;





    Usuario usuario[quant_usuario];
    Empresa empresa[quant_empresa];

    iniciarUsuario(usuario,quant_usuario);
    iniciarEmpresa(empresa, quant_empresa);

    while(op != '0'){
            menu();
            printf("INFORME SUA OPCAO\n");
            op = getche();
            printf("\n");

        switch(op){
            case '1':

            cadastrou = cadUsuario(usuario,quant_usuario);
                if(cadastrou == 1){
                    printf("CADASTRO REALIZADO\n");
                    cadastrou =0;
                }else if(cadastrou == 0){
                    printf("ERRO EM REALIZAR CADASTRO\n");
                }
                else if(cadastrou == 2){
                    printf("CANCELADO\n");
                }

            break;

         case '2':
           cadastrou =  cadEmpresa(empresa,quant_empresa);
                if(cadastrou == 1){
                    printf("CADASTRO REALIZADO\n");
                    cadastrou =0;
                }else if(cadastrou == 0){
                    printf("ERRO EM REALIZAR CADASTRO\n");
                }
                else if(cadastrou == 2){
                    printf("CANCELADO\n");
                }
            break;
        case '3':
            printf("INFORME O CPF (DIGITE -1 PARA CANCELAR)\n");
            scanf("%lld" ,&cpf);

            buscou = buscarUsuario(usuario,quant_usuario,cpf);
            if(buscou == 1){
                imprimirUsuario(usuario,quant_usuario,cpf);
                printf("(1)* PAGAR IMPOSTO\n");
                printf("(2)* ATUALIZAR IMPOSTO\n");
                printf("(3)* VOLTAR\n");
                op = getche();
                printf("\n");
                    if(op == '1'){
                      pagou = pagarImpostoUsuario(usuario,quant_usuario,cpf);
                        if(pagou == 1){
                            printf("DEBITO REALIZADO\n");
                            pagou =0;
                        }else{
                            printf("ERRO AO REALIZAR O DEBITO\n");
                        }
                    }else
                        if(op == '2'){
                            atualizou = atualizarImpostoUsuario(usuario,quant_usuario,cpf);
                                if(atualizou == 1){
                                    printf("-----USUARIO ATUALIZADO-----\n");
                                    imprimirUsuario(usuario,quant_usuario,cpf);
                                    atualizou =0;
                                }else{
                                    printf("ERRO AO ATUALIZAR USUARIO\n");
                                }

                        }
                    else
                    if(op == '3'){

                    }
                buscou =0;
            }else if(buscou == 0){
                printf("CPF INVALIDO\n");
            }

            else if(buscou == 2){
                printf("CANCELADO\n");
            }
            break;
        case '4':
            printf("INFORME O CNPJ (DIGITE -1 PARA CANCELAR)\n");
            scanf("%lld" ,&cnpj);
            buscou = buscarEmpresa(empresa,quant_empresa,cnpj);
            if(buscou == 1){
                imprimirEmpresa(empresa,quant_empresa,cnpj);
                printf("(1)*PAGAR IMPOSTO\n");
                printf("(2)*ATUALIZAR IMPOSTO\n");
                printf("(3)* VOLTAR\n");
                op = getche();
                printf("\n");
                if(op == '1'){
                   pagou = pagarImpostoEmpresa(empresa,quant_empresa,cnpj);
                    if(pagou == 1){
                       printf("DEBITO REALIZADO\n");
                       pagou=0;
                    }else{
                        printf("ERRO AO REALIZAR DEBITO\n");
                    }
                }
            else
                if(op == '2'){
                atualizou = atualizarImpostoEmpresa(empresa,quant_empresa,cnpj);
                    if(atualizou == 1){
                        printf("-----EMPRESA ATUALIZADO-----\n");
                        imprimirEmpresa(empresa,quant_empresa,cnpj);
                        atualizou=0;
                    }else{
                        printf("ERRO AO ATUALIZAR EMPRESA\n");
                    }
            }

                buscou=0;
            }else if(buscou == 0){
                printf("CNPJ INVALIDO\n");
            }
            else if(buscou == 2){
                printf("CANCELADO\n");
            }
            break;
        case '5':
            totalImposto(usuario,empresa,quant_usuario,quant_empresa);
            break;

        case '6':
                total_empresa = totalEmpresaCadastradas(empresa,quant_empresa);
                total_empresa_restantes = quant_empresa - total_empresa;

                if(total_empresa > 0){
                    printf("TOTAL DE EMPRESAS CADASTRADAS %i\n", total_empresa);
                    printf("TOTAL DE EMPRESAS RESTANTES %i\n", total_empresa_restantes);
                }else{
                    printf("NENHUMA EMPRESA CADASTRADA\n");
                }

            break;

        case '7':
                total_usuario = totalUsuarioCadastradas(usuario,quant_usuario);
                total_usuario_restantes = quant_usuario - total_usuario;

                if(total_usuario > 0){
                    printf("TOTAL DE USUARIOS CADASTRADAS %i\n", total_usuario);
                    printf("TOTAL DE USUARIOS RESTANTES %i\n", total_usuario_restantes);
                }else{
                    printf("NENHUM USUARIO CADASTRADO\n");
                }

            break;
        case '8':
                total_usuario = totalUsuarioCadastradas(usuario,quant_usuario);
                 gerou = gerarRelatorioTxtUsuario(usuario,quant_usuario,total_usuario);
                    if(gerou == 1){
                        printf("RELATORIO GERADO COM SUCESSO\n");
                        gerou =0;
                    }else{
                        printf("FALHA EM GERAR RELATORIO\n");
                    }
            break;
        case '9':
                total_empresa = totalEmpresaCadastradas(empresa,quant_empresa);
                gerou = gerarRelatorioTxtEmpresa(empresa,quant_empresa,total_empresa);
                 if(gerou == 1){
                        printf("RELATORIO GERADO COM SUCESSO\n");
                        gerou=0;
                    }else{
                        printf("FALHA EM GERAR RELATORIO\n");
                    }
            break;
        case '0':
            exit(0);
            break;

        default:
            printf("OP INVALIDO\n");

        }

    system("pause");
    system("cls");
    }
}
