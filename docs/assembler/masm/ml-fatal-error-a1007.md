---
title: Erro fatal A1007 (ML)
ms.date: 08/30/2018
ms.custom: error-reference
f1_keywords:
- A1007
helpviewer_keywords:
- A1007
ms.assetid: bcf9c826-beb3-4e93-91fe-1ffd34995fbf
ms.openlocfilehash: 01633b4fa084b7d5e14af5a5c6e51e3dca684d2a
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74856911"
---
# <a name="ml-fatal-error-a1007"></a>Erro fatal A1007 (ML)

**nível de aninhamento muito profundo**

O Assembler atingiu seu limite de aninhamento. O limite é de 20 níveis, exceto quando indicado de outra forma.

Um dos itens a seguir foi aninhado muito profundamente:

- Uma diretiva de alto nível, como [. SE](../../assembler/masm/dot-if.md), [. Repita](../../assembler/masm/dot-repeat.md)ou [. TEMPO](../../assembler/masm/dot-while.md).

- Uma definição de estrutura.

- Uma diretiva de assembly condicional.

- Uma definição de procedimento.

- Uma diretiva [PUSHCONTEXT](../../assembler/masm/pushcontext.md) (o limite é 10).

- Uma definição de segmento.

- Um arquivo de inclusão.

- Uma macro.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>