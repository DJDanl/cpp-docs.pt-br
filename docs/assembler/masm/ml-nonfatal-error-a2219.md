---
title: Erro não fatal A2219 (ML)
ms.date: 08/30/2018
ms.topic: error-reference
f1_keywords:
- A2219
helpviewer_keywords:
- A2219
ms.assetid: 5ebc2f40-e47e-4f8e-b7b9-960b9cfc9f6d
ms.openlocfilehash: 61fa6bc6d630f1e8a8ac84492b60690c9545fb3e
ms.sourcegitcommit: 79e985d3c6e8ccaf94f6e641972887cae8c6eeb0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/24/2019
ms.locfileid: "66197676"
---
# <a name="ml-nonfatal-error-a2219"></a>Erro não fatal A2219 (ML)

> Alinhamento incorreto para o deslocamento no código de desenrolamento

## <a name="remarks"></a>Comentários

O operando [ &period;ALLOCSTACK](../../assembler/masm/dot-allocstack.md) e [ &period;SAVEREG](../../assembler/masm/dot-savereg.md) deve ser um múltiplo de 8.  O operando [ &period;SAVEXMM128](../../assembler/masm/dot-savexmm128.md) e [ &period;SETFRAME](../../assembler/masm/dot-setframe.md) deve ser um múltiplo de 16.

## <a name="see-also"></a>Consulte também

[Mensagens de erro ML](../../assembler/masm/ml-error-messages.md)
