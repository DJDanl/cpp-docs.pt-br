---
title: Convenção de chamada x64
description: Detalhes da Convenção de chamada x64 padrão.
ms.date: 07/06/2020
ms.assetid: 41ca3554-b2e3-4868-9a84-f1b46e6e21d9
ms.openlocfilehash: b615d2e4473fed1d090b7411211c08b0b824bc8f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87200849"
---
# <a name="x64-calling-convention"></a>Convenção de chamada x64

Esta seção descreve os processos e as convenções padrão que uma função (o chamador) usa para fazer chamadas em outra função (o receptor) em código x64.

## <a name="calling-convention-defaults"></a>Padrões de Convenção de chamada

A interface binária de aplicativos x64 (ABI) usa uma Convenção de chamada de chamada rápida de quatro registros por padrão. O espaço é alocado na pilha de chamadas como um armazenamento de sombra para os chamadores salvarem esses registros.

Há uma correspondência estrita de um para um entre os argumentos de uma chamada de função e os registros usados para esses argumentos. Qualquer argumento que não caiba em 8 bytes, ou que não seja 1, 2, 4 ou 8 bytes, deverá ser passado por referência. Um único argumento nunca é distribuído entre vários registros.

A pilha de registro x87 não é usada. Ele pode ser usado pelo receptor, mas considere-o volátil nas chamadas de função. Todas as operações de ponto flutuante são feitas usando os 16 registros de XMM.

