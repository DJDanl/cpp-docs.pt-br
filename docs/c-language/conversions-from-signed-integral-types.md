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
ms.openlocfilehash: 79608b5ca4335ee3c30bdab27e7efade5b7e2f54
ms.sourcegitcommit: c51b2c665849479fa995bc3323a22ebe79d9d7ce
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/07/2019
ms.locfileid: "71998729"
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

A tabela a seguir resume as conversões de tipos integrais com sinal. Ele assume que o tipo **Char** é assinado por padrão. Se você usar uma opção de tempo de compilação para alterar o padrão para o tipo de **caractere** para não assinado, as conversões fornecidas na tabela [conversões de tipos de integral não assinados](../c-language/conversions-from-unsigned-integral-types.md) para o tipo de **caractere não** assinado serão aplicadas, em vez das conversões nesta tabela.

**Seção específica da Microsoft**

No compilador da Microsoft, **int** e **Long** são tipos distintos, mas equivalentes. A conversão de um valor **int** continua da mesma maneira que a conversão de um **longo**.

**Fim da seção específica da Microsoft**

## <a name="table-of-conversions-from-signed-integral-types"></a>Tabela de conversões de tipos integrais assinados

|De|Para|Método|
|----------|--------|------------|
|**caractere**<sup>1</sup>|**short**|Extensão de sinal|
|**char**|**long**|Extensão de sinal|
|**char**|**long long**|Extensão de sinal|
|**char**|**unsigned char**|Preserva o padrão; o bit de ordem superior perde a função como bit de sinal|
|**char**|**unsigned short**|Extensão de sinal para **short**; converte **short** em **unsigned short**|
|**char**|**unsigned long**|Extensão de sinal para **long**; converter **long** em **unsigned long**|
|**char**|**longo longo sem sinal**|Estender conexão para **longa duração**; Converter **longo** longo para **sem sinal** longo longo|
|**char**|**float**|Extensão de sinal para **long**; converte **long** em **float**|
|**char**|**double**|Extensão de sinal para **long**; converte **long** em **double**|
|**char**|**long double**|Extensão de sinal para **long**; converte **long** em **double**|
|**short**|**char**|Preserva o byte de ordem inferior|
|**short**|**long**|Extensão de sinal|
|**short**|**long long**|Extensão de sinal|
|**short**|**unsigned char**|Preserva o byte de ordem inferior|
|**short**|**unsigned short**|Preserva o padrão de bits; o bit de ordem superior perde a função como bit de sinal|
|**short**|**unsigned long**|Extensão de sinal para **long**; converter **long** em **unsigned long**|
|**short**|**longo longo sem sinal**|Estender conexão para **longa duração**; Converter **longo** longo para **sem sinal** longo longo|
|**short**|**float**|Extensão de sinal para **long**; converte **long** em **float**|
|**short**|**double**|Extensão de sinal para **long**; converte **long** em **double**|
|**short**|**long double**|Extensão de sinal para **long**; converte **long** em **double**|
|**long**|**char**|Preserva o byte de ordem inferior|
|**long**|**short**|Preserva a palavra de ordem inferior|
|**long**|**long long**|Extensão de sinal|
|**long**|**unsigned char**|Preserva o byte de ordem inferior|
|**long**|**unsigned short**|Preserva a palavra de ordem inferior|
|**long**|**unsigned long**|Preserva o padrão de bits; o bit de ordem superior perde a função como bit de sinal|
|**long**|**longo longo sem sinal**|Estender conexão para **longa duração**; Converter **longo** longo para **sem sinal** longo longo|
|**long**|**float**|É representado como **float**. Se **Long** não puder ser representado exatamente, alguma precisão será perdida.|
|**long**|**double**|É representado como **double**. Se **Long** não puder ser representado exatamente como **Double**, alguma precisão será perdida.|
|**long**|**long double**|É representado como **double**. Se **Long** não puder ser representado exatamente como **Double**, alguma precisão será perdida.|
|**long long**|**char**|Preserva o byte de ordem inferior|
|**long long**|**short**|Preserva a palavra de ordem inferior|
|**long long**|**long**|Preservar DWORD de ordem inferior|
|**long long**|**unsigned char**|Preserva o byte de ordem inferior|
|**long long**|**unsigned short**|Preserva a palavra de ordem inferior|
|**long long**|**unsigned long**|Preservar DWORD de ordem inferior|
|**long long**|**longo longo sem sinal**|Preserva o padrão de bits; o bit de ordem superior perde a função como bit de sinal|
|**long long**|**float**|É representado como **float**. Se **longos** não puderem ser representados exatamente, alguma precisão será perdida.|
|**long long**|**double**|É representado como **double**. Se **longos** não puderem ser representados exatamente como um **duplo**, alguma precisão será perdida.|
|**long long**|**long double**|É representado como **double**. Se **longos** não puderem ser representados exatamente como um **duplo**, alguma precisão será perdida.|

<sup>1</sup> todas as entradas **Char** pressupõem que o tipo **Char** é assinado por padrão.

## <a name="see-also"></a>Consulte também

[Conversões de atribuição](../c-language/assignment-conversions.md)
