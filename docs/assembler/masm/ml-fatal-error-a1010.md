---
title: Erro fatal A1010 (ML)
ms.date: 08/30/2018
ms.topic: error-reference
f1_keywords:
- A1010
helpviewer_keywords:
- A1010
ms.assetid: 9e0b5241-67f4-4740-8701-3b2d2d1ad9e4
ms.openlocfilehash: eb4d77b856e93a8d64ee6c51bec63ceae59b22e5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62202059"
---
# <a name="ml-fatal-error-a1010"></a>Erro fatal A1010 (ML)

**aninhamento de bloco sem correspondência:**

Início de um bloco não tinha um end correspondente ou o fim do bloco não tinha um começa a correspondência. Um dos procedimentos a seguir pode ser envolvido:

- Uma diretiva de alto nível, como [. IF](../../assembler/masm/dot-if.md), [. REPITA](../../assembler/masm/dot-repeat.md), ou [. ENQUANTO](../../assembler/masm/dot-while.md).

- Uma diretiva condicional assembly como [IF](../../assembler/masm/if-masm.md), [REPITA](../../assembler/masm/repeat.md), ou **ENQUANTO**.

- Uma definição de estrutura ou união.

- Uma definição de procedimento.

- Uma definição de segmento.

- Um [POPCONTEXT](../../assembler/masm/popcontext.md) diretiva.

- Um assembly de condicional diretiva, como um [ELSE](../../assembler/masm/else-masm.md), [ELSEIF](../../assembler/masm/elseif-masm.md), ou **ENDIF** sem encontrar uma correspondência [se](../../assembler/masm/if-masm.md).

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>