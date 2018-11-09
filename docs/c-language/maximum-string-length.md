---
title: Comprimento máximo da cadeia de caracteres
ms.date: 11/04/2016
helpviewer_keywords:
- lengths, strings
- string length, maximum
- maximum string length
- strings [C++], length
ms.assetid: 99a80e4a-6212-47b7-a6bd-bdf99bd44928
ms.openlocfilehash: f2e5461c433a0d195682c1a0f4312a71a8ff5032
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50483971"
---
# <a name="maximum-string-length"></a>Comprimento máximo da cadeia de caracteres

**Seção específica da Microsoft**

A compatibilidade ANSI requer que um compilador aceite até 509 caracteres em uma cadeia de caracteres literal depois da concatenação. O comprimento máximo de uma literal de cadeia de caracteres permitida no Microsoft C é de aproximadamente 2.048 bytes. No entanto, se o literal da cadeia de caracteres consiste em partes incluídas entre aspas duplas, o pré-processador concatena as partes em uma única cadeia de caracteres e, para cada linha concatenada, ele acrescenta um byte adicional ao número total de bytes.

Por exemplo, imagine que uma cadeia de caracteres consiste em 40 linhas com 50 caracteres por linha (2.000 caracteres) e uma linha com 7 caracteres e que cada linha é cercada por aspas duplas. Isso adiciona até 2.007 bytes mais um byte para o caractere nulo de encerramento para um total de 2.008 bytes. Na concatenação, um caractere adicional é acrescentado para cada uma das primeiras 40 linhas. Isso totaliza 2.048 bytes. No entanto, se continuações das linhas (\\) forem usadas em vez de aspas duplas, o pré-processador não acrescentará um caractere adicional para cada linha.

Quando uma cadeia de caracteres individual entre aspas não pode ter mais que 2048 bytes, um literal de cadeia de caracteres de 65535 bytes pode ser criado por meio da concatenação de cadeias de caracteres.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Literais da cadeia de caracteres C](../c-language/c-string-literals.md)