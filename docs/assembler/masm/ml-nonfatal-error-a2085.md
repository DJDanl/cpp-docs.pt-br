---
title: Erro não fatal A2085 (ML)
ms.date: 08/30/2018
ms.custom: error-reference
f1_keywords:
- A2085
helpviewer_keywords:
- A2085
ms.assetid: c2fef415-a32b-4249-896c-6d981fc6e327
ms.openlocfilehash: 3bd89fb2b7f8b755cdb095e63ed89386332ecf9d
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74855752"
---
# <a name="ml-nonfatal-error-a2085"></a>Erro não fatal A2085 (ML)

**instrução ou registro não aceito no modo de CPU atual**

Foi feita uma tentativa de usar uma instrução, um registro ou uma palavra-chave que não era válida para o modo de processador atual.

Por exemplo, os registros de 32 bits exigem [. 386](../../assembler/masm/dot-386.md) ou superior. Os registros de controle, como CR0, exigem o modo Privileged [. 386P](../../assembler/masm/dot-386p.md) ou superior. Esse erro também será gerado para as palavras-chave **NEAR32**, **FAR32**e **Flat** , que exigem. **386** ou superior.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>