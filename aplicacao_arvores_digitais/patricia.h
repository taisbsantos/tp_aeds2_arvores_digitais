//
// Created by tais on 4/5/19.
//

typedef enum {
    Interno, Externo
} TipoNo;
typedef struct TipoPatNo* TipoArvore;
typedef struct TipoPatNo {
    TipoNo nt;
    union {
        struct {
            int posicao;
            char Index;
            TipoArvore Esq, Dir;
        } NInterno ;
char Chave ;
    } NO;
} TipoPatNo;
char Bit(char i, char k);
short EExterno(TipoArvore p);
TipoArvore CriaNoInt(int i, TipoArvore *Esq,  TipoArvore *Dir);
TipoArvore CriaNoExt(char k);
void Pesquisa(char k, TipoArvore t);
TipoArvore InsereEntre(char k, TipoArvore *t, int i);
TipoArvore Insere(char k, TipoArvore *t);