---
title: Tipo para literais da cadeia de caracteres
ms.date: 11/04/2016
helpviewer_keywords:
- string literals, type
- types [C], string literals
ms.assetid: f50a28af-20c1-4440-bdc6-564c86a309c8
ms.openlocfilehash: 601821cf8eec8108227df938468a0efc6b513109
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50607925"
---
# <a name="type-for-string-literals"></a>Tipo para literais da cadeia de caracteres

As literais da cadeias de caracteres têm a matriz do tipo `char` (ou seja, **char[ ]**). (As cadeias de caracteres amplos têm a matriz do tipo `wchar_t` (ou seja, **wchar_t[ ]**)). Isso significa que uma cadeia de caracteres é uma matriz com elementos do tipo `char`. O número de elementos na matriz é igual ao número de caracteres na cadeia de caracteres mais um, para o caractere nulo de encerramento.

## <a name="see-also"></a>Consulte também

[Literais da cadeia de caracteres C](../c-language/c-string-literals.md)