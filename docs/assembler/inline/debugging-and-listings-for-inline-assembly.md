---
title: Depuração e listagens para assembly embutido
ms.date: 08/30/2018
helpviewer_keywords:
- source level debugger
- __asm keyword [C++], debugging
- inline assembly, listings
- bugs, __asm blocks
- debugging [C++], inline assembly code
- inline assembly, debugging
ms.assetid: 69266930-6f9a-433d-b704-f4f44e7b2583
ms.openlocfilehash: 6e97c2528f480268599f561e8cf4a1df2518c6b3
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87192178"
---
# <a name="debugging-and-listings-for-inline-assembly"></a>Depuração e listagens para assembly embutido

**Específico da Microsoft**

Os programas que contêm código de assembly embutido podem ser depurados com um depurador de nível de origem se você compilar com a opção [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) .

No depurador, você pode definir pontos de interrupção em C ou C++ e em linhas de linguagem de assembly. Se você habilitar o modo de assembly e código-fonte misto, poderá exibir a forma de origem e desmontada do código do assembly.

Observe que colocar várias instruções de assembly ou instruções de linguagem de origem em uma linha pode dificultar a depuração. No modo de origem, você pode usar o depurador para definir pontos de interrupção em uma única linha, mas não em instruções individuais na mesma linha. O mesmo princípio se aplica a um **`__asm`** bloco definido como uma macro C, que se expande para uma única linha lógica.

Se você criar uma listagem mista de assembly e fonte com a opção de compilador [/FAS](../../build/reference/fa-fa-listing-file.md) , a listagem conterá os formulários de origem e de assembly de cada linha de linguagem de assembly. As macros não são expandidas em listagens, mas são expandidas durante a compilação.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Usando o idioma do assembly em blocos de __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>
