---
title: Erro não fatal A2219 (ML)
ms.date: 08/30/2018
ms.custom: error-reference
f1_keywords:
- A2219
helpviewer_keywords:
- A2219
ms.assetid: 5ebc2f40-e47e-4f8e-b7b9-960b9cfc9f6d
ms.openlocfilehash: cf2be5db2aa9c21597c199a6840f4aaa50e0a681
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74854583"
---
# <a name="ml-nonfatal-error-a2219"></a>Erro não fatal A2219 (ML)

> Alinhamento incorreto para deslocamento no código de desenrolamento

## <a name="remarks"></a>Comentários

O operando para [&period;allocstack](../../assembler/masm/dot-allocstack.md) e [&period;savereg](../../assembler/masm/dot-savereg.md) deve ser um múltiplo de 8.  O operando para [&period;SAVEXMM128](../../assembler/masm/dot-savexmm128.md) e [&period;SETFRAME](../../assembler/masm/dot-setframe.md) deve ser um múltiplo de 16.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)
