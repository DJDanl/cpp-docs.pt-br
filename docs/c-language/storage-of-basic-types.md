---
title: Armazenamento de tipos básicos
ms.date: 10/02/2019
helpviewer_keywords:
- specifiers [C++], type
- integral types, storage
- storage [C++], types
- floating-point numbers, storage
- type specifiers [C++], sizes
- arithmetic operations [C++], types
- int data type
- short data type
- signed types [C++], storage
- long double keyword [C], storage
- long keyword [C]
- double data type, storage
- types [C], arithmetic
- integral types
- data types [C], specifiers
- storing types [C++]
- unsigned types [C++], storage
- data types [C], storage
ms.assetid: bd1f33c1-c6b9-4558-8a72-afb21aef3318
ms.openlocfilehash: 64c642df4dd85e4aa09f90a143b8aa67c28b7dc2
ms.sourcegitcommit: c51b2c665849479fa995bc3323a22ebe79d9d7ce
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/07/2019
ms.locfileid: "71998765"
---
# <a name="storage-of-basic-types"></a>Armazenamento de tipos básicos

A tabela a seguir resume o armazenamento associado a cada tipo básico.

## <a name="sizes-of-fundamental-types"></a>Tamanhos de tipos fundamentais

|Tipo|Armazenamento|
|----------|-------------|
|**Char**, **Char não assinado**, **caractere assinado**|1 byte|
|**short**, **unsigned short**|2 bytes|
|**int**, **unsigned int**|4 bytes|
|**long**, **unsigned long**|4 bytes|
|**longo tempo**, **não assinado longo**|8 bytes|
|**float**|4 bytes|
|**double**|8 bytes|
|**long double**|8 bytes|

Os tipos de dados C se enquadram nas categorias gerais. Os *tipos integrais* incluem **int**, **Char**, **Short**, **Long**e Long **Long**. Esses tipos podem ser qualificados com **assinados** **ou não assinados**, **e não assinados** por si só podem ser usados como abreviados para **int não assinado**. Os tipos de enumeração (**enum**) também são tratados como tipos integrais para a maioria das finalidades. Os *tipos flutuantes* incluem **float**, **Double**e **Long double**. Os *tipos aritméticos* incluem todos os tipos flutuantes e integrais.

## <a name="see-also"></a>Consulte também

[Declarações e tipos](../c-language/declarations-and-types.md)
