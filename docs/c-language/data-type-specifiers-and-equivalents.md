---
title: Especificadores de tipo de dados e equivalentes
ms.date: 11/04/2016
helpviewer_keywords:
- type specifiers [C++], list
- widening integers
- data types [C++], equivalents
- sign-extending integral types
- zero-extending
- identifiers, data type
- data types [C++], specifiers
- simple types, names
- type names [C++], simple
ms.assetid: 0d4b515a-4f68-4786-83cf-a5d43c7cb6f3
ms.openlocfilehash: 4003d9427c160b0e1c725cdc591190bd9777b3de
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62234924"
---
# <a name="data-type-specifiers-and-equivalents"></a>Especificadores de tipo de dados e equivalentes

Este manual geralmente usa os formatos dos especificadores de tipo listados na tabela a seguir em vez dos formatos longos, e presume que o tipo `char` seja com sinal por padrão. Portanto, ao longo deste manual, `char` é equivalente a **signed char**.

### <a name="type-specifiers-and-equivalents"></a>Especificadores e equivalentes de tipo

|Especificador de tipo|Equivalente(s)|
|--------------------|---------------------|
|**signed char**1|**char**|
|**int assinado**|**signed**, **int**|
|**signed short int**|**short**, **signed short**|
|**signed long int**|**long**, **signed long**|
|**unsigned char**|—|
|**unsigned int**|**unsigned**|
|**unsigned short int**|**unsigned short**|
|**unsigned long int**|**unsigned long**|
|**float**|—|
|**long double**2|—|

1   Quando você tornar o tipo **char** sem sinal por padrão (especificando a opção do compilador /J), não será possível abreviar **signed char** como **char**.

2   Em sistemas operacionais de 32 e 64 bits, o compilador Microsoft C mapeia o tipo **long double** para o tipo **double**.

**Específico da Microsoft**

Você pode especificar a opção do compilador /J para alterar o tipo **char** padrão de com sinal para sem sinal. Quando essa opção é aplicada, **char** significa o mesmo que **unsigned char** e é necessário usar a palavra-chave **signed** para declarar um valor de caractere com sinal. Se um valor **char** for declarado explicitamente com sinal, a opção /J não o afetará e o valor será estendido com sinal quando ampliado para um tipo **int**. O tipo **char** é estendido em zero quando ampliado para o tipo **int**.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Especificadores de tipo C](../c-language/c-type-specifiers.md)
