---
title: Erro fatal A1007 (ML)
ms.date: 12/17/2019
ms.custom: error-reference
f1_keywords:
- A1007
helpviewer_keywords:
- A1007
ms.assetid: bcf9c826-beb3-4e93-91fe-1ffd34995fbf
ms.openlocfilehash: c9527769e0d9397de90f49cbce98b2cca42bed50
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75317117"
---
# <a name="ml-fatal-error-a1007"></a>Erro fatal A1007 (ML)

**nível de aninhamento muito profundo**

O Assembler atingiu seu limite de aninhamento. O limite é de 20 níveis, exceto quando indicado de outra forma.

Um dos itens a seguir foi aninhado muito profundamente:

- Uma diretiva de alto nível, como [. SE](dot-if.md), [. Repita](dot-repeat.md)ou [. TEMPO](dot-while.md).

- Uma definição de estrutura.

- Uma diretiva de assembly condicional.

- Uma definição de procedimento.

- Uma diretiva [PUSHCONTEXT](pushcontext.md) (o limite é 10).

- Uma definição de segmento.

- Um arquivo de inclusão.

- Uma macro.

## <a name="see-also"></a>Veja também

[Mensagens de erro de ML](ml-error-messages.md)
