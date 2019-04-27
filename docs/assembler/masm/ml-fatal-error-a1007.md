---
title: Erro fatal A1007 (ML)
ms.date: 08/30/2018
ms.topic: error-reference
f1_keywords:
- A1007
helpviewer_keywords:
- A1007
ms.assetid: bcf9c826-beb3-4e93-91fe-1ffd34995fbf
ms.openlocfilehash: 98933c3a24da22f447174a3b51c4855690aba83e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62177897"
---
# <a name="ml-fatal-error-a1007"></a>Erro fatal A1007 (ML)

**nível de aninhamento muito profundo**

O montador atingiu seu limite de aninhamento. O limite é de 20 níveis, exceto quando indicado o contrário.

Um dos procedimentos a seguir foi aninhado profundamente demais:

- Uma diretiva de alto nível, como [. IF](../../assembler/masm/dot-if.md), [. REPITA](../../assembler/masm/dot-repeat.md), ou [. ENQUANTO](../../assembler/masm/dot-while.md).

- Uma definição de estrutura.

- Uma diretiva condicional assembly.

- Uma definição de procedimento.

- Um [PUSHCONTEXT](../../assembler/masm/pushcontext.md) diretiva (o limite é 10).

- Uma definição de segmento.

- Um arquivo de inclusão.

- Uma macro.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>