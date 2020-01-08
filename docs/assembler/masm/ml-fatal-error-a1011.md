---
title: Erro fatal A1011 (ML)
ms.date: 12/17/2019
ms.custom: error-reference
f1_keywords:
- A1011
helpviewer_keywords:
- A1011
ms.assetid: 7fbf092d-4189-4330-a884-dfa2268fc3dd
ms.openlocfilehash: 5607d6d56e0b3889332dcf2624d519529819b1c9
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75318066"
---
# <a name="ml-fatal-error-a1011"></a>Erro fatal A1011 (ML)

**a diretiva deve estar no bloco de controle**

O Assembler encontrou uma diretiva de alto nível em que não era esperado. Uma das seguintes diretivas foi encontrada:

- [. SENÃO](dot-else.md) sem [. SE](dot-if.md)

- [. ENDIF](dot-endif.md) sem [. SE](dot-if.md)

- [. ENDW](dot-endw.md) sem [. ENQUANTO](dot-while.md)

- [. UNTILCXZ](dot-untilcxz.md) sem [. REPETIR](dot-repeat.md)

- [. CONTINUAR](dot-continue.md) sem [. WHILE](dot-while.md) ou [. REPETIR](dot-repeat.md)

- [. INTERROMPER](dot-break.md) sem [. WHILE](dot-while.md) ou [. REPETIR](dot-repeat.md)

- [. CASO](dot-else.md) a seguir `.ELSE`

## <a name="see-also"></a>Veja também

[Mensagens de erro de ML](ml-error-messages.md)
