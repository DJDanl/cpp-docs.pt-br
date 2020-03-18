---
title: Alinhamento
description: Como o alinhamento de dados é especificado C++em moderno.
ms.date: 12/11/2019
ms.assetid: a986d510-ccb8-41f8-b905-433df9183485
ms.openlocfilehash: 13f09366501de2482b8ae9ea430898d6c32134c2
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79443661"
---
# <a name="alignment"></a>Alinhamento

Um dos recursos de baixo nível do C++ é a capacidade de especificar o alinhamento preciso dos objetos na memória para tirar o máximo proveito de uma arquitetura de hardware específica. Por padrão, o compilador alinha os membros de classe e struct em seu valor de tamanho: `bool` e `char` em limites de 1 byte, `short` em limites de 2 bytes, `int`, `long`e `float` em limites de 4 bytes e `long long`, `double`e `long double` em limites de 8 bytes. 

Na maioria dos cenários, você nunca precisa se preocupar com alinhamento porque o alinhamento padrão já é o ideal. Em alguns casos, no entanto, você pode obter melhorias significativas de desempenho ou economia de memória, especificando um alinhamento personalizado para suas estruturas de dados. Antes do Visual Studio 2015, você pode usar as palavras-chave específicas da Microsoft `__alignof` e `declspec(alignas)` para especificar um alinhamento maior que o padrão. A partir do Visual Studio 2015, você deve usar as palavras-chave padrão do C++ 11 **alignof** e **alignas** para portabilidade de código máximo. As novas palavras-chave se comportam da mesma forma nos bastidores que as extensões específicas da Microsoft. A documentação para essas extensões também se aplica às novas palavras-chave. Para obter mais informações, consulte [operador de __alignof](../cpp/alignof-operator.md) e [alinhar](../cpp/align-cpp.md). O C++ padrão não especifica o comportamento de empacotamento para alinhamento em limites menores do que o padrão do compilador para a plataforma de destino, para que você ainda precise usar o [pacote](../preprocessor/pack.md) do Microsoft #pragma nesse caso.

Use a [classe aligned_storage](../standard-library/aligned-storage-class.md) para a alocação de memória de estruturas de dados com alinhamentos personalizados. A [classe aligned_union](../standard-library/aligned-union-class.md) é para especificar o alinhamento de uniões com construtores ou destruidores não triviais.

## <a name="alignment-and-memory-addresses"></a>Alinhamento e endereços de memória

O alinhamento é uma propriedade de um endereço de memória, expressa como o módulo de endereço numérico a potência de 2. Por exemplo, o endereço 0x0001103F módulo 4 é 3. Esse endereço é considerado alinhado com 4n + 3, em que 4 indica a potência escolhida de 2. O alinhamento de um endereço depende da potência escolhida 2. O mesmo módulo de endereço 8 é 7. Um endereço será considerado alinhado ao X se seu alinhamento for xn + 0.

As CPUs executam instruções que operam em dados armazenados na memória. Os dados são identificados por seus endereços na memória. Uma única referência também tem um tamanho. Chamamos uma referência *naturalmente alinhada* se seu endereço estiver alinhado ao seu tamanho. Caso contrário, ele será chamado *desalinhado* . Por exemplo, uma referência de ponto flutuante de 8 bytes será naturalmente alinhada se o endereço usado para identificá-lo tiver um alinhamento de 8 bytes.

## <a name="compiler-handling-of-data-alignment"></a>Manipulação de alinhamento de dados do compilador

Os compiladores tentam fazer alocações de dados de forma a impedir o desalinhamento dos dados.

Para tipos de dados simples, o compilador atribui endereços que são múltiplos do tamanho em bytes do tipo de dados. Por exemplo, o compilador atribui endereços a variáveis do tipo `long` que são múltiplos de 4, definindo os dois últimos bits do endereço como zero.

O compilador também ajusta as estruturas de uma forma que alinha naturalmente cada elemento da estrutura. Considere a estrutura `struct x_` no exemplo de código a seguir:

```cpp
struct x_
{
   char a;     // 1 byte
   int b;      // 4 bytes
   short c;    // 2 bytes
   char d;     // 1 byte
} bar[3];
```

O compilador pads essa estrutura para impor o alinhamento naturalmente.

O exemplo de código a seguir mostra como o compilador coloca a estrutura preenchida na memória:

```cpp
// Shows the actual memory layout
struct x_
{
   char a;            // 1 byte
   char _pad0[3];     // padding to put 'b' on 4-byte boundary
   int b;            // 4 bytes
   short c;          // 2 bytes
   char d;           // 1 byte
   char _pad1[1];    // padding to make sizeof(x_) multiple of 4
} bar[3];
```

Ambas as declarações retornam `sizeof(struct x_)` como 12 bytes.

A segunda declaração inclui dois elementos de preenchimento:

1. `char _pad0[3]` alinhar o membro de `int b` em um limite de 4 bytes.

1. `char _pad1[1]` alinhar os elementos de matriz da estrutura `struct _x bar[3];` em um limite de quatro bytes.

O preenchimento alinha os elementos de `bar[3]` de forma que permita o acesso natural.

O exemplo de código a seguir mostra o layout da matriz de `bar[3]`:

```Output
adr offset   element
------   -------
0x0000   char a;         // bar[0]
0x0001   char pad0[3];
0x0004   int b;
0x0008   short c;
0x000a   char d;
0x000b   char _pad1[1];

0x000c   char a;         // bar[1]
0x000d   char _pad0[3];
0x0010   int b;
0x0014   short c;
0x0016   char d;
0x0017   char _pad1[1];

0x0018   char a;         // bar[2]
0x0019   char _pad0[3];
0x001c   int b;
0x0020   short c;
0x0022   char d;
0x0023   char _pad1[1];
```

## <a name="alignof-and-alignas"></a>alignof e alignas

O especificador de tipo **alignas** é uma C++ maneira portátil e padrão de especificar o alinhamento personalizado de variáveis e tipos definidos pelo usuário. O operador **alignof** é, da mesma forma, uma maneira portátil e padrão de obter o alinhamento de um tipo ou variável especificada.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

Você pode usar **alignas** em uma classe, struct ou Union ou em membros individuais. Quando vários especificadores **alignas** forem encontrados, o compilador escolherá o mais estrito (aquele com o maior valor).

```cpp
// alignas_alignof.cpp
// compile with: cl /EHsc alignas_alignof.cpp
#include <iostream>

struct alignas(16) Bar
{
    int i;       // 4 bytes
    int n;      // 4 bytes
    alignas(4) char arr[3];
    short s;          // 2 bytes
};

int main()
{
    std::cout << alignof(Bar) << std::endl; // output: 16
}
```

## <a name="see-also"></a>Consulte também

[Alinhamento da estrutura de dados](https://en.wikipedia.org/wiki/Data_structure_alignment)
