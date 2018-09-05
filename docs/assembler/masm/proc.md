---
title: PROC | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- PROC
dev_langs:
- C++
helpviewer_keywords:
- PROC directive
ms.assetid: ee5bb6b6-fa15-4d73-b0cf-e650178539a9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3ee26e181f0f40126c86a36889c43405f0b40f5e
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43680840"
---
# <a name="proc"></a>PROC

Marca o início e término de um bloco do procedimento chamado *rótulo*. As instruções no bloco podem ser chamadas com o **chamar** instrução ou [INVOKE](../../assembler/masm/invoke.md) diretiva.

## <a name="syntax"></a>Sintaxe

> *rótulo* PROC [[*distância*]] [[*langtype*]] [[*visibilidade*]] [[\<*prologuearg*>]] [[ USA *reglist*]] [[, *parâmetro* [[:*marca*]]]...<br/>
> [[Quadro [[:*ehandler endereço*]]]]<br/>
> *Instruções*<br/>
> *rótulo* ENDP

## <a name="remarks"></a>Comentários

[[Quadro [[:*ehandler endereço*]]]] é válido apenas com ml64.exe e faz com que o MASM gerar uma entrada de tabela de função no registro. pData e. XData informações de desenrolamento para uma função do estruturado comportamento de desenrolamento de manipulação de exceção.

Quando o **quadro** atributo for usado, ele deve ser seguido por um [. ENDPROLOG](../../assembler/masm/dot-endprolog.md) diretiva.

Ver [MASM para x64 (ml64.exe)](../../assembler/masm/masm-for-x64-ml64-exe.md) para obter mais informações sobre como usar ml64.exe.

## <a name="example"></a>Exemplo

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

O código acima será emita a seguinte tabela de função e informações de desenrolamento:

```Output
FileHeader->Machine 34404
Dumping Unwind Information for file ex2.exe

.pdata entry 1 0x00001000 0x00001023

  Unwind data: 0x00002000

    Unwind version: 1
    Unwind Flags: None
    Size of prologue: 0x08
    Count of codes: 3
    Frame register: rbp
    Frame offset: 0x0
    Unwind codes:

      Code offset: 0x08, SET_FPREG, register=rbp, offset=0x00
      Code offset: 0x05, ALLOC_SMALL, size=0x10
      Code offset: 0x01, PUSH_NONVOL, register=rbp
```

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>