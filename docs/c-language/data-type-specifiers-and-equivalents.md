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
ms.openlocfilehash: cc8ba746bea7f6ea885beb625de414d83367b53f
ms.sourcegitcommit: f2a135d69a2a8ef1777da60c53d58fe06980c997
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/03/2020
ms.locfileid: "87520675"
---
# <a name="data-type-specifiers-and-equivalents"></a>Especificadores de tipo de dados e equivalentes

Esse livro geralmente usa os formulários dos especificadores de tipo listados na tabela a seguir, em vez de formulários longos, e pressupõe que o **`char`** tipo é assinado por padrão. Portanto, em todo este livro, **`char`** é equivalente a **`signed char`** .

## <a name="type-specifiers-and-equivalents"></a>Especificadores e equivalentes de tipo

| Especificador de tipo | Equivalente(s) |
|--|--|
| **`signed char`**<sup>uma</sup> | **`char`** |
| **`signed int`** | **`signed`**, **`int`** |
| **`signed short int`** | **`short`**, **`signed short`** |
| **`signed long int`** | **`long`**, **`signed long`** |
| **`unsigned char`** | — |
| **`unsigned int`** | **`unsigned`** |
| **`unsigned short int`** | **`unsigned short`** |
| **`unsigned long int`** | **`unsigned long`** |
| **`float`** | — |
| **`long double`**<sup>2</sup> | — |

<sup>1</sup> quando você torna o **`char`** tipo não assinado por padrão (especificando a opção do **`/J`** compilador), não é possível abreviar **`signed char`** como **`char`** .

<sup>2</sup> em sistemas operacionais de 32 bits e 64 bits, o compilador do Microsoft C é mapeado **`long double`** para o tipo **`double`** .

**Específico da Microsoft**

Você pode especificar a **`/J`** opção do compilador para alterar o **`char`** tipo padrão de **`signed char`** para **`unsigned char`** . Quando essa opção estiver em vigor, **`char`** significa o mesmo que **`unsigned char`** , e você deve usar a **`signed`** palavra-chave para declarar um valor de caractere assinado. Se um **`char`** valor for declarado explicitamente **`signed`** , a **`/J`** opção não o afetará, e o valor será estendido quando se expandir para um **`int`** tipo. O **`char`** tipo é estendido com zero quando ampliado para o **`int`** tipo.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Consulte também

[Especificadores de tipo C](../c-language/c-type-specifiers.md)
