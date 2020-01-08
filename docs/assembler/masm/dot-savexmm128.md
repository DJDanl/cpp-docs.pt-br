---
title: .SAVEXMM128
ms.date: 12/17/2019
f1_keywords:
- .SAVEXMM128
helpviewer_keywords:
- .SAVEXMM128 directive
ms.assetid: 551eb472-b8d0-47b1-8d82-995d1f485723
ms.openlocfilehash: 6402b75c10b1400d56923116621f00b4d0908822
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75318248"
---
# <a name="savexmm128"></a>.SAVEXMM128

Gera um `UWOP_SAVE_XMM128` ou uma `UWOP_SAVE_XMM128_FAR` entrada de código de desenrolamento para o registro XMM especificado e o deslocamento usando o deslocamento de prólogo atual. MASM escolherá a codificação mais eficiente.

## <a name="syntax"></a>Sintaxe

> **. SAVEXMM128** *xmmreg* , *offset*

## <a name="remarks"></a>Comentários

**. O SAVEXMM128** permite que os usuários do ml64. exe especifiquem como a função de quadro se desenrola e só é permitida dentro do prólogo, que se estende da declaração de quadro [proc](proc.md) para o [. Diretiva endprólogo](dot-endprolog.md) . Essas diretivas não geram código; Eles geram apenas `.xdata` e `.pdata`. . SAVEXMM128 deve ser precedido por instruções que realmente implementam as ações a serem rebobinadas. É uma boa prática encapsular as diretivas de desenrolamento e o código que elas devem desenrolar em uma macro para garantir o contrato.

o *deslocamento* deve ser um múltiplo de 16.

Para obter mais informações, consulte [MASM para x64 (ml64. exe)](masm-for-x64-ml64-exe.md).

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
