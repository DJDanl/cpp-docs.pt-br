---
title: Erro fatal A1011 (ML)
ms.date: 08/30/2018
ms.topic: error-reference
f1_keywords:
- A1011
helpviewer_keywords:
- A1011
ms.assetid: 7fbf092d-4189-4330-a884-dfa2268fc3dd
ms.openlocfilehash: 591755a1d7066d8251f61d2a22b9601a9ccb9dcb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62178560"
---
# <a name="ml-fatal-error-a1011"></a>Erro fatal A1011 (ML)

**diretiva deve estar no bloco de controle**

O montador encontrada uma diretiva de alto nível em que não esperava um. Uma das seguintes diretivas foi encontrada:

- [. ELSE](../../assembler/masm/dot-else.md) sem [. IF](../../assembler/masm/dot-if.md)

- [. ENDIF](../../assembler/masm/dot-endif.md) sem [. IF](../../assembler/masm/dot-if.md)

- [. ENDW](../../assembler/masm/dot-endw.md) sem [. WHILE](../../assembler/masm/dot-while.md)

- [. UNTILCXZ](../../assembler/masm/dot-untilcxz.md) sem [. REPITA](../../assembler/masm/dot-repeat.md)

- [. CONTINUE](../../assembler/masm/dot-continue.md) sem [. Embora](../../assembler/masm/dot-while.md) ou [. REPITA](../../assembler/masm/dot-repeat.md)

- [. INTERROMPER](../../assembler/masm/dot-break.md) sem [. Embora](../../assembler/masm/dot-while.md) ou [. REPITA](../../assembler/masm/dot-repeat.md)

- [. ELSE](../../assembler/masm/dot-else.md) seguir `.ELSE`

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>