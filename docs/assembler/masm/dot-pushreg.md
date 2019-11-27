---
title: .PUSHREG
ms.date: 08/30/2018
f1_keywords:
- .PUSHREG
helpviewer_keywords:
- .PUSHREG directive
ms.assetid: e0c83758-dfed-40ea-afe6-cb833c8d2d30
ms.openlocfilehash: 2190bd05667de82dada34a63f11647c653f97247
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74398032"
---
# <a name="pushreg"></a>.PUSHREG

Gera uma entrada de código de desenrolação `UWOP_PUSH_NONVOL` para o número de registro especificado usando o deslocamento atual no prólogo.

## <a name="syntax"></a>Sintaxe

> . Registro de PUSHREG

## <a name="remarks"></a>Comentários

**. O PUSHREG** permite que os usuários do ml64. exe especifiquem como a função de quadro se desenrola e só é permitida dentro do prólogo, que se estende da declaração de **quadro** [proc](../../assembler/masm/proc.md) para o [. Diretiva endprólogo](../../assembler/masm/dot-endprolog.md) . Essas diretivas não geram código; Eles geram apenas `.xdata` e `.pdata`. **. PUSHREG** deve ser precedido por instruções que realmente implementam as ações a serem rebobinadas. É uma boa prática encapsular as diretivas de desenrolamento e o código que elas devem desenrolar em uma macro para garantir o contrato.

Para obter mais informações, consulte [MASM para x64 (ml64. exe)](../../assembler/masm/masm-for-x64-ml64-exe.md).

## <a name="sample"></a>Amostra

### <a name="description"></a>Descrição

O exemplo a seguir mostra como enviar por push registros não voláteis.

### <a name="code"></a>Código

```asm
; ml64 ex1.asm /link /entry:Example1 /SUBSYSTEM:CONSOLE
_text SEGMENT
Example1 PROC FRAME
   push r10
.pushreg r10
   push r15
.pushreg r15
   push rbx
.pushreg rbx
   push rsi
.pushreg rsi
.endprolog
   ; rest of function ...
   ret
Example1 ENDP
_text ENDS
END
```

## <a name="see-also"></a>Consulte também

[Referência de diretivas](directives-reference.md)
