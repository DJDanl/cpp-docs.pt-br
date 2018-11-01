---
title: Erro não fatal A2006 (ML)
ms.date: 08/30/2018
ms.topic: error-reference
f1_keywords:
- A2006
helpviewer_keywords:
- A2006
ms.assetid: b8a8f096-95df-42b5-85ed-d2530560a84c
ms.openlocfilehash: 80283bde4dff36e32d276c998f6797b6eeed8160
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50490058"
---
# <a name="ml-nonfatal-error-a2006"></a>Erro não fatal A2006 (ML)

**símbolo indefinido: identificador**

Foi feita uma tentativa para usar um símbolo que não foi definido.

Pode ter ocorrido um dos seguintes:

- Um símbolo não foi definido.

- Um campo não era um membro da estrutura especificada.

- Um símbolo foi definido em um arquivo de inclusão não tiver sido incluído.

- Um símbolo externo foi usado sem uma [EXTERN](../../assembler/masm/extern-masm.md) ou [EXTERNDEF](../../assembler/masm/externdef.md) diretiva.

- Um nome de símbolo foi digitado incorretamente.

- Um rótulo de código local foi referenciado fora de seu escopo.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>