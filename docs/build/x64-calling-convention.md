---
title: Convenção de chamada x64
description: Detalhes da Convenção de chamada ABI padrão x64.
ms.date: 12/17/2018
ms.assetid: 41ca3554-b2e3-4868-9a84-f1b46e6e21d9
ms.openlocfilehash: 5b9801eff6a9789313d083fdd6ed69c3076643ad
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80078078"
---
# <a name="x64-calling-convention"></a>Convenção de chamada x64

Esta seção descreve os processos e as convenções padrão que uma função (o chamador) usa para fazer chamadas em outra função (o receptor) em código x64.

## <a name="calling-convention-defaults"></a>Padrões de Convenção de chamada

A interface binária de aplicativos x64 (ABI) usa uma Convenção de chamada de chamada rápida de quatro registros por padrão. O espaço é alocado na pilha de chamadas como um armazenamento de sombra para os chamadores salvarem esses registros. Há uma correspondência estrita de um para um entre os argumentos para uma chamada de função e os registros usados para esses argumentos. Qualquer argumento que não caiba em 8 bytes, ou que não seja 1, 2, 4 ou 8 bytes, deverá ser passado por referência. Um único argumento nunca é distribuído entre vários registros. A pilha de registro x87 não é usada e pode ser usada pelo receptor, mas deve ser considerada volátil nas chamadas de função. Todas as operações de ponto flutuante são feitas usando os 16 registros de XMM. Os argumentos inteiros são passados em Registers RCX, RDX, R8 e R9. Argumentos de ponto flutuante são passados em XMM0L, XMM1L, XMM2L e XMM3L. argumentos de 16 bytes são passados por referência. A passagem de parâmetro é descrita detalhadamente em [passagem de parâmetro](#parameter-passing). Além desses registros, RAX, R10, R11, XMM4 e XMM5 são considerados voláteis. Todos os outros registros não são voláteis. O uso do registro é documentado em detalhes no [uso do registro](../build/x64-software-conventions.md#register-usage) e nos [registros salvos do chamador/receptor](#callercallee-saved-registers).

Para funções com protótipo, todos os argumentos são convertidos para os tipos de chamadores esperados antes de passar. O chamador é responsável por alocar espaço para parâmetros para o receptor e sempre deve alocar espaço suficiente para armazenar quatro parâmetros de registro, mesmo se o receptor não usar esse número de parâmetros. Essa convenção simplifica o suporte a funções C-Language sem protótipo e a C/C++ funções vararg. Para funções vararg ou sem protótipo, todos os valores de ponto flutuante devem ser duplicados no registro de finalidade geral correspondente. Todos os parâmetros além dos quatro primeiros devem ser armazenados na pilha após o armazenamento de sombra antes da chamada. Detalhes da função vararg podem ser encontrados em [varargs](#varargs). As informações de função não modeladas são detalhadas em funções não- [protótipos](#unprototyped-functions).

## <a name="alignment"></a>Alinhamento

A maioria das estruturas está alinhada ao seu alinhamento natural. As exceções primárias são o ponteiro de pilha e `malloc` ou `alloca` memória, que são alinhados a 16 bytes para auxiliar o desempenho. O alinhamento acima de 16 bytes deve ser feito manualmente, mas como 16 bytes é um tamanho de alinhamento comum para operações XMM, esse valor deve funcionar para a maioria dos códigos. Para obter mais informações sobre layout e alinhamento de estrutura, consulte [tipos e armazenamento](../build/x64-software-conventions.md#types-and-storage). Para obter informações sobre o layout da pilha, consulte [uso da pilha x64](../build/stack-usage.md).

## <a name="unwindability"></a>Invento

As funções de folha são funções que não alteram nenhum registro não volátil. Uma função não folha pode alterar RSP não volátil, por exemplo, chamando uma função ou alocando espaço de pilha adicional para variáveis locais. Para recuperar registros não voláteis quando uma exceção é tratada, as funções não folha devem ser anotadas com dados estáticos que descrevem como desenrolar corretamente a função em uma instrução arbitrária. Esses dados são armazenados como *pData*, ou dados de procedimento, que, por sua vez, se referem a *XData*, a exceção de manipulação de dados. O XData contém as informações de desenrolamento e pode apontar para pData adicionais ou uma função de manipulador de exceção. O Prologs e o epilogs são altamente restritos para que possam ser descritos corretamente no XData. O ponteiro de pilha deve ser alinhado a 16 bytes em qualquer região de código que não faça parte de um epílogo ou prólogo, exceto em funções de folha. As funções de folha podem ser rebobinadas simplesmente simulando um retorno, portanto, pData e XData não são necessários. Para obter detalhes sobre a estrutura apropriada de Prologs de função e epilogs, consulte [prólogo e epílogo de x64](../build/prolog-and-epilog.md). Para obter mais informações sobre o tratamento de exceções e sobre a manipulação de exceções e o desenrolamento de pData e XData, consulte [manipulação de exceção de x64](../build/exception-handling-x64.md).

## <a name="parameter-passing"></a>Passagem de parâmetro

Os primeiros quatro argumentos inteiros são passados em registros. Os valores inteiros são passados na ordem da esquerda para a direita em RCX, RDX, R8 e R9, respectivamente. Os argumentos cinco e superiores são passados na pilha. Todos os argumentos são justificados à direita nos registros, portanto, o receptor pode ignorar os bits superiores do registro e acessar apenas a parte do registro necessário.

Todos os argumentos de ponto flutuante e de precisão dupla nos quatro primeiros parâmetros são passados em XMM0-XMM3, dependendo da posição. O inteiro registra RCX, RDX, R8 e R9 que normalmente seriam usados para essas posições ignoradas, exceto no caso de argumentos VarArgs. Para obter detalhes, consulte [varargs](#varargs). Da mesma forma, os registros XMM0-XMM3 são ignorados quando o argumento correspondente é um tipo inteiro ou ponteiro.

tipos de [__m128](../cpp/m128.md) , matrizes e cadeias de caracteres nunca são passados por valor imediato. Em vez disso, um ponteiro é passado para a memória alocada pelo chamador. Structs e Unions de tamanho 8, 16, 32 ou 64 bits e tipos de __m64 são passados como se fossem inteiros do mesmo tamanho. Structs ou Unions de outros tamanhos são passadas como um ponteiro para a memória alocada pelo chamador. Para esses tipos de agregação passados como um ponteiro, incluindo \__m128, a memória temporária alocada para o chamador deve ser alinhada em 16 bytes.

Funções intrínsecas que não alocam espaço de pilha e não chamam outras funções, às vezes usam outros registros voláteis para passar argumentos de registro adicionais. Essa otimização é possibilitada pela Associação justa entre o compilador e a implementação da função intrínseca.

O receptor é responsável por despejar os parâmetros de registro em seu espaço de sombra, se necessário.

A tabela a seguir resume como os parâmetros são passados:

|Tipo de parâmetro|Como foi passado|
|--------------------|----------------|
|Ponto flutuante|Primeiros 4 parâmetros-XMM0 até XMM3. Outros passaram na pilha.|
|Integer|Primeiros 4 parâmetros-RCX, RDX, R8, R9. Outros passaram na pilha.|
|Agregações (8, 16, 32 ou 64 bits) e __m64|Primeiros 4 parâmetros-RCX, RDX, R8, R9. Outros passaram na pilha.|
|Agregações (outras)|Por ponteiro. Quatro primeiros parâmetros passados como ponteiros em RCX, RDX, R8 e R9|
|__m128|Por ponteiro. Quatro primeiros parâmetros passados como ponteiros em RCX, RDX, R8 e R9|

### <a name="example-of-argument-passing-1---all-integers"></a>Exemplo de argumento de passagem 1-todos os inteiros

```cpp
func1(int a, int b, int c, int d, int e);
// a in RCX, b in RDX, c in R8, d in R9, e pushed on stack
```

### <a name="example-of-argument-passing-2---all-floats"></a>Exemplo de passagem de argumento 2-todos os floats

```cpp
func2(float a, double b, float c, double d, float e);
// a in XMM0, b in XMM1, c in XMM2, d in XMM3, e pushed on stack
```

### <a name="example-of-argument-passing-3---mixed-ints-and-floats"></a>Exemplo de argumento passando por 3-ints e floats misturados

```cpp
func3(int a, double b, int c, float d);
// a in RCX, b in XMM1, c in R8, d in XMM3
```

### <a name="example-of-argument-passing-4--__m64-__m128-and-aggregates"></a>Exemplo de passagem de argumento 4-__m64, \__m128 e agregações

```cpp
func4(__m64 a, _m128 b, struct c, float d);
// a in RCX, ptr to b in RDX, ptr to c in R8, d in XMM3
```

## <a name="varargs"></a>Varargs

Se os parâmetros forem passados por meio de varargs (por exemplo, argumentos de reticências), a Convenção de passagem de parâmetro de registro normal será aplicada, incluindo o despejo dos argumentos quinto e subsequentes para a pilha. É responsabilidade do receptor despejar argumentos que tenham seu endereço obtido. Somente para valores de ponto flutuante, tanto o registro inteiro quanto o registro de ponto flutuante devem conter o valor, caso o receptor Espere o valor nos registros de inteiro.

## <a name="unprototyped-functions"></a>Funções não com protótipo

Para funções sem protótipo completo, o chamador passa valores inteiros como inteiros e valores de ponto flutuante como precisão dupla. Somente para valores de ponto flutuante, tanto o registro inteiro quanto o registro de ponto flutuante contêm o valor float caso o receptor Espere o valor nos registros de inteiro.

```cpp
func1();
func2() {   // RCX = 2, RDX = XMM1 = 1.0, and R8 = 7
   func1(2, 1.0, 7);
}
```

## <a name="return-values"></a>Valores retornados

Um valor de retorno escalar que pode caber em 64 bits é retornado por meio de RAX; Isso inclui tipos de __m64. Tipos não escalares, incluindo flutuações, duplos e tipos de vetor, como [__m128](../cpp/m128.md), [__m128i](../cpp/m128i.md), [__m128d](../cpp/m128d.md) são retornados em XMM0. O estado dos bits não utilizados no valor retornado em RAX ou XMM0 é indefinido.

Tipos definidos pelo usuário podem ser retornados por valor de funções globais e funções membro estáticas. Para retornar um tipo definido pelo usuário por valor em RAX, ele deve ter um comprimento de 1, 2, 4, 8, 16, 32 ou 64 bits. Ele também não deve ter nenhum construtor definido pelo usuário, destruidor ou operador de atribuição de cópia; nenhum membro de dados privado ou não estático protegido; Não há membros de dados não estáticos do tipo de referência; nenhuma classe base; nenhuma função virtual; e nenhum membro de dados que também atenda a esses requisitos. (Essa é essencialmente a definição de um tipo de POD de C++ 03. Como a definição foi alterada no padrão C++ 11, não recomendamos o uso de `std::is_pod` para este teste.) Caso contrário, o chamador assumirá a responsabilidade de alocar memória e passar um ponteiro para o valor de retorno como o primeiro argumento. Os argumentos subsequentes são, então, deslocados um argumento para a direita. O mesmo ponteiro deve ser retornado pelo receptor em RAX.

Estes exemplos mostram como os parâmetros e valores de retorno são passados para funções com as declarações especificadas:

### <a name="example-of-return-value-1---64-bit-result"></a>Exemplo de resultado de valor de retorno 1-64-bit

```Output
__int64 func1(int a, float b, int c, int d, int e);
// Caller passes a in RCX, b in XMM1, c in R8, d in R9, e pushed on stack,
// callee returns __int64 result in RAX.
```

### <a name="example-of-return-value-2---128-bit-result"></a>Exemplo de resultado de valor de retorno 2-128-bit

```Output
__m128 func2(float a, double b, int c, __m64 d);
// Caller passes a in XMM0, b in XMM1, c in R8, d in R9,
// callee returns __m128 result in XMM0.
```

### <a name="example-of-return-value-3---user-type-result-by-pointer"></a>Exemplo de valor de retorno 3-tipo de usuário resultado por ponteiro

```Output
struct Struct1 {
   int j, k, l;    // Struct1 exceeds 64 bits.
};
Struct1 func3(int a, double b, int c, float d);
// Caller allocates memory for Struct1 returned and passes pointer in RCX,
// a in RDX, b in XMM2, c in R9, d pushed on the stack;
// callee returns pointer to Struct1 result in RAX.
```

### <a name="example-of-return-value-4---user-type-result-by-value"></a>Exemplo de valor de retorno 4-tipo de usuário resultado por valor

```Output
struct Struct2 {
   int j, k;    // Struct2 fits in 64 bits, and meets requirements for return by value.
};
Struct2 func4(int a, double b, int c, float d);
// Caller passes a in RCX, b in XMM1, c in R8, and d in XMM3;
// callee returns Struct2 result by value in RAX.
```

## <a name="callercallee-saved-registers"></a>Registros salvos do chamador/receptor

Os registradores RAX, RCX, RDX, R8, R9, R10, R11, XMM0-5 e as partes superiores de YMM0-15 e ZMM0-15 são considerados voláteis e devem ser considerados destruídos em chamadas de função (a menos que o caso contrário, o de segurança-comprovadas por análise, como a otimização do programa inteiro). Em AVX512VL, os registros ZMM, YMM e XMM 16-31 são voláteis.

Os registros RBX, RBP, RDI, RSI, RSP, R12, R13, R14, R15 e XMM6-15 são considerados não voláteis e devem ser salvos e restaurados por uma função que os utiliza.

## <a name="function-pointers"></a>Ponteiros de função

Ponteiros de função são simplesmente ponteiros para o rótulo da respectiva função. Não há nenhum requisito de Sumário (TOC) para ponteiros de função.

## <a name="floating-point-support-for-older-code"></a>Suporte de ponto flutuante para código mais antigo

Os registros da pilha de ponto flutuante e MMX (MM0-MM7/ST0-ST7) são preservados entre alternâncias de contexto. Não há Convenção de chamada explícita para esses registros. O uso desses registros é estritamente proibido no código de modo kernel.

## <a name="fpcsr"></a>FpCsr

O estado de registro também inclui a palavra de controle FPU x87. A Convenção de chamada determina esse registro como não volátil.

O registro do Word do controle FPU x87 é definido com os seguintes valores padrão no início da execução do programa:

| Registrar bits\[] | Configuração |
|-|-|
| FPCSR\[0:6] | A exceção mascara todos os 1 (todas as exceções mascaradas) |
| FPCSR\[7] | Reservado-0 |
| FPCSR\[8:9] | Controle de precisão-10B (precisão dupla) |
| FPCSR\[10:11] | Controle de arredondamento-0 (redondo para mais próximo) |
| FPCSR\[12] | Controle de infinito-0 (não usado) |

Um receptor que modifica qualquer um dos campos dentro de FPCSR deve restaurá-los antes de retornar ao chamador. Além disso, um chamador que modificou qualquer um desses campos deve restaurá-los para seus valores padrão antes de chamar um receptor, a menos que pelo contrato o receptor Espere os valores modificados.

Há duas exceções às regras sobre o não volatilidade dos sinalizadores de controle:

1. Em funções em que a finalidade documentada da função fornecida é modificar os sinalizadores FpCsr não voláteis.

1. Quando isso é provavelmente correto, a violação dessas regras resulta em um programa que se comporta da mesma forma que o programa em que essas regras não são violadas, por exemplo, por meio da análise de todo o programa.

## <a name="mxcsr"></a>MxCsr

O estado de registro também inclui MxCsr. A Convenção de chamada divide esse registro em uma parte volátil e não volátil. A parte volátil consiste nos seis sinalizadores de status, no MXCSR\[0:5], enquanto o restante do registro, MXCSR\[6:15], é considerado não volátil.

A parte não volátil é definida com os seguintes valores padrão no início da execução do programa:

| Registrar bits\[] | Configuração |
|-|-|
| MXCSR\[6] | Os desnormals são zeros-0 |
| MXCSR\[7:12] | A exceção mascara todos os 1 (todas as exceções mascaradas) |
| MXCSR\[13:14] | Controle de arredondamento-0 (redondo para mais próximo) |
| MXCSR\[15] | Liberar para zero para estouro negativo mascarado-0 (desativado) |

Um receptor que modifica qualquer um dos campos não voláteis dentro de MXCSR deve restaurá-los antes de retornar ao chamador. Além disso, um chamador que modificou qualquer um desses campos deve restaurá-los para seus valores padrão antes de chamar um receptor, a menos que pelo contrato o receptor Espere os valores modificados.

Há duas exceções às regras sobre o não volatilidade dos sinalizadores de controle:

- Em funções em que a finalidade documentada da função fornecida é modificar os sinalizadores MxCsr não voláteis.

- Quando isso é provavelmente correto, a violação dessas regras resulta em um programa que se comporta da mesma forma que o programa em que essas regras não são violadas, por exemplo, por meio da análise de todo o programa.

Não é possível fazer suposições sobre o estado da parte volátil de MXCSR em um limite de função, a menos que especificamente descrito na documentação de uma função.

## <a name="setjmplongjmp"></a>setjmp/longjmp

Quando você inclui setjmpex. h ou setjmp. h, todas as chamadas para [setjmp](../c-runtime-library/reference/setjmp.md) ou [longjmp](../c-runtime-library/reference/longjmp.md) resultam em um desenrolamento que invoca destruidores e chamadas de `__finally`.  Isso difere do x86, em que incluir setjmp. h resulta em cláusulas `__finally` e destruidores não são invocados.

Uma chamada para `setjmp` preserva o ponteiro de pilha atual, os registros não volátil e os registros de MxCsr.  Chamadas para `longjmp` retornam para o site de chamada de `setjmp` mais recente e redefinem o ponteiro de pilha, os registros não voláteis e os registros de MxCsr, de volta ao estado como preservado pela chamada de `setjmp` mais recente.

## <a name="see-also"></a>Confira também

[Convenções de software x64](../build/x64-software-conventions.md)
