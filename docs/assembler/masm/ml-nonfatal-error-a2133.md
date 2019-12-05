---
title: Erro não fatal A2133 (ML)
ms.date: 08/30/2018
ms.custom: error-reference
f1_keywords:
- A2133
helpviewer_keywords:
- A2133
ms.assetid: 5ba50911-22c8-43b7-90e2-946fc612e05f
ms.openlocfilehash: c2d13aefe02543129340bcc307771a1026776d61
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74854609"
---
# <a name="ml-nonfatal-error-a2133"></a>Erro não fatal A2133 (ML)

**registrar valor substituído por INVOKE**

Um registro foi passado como um argumento para um procedimento, mas o código gerado por [Invoke](../../assembler/masm/invoke.md) para passar outros argumentos destruiu o conteúdo do registro.

Os registros AX, AL, AH, EAX, DX, DL, DH e EDX podem ser usados pelo Assembler para executar a conversão de dados.

Use um registro diferente.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>