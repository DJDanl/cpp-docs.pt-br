---
title: Alinhamento (declarações C++)
description: Como o alinhamento de dados é especificado C++em moderno.
ms.date: 09/19/2019
ms.assetid: a986d510-ccb8-41f8-b905-433df9183485
ms.openlocfilehash: 67debc00343b8bee4184e020c9269011e2fcebc9
ms.sourcegitcommit: f907b15f50a6b945d0b87c03af0050946157d701
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/20/2019
ms.locfileid: "71158748"
---
# <a name="alignment-c-declarations"></a>Alinhamento (declarações C++)

Um dos recursos de baixo nível do C++ é a capacidade de especificar o alinhamento preciso dos objetos na memória para tirar o máximo proveito de uma arquitetura de hardware específica. Por padrão, o compilador alinha os membros de classe e struct em seu valor de `bool` tamanho `char` : e em limites de 1 `short` byte, em limites de 2 `int`bytes `long`,, `float` , e em limites de 4 bytes, e `long long`, eem`long double` limites de 8 bytes. `double` Na maioria dos cenários, você nunca precisa se preocupar com alinhamento porque o alinhamento padrão já é o ideal. Em alguns casos, no entanto, você pode obter melhorias significativas de desempenho ou economia de memória, especificando um alinhamento personalizado para suas estruturas de dados. Antes do Visual Studio 2015, você pode usar as palavras-chave `__alignof` específicas da Microsoft e `declspec(alignas)` especificar um alinhamento maior que o padrão. A partir do Visual Studio 2015, você deve usar as palavras-chave padrão do C++ 11 [alignof e alignas](../cpp/alignof-and-alignas-cpp.md) para portabilidade de código máximo. As novas palavras-chave se comportam da mesma forma nos bastidores que as extensões específicas da Microsoft. A documentação para essas extensões também se aplica às novas palavras-chave. Para obter mais informações, consulte [operador __alignof](../cpp/alignof-operator.md) e [align](../cpp/align-cpp.md). O C++ padrão não especifica o comportamento de empacotamento para alinhamento em limites menores do que o padrão do compilador para a plataforma de destino, para que você ainda precise usar o [pacote](../preprocessor/pack.md) do Microsoft #pragma nesse caso.

Use a [classe aligned_storage](../standard-library/aligned-storage-class.md) para a alocação de memória de estruturas de dados com alinhamentos personalizados. A [classe aligned_union](../standard-library/aligned-union-class.md) é para especificar o alinhamento de uniões com construtores ou destruidores não triviais.

## <a name="about-alignment"></a>Sobre alinhamento

O alinhamento é uma propriedade de um endereço de memória, expressa como o módulo de endereço numérico a potência de 2. Por exemplo, o endereço 0x0001103F módulo 4 é 3. Esse endereço é considerado alinhado com 4n + 3, em que 4 indica a potência escolhida de 2. O alinhamento de um endereço depende da potência escolhida 2. O mesmo módulo de endereço 8 é 7. Um endereço será considerado alinhado ao X se seu alinhamento for xn + 0.

As CPUs executam instruções que operam em dados armazenados na memória. Os dados são identificados por seus endereços na memória. Uma única referência também tem um tamanho. Chamamos uma referência *naturalmente alinhada* se seu endereço estiver alinhado ao seu tamanho. Caso contrário, ele será chamado *desalinhado* . Por exemplo, uma referência de ponto flutuante de 8 bytes será naturalmente alinhada se o endereço usado para identificá-lo tiver um alinhamento de 8 bytes.

## <a name="compiler-handling-of-data-alignment"></a>Manipulação de alinhamento de dados do compilador

Os compiladores tentam fazer alocações de dados de forma a impedir o desalinhamento dos dados.

Para tipos de dados simples, o compilador atribui endereços que são múltiplos do tamanho em bytes do tipo de dados. Por exemplo, o compilador atribui endereços a variáveis do tipo `long` que são múltiplos de 4, definindo os dois bits inferiores do endereço como zero.

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

Ambas as declarações `sizeof(struct x_)` retornam como 12 bytes.

A segunda declaração inclui dois elementos de preenchimento:

1. `char _pad0[3]`para alinhar `int b` o membro em um limite de 4 bytes.

1. `char _pad1[1]`para alinhar os elementos de matriz da `struct _x bar[3];` estrutura em um limite de quatro bytes.

O preenchimento alinha os elementos de `bar[3]` uma maneira que permite o acesso natural.

O exemplo de código a seguir `bar[3]` mostra o layout da matriz:

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

## <a name="see-also"></a>Consulte também

[Alinhamento da estrutura de dados](https://en.wikipedia.org/wiki/Data_structure_alignment)
