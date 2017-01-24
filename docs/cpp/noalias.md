---
title: "noalias | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "noalias"
  - "noalias_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __declspec [C++], noalias"
  - "palavra-chave noalias __declspec"
ms.assetid: efafa8b0-7f39-4edc-a81e-d287ae882c9b
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# noalias
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 `noalias` significa que uma chamada de função não modifica ou referencia o estado global visível e modifica somente a memória apontada para `directly` pelos parâmetros do ponteiro \(indireções de primeiro nível\).  
  
 Se uma função é anotada como `noalias`, o otimizador pode assumir que, além dos parâmetros em si, somente as indireções de primeiro nível dos parâmetros do ponteiro são referenciadas ou modificadas na função.  O estado global visível é o conjunto de todos os dados que não estão definidos ou referenciados fora do escopo da compilação, e o endereço não é pego.  O escopo da compilação é todos os arquivos de origem \(compilações [\/LTCG \(geração de código do tempo de vinculação\)](../build/reference/ltcg-link-time-code-generation.md)\) ou um único arquivo de origem \(compilação não **\/LTCG**\).  
  
## Exemplo  
 O exemplo a seguir demonstra o uso `__declspec(restrict)` e `__declspec(noalias)`.  Normalmente, a memória de retornada de `malloc` é `restrict` e `noalias` pois os cabeçalhos de CRT são decorados adequadamente.  
  
 No entanto, neste exemplo, os ponteiros `mempool` e `memptr` são globais para que o compilador não tenha segurança de que a memória não está sujeita a alias.  Decorando as funções que retornam ponteiros com `__declspec(restrict)` dizem ao compilador que a memória apontada pelo valor de retorno não possui alias.  
  
 Decorando a função no exemplo que acessa a memória com `__declspec(noalias)` informa o compilador que essa função não interfere no estado global exceto por ponteiros na lista de parâmetros.  
  
```  
// declspec_noalias.c   
#include <stdio.h>  
#include <stdlib.h>  
  
#define M 800  
#define N 600  
#define P 700  
  
float * mempool, * memptr;  
  
__declspec(restrict) float * ma(int size)  
{  
    float * retval;  
    retval = memptr;  
    memptr += size;  
    return retval;  
}  
  
__declspec(restrict) float * init(int m, int n)  
{  
    float * a;  
    int i, j;  
    int k=1;  
  
    a = ma(m * n);  
    if (!a) exit(1);  
    for (i=0; i<m; i++)  
        for (j=0; j<n; j++)  
            a[i*n+j] = 0.1/k++;  
    return a;  
}  
  
__declspec(noalias) void multiply(float * a, float * b, float * c)  
{  
    int i, j, k;  
  
    for (j=0; j<P; j++)  
        for (i=0; i<M; i++)  
            for (k=0; k<N; k++)  
                c[i * P + j] =   
                          a[i * N + k] *   
                          b[k * P + j];  
}  
  
int main()  
{  
    float * a, * b, * c;  
  
    mempool = (float *) malloc(sizeof(float) * (M*N + N*P + M*P));  
  
    if (!mempool)   
    {  
        puts("ERROR: Malloc returned null");  
        exit(1);  
    }  
  
    memptr = mempool;  
    a = init(M, N);  
    b = init(N, P);  
    c = init(M, P);  
  
    multiply(a, b, c);  
}  
```  
  
## Consulte também  
 [\_\_declspec](../cpp/declspec.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)