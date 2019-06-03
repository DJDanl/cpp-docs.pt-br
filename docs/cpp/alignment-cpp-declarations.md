---
title: Alinhamento (declarações C++)
description: Como o alinhamento de dados é especificado no moderno C++.
ms.date: 05/30/2019
ms.assetid: a986d510-ccb8-41f8-b905-433df9183485
ms.openlocfilehash: b6e03ac2b89624a0eb6602183d4ff4bf8b518f8d
ms.sourcegitcommit: 28eae422049ac3381c6b1206664455dbb56cbfb6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/31/2019
ms.locfileid: "66450775"
---
# <a name="alignment-c-declarations"></a>Alinhamento (declarações C++)

Um dos recursos do C++ baixo nível é a capacidade de especificar o alinhamento preciso dos objetos na memória para tirar o máximo proveito de uma arquitetura de hardware específico. Por padrão, o compilador alinha os membros de classe e struct no seu valor de tamanho: `bool` e `char` em limites de 1 byte `short` em limites de 2 bytes `int`, `long`, e `float` nos limites de 4 bytes e `long long`, `double`, e `long double` em limites de 8 bytes. Na maioria dos cenários, você nunca precisará se preocupar com alinhamento porque o alinhamento padrão já é ideal. Em alguns casos, entretanto, você pode obter melhorias significativas de desempenho ou economia de memória, especificando um alinhamento personalizado para suas estruturas de dados. Antes do Visual Studio 2015, você pode usar as palavras-chave específicas da Microsoft `__alignof` e `declspec(alignas)` para especificar um alinhamento maior do que o padrão. Iniciando no Visual Studio 2015, você deve usar as C + + 11 palavras-chave padrão [alignof e alignas](../cpp/alignof-and-alignas-cpp.md) para fins de portabilidade de código máximo. As novas palavras-chave se comportam da mesma forma nos bastidores que as extensões específicas da Microsoft. A documentação para as extensões também se aplica às novas palavras-chave. Para obter mais informações, consulte [operador de alignof](../cpp/alignof-operator.md) e [alinhar](../cpp/align-cpp.md). O C++ padrão não especifica o comportamento de empacotamento para o alinhamento em limites de menores do que o padrão do compilador para a plataforma de destino, portanto, você ainda precisará usar o Microsoft #pragma [pack](../preprocessor/pack.md) nesse caso.

Use o [classe aligned_storage](../standard-library/aligned-storage-class.md) para alocação de memória de estruturas de dados com alinhamentos personalizados. O [classe aligned_union](../standard-library/aligned-union-class.md) é para especificar o alinhamento para uniões com construtores não-triviais ou destruidores.

## <a name="about-alignment"></a>Sobre o alinhamento

Alinhamento é uma propriedade de um endereço de memória, expressada como o endereço numérico de módulo uma potência de 2. Por exemplo, o endereço 0x0001103F módulo 4 é 3. Esse endereço deve ser alinhado a 4n + 3, em que 4 indica a escolhido potência de 2. O alinhamento de um endereço depende escolhida potência de 2. O mesmo endereço de módulo 8 é 7. Um endereço deve ser alinhado a X se seu alinhamento é Xn + 0.

CPUs executar instruções que operam nos dados armazenados na memória. Os dados são identificados por seus endereços de memória. Um único datum também tem um tamanho. Chamamos uma datum *alinhados naturalmente* se seu endereço é alinhado ao seu tamanho. Ele é chamado *desalinhados* caso contrário. Por exemplo, uma referência de ponto flutuante de 8 bytes é alinhada naturalmente se o endereço usado para identificá-lo tem um alinhamento de 8 bytes.

## <a name="compiler-handling-of-data-alignment"></a>Manipulação de compilador de alinhamento de dados

Os compiladores tentam fazer as alocações de dados de uma maneira que impede que o desalinhamento de dados.

Para tipos de dados simples, o compilador atribui endereços que sejam múltiplos do tamanho em bytes do tipo de dados. Por exemplo, o compilador atribui endereços a variáveis do tipo `long` que sejam múltiplos de 4, configurar a parte inferior de 2 bits do endereço como zero.

O compilador também acrescenta estruturas de forma que naturalmente alinha-se cada elemento da estrutura. Considere a estrutura `struct x_` no exemplo de código a seguir:

```cpp
struct x_
{
   char a;     // 1 byte
   int b;      // 4 bytes
   short c;    // 2 bytes
   char d;     // 1 byte
} MyStruct;
```

O compilador acrescenta essa estrutura para impor o alinhamento naturalmente.

O exemplo de código a seguir mostra como o compilador acrescenta macia estrutura na memória:

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
}
```

1. As duas declarações de retorno `sizeof(struct x_)` como 12 bytes.

1. A segunda declaração inclui dois elementos de preenchimento:

1. `char _pad0[3]` Para alinhar o `int b` membro em um limite de 4 bytes

1. `char _pad1[1]` Para alinhar os elementos da matriz da estrutura `struct _x bar[3];`

1. O preenchimento alinha os elementos de `bar[3]` de forma que permita o acesso natural.

O seguinte exemplo de código mostra o `bar[3]` layout de matriz:

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

[Alinhamento de estrutura de dados](https://en.wikipedia.org/wiki/Data_structure_alignment)
