//
// Created by tais on 4/5/19.
//

typedef enum {
    Interno, Externo
} TipoNo;

typedef struct TipoPatNo {
    TipoNo nt;
    union {
        struct {
            int posicao;
            char letra_palavra;
            struct TipoPatNo *Esq, *Dir;
        } NInterno ;
        char palavra[50] ;

    } NO;
} TipoPatNo;

void inicializa_pat(TipoPatNo **no);
short EExterno(TipoPatNo * p);
TipoPatNo * CriaNoInt(int i, char letra, TipoPatNo *Esq,  TipoPatNo *Dir);
TipoPatNo * CriaNoExt(char *k);
TipoPatNo * InsereEntre(char *k,TipoPatNo *t, int i, char letra);
TipoPatNo * Insere(char *k, TipoPatNo *t);
void Pesquisa(char *k, TipoPatNo *t);
char max(char a, char b) ;