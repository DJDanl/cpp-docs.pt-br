---
title: Erro fatal A1010 (ML)
ms.date: 12/17/2019
ms.custom: error-reference
f1_keywords:
- A1010
helpviewer_keywords:
- A1010
ms.assetid: 9e0b5241-67f4-4740-8701-3b2d2d1ad9e4
ms.openlocfilehash: b3141f8819a33281c70e34bd7772d4475886e557
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75312580"
---
# <a name="ml-fatal-error-a1010"></a>Erro fatal A1010 (ML)

**aninhamento de bloco sem correspondência:**

Um início de bloco não tinha uma extremidade correspondente ou um final de bloco não tinha um início correspondente. Uma das seguintes opções pode estar envolvida:

- Uma diretiva de alto nível, como [. SE](dot-if.md), [. Repita](dot-repeat.md)ou [. TEMPO](dot-while.md).

- Uma diretiva de assembly condicional, como [If](if-masm.md), [REPEAT](repeat.md)ou **while**.

- Uma definição de estrutura ou União.

- Uma definição de procedimento.

- Uma definição de segmento.

- Uma diretiva [POPCONTEXT](popcontext.md) .

- Uma diretiva de assembly condicional, como [else](else-masm.md), [ElseIf](elseif-masm.md)ou **endif** sem um [If](if-masm.md)correspondente.

## <a name="see-also"></a>Veja também

[Mensagens de erro de ML](ml-error-messages.md)
