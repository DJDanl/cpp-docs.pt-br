---
title: .SAVEREG
ms.date: 08/30/2018
f1_keywords:
- .SAVEREG
helpviewer_keywords:
- .SAVEREG directive
ms.assetid: 1dbc2ef6-a197-40e7-9e55-fddcae8cef29
ms.openlocfilehash: cac7aa7f2bdbf6b60831d2beb062f86559ec0358
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50472808"
---
# <a name="savereg"></a>.SAVEREG

Gera a um `UWOP_SAVE_NONVOL` ou um `UWOP_SAVE_NONVOL_FAR` desenrolar a entrada de código para o registro especificado (`reg`) e deslocamento (`offset`) usando o deslocamento atual do prólogo. MASM escolherá a codificação mais eficiente.

## <a name="syntax"></a>Sintaxe

> . Reg SAVEREG, deslocamento

## <a name="remarks"></a>Comentários

. SAVEREG permite que os usuários ml64.exe especificar como uma função de quadro é desenrolado e só é permitido dentro do prólogo, que se estende do [PROC](../../assembler/masm/proc.md) declaração de quadro para o [. ENDPROLOG](../../assembler/masm/dot-endprolog.md) diretiva. Essas diretivas não geram código; elas só geram `.xdata` e `.pdata`. . SAVEREG deve ser precedido por instruções que realmente implementam as ações a ser organizado. É uma boa prática para encapsular as diretivas de desenrolamento e o código que eles se destinam à desenrolamento em uma macro para garantir que o contrato.

Para obter mais informações, consulte [MASM para x64 (ml64.exe)](../../assembler/masm/masm-for-x64-ml64-exe.md).

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>