---
title: align (C++)
ms.date: 12/17/2018
f1_keywords:
- align_cpp
helpviewer_keywords:
- align __declspec keyword
- __declspec keyword [C++], align
ms.assetid: 9cb63f58-658b-4425-ac47-af8eabfc5878
ms.openlocfilehash: 0a1212f1c78f49029f82be5a2f5d82ea1788b6e0
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227654"
---
# <a name="align-c"></a>align (C++)

No Visual Studio 2015 e posterior, use o especificador standard do C++ 11 **`alignas`** para controlar o alinhamento. Para obter mais informações, consulte [Alignment](../cpp/alignment-cpp-declarations.md).

**Específico da Microsoft**

Use `__declspec(align(#))` para controlar precisamente o alinhamento dos dados definidos pelo usuário (por exemplo, alocações estáticas ou dados automáticos em uma função).

## <a name="syntax"></a>Sintaxe

> Declarador **de __declspec (align (** *#* **))** *declarator*

## <a name="remarks"></a>Comentários

Criar aplicativos que usam as instruções mais recentes do processador acarreta algumas restrições e problemas novos. Muitas novas instruções exigem dados alinhados a limites de 16 bytes. Além disso, ao alinhar os dados usados com frequência ao tamanho da linha de cache do processador, você melhora o desempenho do cache. Por exemplo, se você definir uma estrutura cujo tamanho é menor que 32 bytes, talvez queira o alinhamento de 32 bytes para garantir que os objetos desse tipo de estrutura sejam armazenados em cache de forma eficiente.

\#é o valor de alinhamento. As entradas válidas são potências inteiras de dois de 1 a 8192 (bytes), como 2, 4, 8, 16, 32 ou 64. `declarator`são os dados que você está declarando como alinhados.

Para obter informações sobre como retornar um valor do tipo `size_t` que é o requisito de alinhamento do tipo, consulte [`alignof`](../cpp/alignof-operator.md) . Para obter informações sobre como declarar ponteiros não alinhados ao direcionar processadores de 64 bits, consulte [`__unaligned`](../cpp/unaligned.md) .

Você pode usar `__declspec(align(#))` quando define um **`struct`** , **`union`** ou **`class`** , ou quando você declara uma variável.

O compilador não garante ou tenta preservar o atributo de alinhamento dos dados durante uma operação de cópia ou de transformação de dados. Por exemplo, [`memcpy`](../c-runtime-library/reference/memcpy-wmemcpy.md) pode copiar uma struct declarada com `__declspec(align(#))` para qualquer local. Os alocadores comuns (por exemplo, [`malloc`](../c-runtime-library/reference/malloc.md) C++ [`operator new`](new-operator-cpp.md) e os alocadores do Win32) normalmente retornam memória que não está suficientemente alinhada para `__declspec(align(#))` estruturas ou matrizes de estruturas. Para garantir que o destino de uma operação de cópia ou de transformação de dados esteja alinhado corretamente, use [`_aligned_malloc`](../c-runtime-library/reference/aligned-malloc.md) . Ou escreva seu próprio alocador.

Você não pode especificar o alinhamento para parâmetros de função. Quando você passa dados que têm um atributo de alinhamento por valor na pilha, seu alinhamento é controlado pela Convenção de chamada. Se o alinhamento de dados for importante na função chamada, copie o parâmetro na memória alinhada corretamente antes de usar.

Sem `__declspec(align(#))` , o compilador geralmente alinha os dados em limites naturais com base no processador de destino e no tamanho dos dados, limites de até 4 bytes em processadores de 32 bits e limites de 8 bytes em processadores de 64 bits. Os dados em classes ou estruturas são alinhados na classe ou estrutura no mínimo de seu alinhamento natural e na configuração de empacotamento atual (de `#pragma pack` ou a `/Zp` opção do compilador).

Este exemplo mostra o uso de `__declspec(align(#))`:

```cpp
__declspec(align(32)) struct Str1{
   int a, b, c, d, e;
};
```

Esse tipo agora tem um atributo de alinhamento de 32 bytes. Isso significa que todas as instâncias estática e automática iniciam em um limite de 32 bytes. Tipos de estrutura adicionais declarados com esse tipo como um membro preservam o atributo de alinhamento deste tipo, ou seja, qualquer estrutura com `Str1` como um elemento tem um atributo de alinhamento de pelo menos 32.

Aqui, `sizeof(struct Str1)` é igual a 32. Isso significa que, se uma matriz de `Str1` objetos for criada e a base da matriz estiver alinhada em 32 bytes, cada membro da matriz também será de 32 bytes alinhado. Para criar uma matriz cuja base está alinhada corretamente na memória dinâmica, use [`_aligned_malloc`](../c-runtime-library/reference/aligned-malloc.md) . Ou escreva seu próprio alocador.

O **`sizeof`** valor de qualquer estrutura é o deslocamento do membro final, além do tamanho do membro, arredondado para o múltiplo mais próximo do maior valor de alinhamento de membro ou o valor de alinhamento de estrutura inteiro, o que for maior.

O compilador usa essas regras para alinhamento de estrutura:

- A menos que seja substituído por `__declspec(align(#))`, o alinhamento de um membro de estrutura escalar é o mínimo do seu tamanho e da compactação atual.

- A menos que seja substituído por `__declspec(align(#))`, o alinhamento de uma estrutura é o máximo de alinhamentos individuais dos seus membros.

- Um membro de estrutura é colocado em um deslocamento do início de sua estrutura pai que é o menor múltiplo de seu alinhamento maior ou igual ao deslocamento do final do membro anterior.

- O tamanho de uma estrutura é o menor múltiplo de seu maior alinhamento maior que ou igual ao deslocamento do final de seu último membro.

`__declspec(align(#))` só pode aumentar as restrições de alinhamento.

Para obter mais informações, consulte:

- [`align`Disso](#vclrfalignexamples)

- [Definindo novos tipos com`__declspec(align(#))`](#vclrf_declspecaligntypedef)

- [Alinhando dados no armazenamento local de threads](#vclrfthreadlocalstorageallocation)

- [Como o `align` funciona com a compactação de dados](#vclrfhowalignworkswithdatapacking)

- [Exemplos de alinhamento de estrutura](../build/x64-software-conventions.md#examples-of-structure-alignment) (específico para x64)

## <a name="align-examples"></a><a name="vclrfalignexamples"></a>alinhar exemplos

Os exemplos a seguir mostram como `__declspec(align(#))` afeta o tamanho e o alinhamento de estruturas de dados. Os exemplos assumem as seguintes definições:

```cpp
#define CACHE_LINE  32
#define CACHE_ALIGN __declspec(align(CACHE_LINE))
```

Neste exemplo, a estrutura `S1` é definida usando `__declspec(align(32))`. Todos os usos de `S1` para uma definição de variável ou em outras declarações de tipo são alinhados como 32 bytes. `sizeof(struct S1)` retorna 32 e `S1` tem 16 bytes de preenchimento depois dos 16 bytes necessários para armazenar os quatro inteiros. Cada **`int`** membro requer alinhamento de 4 bytes, mas o alinhamento da estrutura em si é declarado como 32. Em seguida, o alinhamento geral é 32.

```cpp
struct CACHE_ALIGN S1 { // cache align all instances of S1
   int a, b, c, d;
};
struct S1 s1;   // s1 is 32-byte cache aligned
```

Neste exemplo, `sizeof(struct S2)` retorna 16, que é exatamente a soma dos tamanhos do membro, pois esse é um múltiplo do maior requisito de alinhamento (um múltiplo de 8).

```cpp
__declspec(align(8)) struct S2 {
   int a, b, c, d;
};
```

No exemplo a seguir, `sizeof(struct S3)` retorna 64.

```cpp
struct S3 {
   struct S1 s1;   // S3 inherits cache alignment requirement
                  // from S1 declaration
   int a;         // a is now cache aligned because of s1
                  // 28 bytes of trailing padding
};
```

Neste exemplo, observe que `a` tem o alinhamento de seu natural tipo, nesse caso, 4 bytes. No entanto, `S1` deve ser alinhado para 32 bytes. a seguir, 28 bytes de preenchimento `a` , para que `s1` comece no deslocamento 32. `S4`em seguida, o herda o requisito de alinhamento do `S1` , porque ele é o maior requisito de alinhamento na estrutura. `sizeof(struct S4)` retorna 64.

```cpp
struct S4 {
   int a;
   // 28 bytes padding
   struct S1 s1;      // S4 inherits cache alignment requirement of S1
};
```

As três declarações de variável a seguir também usam `__declspec(align(#))`. Em cada caso, a variável deve ser alinhada para 32 bytes. Na matriz, o endereço base da matriz, e não cada membro da matriz, é alinhado em 32 bytes. O **`sizeof`** valor de cada membro da matriz não é afetado quando você usa o `__declspec(align(#))` .

```cpp
CACHE_ALIGN int i;
CACHE_ALIGN int array[128];
CACHE_ALIGN struct s2 s;
```

Para alinhar cada membro de uma matriz, códigos como estes deverão ser usados:

```cpp
typedef CACHE_ALIGN struct { int a; } S5;
S5 array[10];
```

Neste exemplo, observe que alinhar a estrutura em si e alinhar o primeiro elemento tem o mesmo efeito:

```cpp
CACHE_ALIGN struct S6 {
   int a;
   int b;
};

struct S7 {
   CACHE_ALIGN int a;
               int b;
};
```

`S6` e `S7` têm alinhamento, alocação e características de tamanho idênticos.

Neste exemplo, o alinhamento dos endereços iniciais de a, b, c e d são 4, 1, 4 e 1, respectivamente.

```cpp
void fn() {
   int a;
   char b;
   long c;
   char d[10]
}
```

O alinhamento, se a memória tiver sido alocada no heap, depende de qual função de alocação é chamada.  Por exemplo, se você usar `malloc`, o resultado dependerá do tamanho do operando. Se *arg* >= 8, a memória retornada será alinhada em 8 bytes. Se *arg* < 8, o alinhamento da memória retornado será a primeira potência de 2 menos de *ARG*. Por exemplo, se você usar `malloc(7)` , o alinhamento será de 4 bytes.

## <a name="defining-new-types-with-__declspecalign"></a><a name="vclrf_declspecaligntypedef"></a>Definindo novos tipos com`__declspec(align(#))`

Você pode definir um tipo com uma característica de alinhamento.

Por exemplo, você pode definir um **`struct`** com um valor de alinhamento desta forma:

```cpp
struct aType {int a; int b;};
typedef __declspec(align(32)) struct aType bType;
```

Agora, `aType` e `bType` têm o mesmo tamanho (8 bytes), mas as variáveis do tipo `bType` são alinhadas em 32 bytes.

## <a name="aligning-data-in-thread-local-storage"></a><a name="vclrfthreadlocalstorageallocation"></a>Alinhando dados no armazenamento local de threads

O armazenamento local de thread estático (TLS ) criado com o atributo `__declspec(thread)` e colocado na seção TLS na imagem funciona para o alinhamento exatamente como dados estáticos normais. Para criar dados TLS, o sistema operacional aloca memória do tamanho da seção do TLS e respeita o atributo de alinhamento da seção do TLS.

Este exemplo mostra várias maneiras de colocar dados alinhados no armazenamento local de threads.

```cpp
// put an aligned integer in TLS
__declspec(thread) __declspec(align(32)) int a;

// define an aligned structure and put a variable of the struct type
// into TLS
__declspec(thread) __declspec(align(32)) struct F1 { int a; int b; } a;

// create an aligned structure
struct CACHE_ALIGN S9 {
   int a;
   int b;
};
// put a variable of the structure type into TLS
__declspec(thread) struct S9 a;
```

## <a name="how-align-works-with-data-packing"></a><a name="vclrfhowalignworkswithdatapacking"></a>Como o `align` funciona com a compactação de dados

A `/Zp` opção do compilador e o `pack` pragma têm o efeito de empacotar dados para membros de estrutura e União. Este exemplo mostra como `/Zp` e `__declspec(align(#))` trabalhar juntos:

```cpp
struct S {
   char a;
   short b;
   double c;
   CACHE_ALIGN double d;
   char e;
   double f;
};
```

A tabela a seguir lista o deslocamento de cada membro em `/Zp` valores diferentes (ou `#pragma pack` ), mostrando como os dois interagem.

|Variável|/Zp1|/Zp2|/Zp4|/Zp8|
|--------------|-----------|-----------|-----------|-----------|
|um|0|0|0|0|
|b|1|2|2|2|
|c|3|4|4|8|
|d|32|32|32|32|
|e|40|40|40|40|
|f|41|42|44|48|
|sizeof(S)|64|64|64|64|

Para obter mais informações, consulte [ `/Zp` (alinhamento de membro de struct)](../build/reference/zp-struct-member-alignment.md).

O deslocamento de um objeto baseia-se no deslocamento do objeto anterior e na configuração atual de compactação, a menos que o objeto tenha um atributo `__declspec(align(#))`. Nesse caso, o alinhamento será baseado no deslocamento do objeto anterior e no valor de `__declspec(align(#))` para o objeto.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[`__declspec`](../cpp/declspec.md)<br/>
[Visão geral das convenções da ABI do ARM](../build/overview-of-arm-abi-conventions.md)<br/>
[Convenções de software x64](../build/x64-software-conventions.md)
