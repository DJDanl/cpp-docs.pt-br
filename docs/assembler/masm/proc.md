---
title: PROC
ms.date: 08/30/2018
f1_keywords:
- PROC
helpviewer_keywords:
- PROC directive
ms.assetid: ee5bb6b6-fa15-4d73-b0cf-e650178539a9
ms.openlocfilehash: 5d1e44fcc4adbbe012b2f31fe9c6c27511bafff1
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74395025"
---
# <a name="proc"></a>PROC

Marca o início e o fim de um bloco de procedimento chamado *rótulo*. As instruções no bloco podem ser chamadas com a instrução **Call** ou a diretiva [Invoke](../../assembler/masm/invoke.md) .

## <a name="syntax"></a>Sintaxe

> *rótulo* **proc** ⟦*Distance*⟧ ⟦*idioma-tipo*⟧ ⟦*visibilidade*⟧ ⟦ __\<__ *prologuearg* __>__ ⟧ ⟦**usa** *reglist*⟧ ⟦ __,__ *parâmetro* ⟦ __:__ *marca*⟧... ⟧\
> ⟦**Quadro** ⟦ __:__ *ehandler-address*⟧ ⟧ \
> *instruções*\
> *rótulo* **ENDP**

## <a name="remarks"></a>Comentários

⟦**Frame** ⟦ __:__ *ehandler-address*⟧ ⟧ é válido somente com ml64. exe e faz com que MASM gere uma entrada de tabela de função em. pData e desenrola informações em. xdata para o comportamento de desenrolamento de manipulação de exceção estruturada de uma função.

Quando o atributo de **quadro** é usado, ele deve ser seguido por um [. Diretiva endprólogo](../../assembler/masm/dot-endprolog.md) .

Consulte [MASM para x64 (ml64. exe)](../../assembler/masm/masm-for-x64-ml64-exe.md) para obter mais informações sobre como usar o ml64. exe.

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

O código acima emitirá a seguinte tabela de função e informações de desenrolamento:

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

[Referência de diretivas](../../assembler/masm/directives-reference.md)