Os argumentos inteiros são passados em Registers RCX, RDX, R8 e R9. Argumentos de ponto flutuante são passados em XMM0L, XMM1L, XMM2L e XMM3L. argumentos de 16 bytes são passados por referência. A passagem de parâmetro é descrita detalhadamente em [passagem de parâmetro](#parameter-passing). Esses registros e RAX, R10, R11, XMM4 e XMM5, são considerados voláteis. O uso do registro é documentado em detalhes no [uso do registro](../build/x64-software-conventions.md#register-usage) e nos [registros salvos do chamador/receptor](#callercallee-saved-registers).

Para funções com protótipo, todos os argumentos são convertidos para os tipos de chamadores esperados antes de passar. O chamador é responsável por alocar espaço para os parâmetros do receptor. O chamador deve sempre alocar espaço suficiente para armazenar quatro parâmetros de registro, mesmo se o receptor não usar esse número de parâmetros. Essa convenção simplifica o suporte a funções C-Language sem protótipo e a funções vararg C/C++. Para funções vararg ou sem protótipo, todos os valores de ponto flutuante devem ser duplicados no registro de finalidade geral correspondente. Todos os parâmetros além dos quatro primeiros devem ser armazenados na pilha após o armazenamento de sombra antes da chamada. Detalhes da função vararg podem ser encontrados em [varargs](#varargs). As informações de função não modeladas são detalhadas em funções não- [protótipos](#unprototyped-functions).

## <a name="alignment"></a>Alinhamento

A maioria das estruturas está alinhada ao seu alinhamento natural. As exceções primárias são o ponteiro de pilha e a `malloc` `alloca` memória, que são alinhados em 16 bytes para auxiliar o desempenho. O alinhamento acima de 16 bytes deve ser feito manualmente. Como 16 bytes é um tamanho de alinhamento comum para operações XMM, esse valor deve funcionar para a maioria dos códigos. Para obter mais informações sobre layout e alinhamento de estrutura, consulte [tipos e armazenamento](../build/x64-software-conventions.md#types-and-storage). Para obter informações sobre o layout da pilha, consulte [uso da pilha x64](../build/stack-usage.md).

## <a name="unwindability"></a>Invento

As funções de folha são funções que não alteram nenhum registro não volátil. Uma função não folha pode alterar RSP não volátil, por exemplo, chamando uma função. Ou, ele pode alterar o RSP alocando espaço adicional de pilha para variáveis locais. Para recuperar registros não voláteis quando uma exceção é tratada, as funções não folha são anotadas com dados estáticos. Os dados descrevem como desenrolar corretamente a função em uma instrução arbitrária. Esses dados são armazenados como *pData*, ou dados de procedimento, que, por sua vez, se referem a *XData*, a exceção de manipulação de dados. O XData contém as informações de desenrolamento e pode apontar para pData adicionais ou uma função de manipulador de exceção.

O Prologs e o epilogs são altamente restritos para que possam ser descritos corretamente no XData. O ponteiro de pilha deve permanecer alinhado em 16 bytes em qualquer região de código que não faça parte de um epílogo ou prólogo, exceto nas funções de folha. As funções de folha podem ser rebobinadas simplesmente simulando um retorno, portanto, pData e XData não são necessários. Para obter detalhes sobre a estrutura apropriada de Prologs de função e epilogs, consulte [prólogo e epílogo de x64](../build/prolog-and-epilog.md). Para obter mais informações sobre o tratamento de exceções e sobre a manipulação de exceções e o desenrolamento de pData e XData, consulte [manipulação de exceção de x64](../build/exception-handling-x64.md).

## <a name="parameter-passing"></a>Passagem de parâmetro

Por padrão, a Convenção de chamada x64 passa os primeiros quatro argumentos para uma função nos registros. Os registros usados para esses argumentos dependem da posição e do tipo do argumento. Os argumentos restantes são enviados por push na pilha na ordem da direita para a esquerda.

Os argumentos com valor inteiro nas quatro posições mais à esquerda são passados na ordem da extrema direita em RCX, RDX, R8 e R9, respectivamente. Os argumentos quinto e mais alto são passados na pilha conforme descrito anteriormente. Todos os argumentos inteiros nos registros são justificados à direita, portanto, o receptor pode ignorar os bits superiores do registro e acessar apenas a parte do registro necessário.

Todos os argumentos de ponto flutuante e de precisão dupla nos quatro primeiros parâmetros são passados em XMM0-XMM3, dependendo da posição. Os valores de ponto flutuante são colocados apenas no inteiro registra RCX, RDX, R8 e R9 quando há argumentos VarArgs. Para obter detalhes, consulte [varargs](#varargs). Da mesma forma, os registros XMM0-XMM3 são ignorados quando o argumento correspondente é um tipo inteiro ou ponteiro.

[`__m128`](../cpp/m128.md)tipos, matrizes e cadeias de caracteres nunca são passados por valor imediato. Em vez disso, um ponteiro é passado para a memória alocada pelo chamador. Structs e Unions de tamanho 8, 16, 32 ou 64 bits e **`__m64`** tipos são passados como se fossem inteiros do mesmo tamanho. Structs ou Unions de outros tamanhos são passadas como um ponteiro para a memória alocada pelo chamador. Para esses tipos de agregação passados como um ponteiro, incluindo **`__m128`** , a memória temporária alocada para o chamador deve ser alinhada em 16 bytes.

Funções intrínsecas que não alocam espaço de pilha e não chamam outras funções, às vezes usam outros registros voláteis para passar argumentos de registro adicionais. Essa otimização é possibilitada pela Associação justa entre o compilador e a implementação da função intrínseca.

O receptor é responsável por despejar os parâmetros de registro em seu espaço de sombra, se necessário.

A tabela a seguir resume como os parâmetros são passados, por tipo e posição à esquerda:

| Tipo de parâmetro | quinto e superior | quarto | fornecidos | second | mais à esquerda |
|-|-|-|-|-|-|
| ponto flutuante | stack | XMM3 | XMM2 | XMM1 | XMM0 |
| inteiro | stack | R9 | R8 | RDX | RCX |
| Agregações (8, 16, 32 ou 64 bits) e**`__m64`** | stack | R9 | R8 | RDX | RCX |
| Outras agregações, como ponteiros | stack | R9 | R8 | RDX | RCX |
| **`__m128`**, como um ponteiro | stack | R9 | R8 | RDX | RCX |

### <a name="example-of-argument-passing-1---all-integers"></a>Exemplo de argumento de passagem 1-todos os inteiros

```cpp
func1(int a, int b, int c, int d, int e, int f);
// a in RCX, b in RDX, c in R8, d in R9, f then e pushed on stack
```

### <a name="example-of-argument-passing-2---all-floats"></a>Exemplo de passagem de argumento 2-todos os floats

```cpp
func2(float a, double b, float c, double d, float e, float f);
// a in XMM0, b in XMM1, c in XMM2, d in XMM3, f then e pushed on stack
```

### <a name="example-of-argument-passing-3---mixed-ints-and-floats"></a>Exemplo de argumento passando por 3-ints e floats misturados

```cpp
func3(int a, double b, int c, float d, int e, float f);
// a in RCX, b in XMM1, c in R8, d in XMM3, f then e pushed on stack
```

### <a name="example-of-argument-passing-4---__m64-__m128-and-aggregates"></a>Exemplo de argumento que transmite 4- `__m64` , `__m128` e agregações

```cpp
func4(__m64 a, __m128 b, struct c, float d, __m128 e, __m128 f);
// a in RCX, ptr to b in RDX, ptr to c in R8, d in XMM3,
// ptr to f pushed on stack, then ptr to e pushed on stack
```

## <a name="varargs"></a>Varargs

Se os parâmetros forem passados por meio de varargs (por exemplo, argumentos de reticências), a Convenção de passagem de parâmetro de registro normal será aplicada. Essa convenção inclui despejar os argumentos quinto e posteriores para a pilha. É responsabilidade do receptor despejar argumentos que tenham seu endereço obtido. Somente para valores de ponto flutuante, tanto o registro inteiro quanto o registro de ponto flutuante devem conter o valor, caso o receptor Espere o valor nos registros de inteiro.

## <a name="unprototyped-functions"></a>Funções não com protótipo

Para funções sem protótipo completo, o chamador passa valores inteiros como inteiros e valores de ponto flutuante como precisão dupla. Somente para valores de ponto flutuante, tanto o registro inteiro quanto o registro de ponto flutuante contêm o valor float caso o receptor Espere o valor nos registros de inteiro.

```cpp
func1();
func2() {   // RCX = 2, RDX = XMM1 = 1.0, and R8 = 7
   func1(2, 1.0, 7);
}
```

## <a name="return-values"></a>Valores retornados

Um valor de retorno escalar que pode caber em 64 bits, incluindo o **`__m64`** tipo, é retornado por meio de RAX. Tipos não escalares, incluindo flutuações, duplos e tipos de vetor, como [`__m128`](../cpp/m128.md) , [`__m128i`](../cpp/m128i.md) , [`__m128d`](../cpp/m128d.md) são retornados em XMM0. O estado dos bits não utilizados no valor retornado em RAX ou XMM0 é indefinido.

Tipos definidos pelo usuário podem ser retornados por valor de funções globais e funções membro estáticas. Para retornar um tipo definido pelo usuário por valor em RAX, ele deve ter um comprimento de 1, 2, 4, 8, 16, 32 ou 64 bits. Ele também não deve ter nenhum construtor definido pelo usuário, destruidor ou operador de atribuição de cópia. Ele não pode ter nenhum membro de dados privado ou protegido não estático e nenhum membro de dados não estático do tipo de referência. Ele não pode ter classes base ou funções virtuais. E ele só pode ter membros de dados que também atendam a esses requisitos. (Essa definição é essencialmente a mesma que um tipo de POD C++ 03. Como a definição foi alterada no padrão C++ 11, não recomendamos o uso `std::is_pod` para este teste.) Caso contrário, o chamador deve alocar memória para o valor de retorno e passar um ponteiro para ele como o primeiro argumento. Os argumentos restantes são, então, deslocados um argumento para a direita. O mesmo ponteiro deve ser retornado pelo receptor em RAX.

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

A ABI x64 considera os registros RAX, RCX, RDX, R8, R9, R10, R11 e XMM0-XMM5 volatile. Quando presentes, as partes superiores de YMM0-YMM15 e ZMM0-ZMM15 também são voláteis. Em AVX512VL, os registros ZMM, YMM e XMM 16-31 também são voláteis. Considere os registros voláteis destruídos nas chamadas de função, a menos que seja o comprovadas de segurança por análise, como a otimização de todo o programa.

A ABI do x64 considera registros RBX, RBP, RDI, RSI, RSP, R12, R13, R14, R15 e XMM6-XMM15 não volátil. Eles devem ser salvos e restaurados por uma função que os utiliza.

## <a name="function-pointers"></a>Ponteiros de função

Ponteiros de função são simplesmente ponteiros para o rótulo da respectiva função. Não há nenhum requisito de Sumário (TOC) para ponteiros de função.

## <a name="floating-point-support-for-older-code"></a>Suporte de ponto flutuante para código mais antigo

Os registros da pilha de ponto flutuante e MMX (MM0-MM7/ST0-ST7) são preservados entre alternâncias de contexto. Não há Convenção de chamada explícita para esses registros. O uso desses registros é estritamente proibido no código de modo kernel.

## <a name="fpcsr"></a>FPCSR

O estado de registro também inclui a palavra de controle FPU x87. A Convenção de chamada determina esse registro como não volátil.

O registro do Word do controle FPU x87 é definido usando os seguintes valores padrão no início da execução do programa:

| Registrar \[ bits] | Configuração |
|-|-|
| FPCSR \[ 0:6] | A exceção mascara todos os 1 (todas as exceções mascaradas) |
| FPCSR \[ 7] | Reservado-0 |
| FPCSR \[ 8:9] | Controle de precisão-10B (precisão dupla) |
| FPCSR \[ 10:11] | Controle de arredondamento-0 (redondo para mais próximo) |
| FPCSR \[ 12] | Controle de infinito-0 (não usado) |

Um receptor que modifica qualquer um dos campos dentro de FPCSR deve restaurá-los antes de retornar ao chamador. Além disso, um chamador que modificou qualquer um desses campos deve restaurá-los para seus valores padrão antes de invocar um receptor, a menos que por contrato o receptor Espere os valores modificados.

Há duas exceções às regras sobre o não volatilidade dos sinalizadores de controle:

- Em funções em que a finalidade documentada da função fornecida é modificar os sinalizadores FPCSR não voláteis.

- Quando é provavelmente correto que a violação dessas regras resulte em um programa que se comporta da mesma forma que um programa que não viola as regras, por exemplo, por meio da análise completa do programa.

## <a name="mxcsr"></a>MXCSR

O estado de registro também inclui MXCSR. A Convenção de chamada divide esse registro em uma parte volátil e não volátil. A parte volátil consiste nos seis sinalizadores de status, em MXCSR \[ 0:5], enquanto o restante do registro, MXCSR \[ 6:15], é considerado não volátil.

A parte não volátil é definida com os seguintes valores padrão no início da execução do programa:

| Registrar \[ bits] | Configuração |
|-|-|
| MXCSR \[ 6] | Os desnormals são zeros-0 |
| MXCSR \[ 7:12] | A exceção mascara todos os 1 (todas as exceções mascaradas) |
| MXCSR \[ 13:14] | Controle de arredondamento-0 (redondo para mais próximo) |
| MXCSR \[ 15] | Liberar para zero para estouro negativo mascarado-0 (desativado) |

Um receptor que modifica qualquer um dos campos não voláteis dentro de MXCSR deve restaurá-los antes de retornar ao chamador. Além disso, um chamador que modificou qualquer um desses campos deve restaurá-los para seus valores padrão antes de invocar um receptor, a menos que por contrato o receptor Espere os valores modificados.

Há duas exceções às regras sobre o não volatilidade dos sinalizadores de controle:

- Em funções em que a finalidade documentada da função fornecida é modificar os sinalizadores MXCSR não voláteis.

- Quando é provavelmente correto que a violação dessas regras resulte em um programa que se comporta da mesma forma que um programa que não viola as regras, por exemplo, por meio da análise completa do programa.

Não faça suposições sobre o estado da parte volátil do registro MXCSR em um limite de função, a menos que a documentação da função a Descreva explicitamente.

## <a name="setjmplongjmp"></a>setjmp/longjmp

Quando você inclui setjmpex. h ou setjmp. h, todas as chamadas para [`setjmp`](../c-runtime-library/reference/setjmp.md) ou [`longjmp`](../c-runtime-library/reference/longjmp.md) resultam em um desenrolamento que invoca destruidores e **`__finally`** chamadas.  Esse comportamento é diferente do x86, em que incluir setjmp. h resulta em **`__finally`** cláusulas e destruidores que não estão sendo invocados.

Uma chamada para `setjmp` preserva o ponteiro de pilha atual, registros não voláteis e registros de MXCSR.  As chamadas para `longjmp` retornar ao site de `setjmp` chamada mais recente e redefinem o ponteiro de pilha, os registros não voláteis e os registros de MXCSR, de volta ao estado como preservado pela chamada mais recente `setjmp` .

## <a name="see-also"></a>Confira também

[Convenções de software x64](../build/x64-software-conventions.md)
