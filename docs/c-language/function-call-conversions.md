---
title: Conversões de função de chamada
ms.date: 11/04/2016
helpviewer_keywords:
- function calls, converting
- function calls, argument type conversions
- functions [C], argument conversions
ms.assetid: 04ea0f81-509a-4913-8b12-0937a81babcf
ms.openlocfilehash: e4e84c9d4e1f25a56c0bcabcec99e5e75fcaa321
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229669"
---
# <a name="function-call-conversions"></a>Conversões de função de chamada

O tipo de conversão executado nos argumentos em uma chamada de função depende da presença de um protótipo de função (declaração de encaminhamento) com tipos de argumentos declarados para a função chamada.

Se um protótipo da função estiver presente e incluir tipos de argumentos declarados, o compilador fará a verificação de tipo (consulte [Funções](../c-language/functions-c.md)).

Se nenhum protótipo da função estiver presente, somente as conversões aritméticas comuns serão executadas nos argumentos na chamada da função. Essas conversões são executadas independentemente em cada argumento na chamada. Isso significa que um **`float`** valor é convertido em a **`double`** ; um **`char`** ou **`short`** valor é convertido em um **`int`** ; e um **`unsigned char`** ou **`unsigned short`** é convertido em um **`unsigned int`** .

## <a name="see-also"></a>Confira também

[Conversões de tipo](../c-language/type-conversions-c.md)
