---
title: Erro não fatal A2085 (ML)
ms.date: 12/17/2019
ms.custom: error-reference
f1_keywords:
- A2085
helpviewer_keywords:
- A2085
ms.assetid: c2fef415-a32b-4249-896c-6d981fc6e327
ms.openlocfilehash: f8fdedfc1bc8bff63124d18fe1410d9f144cb926
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75316831"
---
# <a name="ml-nonfatal-error-a2085"></a>Erro não fatal A2085 (ML)

**instrução ou registro não aceito no modo de CPU atual**

Foi feita uma tentativa de usar uma instrução, um registro ou uma palavra-chave que não era válida para o modo de processador atual.

Por exemplo, os registros de 32 bits exigem [. 386](dot-386.md) ou superior. Os registros de controle, como CR0, exigem o modo Privileged [. 386P](dot-386p.md) ou superior. Esse erro também será gerado para as palavras-chave **NEAR32**, **FAR32**e **Flat** , que exigem. **386** ou superior.

## <a name="see-also"></a>Veja também

[Mensagens de erro de ML](ml-error-messages.md)
