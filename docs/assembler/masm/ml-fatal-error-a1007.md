---
title: Erro Fatal de ML A1007 | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A1007
dev_langs:
- C++
helpviewer_keywords:
- A1007
ms.assetid: bcf9c826-beb3-4e93-91fe-1ffd34995fbf
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 539ab431510d5dc721e6531c11069a87e27c287a
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43693595"
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