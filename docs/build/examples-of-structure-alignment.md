---
title: Exemplos de alinhamento da estrutura | Microsoft Docs
ms.custom: ''
ms.date: 03/26/2018
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- structure alignment
- examples [C++], structure alignment
ms.assetid: 03d137bf-5cc4-472e-9583-6498f2534199
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a9c4e8cb27d02777e40af56217bd82dec6e647b6
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32367736"
---
# <a name="examples-of-structure-alignment"></a>Exemplos de alinhamento da estrutura

Os quatro exemplos a seguir cada declarar que uma estrutura alinhada ou union e os números correspondentes a ilustrar o layout da estrutura ou união na memória. Cada coluna em uma figura representa um byte de memória e o número na coluna indica o deslocamento do que byte. O nome da segunda linha de cada figura corresponde ao nome de uma variável na declaração. As colunas sombreadas indicam o preenchimento que é necessário para alcançar o alinhamento especificado.

## <a name="example-1"></a>Exemplo 1

```C
// Total size = 2 bytes, alignment = 2 bytes (word).

_declspec(align(2)) struct {
    short a;      // +0; size = 2 bytes
}
```

![Exemplo de conversão AMD](../build/media/vcamd_conv_ex_1_block.png "vcAmd_conv_ex_1")

## <a name="example-2"></a>Exemplo 2

```C
// Total size = 24 bytes, alignment = 8 bytes (quadword).

_declspec(align(8)) struct {
    int a;       // +0; size = 4 bytes
    double b;    // +8; size = 8 bytes
    short c;     // +16; size = 2 bytes
}
```

![Exemplo de conversão AMD](../build/media/vcamd_conv_ex_2_block.png "vcAmd_conv_ex_2")

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

![Exemplo de conversão AMD](../build/media/vcamd_conv_ex_3_block.png "vcAmd_conv_ex_3")

## <a name="example-4"></a>Exemplo 4

```C
// Total size = 8 bytes, alignment = 8 bytes (quadword).

_declspec(align(8)) union {
    char *p;      // +0; size = 8 bytes
    short s;      // +0; size = 2 bytes
    long l;       // +0; size = 4 bytes
}
```

![Exemplo de conversão AMD](../build/media/vcamd_conv_ex_4_block.png "vcAmd_conv_ex_4")

## <a name="see-also"></a>Consulte também

[Tipos e armazenamento](../build/types-and-storage.md)<br/>
