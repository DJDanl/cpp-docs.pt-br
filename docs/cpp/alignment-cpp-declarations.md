---
title: Alinhamento (declarações C++)
ms.date: 11/04/2016
ms.assetid: a986d510-ccb8-41f8-b905-433df9183485
ms.openlocfilehash: 0709ad414af3f167a64d9c89c342690015190287
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51522864"
---
# <a name="alignment-c-declarations"></a>Alinhamento (declarações C++)

Um dos recursos do C++ baixo nível é a capacidade de especificar o alinhamento preciso dos objetos na memória para tirar o máximo proveito de uma arquitetura de hardware específico. Por padrão, o compilador alinha os membros de classe e struct no seu valor de tamanho: bool e char é alinhados em limites de um byte, short em dois bytes, int em quatro bytes, long longos, double e double longo em oito bytes. Na maioria dos cenários, você nunca precisará se preocupar com alinhamento porque o alinhamento padrão já é ideal. Em alguns casos, no entanto, você pode obter melhorias significativas de desempenho ou economia de memória, especificando um alinhamento personalizado para suas estruturas de dados. Antes do Visual Studio 2015, você pode usar o alignof de palavras-chave específicas da Microsoft e declspec(alignas) para especificar um alinhamento maior do que o padrão. Iniciando no Visual Studio 2015, você deve usar as C + + 11 palavras-chave padrão [alignof e alignas](../cpp/alignof-and-alignas-cpp.md) para fins de portabilidade de código máximo. As novas palavras-chave se comportam da mesma forma nos bastidores, como as extensões específicas da Microsoft, e a documentação para as extensões também se aplica às novas palavras-chave. Ver [operador de alignof](../cpp/alignof-operator.md) e [alinhar](../cpp/align-cpp.md) para obter mais informações. O padrão C++ não especifica o comportamento de empacotamento para o alinhamento em limites de menores do que o padrão do compilador para a plataforma de destino, portanto, você ainda precisará usar o Microsoft #pragma [pack](../preprocessor/pack.md) nesse caso.

A biblioteca padrão C++ fornece as [classe aligned_storage](../standard-library/aligned-storage-class.md) para alocar memória para estruturas de dados com alinhamentos personalizados e o [classe aligned_union](../standard-library/aligned-union-class.md) para especificar o alinhamento para uniões com construtores triviais ou destruidores.

## <a name="about-alignment"></a>Sobre o alinhamento

Alinhamento é uma propriedade de um endereço de memória, expressada como o endereço numérico de módulo uma potência de 2. Por exemplo, o endereço 0x0001103F módulo 4 é 3; Esse endereço deve ser alinhado a 4n + 3, em que 4 indica a escolhido potência de 2. O alinhamento de um endereço depende a escolhido potência de dois. O mesmo endereço de módulo 8 é 7. Um endereço deve ser alinhado a X se seu alinhamento é Xn + 0.

CPUs executam instruções que operam em dados armazenados na memória e os dados são identificados por seus endereços na memória. Além de seu endereço, um único datum também tem um tamanho. Uma referência é chamada alinhada naturalmente se seu endereço é alinhado ao seu tamanho e desalinhados caso contrário. Por exemplo, uma referência de ponto flutuante de 8 bytes é alinhada naturalmente se o endereço usado para identificá-lo é alinhado para 8.

Tratamento de compilador de dados alignmentDevice compiladores tentativa para alocar dados de uma maneira que impede que o desalinhamento de dados.

Para tipos de dados simples, o compilador atribui endereços que sejam múltiplos do tamanho em bytes do tipo de dados. Assim, o compilador atribui endereços a variáveis do tipo long que sejam múltiplos de quatro, definindo os parte inferior dois bits do endereço como zero.

Além disso, o compilador acrescenta estruturas de forma que naturalmente alinha-se cada elemento da estrutura. Considere o x_ struct de estrutura no exemplo de código a seguir:

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

O exemplo de código a seguir mostra como o compilador coloca a estrutura preenchida na cópia de memória:

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

1. As duas declarações retornam sizeof(struct x_) como 12 bytes.

1. A segunda declaração inclui dois elementos de preenchimento:

1. char _pad0 [3] para alinhar o membro de b int em um limite de quatro bytes

1. char _pad1 [1] para alinhar os elementos da matriz do struct de estrutura x barra [3];

1. O preenchimento alinha os elementos da barra [3], de forma que permita o acesso natural.

O exemplo de código a seguir mostra a barra de layout de matriz [3]:

```
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

[Alinhamento de estrutura de dados](http://en.wikipedia.org/wiki/Data_structure_alignment)