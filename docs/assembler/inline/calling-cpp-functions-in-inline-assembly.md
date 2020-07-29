---
title: Chamando funções C++ no assembly embutido
ms.date: 08/30/2018
helpviewer_keywords:
- functions [C++], calling in inline assembly
- function calls, C++ functions
- function calls, in inline assembly
- Visual C++, functions
- inline assembly, calling functions
- __asm keyword [C++], calling functions
ms.assetid: 1f0d1eb3-54cf-45d5-838d-958188616b38
ms.openlocfilehash: 781b60c8973593039c0fdfa2f457170e95048597
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87192529"
---
# <a name="calling-c-functions-in-inline-assembly"></a>Chamando funções C++ no assembly embutido

**Específico da Microsoft**

Um **`__asm`** bloco pode chamar somente funções globais do C++ que não estão sobrecarregadas. Se você chamar uma função de C++ global sobrecarregada ou uma função membro do C++, o compilador emitirá um erro.

Você também pode chamar qualquer função declarada com ligação **"C" externa** . Isso permite que um **`__asm`** bloco em um programa C++ chame as funções da biblioteca C, porque todos os arquivos de cabeçalho padrão declaram as funções de biblioteca para ter vínculo **"C" externo** .

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>
