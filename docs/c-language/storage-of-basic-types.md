---
title: Armazenamento de tipos básicos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 14c8483671e806adb9170429f2e17d4487de0cfd
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46090484"
---
# <a name="storage-of-basic-types"></a>Armazenamento de tipos básicos

A tabela a seguir resume o armazenamento associado a cada tipo básico.

### <a name="sizes-of-fundamental-types"></a>Tamanhos de tipos fundamentais

|Tipo|Armazenamento|
|----------|-------------|
|`char`, `unsigned char`, **signed char**|1 byte|
|**short**, **unsigned short**|2 bytes|
|`int`, `unsigned int`|4 bytes|
|**long**, `unsigned long`|4 bytes|
|**float**|4 bytes|
|**double**|8 bytes|
|`long double`|8 bytes|

Os tipos de dados C se enquadram nas categorias gerais. Os “tipos integrais” incluem `char`, `int`, **short**, **long**, **signed**, `unsigned` e `enum`. Os “tipos flutuantes” incluem **float**, **double** e `long double`. Os “tipos aritméticos” incluem todos os tipos flutuantes e integrais.

## <a name="see-also"></a>Consulte também

[Declarações e tipos](../c-language/declarations-and-types.md)