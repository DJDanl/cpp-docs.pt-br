---
title: Conversões de tipos integrais assinados | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- integral conversions, from signed
- integers, converting
- conversions [C++], integral
- data type conversion [C++], signed and unsigned integers
- type conversion [C++], signed and unsigned integers
ms.assetid: 5eea32f8-8b14-413d-acac-c063b3d118d7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3fc38fd8b1ab4bc84898704218b2da5722514cea
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46101378"
---
# <a name="conversions-from-signed-integral-types"></a>Conversões de tipos integrais com sinal

Quando um inteiro com sinal é convertido em um inteiro sem sinal de tamanho igual ou maior e o valor do inteiro com sinal não é negativo, o valor não é alterado. A conversão é feita estendendo o sinal do inteiro com sinal. Um inteiro com sinal é convertido em um inteiro com sinal mais curto truncando os bits de ordem superior. O resultado é interpretado como um valor sem sinal, conforme é mostrado neste exemplo.

```C
int i = -3;
unsigned short u;

u = i;
printf_s( "%hu\n", u );  // Prints 65533
```

Nenhuma informação é perdida quando um inteiro com sinal é convertido em um valor flutuante; no entanto, um pouco de precisão pode ser perdido quando um valor **long int** ou **unsigned long int** é convertido em um valor **float**.

A tabela a seguir resume as conversões de tipos integrais com sinal. Essa tabela pressupõe que, por padrão, o tipo **char** tenha sinal. Se você usar uma opção de tempo de compilação para alterar o padrão do tipo **char** para sem sinal, as conversões fornecidas na tabela [Conversões de Tipos Integrais sem Sinal](../c-language/conversions-from-unsigned-integral-types.md) para o tipo **unsigned char** serão aplicadas no lugar das conversões indicadas na tabela a seguir, Conversões de Tipos Integrais Com Sinal.

### <a name="conversions-from-signed-integral-types"></a>Conversões de tipos integrais com sinal

|De|Para|Método|
|----------|--------|------------|
|**char**1|**short**|Extensão de sinal|
|**char**|**long**|Extensão de sinal|
|**char**|**unsigned char**|Preserva o padrão; o bit de ordem superior perde a função como bit de sinal|
|**char**|**unsigned short**|Extensão de sinal para **short**; converte **short** em **unsigned short**|
|**char**|**unsigned long**|Extensão de sinal para **long**; converter **long** em **unsigned long**|
|**char**|**float**|Extensão de sinal para **long**; converte **long** em **float**|
|**char**|**double**|Extensão de sinal para **long**; converte **long** em **double**|
|**char**|**long double**|Extensão de sinal para **long**; converte **long** em **double**|
|**short**|**char**|Preserva o byte de ordem inferior|
|**short**|**long**|Extensão de sinal|
|**short**|**unsigned char**|Preserva o byte de ordem inferior|
|**short**|**unsigned short**|Preserva o padrão de bits; o bit de ordem superior perde a função como bit de sinal|
|**short**|**unsigned long**|Extensão de sinal para **long**; converter **long** em **unsigned long**|
|**short**|**float**|Extensão de sinal para **long**; converte **long** em **float**|
|**short**|**double**|Extensão de sinal para **long**; converte **long** em **double**|
|**short**|**long double**|Extensão de sinal para **long**; converte **long** em **double**|
|**long**|**char**|Preserva o byte de ordem inferior|
|**long**|**short**|Preserva a palavra de ordem inferior|
|**long**|**unsigned char**|Preserva o byte de ordem inferior|
|**long**|**unsigned short**|Preserva a palavra de ordem inferior|
|**long**|**unsigned long**|Preserva o padrão de bits; o bit de ordem superior perde a função como bit de sinal|
|**long**|**float**|É representado como **float**. Se **long** não puder ser representado exatamente, um pouco da precisão será perdido.|
|**long**|**double**|É representado como **double**. Se **long** não puder ser representado exatamente como **double**, um pouco da precisão será perdido.|
|**long**|**long double**|É representado como **double**. Se **long** não puder ser representado exatamente como **double**, um pouco da precisão será perdido.|

1. Todas as entradas de **char** pressupõem que, por padrão, o tipo **char** tem sinal.

**Seção específica da Microsoft**

Para o compilador de C de 32 bits da Microsoft, um inteiro é equivalente a um **long**. A conversão de um valor **int** é realizada da mesma forma que para um **long**.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Conversões de atribuição](../c-language/assignment-conversions.md)