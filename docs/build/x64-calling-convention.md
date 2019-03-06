---
title: convenção de chamada de x64
description: Detalhes de convenção de chamada de ABI x64 padrão.
ms.date: 12/17/2018
ms.assetid: 41ca3554-b2e3-4868-9a84-f1b46e6e21d9
ms.openlocfilehash: 02bf4719766366049b600b148ad88fc238f4e54e
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57415773"
---
# <a name="x64-calling-convention"></a>convenção de chamada de x64

Esta seção descreve os processos padrão e convenções que uma função (o chamador) usa para fazer chamadas para outra função (receptor) no x64 código.

## <a name="calling-convention-defaults"></a>Padrões de convenção de chamada

X64 Interface binária do aplicativo (ABI) usa uma convenção de chamada de fast-chamada registrar quatro por padrão. Espaço é alocado na pilha de chamadas como um armazenamento de sombra para os receptores salvar esses registros. Há uma correspondência estrita entre os argumentos para uma chamada de função e os registros usados para esses argumentos. Qualquer argumento que não se encaixa em 8 bytes ou não é 1, 2, 4 ou 8 bytes, deve ser passado por referência. Um único argumento nunca é distribuído entre vários registros. Pilha de registro do x87 não é usado e pode ser usado pelo receptor, mas devem ser considerados volátil em chamadas de função. Ponto flutuante de todas as operações são executadas usando a 16 registros XMM registra. Argumentos inteiros são passados nos registradores RCX, RDX, R8 e R9. Os argumentos são passados em XMM0L, XMM1L, XMM2L e XMM3L de ponto flutuante. argumentos de 16 bytes são passados por referência. Passar o parâmetro é descrito detalhadamente no [passagem de parâmetro](#parameter-passing). Além desses registros, XMM5, R10, R11, XMM4 e RAX são considerados voláteis. Todos os outros registros são não-volátil. Registrar uso está documentado em detalhes no [registrar o uso](../build/x64-software-conventions.md#register-usage) e [chamador/receptor salvo registra](#callercallee-saved-registers).

Para funções com protótipo, todos os argumentos são convertidos para os tipos de receptor esperada antes de passar. O chamador é responsável por alocar espaço para os parâmetros para o receptor e sempre deve alocar espaço suficiente para armazenar quatro parâmetros de registro, mesmo se o receptor não tem muitos parâmetros. Essa convenção simplifica o suporte para as funções sem protótipo de linguagem C e C/C++ vararg. Para funções vararg ou unprototyped, qualquer ponto flutuante de valores deve ser duplicada no registro de uso geral correspondente. Todos os parâmetros além os quatro primeiros devem ser armazenados na pilha após a sombra armazenar antes da chamada. Detalhes da função vararg podem ser encontradas no [Varargs](#varargs). Informações de função sem protótipo são detalhadas na [funções sem protótipo](#unprototyped-functions).

## <a name="alignment"></a>Alinhamento

A maioria das estruturas são alinhadas com seu alinhamento natural. As principais exceções são o ponteiro de pilha e `malloc` ou `alloca` memória, que são alinhados com 16 bytes para ajudar o desempenho. Alinhamento acima de 16 bytes deve ser feito manualmente, mas como 16 bytes é um tamanho de alinhamento comum para operações de registros de MMX, esse valor deve funcionar para a maioria dos códigos. Para obter mais informações sobre o layout da estrutura e o alinhamento, consulte [tipos e armazenamento](../build/x64-software-conventions.md#types-and-storage). Para obter informações sobre o layout de pilha, consulte [uso de pilha x64](../build/stack-usage.md).

## <a name="unwindability"></a>Unwindability

Funções de folha são funções que não alteram qualquer registros não voláteis. Uma função não-folha pode mudar RSP não-volátil, por exemplo, chamando uma função ou a alocação de espaço de pilha adicionais para variáveis locais. Para recuperar os registros não voláteis quando uma exceção é manipulada, funções de não-folha devem ser anotadas com os dados estáticos que descreve como desenrolar corretamente a função em uma instrução de arbitrária. Esses dados são armazenados como *pdata*, ou dados de procedimento, que por sua vez, refere-se ao *xdata*, com exceção de manipulação de dados. O xdata contém as informações de desenrolamento e pode apontar para pdata adicional ou uma função de manipulador de exceção. Prólogos e epílogos são altamente restritos para que eles possam ser descritos adequadamente xdata. O ponteiro de pilha deve ser alinhado a 16 bytes em qualquer região do código que não faça parte de um epílogo ou prólogo, exceto nas funções de folha. Funções folha podem desenroladas simplesmente simulando um retorno, portanto, não são necessárias pdata e xdata. Para obter detalhes sobre a estrutura adequada da função Prólogos e epílogos, consulte [x64 prólogo e epílogo](../build/prolog-and-epilog.md). Para obter mais informações sobre o tratamento de exceção e a manipulação de exceção e desenrolamento de pdata e xdata, consulte [x64 tratamento de exceção](../build/exception-handling-x64.md).

## <a name="parameter-passing"></a>Passagem de parâmetro

Os primeiros quatro argumentos inteiros são passados em registros. Valores inteiros são passados na ordem da esquerda para a direita em RCX, RDX, R8 e R9, respectivamente. Argumentos de cinco e superior são passados na pilha. Todos os argumentos são justificados à direita em registros, para que o receptor pode ignorar os bits superiores do registro e acessar apenas a parte do Registro necessária.

Os argumentos de ponto flutuantes e precisão dupla nos primeiros quatro parâmetros são passados em XMM0 - XMM3, dependendo da posição. Os registros de inteiros RCX, RDX, R8 e R9 seriam usados normalmente para essas posições são ignorados, exceto no caso de argumentos de varargs. Para obter detalhes, consulte [Varargs](#varargs). Da mesma forma, o XMM0 - XMM3 registros são ignorados quando o argumento correspondente é um tipo de inteiro ou ponteiro.

[__m128](../cpp/m128.md) tipos, matrizes e cadeias de caracteres nunca são passadas por valor imediato. Em vez disso, um ponteiro é passado para a memória alocada pelo chamador. Estruturas e uniões de tamanho 8, 16, 32 ou 64 bits e os tipos __m64, são passadas como se fossem inteiros do mesmo tamanho. Estruturas ou uniões de outros tamanhos são passadas como um ponteiro para a memória alocada pelo chamador. Para esses tipos de agregação passados como um ponteiro, incluindo \__m128, a memória alocada pelo chamador para temporária deve ser alinhado de 16 bytes.

Funções intrínsecas que não Aloque espaço de pilha e não chamam outras funções, às vezes, usam outros registros voláteis para passar argumentos adicionais do registro. Essa otimização é possibilitada pela ligação forte entre o compilador e a implementação de função intrínseca.

O chamador é responsável por despejar os parâmetros de registro em seu espaço de sombra se necessário.

A tabela a seguir resume como os parâmetros são passados:

|Tipo de parâmetro|Como aprovado|
|--------------------|----------------|
|Ponto flutuante|Primeiro 4 parâmetros - XMM0 por meio de XMM3. Outras pessoas passado na pilha.|
|Inteiro|Primeiro 4 parâmetros - RCX, RDX, R8, R9. Outras pessoas passado na pilha.|
|Agregações (8, 16, 32 ou 64 bits) e __m64|Primeiro 4 parâmetros - RCX, RDX, R8, R9. Outras pessoas passado na pilha.|
|Agregações (outro)|Pelo ponteiro. Primeiro, 4 parâmetros passados como ponteiros em RCX, RDX, R8 e R9|
|__m128|Pelo ponteiro. Primeiro, 4 parâmetros passados como ponteiros em RCX, RDX, R8 e R9|

### <a name="example-of-argument-passing-1---all-integers"></a>Exemplo de 1 - todos os inteiros de passagem de argumento

```cpp
func1(int a, int b, int c, int d, int e);
// a in RCX, b in RDX, c in R8, d in R9, e pushed on stack
```

### <a name="example-of-argument-passing-2---all-floats"></a>Exemplo de passar 2 - floats todos os argumentos

```cpp
func2(float a, double b, float c, double d, float e);
// a in XMM0, b in XMM1, c in XMM2, d in XMM3, e pushed on stack
```

### <a name="example-of-argument-passing-3---mixed-ints-and-floats"></a>Exemplo de 3 - ints misto e flutuações de passagem de argumento

```cpp
func3(int a, double b, int c, float d);
// a in RCX, b in XMM1, c in R8, d in XMM3
```

### <a name="example-of-argument-passing-4--m64-m128-and-aggregates"></a>Exemplo de argumento passando 4-__m64, \__m128 e agregações

```cpp
func4(__m64 a, _m128 b, struct c, float d);
// a in RCX, ptr to b in RDX, ptr to c in R8, d in XMM3
```

## <a name="varargs"></a>Varargs

Se os parâmetros são passados por meio de varargs (por exemplo, argumentos de reticências), em seguida, o convenção de passagem de parâmetro de registro normal se aplica, incluindo despejar o quintas e subsequentes argumentos para a pilha. É responsabilidade do receptor para argumentos de despejo que ter seus endereços obtidos. Para valores de ponto flutuante somente, o registro de inteiro e o registro de ponto flutuante devem conter o valor, caso o receptor espera que o valor em registros de inteiros.

## <a name="unprototyped-functions"></a>Funções sem protótipo

Para funções não totalmente com protótipo, o chamador passa valores inteiros como valores de ponto flutuantes e inteiros como de precisão dupla. Para valores de ponto flutuante somente, o registro de inteiro e o registro de ponto flutuante contêm o valor de float, caso o receptor espera que o valor em registros de inteiros.

```cpp
func1();
func2() {   // RCX = 2, RDX = XMM1 = 1.0, and R8 = 7
   func1(2, 1.0, 7);
}
```

## <a name="return-values"></a>Valores de retorno

Um valor de retorno escalar que pode caber em 64 bits é retornado com o RAX; Isso inclui os tipos __m64. Tipos não escalares incluindo floats, doubles e tipos de vetor, como [__m128](../cpp/m128.md), [__m128i](../cpp/m128i.md), [__m128d](../cpp/m128d.md) são retornados em XMM0. O estado de bits não usados no valor retornado em RAX ou XMM0 é indefinido.

Tipos definidos pelo usuário podem ser retornados pelo valor de funções globais e funções de membro estático. Para retornar um tipo definido pelo usuário pelo valor em RAX, ele deve ter um comprimento de 1, 2, 4, 8, 16, 32 ou 64 bits. Ela também não deve ter nenhum construtor definido pelo usuário, o destruidor ou o operador de atribuição de cópia; Nenhum membro de dados de não estático particular ou protegido; Nenhum membro de dados não estáticos do tipo de referência; Nenhuma classe base; Nenhuma função virtual; e nenhum membro de dados que também não atender a esses requisitos. (Isso é, essencialmente, a definição de um c++03 tipo POD. Como a definição foi alterada no c++11 standard, não recomendamos usar `std::is_pod` para este teste.) Caso contrário, o chamador assume a responsabilidade de alocação de memória e passar um ponteiro para o valor retornado como o primeiro argumento. Os argumentos subsequentes são, em seguida, deslocado um argumento para a direita. O mesmo ponteiro deve ser retornado pelo receptor em RAX.

Estes exemplos mostram como parâmetros e valores de retorno são passadas para funções com as declarações especificadas:

### <a name="example-of-return-value-1---64-bit-result"></a>Exemplo de valor de retorno 1 – resultado de 64 bits

```Output
__int64 func1(int a, float b, int c, int d, int e);
// Caller passes a in RCX, b in XMM1, c in R8, d in R9, e pushed on stack,
// callee returns __int64 result in RAX.
```

### <a name="example-of-return-value-2---128-bit-result"></a>Exemplo de valor de retorno 2 – resultado de 128 bits

```Output
__m128 func2(float a, double b, int c, __m64 d);
// Caller passes a in XMM0, b in XMM1, c in R8, d in R9,
// callee returns __m128 result in XMM0.
```

### <a name="example-of-return-value-3---user-type-result-by-pointer"></a>Exemplo de valor de retorno 3 – resultado de tipo de usuário pelo ponteiro

```Output
struct Struct1 {
   int j, k, l;    // Struct1 exceeds 64 bits.
};
Struct1 func3(int a, double b, int c, float d);
// Caller allocates memory for Struct1 returned and passes pointer in RCX,
// a in RDX, b in XMM2, c in R9, d pushed on the stack;
// callee returns pointer to Struct1 result in RAX.
```

### <a name="example-of-return-value-4---user-type-result-by-value"></a>Exemplo de valor de retorno 4 – resultado de tipo de usuário por valor

```Output
struct Struct2 {
   int j, k;    // Struct2 fits in 64 bits, and meets requirements for return by value.
};
Struct2 func4(int a, double b, int c, float d);
// Caller passes a in RCX, b in XMM1, c in R8, and d in XMM3;
// callee returns Struct2 result by value in RAX.
```

## <a name="callercallee-saved-registers"></a>Registros salvo de chamador/receptor

Os registros RAX, RCX, RDX, R8, R9, R10, R11 são considerados voláteis e devem ser considerados destruídos em chamadas de função (a menos que caso contrário, segurança-possível prová-los por análise como otimização de programa inteiro).

Os registros RBX, RBP, RDI, RSI, RSP, versão 12, R13, R14 e R15 são considerados não-volátil e devem ser salvo e restaurado por uma função que usa-los.

## <a name="function-pointers"></a>Ponteiros de função

Ponteiros de função são simplesmente os ponteiros para o rótulo da respectiva função. Não há nenhuma tabela de requisitos de sumário (TOC) para ponteiros de função.

## <a name="floating-point-support-for-older-code"></a>Suporte de ponto flutuante para código anterior

O MMX e os registros de pilha de ponto flutuante (MM0-MM7/ST0-ST7) são preservados entre alternâncias de contexto. Não há nenhum convenção de chamada explícita para esses registros. O uso desses registros é estritamente proibido no código em modo kernel.

## <a name="fpcsr"></a>FpCsr

O estado do registro também inclui x87 palavra de controle FPU. A convenção de chamada determina o registro para ser não-volátil.

X87 registro de palavra de controle FPU é definido com os seguintes valores padrão no início da execução do programa:

| Registrar\[bits] | Configuração |
|-|-|
| FPCSR\[0:6] | Exceção mascara todas as do 1 (todas as exceções são mascarados) |
| FPCSR\[7] | Reservado - 0 |
| FPCSR\[8:9] | Controle de precisão - 10 bilhões (duplas precisão) |
| FPCSR\[10:11] | Controle de arredondamento - 0 (round para mais próximo) |
| FPCSR\[12] | Controle de infinito - 0 (não usado) |

Um receptor que modifica qualquer um dos campos dentro de FPCSR necessário restaurá-los antes de retornar a seu chamador. Além disso, um chamador que modificou a qualquer um desses campos deve restaurá-los para seus valores padrão antes de invocar um receptor, a menos que o contrato, o receptor espera que os valores modificados.

Há duas exceções às regras sobre o não-volatilidade dos sinalizadores de controle:

1. Em funções em que a finalidade documentada da função fornecida é modificar o FpCsr não volátil sinalizadores.

1. Quando ele é provavelmente corrigi a que a violação dessas regras resulta em um programa que se comporta da mesma maneira como um programa onde essas regras não forem violadas, por exemplo, por meio de análise de programa inteiro.

## <a name="mxcsr"></a>MxCsr

O estado de registro também inclui MxCsr. A convenção de chamada divide o registro em uma parte voláteis e uma parte não volátil. A parte volátil consiste dos sinalizadores de seis status, no registro MXCSR\[0:5], enquanto o restante do registro, MXCSR\[6:15], é considerada não-volátil.

A parte não-volátil é definida para os seguintes valores padrão no início da execução do programa:

| Registrar\[bits] | Configuração |
|-|-|
| MXCSR\[6] | Denormals são zeros – 0 |
| MXCSR\[7:12] | Exceção mascara todas as do 1 (todas as exceções são mascarados) |
| MXCSR\[13:14] | Controle de arredondamento - 0 (round para mais próximo) |
| MXCSR\[15] | Liberar para zero, estouro negativo a mascarada - 0 (desativado) |

Um receptor que modifica qualquer um dos campos não-volátil dentro do registro MXCSR deve restaurá-los antes de retornar a seu chamador. Além disso, um chamador que modificou a qualquer um desses campos deve restaurá-los para seus valores padrão antes de invocar um receptor, a menos que o contrato, o receptor espera que os valores modificados.

Há duas exceções às regras sobre o não-volatilidade dos sinalizadores de controle:

- Em funções em que a finalidade documentada da função fornecida é modificar o registro não volátil MxCsr sinalizadores.

- Quando ele é provavelmente corrigi a que a violação dessas regras resulta em um programa que se comporta da mesma maneira como um programa onde essas regras não forem violadas, por exemplo, por meio de análise de programa inteiro.

Não pode ser feita nenhuma suposição sobre o estado da parte voláteis de MXCSR em um limite de função, a menos que especificamente descrito na documentação da função.

## <a name="setjmplongjmp"></a>setjmp/longjmp

Quando você inclui setjmpex ou setjmp, todas as chamadas para [setjmp](../c-runtime-library/reference/setjmp.md) ou [longjmp](../c-runtime-library/reference/longjmp.md) resultar em um desenrolamento que invoca os destruidores e `__finally` chamadas.  Isso é diferente do x86, onde setjmp incluindo resulta em `__finally` cláusulas e destruidores não está sendo invocados.

Uma chamada para `setjmp` preserva o ponteiro de pilha atual, os registros não voláteis e MxCsr registros.  Chamadas para `longjmp` volte para a mais recente `setjmp` chamar site e redefine o ponteiro de pilha, registros não voláteis e MxCsr registra, volta ao estado conforme preservado por mais recente `setjmp` chamar.

## <a name="see-also"></a>Consulte também

[Convenções de software x64](../build/x64-software-conventions.md)
