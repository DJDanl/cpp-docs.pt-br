---
title: .ALLOCSTACK
ms.date: 08/30/2018
f1_keywords:
- .ALLOCSTACK
helpviewer_keywords:
- .ALLOCSTACK directive
ms.assetid: 9801594b-7ac2-4df2-a49d-07d9dd9af99e
ms.openlocfilehash: b92db3d03bb5c45e67473cd4085f2369698f6b42
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62185647"
---
# <a name="allocstack"></a>.ALLOCSTACK

Gera uma **UWOP_ALLOC_SMALL** ou um **UWOP_ALLOC_LARGE** com o tamanho especificado para o deslocamento atual no prólogo.

## <a name="syntax"></a>Sintaxe

> . Tamanho ALLOCSTACK

## <a name="remarks"></a>Comentários

MASM escolherá a codificação mais eficiente para um determinado tamanho.

. ALLOCSTACK permite que os usuários ml64.exe especificar como uma função de quadro é desenrolado e só é permitido dentro do prólogo, que se estende do [PROC](../../assembler/masm/proc.md) declaração de quadro para o [. ENDPROLOG](../../assembler/masm/dot-endprolog.md) diretiva. Essas diretivas não geram código; elas só geram `.xdata` e `.pdata`. . ALLOCSTACK deve ser precedido por instruções que realmente implementam as ações a ser organizado. É uma boa prática para encapsular as diretivas de desenrolamento e o código que eles se destinam à desenrolamento em uma macro para garantir que o contrato.

O `size` operando deve ser um múltiplo de 8.

Para obter mais informações, consulte [MASM para x64 (ml64.exe)](../../assembler/masm/masm-for-x64-ml64-exe.md).

## <a name="sample"></a>Amostra

O exemplo a seguir mostra como especificar um manipulador de exceção/desenrolamento:

```asm
; ml64 ex3.asm /link /entry:Example1  /SUBSYSTEM:Console
text SEGMENT
PUBLIC Example3
PUBLIC Example3_UW
Example3_UW PROC NEAR
   ; exception/unwind handler body

   ret 0

Example3_UW ENDP

Example3 PROC FRAME : Example3_UW

   sub rsp, 16
.allocstack 16

.endprolog

   ; function body
    add rsp, 16
   ret 0

Example3 ENDP
text ENDS
END
```

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>