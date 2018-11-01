---
title: Erro não fatal A2085 (ML)
ms.date: 08/30/2018
ms.topic: error-reference
f1_keywords:
- A2085
helpviewer_keywords:
- A2085
ms.assetid: c2fef415-a32b-4249-896c-6d981fc6e327
ms.openlocfilehash: 729f6f38761171c6ddc4cccfc2443c6a2b597bf3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50444340"
---
# <a name="ml-nonfatal-error-a2085"></a>Erro não fatal A2085 (ML)

**instrução ou o registro não foi aceito no modo de CPU atual**

Foi feita uma tentativa para usar uma instrução, registre-se ou uma palavra-chave que não era válido para o modo atual do processador.

Por exemplo, registros de 32 bits exigem [. 386 de](../../assembler/masm/dot-386.md) ou superior. Registros de controle, como CR0 exigem modo privilegiado [. 386p](../../assembler/masm/dot-386p.md) ou superior. Esse erro também será gerado para o **NEAR32**, **FAR32**, e **simples** palavras-chave, que exigem. **386** ou superior.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>