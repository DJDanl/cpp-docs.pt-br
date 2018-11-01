---
title: Passagem de parâmetro
ms.date: 11/04/2016
ms.assetid: e838ee5f-c2fe-40b0-9a23-8023c949c820
ms.openlocfilehash: 1b7fb126ab3b140d0ab672067df35c5fc8df926e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50648741"
---
# <a name="parameter-passing"></a>Passagem de parâmetro

Os primeiros quatro argumentos inteiros são passados em registros. Valores inteiros são passados (na ordem da esquerda para a direita) em RCX, RDX, R8 e R9. Argumentos de cinco e superior são passados na pilha. Todos os argumentos são justificados à direita em registros. Isso é feito para que o receptor pode ignorar os bits superiores do registro se precisa ser e podem acessar apenas a parte do registro necessárias.

Argumentos de ponto flutuantes e precisão dupla são passados em XMM0 - XMM3 (até 4) com o slot de inteiro (RCX, RDX, R8 e R9) que normalmente seria usado para esse slot cardinal que está sendo ignorado (veja o exemplo) e vice-versa.

[__m128](../cpp/m128.md) tipos, matrizes e cadeias de caracteres nunca são passadas por valor imediato, mas em vez disso, um ponteiro é passado para a memória alocada pelo chamador. Structs/uniões de bits de tamanho 8, 16, 32 ou 64 e __m64 são passadas como se fossem inteiros do mesmo tamanho. Structs/uniões diferentes esses tamanhos são passadas como um ponteiro para a memória alocada pelo chamador. Para esses tipos de agregação passado como um ponteiro (incluindo \__m128), a memória alocada pelo chamador para temporária será alinhada de 16 bytes.

Funções intrínsecas que não alocar espaço de pilha e não chamam outras funções podem usar outros registros voláteis para passar argumentos adicionais do registro, porque não há uma associação estreita entre o compilador e a implementação da função intrínseca. Esta é uma oportunidade adicional para melhorar o desempenho.

O receptor tem a responsabilidade de despejar os parâmetros de registro em seu espaço de sombra se necessário.

A tabela a seguir resume como os parâmetros são passados:

|Tipo de parâmetro|Como aprovado|
|--------------------|----------------|
|Ponto flutuante|Primeiro 4 parâmetros - XMM0 por meio de XMM3. Outras pessoas passado na pilha.|
|Inteiro|Primeiro 4 parâmetros - RCX, RDX, R8, R9. Outras pessoas passado na pilha.|
|Agregações (8, 16, 32 ou 64 bits) e __m64|Primeiro 4 parâmetros - RCX, RDX, R8, R9. Outras pessoas passado na pilha.|
|Agregações (outro)|Pelo ponteiro. Primeiro, 4 parâmetros passados como ponteiros em RCX, RDX, R8 e R9|
|__m128|Pelo ponteiro. Primeiro, 4 parâmetros passados como ponteiros em RCX, RDX, R8 e R9|

## <a name="example-of-argument-passing-1---all-integers"></a>Exemplo de 1 - todos os inteiros de passagem de argumento

```
func1(int a, int b, int c, int d, int e);
// a in RCX, b in RDX, c in R8, d in R9, e pushed on stack
```

## <a name="example-of-argument-passing-2---all-floats"></a>Exemplo de passar 2 - floats todos os argumentos

```
func2(float a, double b, float c, double d, float e);
// a in XMM0, b in XMM1, c in XMM2, d in XMM3, e pushed on stack
```

## <a name="example-of-argument-passing-3---mixed-ints-and-floats"></a>Exemplo de 3 - ints misto e flutuações de passagem de argumento

```
func3(int a, double b, int c, float d);
// a in RCX, b in XMM1, c in R8, d in XMM3
```

## <a name="example-of-argument-passing-4--m64-m128-and-aggregates"></a>Exemplo de argumento passando 4-__m64, \__m128 e agregações

```
func4(__m64 a, _m128 b, struct c, float d);
// a in RCX, ptr to b in RDX, ptr to c in R8, d in XMM3
```

## <a name="see-also"></a>Consulte também

[Convenção de chamada](../build/calling-convention.md)