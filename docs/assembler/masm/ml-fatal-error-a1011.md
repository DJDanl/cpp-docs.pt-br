---
title: Erro fatal A1011 (ML)
ms.date: 08/30/2018
ms.custom: error-reference
f1_keywords:
- A1011
helpviewer_keywords:
- A1011
ms.assetid: 7fbf092d-4189-4330-a884-dfa2268fc3dd
ms.openlocfilehash: 0d8d3896f7788aa3f51605651ee1b728b0e1d60a
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74856846"
---
# <a name="ml-fatal-error-a1011"></a>Erro fatal A1011 (ML)

**a diretiva deve estar no bloco de controle**

O Assembler encontrou uma diretiva de alto nível em que não era esperado. Uma das seguintes diretivas foi encontrada:

- [. SENÃO](../../assembler/masm/dot-else.md) sem [. SE](../../assembler/masm/dot-if.md)

- [. ENDIF](../../assembler/masm/dot-endif.md) sem [. SE](../../assembler/masm/dot-if.md)

- [. ENDW](../../assembler/masm/dot-endw.md) sem [. ENQUANTO](../../assembler/masm/dot-while.md)

- [. UNTILCXZ](../../assembler/masm/dot-untilcxz.md) sem [. REPETIR](../../assembler/masm/dot-repeat.md)

- [. CONTINUAR](../../assembler/masm/dot-continue.md) sem [. WHILE](../../assembler/masm/dot-while.md) ou [. REPETIR](../../assembler/masm/dot-repeat.md)

- [. INTERROMPER](../../assembler/masm/dot-break.md) sem [. WHILE](../../assembler/masm/dot-while.md) ou [. REPETIR](../../assembler/masm/dot-repeat.md)

- [. CASO](../../assembler/masm/dot-else.md) a seguir `.ELSE`

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>