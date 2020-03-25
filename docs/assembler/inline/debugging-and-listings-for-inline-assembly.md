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
ms.openlocfilehash: 3254fb6b750466de0a38230c5e1cfa067c476f5e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169507"
---
# <a name="debugging-and-listings-for-inline-assembly"></a>Depuração e listagens para assembly embutido

**Seção específica da Microsoft**

Os programas que contêm código de assembly embutido podem ser depurados com um depurador de nível de origem se você compilar com a opção [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) .

No depurador, você pode definir pontos de interrupção nas linhas C ou C++ e assembly-Language. Se você habilitar o modo de assembly e código-fonte misto, poderá exibir a forma de origem e desmontada do código do assembly.

Observe que colocar várias instruções de assembly ou instruções de linguagem de origem em uma linha pode dificultar a depuração. No modo de origem, você pode usar o depurador para definir pontos de interrupção em uma única linha, mas não em instruções individuais na mesma linha. O mesmo princípio se aplica a um bloco de `__asm` definido como uma macro C, que se expande para uma única linha lógica.

Se você criar uma listagem mista de assembly e fonte com a opção de compilador [/FAS](../../build/reference/fa-fa-listing-file.md) , a listagem conterá os formulários de origem e de assembly de cada linha de linguagem de assembly. As macros não são expandidas em listagens, mas são expandidas durante a compilação.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>
