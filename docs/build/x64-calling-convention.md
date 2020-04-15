---
title: Convenção de chamada x64
description: Detalhes da convenção de chamada padrão x64 ABI.
ms.date: 12/17/2018
ms.assetid: 41ca3554-b2e3-4868-9a84-f1b46e6e21d9
ms.openlocfilehash: caf22172ea5e9c20280bce8e508d72fd30c00c5b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81335128"
---
# <a name="x64-calling-convention"></a>Convenção de chamada x64

Esta seção descreve os processos e convenções padrão que uma função (o chamador) usa para fazer chamadas em outra função (a callee) em código x64.

## <a name="calling-convention-defaults"></a>Chamada de padrões de convenção

A interface binária de aplicativo x64 (ABI) usa uma convenção de chamada de chamada rápida de quatro registros por padrão. O espaço é alocado na pilha de chamadas como uma loja de sombras para os callees salvarem esses registros. Há uma correspondência estrito entre os argumentos de uma chamada de função e os registros usados para esses argumentos. Qualquer argumento que não se encaixe em 8 bytes, ou não seja 1, 2, 4 ou 8 bytes, deve ser aprovado por referência. Um único argumento nunca é espalhado em vários registros. A pilha de registro x87 não é utilizada e pode ser usada pela callee, mas deve ser considerada volátil entre as chamadas de função. Todas as operações de ponto flutuante são feitas usando os registros de 16 XMM. Os argumentos inteiros são passados nos registros RCX, RDX, R8 e R9. Os argumentos de ponto flutuante são passados em XMM0L, XMM1L, XMM2L e XMM3L. Os argumentos de 16 bytes são aprovados por referência. A passagem de parâmetros é descrita em detalhes em [Passagem de Parâmetro](#parameter-passing). Além desses registros, RAX, R10, R11, XMM4 e XMM5 são considerados voláteis. Todos os outros registros não são voláteis. O uso do registro é documentado em detalhes no [Registro de Uso](../build/x64-software-conventions.md#register-usage) e Registros [Salvos de Chamada/Chamada](#callercallee-saved-registers).

Para funções protótipos, todos os argumentos são convertidos para os tipos de callee esperados antes de passar. O chamador é responsável por alocar espaço para parâmetros para a callee, e deve sempre alocar espaço suficiente para armazenar quatro parâmetros de registro, mesmo que a chamada não tome tantos parâmetros. Esta convenção simplifica o suporte para funções de linguagem C não protótipos e funções vararg C/C+++. Para funções vararg ou não protótipos, quaisquer valores de ponto flutuante devem ser duplicados no registro de propósito geral correspondente. Quaisquer parâmetros além dos quatro primeiros devem ser armazenados na pilha após a loja de sombras antes da chamada. Os detalhes da função vararg podem ser encontrados em [Varargs](#varargs). As informações de função não protótipos são detalhadas em [Funções Não protótipos](#unprototyped-functions).

## <a name="alignment"></a>Alinhamento

A maioria das estruturas estão alinhadas ao seu alinhamento natural. As principais exceções são `malloc` `alloca` o ponteiro de pilha e ou memória, que estão alinhados a 16 bytes para ajudar o desempenho. O alinhamento acima de 16 bytes deve ser feito manualmente, mas como 16 bytes é um tamanho de alinhamento comum para operações XMM, esse valor deve funcionar para a maioria dos códigos. Para obter mais informações sobre o layout e o alinhamento da estrutura, consulte [Tipos e Armazenamento](../build/x64-software-conventions.md#types-and-storage). Para obter informações sobre o layout da pilha, consulte o [uso da pilha x64](../build/stack-usage.md).

## <a name="unwindability"></a>Inwindability

Funções de folha são funções que não alteram nenhum registro não volátil. Uma função não-folha pode alterar o RSP não volátil, por exemplo, chamando uma função ou alocando espaço de pilha adicional para variáveis locais. Para recuperar registros não voláteis quando uma exceção é tratada, as funções não-folha devem ser anotadas com dados estáticos que descrevem como desenrolar adequadamente a função em uma instrução arbitrária. Esses dados são armazenados como *pdata*, ou dados de procedimento, que por sua vez se refere a *xdata*, os dados de tratamento de exceção. Os xdata contêm as informações de sumidorde e podem apontar para pdatas adicionais ou uma função de manipulador de exceção. Prólogos e epílogs são altamente restritos para que possam ser descritos corretamente em xdata. O ponteiro de pilha deve ser alinhado a 16 bytes em qualquer região de código que não faça parte de um epílogo ou prólogo, exceto dentro das funções da folha. As funções do leaf podem ser desbobinadas simplesmente simulando um retorno, de modo que pdata e xdata não são necessários. Para obter detalhes sobre a estrutura adequada de prólogs e epílogs de função, consulte [o prólogo e o epílog x64](../build/prolog-and-epilog.md). Para obter mais informações sobre o manuseio de exceções e o tratamento de exceções e o desenrolar de pdata sexdata, consulte [o tratamento de exceções x64](../build/exception-handling-x64.md).

## <a name="parameter-passing"></a>Passagem de parâmetro

Os quatro primeiros argumentos inteiros são passados em registros. Os valores inteiros são passados em ordem da esquerda para a direita em RCX, RDX, R8 e R9, respectivamente. Argumentos cinco ou mais são passados na pilha. Todos os argumentos são justos nos registros, de modo que a callee pode ignorar os bits superiores do registro e acessar apenas a parte do registro necessário.

Quaisquer argumentos de ponto flutuante e dupla precisão nos quatro primeiros parâmetros são passados em XMM0 - XMM3, dependendo da posição. O inteiro registra RCX, RDX, R8 e R9 que normalmente seriam usados para essas posições são ignorados, exceto no caso de argumentos varargs. Para obter detalhes, consulte [Varargs](#varargs). Da mesma forma, os registros XMM0 - XMM3 são ignorados quando o argumento correspondente é um inteiro ou tipo ponteiro.

[__m128](../cpp/m128.md) tipos, matrizes e strings nunca são passados por valor imediato. Em vez disso, um ponteiro é passado para a memória alocada pelo chamador. Estruturas e sindicatos de tamanho 8, 16, 32 ou 64 bits, e __m64 tipos, são passados como se fossem inteiros do mesmo tamanho. Estruturas ou sindicatos de outros tamanhos são passados como um ponteiro para a memória alocada pelo chamador. Para esses tipos agregados passados como ponteiro, incluindo \__m128, a memória temporária alocada pelo chamador deve estar alinhada com 16 bytes.

Funções intrínsecas que não alocam espaço em pilha, e não chamam outras funções, às vezes usam outros registros voláteis para passar argumentos de registro adicionais. Essa otimização é possível pela estreita ligação entre o compilador e a implementação da função intrínseca.

A calee é responsável por despejar os parâmetros de registro em seu espaço de sombra, se necessário.

A tabela a seguir resume como os parâmetros são passados:

|Tipo de parâmetro|Como passou|
|--------------------|----------------|
|Ponto flutuante|Primeiros 4 parâmetros - XMM0 a XMM3. Outros passaram em pilha.|
|Integer|Primeiros 4 parâmetros - RCX, RDX, R8, R9. Outros passaram em pilha.|
|Agregados (8, 16, 32 ou 64 bits) e __m64|Primeiros 4 parâmetros - RCX, RDX, R8, R9. Outros passaram em pilha.|
|Agregados (outros)|Por ponteiro. Os primeiros 4 parâmetros passaram como ponteiros em RCX, RDX, R8 e R9|
|__m128|Por ponteiro. Os primeiros 4 parâmetros passaram como ponteiros em RCX, RDX, R8 e R9|

### <a name="example-of-argument-passing-1---all-integers"></a>Exemplo de argumento passando 1 - todos os inteiros

```cpp
func1(int a, int b, int c, int d, int e);
// a in RCX, b in RDX, c in R8, d in R9, e pushed on stack
```

### <a name="example-of-argument-passing-2---all-floats"></a>Exemplo de argumento passando 2 - todos os carros alegóricos

```cpp
func2(float a, double b, float c, double d, float e);
// a in XMM0, b in XMM1, c in XMM2, d in XMM3, e pushed on stack
```

### <a name="example-of-argument-passing-3---mixed-ints-and-floats"></a>Exemplo de argumento passando 3 - ints mistos e carros alegóricos

```cpp
func3(int a, double b, int c, float d);
// a in RCX, b in XMM1, c in R8, d in XMM3
```

### <a name="example-of-argument-passing-4--__m64-__m128-and-aggregates"></a>Exemplo de argumento passando \_4 -__m64, _m128 e agregados

```cpp
func4(__m64 a, _m128 b, struct c, float d);
// a in RCX, ptr to b in RDX, ptr to c in R8, d in XMM3
```

## <a name="varargs"></a>Varargs

Se os parâmetros forem aprovados através de varargs (por exemplo, argumentos de elipse), então a convenção de aprovação de parâmetros de registro normal se aplica, incluindo o derramamento do quinto e subsequente argumentos para a pilha. É responsabilidade da callee descartar argumentos que tenham seu endereço tomado. Somente para valores de ponto flutuante, tanto o registro inteiro quanto o registro de ponto flutuante devem conter o valor, caso a callee espere o valor nos registros inteiros.

## <a name="unprototyped-functions"></a>Funções não protótipos

Para funções não totalmente protótipos, o chamador passa valores inteiros como inteiros e valores de ponto flutuante como dupla precisão. Apenas para valores de ponto flutuante, tanto o registro inteiro quanto o registro de ponto flutuante contêm o valor flutuante caso a caderência espere o valor nos registros inteiros.

```cpp
func1();
func2() {   // RCX = 2, RDX = XMM1 = 1.0, and R8 = 7
   func1(2, 1.0, 7);
}
```

## <a name="return-values"></a>Valores retornados

Um valor de retorno escalar que pode caber em 64 bits é devolvido através do RAX; isso inclui __m64 tipos. Tipos não escalares, incluindo carros alegóricos, duplos e tipos de vetores, como [__m128,](../cpp/m128.md) [__m128i,](../cpp/m128i.md) [__m128d](../cpp/m128d.md) são devolvidos em XMM0. O estado dos bits não utilizados no valor devolvido em RAX ou XMM0 é indefinido.

Os tipos definidos pelo usuário podem ser retornados por valor a partir de funções globais e funções de membros estáticos. Para retornar um tipo definido pelo usuário por valor no RAX, ele deve ter um comprimento de 1, 2, 4, 8, 16, 32 ou 64 bits. Também não deve ter nenhum construtor, destruidor ou operador de atribuição de cópia definido pelo usuário; nenhum membro de dados não estático sético ou privado; nenhum membro de dados não estático do tipo de referência; sem classes básicas; sem funções virtuais; e nenhum membro de dados que também não atenda a esses requisitos. (Esta é essencialmente a definição de um tipo POD C++03. Como a definição mudou no padrão C++11, não `std::is_pod` recomendamos o uso para este teste.) Caso contrário, o chamador assume a responsabilidade de alocar memória e passar um ponteiro para o valor de retorno como o primeiro argumento. Os argumentos subseqüentes são então deslocados um argumento para a direita. O mesmo ponteiro deve ser devolvido pela callee em RAX.

Esses exemplos mostram como parâmetros e valores de retorno são passados para funções com as declarações especificadas:

### <a name="example-of-return-value-1---64-bit-result"></a>Exemplo de valor de retorno 1 - resultado de 64 bits

```Output
__int64 func1(int a, float b, int c, int d, int e);
// Caller passes a in RCX, b in XMM1, c in R8, d in R9, e pushed on stack,
// callee returns __int64 result in RAX.
```

### <a name="example-of-return-value-2---128-bit-result"></a>Exemplo de valor de retorno 2 - resultado de 128 bits

```Output
__m128 func2(float a, double b, int c, __m64 d);
// Caller passes a in XMM0, b in XMM1, c in R8, d in R9,
// callee returns __m128 result in XMM0.
```

### <a name="example-of-return-value-3---user-type-result-by-pointer"></a>Exemplo de valor de retorno 3 - resultado do tipo de usuário por ponteiro

```Output
struct Struct1 {
   int j, k, l;    // Struct1 exceeds 64 bits.
};
Struct1 func3(int a, double b, int c, float d);
// Caller allocates memory for Struct1 returned and passes pointer in RCX,
// a in RDX, b in XMM2, c in R9, d pushed on the stack;
// callee returns pointer to Struct1 result in RAX.
```

### <a name="example-of-return-value-4---user-type-result-by-value"></a>Exemplo de valor de retorno 4 - resultado do tipo de usuário por valor

```Output
struct Struct2 {
   int j, k;    // Struct2 fits in 64 bits, and meets requirements for return by value.
};
Struct2 func4(int a, double b, int c, float d);
// Caller passes a in RCX, b in XMM1, c in R8, and d in XMM3;
// callee returns Struct2 result by value in RAX.
```

## <a name="callercallee-saved-registers"></a>Registros salvos do chamador/Callee

Os registros RAX, RCX, RDX, R8, R9, R10, R11, XMM0-5 e as porções superiores de YMM0-15 e ZMM0-15 são considerados voláteis e devem ser considerados destruídos em chamadas de função (salvo de outra forma, com prova de segurança por análises como a otimização de todo o programa). No AVX512VL, os registros ZMM, YMM e XMM 16-31 são voláteis.

Os registros RBX, RBP, RDI, RSI, RSP, R12, R13, R14, R15 e XMM6-15 são considerados não voláteis e devem ser salvos e restaurados por uma função que os utiliza.

## <a name="function-pointers"></a>Ponteiros de função

Ponteiros de função são simplesmente ponteiros para o rótulo da respectiva função. Não há requisitos de tabela de conteúdo (TOC) para ponteiros de função.

## <a name="floating-point-support-for-older-code"></a>Suporte de ponto flutuante para código mais antigo

Os registros de pilha de MMX e de ponto flutuante (MM0-MM7/ST0-ST7) são preservados entre os switches de contexto. Não há convenção de chamada explícita para esses registros. O uso desses registros é estritamente proibido no código do modo kernel.

## <a name="fpcsr"></a>FpCsr

O estado de registro também inclui a palavra de controle FPU x87. A convenção de chamada dita que este registro não é volátil.

O registro de palavra de controle x87 FPU é definido para os seguintes valores padrão no início da execução do programa:

| Registre\[bits] | Configuração |
|-|-|
| FPCSR\[0:6] | Máscaras de exceção todas as 1's (todas as exceções mascaradas) |
| FPCSR\[7] | Reservado - 0 |
| FPCSR\[8:9] | Controle de Precisão - 10B (dupla precisão) |
| FPCSR\[10:11] | Controle de arredondamento - 0 (rodada a mais próxima) |
| FPCSR\[12] | Controle infinito - 0 (não utilizado) |

Uma chamada que modifique qualquer um dos campos dentro do FPCSR deve restaurá-los antes de retornar ao seu chamador. Além disso, um chamador que modificou qualquer um desses campos deve restaurá-los aos seus valores padrão antes de invocar uma callee, a menos que, por acordo, a callee espere os valores modificados.

Há duas exceções às regras sobre a não volatilidade das bandeiras de controle:

1. Em funções onde o propósito documentado da função dada é modificar as bandeiras FpCsr não voláteis.

1. Quando é comprovadamente correto que a violação dessas regras resulte em um programa que se comporta da mesma forma que um programa onde essas regras não são violadas, por exemplo, através de análises de programas inteiros.

## <a name="mxcsr"></a>MxCsr

O estado de registro também inclui MxCsr. A convenção de chamada divide este registro em uma parte volátil e uma porção não volátil. A parte volátil consiste nos seis sinalizadores de\[status, em MXCSR 0:5],\[enquanto o resto do registro, MXCSR 6:15], é considerado não volátil.

A parte não volátil é definida para os seguintes valores padrão no início da execução do programa:

| Registre\[bits] | Configuração |
|-|-|
| MXCSR\[6] | Denormals são zeros - 0 |
| MXCSR\[7:12] | Máscaras de exceção todas as 1's (todas as exceções mascaradas) |
| MXCSR\[13:14] | Controle de arredondamento - 0 (rodada a mais próxima) |
| MXCSR\[15] | Flush a zero para subfluxo mascarado - 0 (off) |

Uma chamada que modifique qualquer um dos campos não voláteis dentro do MXCSR deve restaurá-los antes de retornar ao seu chamador. Além disso, um chamador que modificou qualquer um desses campos deve restaurá-los aos seus valores padrão antes de invocar uma callee, a menos que, por acordo, a callee espere os valores modificados.

Há duas exceções às regras sobre a não volatilidade das bandeiras de controle:

- Em funções onde o propósito documentado da função dada é modificar as bandeiras MxCsr não voláteis.

- Quando é comprovadamente correto que a violação dessas regras resulte em um programa que se comporta da mesma forma que um programa onde essas regras não são violadas, por exemplo, através de análises de programas inteiros.

Nenhuma suposição pode ser feita sobre o estado da porção volátil do MXCSR através de um limite de função, a menos que especificamente descrito na documentação de uma função.

## <a name="setjmplongjmp"></a>setjmp/longjmp

Quando você inclui setjmpex.h ou setjmp.h, todas as chamadas para [setjmp](../c-runtime-library/reference/setjmp.md) ou [longjmp](../c-runtime-library/reference/longjmp.md) resultam em um desenrolar que invoca destructores e `__finally` chamadas.  Isso difere de x86, onde incluindo setsjmp.h resulta em `__finally` cláusulas e destruidores não sendo invocados.

Uma chamada `setjmp` para preservar o ponteiro de pilha atual, registros não voláteis e registros MxCsr.  Chamadas `longjmp` para retornar ao `setjmp` site de chamada mais recente e redefinir o ponteiro de pilha, registros não voláteis e `setjmp` registros MxCsr, de volta ao estado como preservado pela chamada mais recente.

## <a name="see-also"></a>Confira também

[Convenções de software x64](../build/x64-software-conventions.md)
