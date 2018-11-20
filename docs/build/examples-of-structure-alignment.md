---
title: Exemplos de alinhamento da estrutura
ms.date: 11/19/2018
helpviewer_keywords:
- structure alignment
- examples [C++], structure alignment
ms.assetid: 03d137bf-5cc4-472e-9583-6498f2534199
ms.openlocfilehash: 7c4b3ae29674e9c4fc27e8e175867339001b9a0d
ms.sourcegitcommit: 9e891eb17b73d98f9086d9d4bfe9ca50415d9a37
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2018
ms.locfileid: "52175334"
---
# <a name="examples-of-structure-alignment"></a>Exemplos de alinhamento da estrutura

Os quatro exemplos a seguir cada declaram que uma estrutura alinhada ou união e os números correspondentes ilustram o layout da estrutura ou união na memória. Cada coluna em uma figura representa um byte de memória, e o número na coluna indica o deslocamento do que bytes. O nome da segunda linha de cada figura corresponde ao nome de uma variável na declaração. Colunas sombreadas indicam o preenchimento que é necessário para alcançar o alinhamento especificado.

## <a name="example-1"></a>Exemplo 1

```C
// Total size = 2 bytes, alignment = 2 bytes (word).

_declspec(align(2)) struct {
    short a;      // +0; size = 2 bytes
}
```

![Layout de estrutura de exemplo 1 de conversão AMD](../build/media/vcamd_conv_ex_1_block.png "layout da estrutura AMD conversão exemplo 1")

## <a name="example-2"></a>Exemplo 2

```C
// Total size = 24 bytes, alignment = 8 bytes (quadword).

_declspec(align(8)) struct {
    int a;       // +0; size = 4 bytes
    double b;    // +8; size = 8 bytes
    short c;     // +16; size = 2 bytes
}
```

![Layout de estrutura de exemplo 2 de conversão AMD](../build/media/vcamd_conv_ex_2_block.png "layout da estrutura AMD conversão exemplo 2")

## <a name="example-3"></a>Exemplo 3:

```C
// Total size = 22 bytes, alignment = 4 bytes (doubleword).

_declspec(align(4)) struct {
    char a;       // +0; size = 1 byte
    short b;      // +2; size = 2 bytes
    char c;       // +4; size = 1 byte
    int d;        // +8; size = 4 bytes
}
```

![Layout de estrutura de exemplo 2 de conversão AMD](../build/media/vcamd_conv_ex_3_block.png "layout da estrutura AMD conversão exemplo 2")

## <a name="example-4"></a>Exemplo 4

```C
// Total size = 8 bytes, alignment = 8 bytes (quadword).

_declspec(align(8)) union {
    char *p;      // +0; size = 8 bytes
    short s;      // +0; size = 2 bytes
    long l;       // +0; size = 4 bytes
}
```

![AMD conversão exemplo 4 união layouit](../build/media/vcamd_conv_ex_4_block.png "layouit union do AMD conversão exemplo 4")

## <a name="see-also"></a>Consulte também

[Tipos e armazenamento](../build/types-and-storage.md)<br/>
