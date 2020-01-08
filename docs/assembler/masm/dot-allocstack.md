---
title: .ALLOCSTACK
ms.date: 12/17/2019
f1_keywords:
- .ALLOCSTACK
helpviewer_keywords:
- .ALLOCSTACK directive
ms.assetid: 9801594b-7ac2-4df2-a49d-07d9dd9af99e
ms.openlocfilehash: bcc94619dfa24ab5c8b5d23a60825641290ef176
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75314179"
---
# <a name="allocstack"></a>.ALLOCSTACK

Gera um **UWOP_ALLOC_SMALL** ou um **UWOP_ALLOC_LARGE** com o tamanho especificado para o deslocamento atual no prólogo.

## <a name="syntax"></a>Sintaxe

> **.**  *Tamanho* do ALLOCSTACK

## <a name="remarks"></a>Comentários

MASM escolherá a codificação mais eficiente para um determinado tamanho.

**. ALLOCSTACK** permite que os usuários de ml64. exe especifiquem como uma função de quadro desenrola e só é permitida dentro do prólogo, que se estende da declaração de quadro [proc](proc.md) para o [. Diretiva endprólogo](dot-endprolog.md) . Essas diretivas não geram código; Eles geram apenas `.xdata` e `.pdata`. **. ALLOCSTACK** deve ser precedido por instruções que realmente implementam as ações a serem rebobinadas. É uma boa prática encapsular as diretivas de desenrolamento e o código que elas devem desenrolar em uma macro para garantir o contrato.

O operando de *tamanho* deve ser um múltiplo de 8.

Para obter mais informações, consulte [MASM para x64 (ml64. exe)](masm-for-x64-ml64-exe.md).

## <a name="sample"></a>Amostra

O exemplo a seguir mostra como especificar um manipulador de desenrolamento/exceção:

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

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
