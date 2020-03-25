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
ms.openlocfilehash: f16e466ebb5f31231411eaaf9a1a85bfcc46a34d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169572"
---
# <a name="calling-c-functions-in-inline-assembly"></a>Chamando funções C++ no assembly embutido

**Seção específica da Microsoft**

Um bloco de `__asm` pode chamar somente C++ funções globais que não estão sobrecarregadas. Se você chamar uma função global C++ sobrecarregada ou uma C++ função de membro, o compilador emitirá um erro.

Você também pode chamar qualquer função declarada com ligação **"C" externa** . Isso permite que um bloco de `__asm` C++ dentro de um programa chame as funções da biblioteca C, porque todos os arquivos de cabeçalho padrão declaram as funções de biblioteca para ter vínculo **"C" externo** .

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>
