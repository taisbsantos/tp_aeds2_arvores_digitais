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
            char Index;
            struct TipoPatNo *Esq, *Dir;
        } NInterno ;
char Chave ;
    } NO;
} TipoPatNo;

void inicializa_pat(TipoPatNo **no);
char Bit(char i, char k);
short EExterno(TipoPatNo ** p);
TipoPatNo * CriaNoInt(int i, TipoPatNo **Esq,  TipoPatNo **Dir);
TipoPatNo * CriaNoExt(char k);
TipoPatNo * InsereEntre(char *k, TipoPatNo **t, int i);
TipoPatNo * Insere(char *k, TipoPatNo **t);
void Pesquisa(char *k, TipoPatNo **t);