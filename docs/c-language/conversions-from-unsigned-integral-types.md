---
title: Conversões de tipos integrais sem sinal
ms.date: 10/02/2019
helpviewer_keywords:
- integers, converting
- type casts, involving integers
- data type conversion [C++], signed and unsigned integers
- type conversion [C++], signed and unsigned integers
- integral conversions, from unsigned
ms.assetid: 60fb7e10-bff9-4a13-8a48-e19f25a36a02
ms.openlocfilehash: 08b88b1343f56f8d79fc39c53505b26caecfe3c4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226458"
---
# <a name="conversions-from-unsigned-integral-types"></a>Conversões de tipos integrais sem sinal

Quando um inteiro sem sinal é convertido em um tipo inteiro ou de ponto flutuante, se o valor original for representável no tipo de resultado, o valor será inalterado.

Ao converter um inteiro não assinado em um inteiro de tamanho maior, o valor será estendido como zero. Ao converter para um inteiro de tamanho menor, os bits de ordem superior são truncados. O resultado é interpretado usando o tipo de resultado, conforme mostrado neste exemplo.

```C
unsigned k = 65533;
short j;

j = k;
printf_s( "%hd\n", j );   // Prints -3
```

Ao converter um inteiro não assinado em um tipo de ponto flutuante, se o valor original não puder ser representado exatamente no tipo de resultado, o resultado será o próximo valor reapresentável mais alto ou mais baixo.

Consulte [armazenamento de tipos básicos](../c-language/storage-of-basic-types.md) para obter informações sobre os tamanhos de tipos de ponto flutuante e integral.

**Específico da Microsoft**

No compilador da Microsoft, **`unsigned`** (ou **`unsigned int`** ) e **`unsigned long`** são tipos distintos, mas equivalentes. A conversão de um **`unsigned int`** valor prossegue da mesma maneira que a conversão de um **`unsigned long`** .

**FINAL específico da Microsoft**

A tabela a seguir resume as conversões de tipos integrais sem sinal.

## <a name="table-of-conversions-from-unsigned-integral-types"></a>Tabela de conversões de tipos integrais não assinados

|De|Para|Método|
|----------|--------|------------|
|**`unsigned char`**|**`char`**|Preserva o padrão de bits; o bit de ordem superior torna-se o bit de sinal|
|**`unsigned char`**|**`short`**|Extensão de zero|
|**`unsigned char`**|**`long`**|Extensão de zero|
|**`unsigned char`**|**`long long`**|Extensão de zero|
|**`unsigned char`**|**`unsigned short`**|Extensão de zero|
|**`unsigned char`**|**`unsigned long`**|Extensão de zero|
|**`unsigned char`**|**`unsigned long long`**|Extensão de zero|
|**`unsigned char`**|**`float`**|Converter em **`long`** ; Converter **`long`** em**`float`**|
|**`unsigned char`**|**`double`**|Converter em **`long`** ; Converter **`long`** em**`double`**|
|**`unsigned char`**|**`long double`**|Converter em **`long`** ; Converter **`long`** em**`double`**|
|**`unsigned short`**|**`char`**|Preserva o byte de ordem inferior|
|**`unsigned short`**|**`short`**|Preserva o padrão de bits; o bit de ordem superior torna-se o bit de sinal|
|**`unsigned short`**|**`long`**|Extensão de zero|
|**`unsigned short`**|**`long long`**|Extensão de zero|
|**`unsigned short`**|**`unsigned char`**|Preserva o byte de ordem inferior|
|**`unsigned short`**|**`unsigned long`**|Extensão de zero|
|**`unsigned short`**|**`unsigned long long`**|Extensão de zero|
|**`unsigned short`**|**`float`**|Converter em **`long`** ; Converter **`long`** em**`float`**|
|**`unsigned short`**|**`double`**|Converter em **`long`** ; Converter **`long`** em**`double`**|
|**`unsigned short`**|**`long double`**|Converter em **`long`** ; Converter **`long`** em**`double`**|
|**`unsigned long`**|**`char`**|Preserva o byte de ordem inferior|
|**`unsigned long`**|**`short`**|Preserva a palavra de ordem inferior|
|**`unsigned long`**|**`long`**|Preserva o padrão de bits; o bit de ordem superior torna-se o bit de sinal|
|**`unsigned long`**|**`long long`**|Extensão de zero|
|**`unsigned long`**|**`unsigned char`**|Preserva o byte de ordem inferior|
|**`unsigned long`**|**`unsigned short`**|Preserva a palavra de ordem inferior|
|**`unsigned long`**|**`unsigned long long`**|Extensão de zero|
|**`unsigned long`**|**`float`**|Converter em **`long`** ; Converter **`long`** em**`float`**|
|**`unsigned long`**|**`double`**|Converter diretamente em**`double`**|
|**`unsigned long`**|**`long double`**|Converter em **`long`** ; Converter **`long`** em**`double`**|
|**`unsigned long long`**|**`char`**|Preserva o byte de ordem inferior|
|**`unsigned long long`**|**`short`**|Preserva a palavra de ordem inferior|
|**`unsigned long long`**|**`long`**|Preservar DWORD de ordem inferior|
|**`unsigned long long`**|**`long long`**|Preserva o padrão de bits; o bit de ordem superior torna-se o bit de sinal|
|**`unsigned long long`**|**`unsigned char`**|Preserva o byte de ordem inferior|
|**`unsigned long long`**|**`unsigned short`**|Preserva a palavra de ordem inferior|
|**`unsigned long long`**|**`unsigned long`**|Preservar DWORD de ordem inferior|
|**`unsigned long long`**|**`float`**|Converter em **`long`** ; Converter **`long`** em**`float`**|
|**`unsigned long long`**|**`double`**|Converter diretamente em**`double`**|
|**`unsigned long long`**|**`long double`**|Converter em **`long`** ; Converter **`long`** em**`double`**|

## <a name="see-also"></a>Confira também

[Conversões de atribuição](../c-language/assignment-conversions.md)
