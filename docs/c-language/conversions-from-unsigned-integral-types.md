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
ms.openlocfilehash: 3099f0113103223e392dc20560899b4a6e3ebf20
ms.sourcegitcommit: c51b2c665849479fa995bc3323a22ebe79d9d7ce
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/07/2019
ms.locfileid: "71998795"
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

**Seção específica da Microsoft**

No compilador Microsoft, os tipos **não** assinados (ou **int**. não assinados) e **longos** não assinados são distintos, mas equivalentes. A conversão de um valor **unsigned int** é realizada da mesma maneira que a conversão de um **unsigned long**.

**Fim da seção específica da Microsoft**

A tabela a seguir resume as conversões de tipos integrais sem sinal.

## <a name="table-of-conversions-from-unsigned-integral-types"></a>Tabela de conversões de tipos integrais não assinados

|De|Para|Método|
|----------|--------|------------|
|**unsigned char**|**char**|Preserva o padrão de bits; o bit de ordem superior torna-se o bit de sinal|
|**unsigned char**|**short**|Extensão de zero|
|**unsigned char**|**long**|Extensão de zero|
|**unsigned char**|**long long**|Extensão de zero|
|**unsigned char**|**unsigned short**|Extensão de zero|
|**unsigned char**|**unsigned long**|Extensão de zero|
|**unsigned char**|**longo longo sem sinal**|Extensão de zero|
|**unsigned char**|**float**|Converte em **long**; converte **long** em **float**|
|**unsigned char**|**double**|Converte em **long**; converte **long** em **double**|
|**unsigned char**|**long double**|Converte em **long**; converte **long** em **double**|
|**unsigned short**|**char**|Preserva o byte de ordem inferior|
|**unsigned short**|**short**|Preserva o padrão de bits; o bit de ordem superior torna-se o bit de sinal|
|**unsigned short**|**long**|Extensão de zero|
|**unsigned short**|**long long**|Extensão de zero|
|**unsigned short**|**unsigned char**|Preserva o byte de ordem inferior|
|**unsigned short**|**unsigned long**|Extensão de zero|
|**unsigned short**|**longo longo sem sinal**|Extensão de zero|
|**unsigned short**|**float**|Converte em **long**; converte **long** em **float**|
|**unsigned short**|**double**|Converte em **long**; converte **long** em **double**|
|**unsigned short**|**long double**|Converte em **long**; converte **long** em **double**|
|**unsigned long**|**char**|Preserva o byte de ordem inferior|
|**unsigned long**|**short**|Preserva a palavra de ordem inferior|
|**unsigned long**|**long**|Preserva o padrão de bits; o bit de ordem superior torna-se o bit de sinal|
|**unsigned long**|**long long**|Extensão de zero|
|**unsigned long**|**unsigned char**|Preserva o byte de ordem inferior|
|**unsigned long**|**unsigned short**|Preserva a palavra de ordem inferior|
|**unsigned long**|**longo longo sem sinal**|Extensão de zero|
|**unsigned long**|**float**|Converte em **long**; converte **long** em **float**|
|**unsigned long**|**double**|Converter diretamente em **double**|
|**unsigned long**|**long double**|Converte em **long**; converte **long** em **double**|
|**longo longo sem sinal**|**char**|Preserva o byte de ordem inferior|
|**longo longo sem sinal**|**short**|Preserva a palavra de ordem inferior|
|**longo longo sem sinal**|**long**|Preservar DWORD de ordem inferior|
|**longo longo sem sinal**|**long long**|Preserva o padrão de bits; o bit de ordem superior torna-se o bit de sinal|
|**longo longo sem sinal**|**unsigned char**|Preserva o byte de ordem inferior|
|**longo longo sem sinal**|**unsigned short**|Preserva a palavra de ordem inferior|
|**longo longo sem sinal**|**unsigned long**|Preservar DWORD de ordem inferior|
|**longo longo sem sinal**|**float**|Converte em **long**; converte **long** em **float**|
|**longo longo sem sinal**|**double**|Converter diretamente em **double**|
|**longo longo sem sinal**|**long double**|Converte em **long**; converte **long** em **double**|

## <a name="see-also"></a>Consulte também

[Conversões de atribuição](../c-language/assignment-conversions.md)
