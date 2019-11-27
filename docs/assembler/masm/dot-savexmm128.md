---
title: .SAVEXMM128
ms.date: 08/30/2018
f1_keywords:
- .SAVEXMM128
helpviewer_keywords:
- .SAVEXMM128 directive
ms.assetid: 551eb472-b8d0-47b1-8d82-995d1f485723
ms.openlocfilehash: 08bc5ab50e15aa59e0c49992d1810c7de20f364e
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74397958"
---
# <a name="savexmm128"></a>.SAVEXMM128

Gera um `UWOP_SAVE_XMM128` ou uma `UWOP_SAVE_XMM128_FAR` entrada de código de desenrolamento para o registro XMM especificado e o deslocamento usando o deslocamento de prólogo atual. MASM escolherá a codificação mais eficiente.

## <a name="syntax"></a>Sintaxe

> **. SAVEXMM128** *xmmreg* , *offset*

## <a name="remarks"></a>Comentários

**. O SAVEXMM128** permite que os usuários do ml64. exe especifiquem como a função de quadro se desenrola e só é permitida dentro do prólogo, que se estende da declaração de quadro [proc](../../assembler/masm/proc.md) para o [. Diretiva endprólogo](../../assembler/masm/dot-endprolog.md) . Essas diretivas não geram código; Eles geram apenas `.xdata` e `.pdata`. . SAVEXMM128 deve ser precedido por instruções que realmente implementam as ações a serem rebobinadas. É uma boa prática encapsular as diretivas de desenrolamento e o código que elas devem desenrolar em uma macro para garantir o contrato.

o *deslocamento* deve ser um múltiplo de 16.

Para obter mais informações, consulte [MASM para x64 (ml64. exe)](../../assembler/masm/masm-for-x64-ml64-exe.md).

## <a name="see-also"></a>Consulte também

[Referência de diretivas](directives-reference.md)
