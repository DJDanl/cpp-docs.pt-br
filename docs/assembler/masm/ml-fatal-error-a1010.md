---
title: Erro fatal A1010 (ML)
ms.date: 08/30/2018
ms.custom: error-reference
f1_keywords:
- A1010
helpviewer_keywords:
- A1010
ms.assetid: 9e0b5241-67f4-4740-8701-3b2d2d1ad9e4
ms.openlocfilehash: 6ec82f7f6d559d977a9aa039ed91689a0ef4d49a
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74856872"
---
# <a name="ml-fatal-error-a1010"></a>Erro fatal A1010 (ML)

**aninhamento de bloco sem correspondência:**

Um início de bloco não tinha uma extremidade correspondente ou um final de bloco não tinha um início correspondente. Uma das seguintes opções pode estar envolvida:

- Uma diretiva de alto nível, como [. SE](../../assembler/masm/dot-if.md), [. Repita](../../assembler/masm/dot-repeat.md)ou [. TEMPO](../../assembler/masm/dot-while.md).

- Uma diretiva de assembly condicional, como [If](../../assembler/masm/if-masm.md), [REPEAT](../../assembler/masm/repeat.md)ou **while**.

- Uma definição de estrutura ou União.

- Uma definição de procedimento.

- Uma definição de segmento.

- Uma diretiva [POPCONTEXT](../../assembler/masm/popcontext.md) .

- Uma diretiva de assembly condicional, como [else](../../assembler/masm/else-masm.md), [ElseIf](../../assembler/masm/elseif-masm.md)ou **endif** sem um [If](../../assembler/masm/if-masm.md)correspondente.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>