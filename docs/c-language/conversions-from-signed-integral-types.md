---
title: Conversões de tipos integrais com sinal
ms.date: 10/02/2019
helpviewer_keywords:
- integral conversions, from signed
- integers, converting
- conversions [C++], integral
- data type conversion [C++], signed and unsigned integers
- type conversion [C++], signed and unsigned integers
ms.assetid: 5eea32f8-8b14-413d-acac-c063b3d118d7
ms.openlocfilehash: d41d2fd205a87f9f2be2179ffd8e38256a96e4f7
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226471"
---
# <a name="conversions-from-signed-integral-types"></a>Conversões de tipos integrais com sinal

Quando um inteiro assinado é convertido em um número inteiro ou em um tipo de ponto flutuante, se o valor original for representável no tipo de resultado, o valor será inalterado.

Quando um inteiro assinado é convertido em um número inteiro de tamanho maior, o valor é Sign-Extended. Quando convertido para um inteiro de tamanho menor, os bits de ordem superior são truncados. O resultado é interpretado usando o tipo de resultado, conforme mostrado neste exemplo:

```C
int i = -3;
unsigned short u;

u = i;
printf_s( "%hu\n", u );  // Prints 65533
```

Ao converter um inteiro assinado em um tipo de ponto flutuante, se o valor original não for reapresentável exatamente no tipo de resultado, o resultado será o próximo valor reapresentável mais alto ou mais baixo.

Para obter informações sobre os tamanhos de tipos de ponto flutuante e integral, consulte [armazenamento de tipos básicos](../c-language/storage-of-basic-types.md).

A tabela a seguir resume as conversões de tipos integrais com sinal. Ele pressupõe que o **`char`** tipo é assinado por padrão. Se você usar uma opção de tempo de compilação para alterar o padrão do **`char`** tipo para não assinado, as conversões fornecidas na tabela [conversões de tipos de integral não assinados](../c-language/conversions-from-unsigned-integral-types.md) para o **`unsigned char`** tipo se aplicam, em vez das conversões nesta tabela.

**Específico da Microsoft**

No compilador da Microsoft, **`int`** e **`long`** são tipos distintos, mas equivalentes. A conversão de um **`int`** valor prossegue da mesma maneira que a conversão de um **`long`** .

**FINAL específico da Microsoft**

## <a name="table-of-conversions-from-signed-integral-types"></a>Tabela de conversões de tipos integrais assinados

|De|Para|Método|
|----------|--------|------------|
|**`char`**<sup>uma</sup>|**`short`**|Extensão de sinal|
|**`char`**|**`long`**|Extensão de sinal|
|**`char`**|**`long long`**|Extensão de sinal|
|**`char`**|**`unsigned char`**|Preserva o padrão; o bit de ordem superior perde a função como bit de sinal|
|**`char`**|**`unsigned short`**|Assinar para **`short`** ; Converter **`short`** em**`unsigned short`**|
|**`char`**|**`unsigned long`**|Assinar para **`long`** ; Converter **`long`** em**`unsigned long`**|
|**`char`**|**`unsigned long long`**|Assinar para **`long long`** ; Converter **`long long`** em**`unsigned long long`**|
|**`char`**|**`float`**|Assinar para **`long`** ; Converter **`long`** em**`float`**|
|**`char`**|**`double`**|Assinar para **`long`** ; Converter **`long`** em**`double`**|
|**`char`**|**`long double`**|Assinar para **`long`** ; Converter **`long`** em**`double`**|
|**`short`**|**`char`**|Preserva o byte de ordem inferior|
|**`short`**|**`long`**|Extensão de sinal|
|**`short`**|**`long long`**|Extensão de sinal|
|**`short`**|**`unsigned char`**|Preserva o byte de ordem inferior|
|**`short`**|**`unsigned short`**|Preserva o padrão de bits; o bit de ordem superior perde a função como bit de sinal|
|**`short`**|**`unsigned long`**|Assinar para **`long`** ; Converter **`long`** em**`unsigned long`**|
|**`short`**|**`unsigned long long`**|Assinar para **`long long`** ; Converter **`long long`** em**`unsigned long long`**|
|**`short`**|**`float`**|Assinar para **`long`** ; Converter **`long`** em**`float`**|
|**`short`**|**`double`**|Assinar para **`long`** ; Converter **`long`** em**`double`**|
|**`short`**|**`long double`**|Assinar para **`long`** ; Converter **`long`** em**`double`**|
|**`long`**|**`char`**|Preserva o byte de ordem inferior|
|**`long`**|**`short`**|Preserva a palavra de ordem inferior|
|**`long`**|**`long long`**|Extensão de sinal|
|**`long`**|**`unsigned char`**|Preserva o byte de ordem inferior|
|**`long`**|**`unsigned short`**|Preserva a palavra de ordem inferior|
|**`long`**|**`unsigned long`**|Preserva o padrão de bits; o bit de ordem superior perde a função como bit de sinal|
|**`long`**|**`unsigned long long`**|Assinar para **`long long`** ; Converter **`long long`** em**`unsigned long long`**|
|**`long`**|**`float`**|Representar como **`float`** . Se **`long`** não puder ser representado exatamente, alguma precisão será perdida.|
|**`long`**|**`double`**|Representar como **`double`** . Se **`long`** não puder ser representado exatamente como um **`double`** , alguma precisão será perdida.|
|**`long`**|**`long double`**|Representar como **`double`** . Se **`long`** não puder ser representado exatamente como um **`double`** , alguma precisão será perdida.|
|**`long long`**|**`char`**|Preserva o byte de ordem inferior|
|**`long long`**|**`short`**|Preserva a palavra de ordem inferior|
|**`long long`**|**`long`**|Preservar DWORD de ordem inferior|
|**`long long`**|**`unsigned char`**|Preserva o byte de ordem inferior|
|**`long long`**|**`unsigned short`**|Preserva a palavra de ordem inferior|
|**`long long`**|**`unsigned long`**|Preservar DWORD de ordem inferior|
|**`long long`**|**`unsigned long long`**|Preserva o padrão de bits; o bit de ordem superior perde a função como bit de sinal|
|**`long long`**|**`float`**|Representar como **`float`** . Se **`long long`** não puder ser representado exatamente, alguma precisão será perdida.|
|**`long long`**|**`double`**|Representar como **`double`** . Se **`long long`** não puder ser representado exatamente como um **`double`** , alguma precisão será perdida.|
|**`long long`**|**`long double`**|Representar como **`double`** . Se **`long long`** não puder ser representado exatamente como um **`double`** , alguma precisão será perdida.|

<sup>1</sup> todas as **`char`** entradas pressupõem que o **`char`** tipo é assinado por padrão.

## <a name="see-also"></a>Confira também

[Conversões de atribuição](../c-language/assignment-conversions.md)
