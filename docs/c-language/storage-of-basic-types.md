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
ms.openlocfilehash: 973866a912b694510d587df765ac8dd54176638e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211665"
---
# <a name="storage-of-basic-types"></a>Armazenamento de tipos básicos

A tabela a seguir resume o armazenamento associado a cada tipo básico.

## <a name="sizes-of-fundamental-types"></a>Tamanhos de tipos fundamentais

|Type|Armazenamento|
|----------|-------------|
|**`char`**, **`unsigned char`**, **`signed char`**|1 byte|
|**`short`**, **`unsigned short`**|2 bytes|
|**`int`**, **`unsigned int`**|4 bytes|
|**`long`**, **`unsigned long`**|4 bytes|
|**`long long`**, **`unsigned long long`**|8 bytes|
|**`float`**|4 bytes|
|**`double`**|8 bytes|
|**`long double`**|8 bytes|

Os tipos de dados C se enquadram nas categorias gerais. Os *tipos integrais* incluem,,, **`int`** **`char`** **`short`** **`long`** e **`long long`** . Esses tipos podem ser qualificados com **`signed`** ou e **`unsigned`** , e **`unsigned`** por si só podem ser usados como abreviados para **`unsigned int`** . Os tipos de enumeração ( **`enum`** ) também são tratados como tipos integrais para a maioria das finalidades. Os *tipos flutuantes* incluem **`float`** , **`double`** e **`long double`** . Os *tipos aritméticos* incluem todos os tipos flutuantes e integrais.

## <a name="see-also"></a>Confira também

[Declarações e tipos](../c-language/declarations-and-types.md)
