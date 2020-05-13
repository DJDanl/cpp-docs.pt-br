---
title: Tipo para literais da cadeia de caracteres
ms.date: 11/04/2016
helpviewer_keywords:
- string literals, type
- types [C], string literals
ms.assetid: f50a28af-20c1-4440-bdc6-564c86a309c8
ms.openlocfilehash: 7e832ac7aa08ad80ab395baa59eabbabb486b46f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62344844"
---
# <a name="type-for-string-literals"></a>Tipo para literais da cadeia de caracteres

As literais da cadeias de caracteres têm a matriz do tipo `char` (ou seja, **char[ ]**). (Cadeias de caracteres largos têm matriz `wchar_t` de tipo de (ou seja, **wchar_t []**).) Isso significa que uma cadeia de caracteres é uma matriz com elementos `char`do tipo. O número de elementos na matriz é igual ao número de caracteres na cadeia de caracteres mais um, para o caractere nulo de encerramento.

## <a name="see-also"></a>Confira também

[Literais da cadeia de caracteres C](../c-language/c-string-literals.md)
