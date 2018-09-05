---
title: Erro Fatal de ML A1010 | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A1010
dev_langs:
- C++
helpviewer_keywords:
- A1010
ms.assetid: 9e0b5241-67f4-4740-8701-3b2d2d1ad9e4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 12b7e8698951e8ef59e0433134ec992af5d5f77f
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43676291"
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