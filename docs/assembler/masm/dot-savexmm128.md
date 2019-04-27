---
title: .SAVEXMM128
ms.date: 08/30/2018
f1_keywords:
- .SAVEXMM128
helpviewer_keywords:
- .SAVEXMM128 directive
ms.assetid: 551eb472-b8d0-47b1-8d82-995d1f485723
ms.openlocfilehash: c29ec47170c5e0f46f02d53f23ab477a79bbdc32
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62205212"
---
# <a name="savexmm128"></a>.SAVEXMM128

Gera a um `UWOP_SAVE_XMM128` ou um `UWOP_SAVE_XMM128_FAR` desenrolar a entrada de código para o registro de registros de MMX especificado e usando o deslocamento atual do prólogo de deslocamento. MASM escolherá a codificação mais eficiente.

## <a name="syntax"></a>Sintaxe

> .savexmm128 xmmreg , offset

## <a name="remarks"></a>Comentários

. SAVEXMM128 permite que os usuários de ml64.exe especificar como uma função de quadro é desenrolado e só é permitida dentro do prólogo, que se estende do [PROC](../../assembler/masm/proc.md) declaração de quadro para o [. ENDPROLOG](../../assembler/masm/dot-endprolog.md) diretiva. Essas diretivas não geram código; elas só geram `.xdata` e `.pdata`. . SAVEXMM128 deve ser precedido por instruções que realmente implementam as ações a ser organizado. É uma boa prática para encapsular as diretivas de desenrolamento e o código que eles se destinam à desenrolamento em uma macro para garantir que o contrato.

*deslocamento* deve ser um múltiplo de 16.

Para obter mais informações, consulte [MASM para x64 (ml64.exe)](../../assembler/masm/masm-for-x64-ml64-exe.md).

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>