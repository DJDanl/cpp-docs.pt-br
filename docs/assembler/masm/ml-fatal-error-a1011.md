---
title: Erro Fatal de ML A1011 | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A1011
dev_langs:
- C++
helpviewer_keywords:
- A1011
ms.assetid: 7fbf092d-4189-4330-a884-dfa2268fc3dd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 32949773b869d189516a381ca7df941760a1e4e4
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43690802"
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