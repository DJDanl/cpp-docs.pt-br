---
title: Programa de exemplo
ms.date: 11/04/2016
ms.assetid: fc22ef82-9caa-425f-b201-2891bc123d1f
ms.openlocfilehash: fc00ee391fd845039791b8cec727623074a7aeff
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56147120"
---
# <a name="example-program"></a>Programa de exemplo

O seguinte programa de origem de C consiste de dois arquivos de origem. Ele fornece uma visão geral das várias declarações e definições possíveis em um programa C. Seções posteriores neste manual descrevem como gravar essas declarações, definições e inicializações, além de como usar as palavras-chave do C como **static** e `extern`. A função `printf` é declarada no arquivo de cabeçalho STDIO.H do C.

As funções `main` e `max` são assumidas como em arquivos separados e a execução do programa começa com a função `main`. Nenhuma função explícita do usuário é executada antes de `main`.

```
/*****************************************************************
                    FILE1.C - main function
*****************************************************************/

#define ONE     1
#define TWO     2
#define THREE   3
#include <stdio.h>

int a = 1;                       // Defining declarations
int b = 2;                       //  of external variables

extern int max( int a, int b );  // Function prototype

int main()                       // Function definition
{                                //  for main function
    int c;                       // Definitions for
    int d;                       //  two uninitialized
                                 //  local variables

    extern int u;                // Referencing declaration
                                 //  of external variable
                                 //  defined elsewhere
    static int v;                // Definition of variable
                                 //  with continuous lifetime

    int w = ONE, x = TWO, y = THREE;
    int z = 0;

    z = max( x, y );             // Executable statements
    w = max( z, w );
    printf_s( "%d %d\n", z, w );
    return 0;
}

/****************************************************************
            FILE2.C - definition of max function
****************************************************************/

int max( int a, int b )          // Note formal parameters are
                                 //  included in function header
{
    if( a > b )
        return( a );
    else
        return( b );
}
```

FILE1.C contém o protótipo da função `max`. Esse tipo de declaração, às vezes, é chamado de “declaração de encaminhamento” porque a função é declarada antes de ser usada. A definição para a função `main` inclui chamadas a `max`.

As linhas iniciadas com `#define` são políticas do pré-processador. Essas políticas mandam o pré-processador substituir os identificadores `ONE`, `TWO` e `THREE` pelos números `1`, `2` e `3`, respectivamente, por FILE1.C. No entanto, as políticas não se aplicam a FILE2.C, que é compilado separadamente e vinculado com FILE1.C. As linhas iniciadas com `#include` informam o compilador para incluir o arquivo STDIO.H, que contém o protótipo da função `printf`. As [Políticas de pré-processador](../preprocessor/preprocessor-directives.md) são explicadas na *Referência de pré-processador*.

FILE1.C usa a declarações de definição para inicializar as variáveis globais `a` e `b`. As variáveis locais `c` e `d` são declaradas mas não inicializadas. O armazenamento é atribuído a todas esses variáveis. As variáveis estáticas e externas, `u` e `v`, são inicializados automaticamente como 0. Portanto, apenas `a`, `b`, `u`, e `v` contêm valores significativos quando declarados pois são inicializados, explicitamente ou implicitamente. FILE2.C contém a definição de função para `max`. Esta definição satisfaz as chamadas a `max` em. FILE1.C.

O tempo de vida e a visibilidade dos identificadores são discutidos em [Tempo de vida, escopo, visibilidade e vinculação](../c-language/lifetime-scope-visibility-and-linkage.md). Para obter mais informações sobre funções, consulte [Funções](../c-language/functions-c.md).

## <a name="see-also"></a>Consulte também

[Arquivos e programas de origem](../c-language/source-files-and-source-programs.md)
