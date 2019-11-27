---
title: IF (MASM)
ms.date: 08/30/2018
f1_keywords:
- if
helpviewer_keywords:
- IF directive
ms.assetid: 82e43712-4f0c-4bf6-90ce-0663e81af707
ms.openlocfilehash: ed7b9e63bb19dcc16539dbdaaf1f6a7f16566b3c
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74397460"
---
# <a name="if-masm"></a>IF (MASM)

Concede o assembly de *ifstatements* se *expressão1* for true (diferente de zero) ou *elseifstatements* se *expressão1* for false (0) e *expression2* for true.

## <a name="syntax"></a>Sintaxe

> **Se** *expressão1*\
> *instruções if*\
> ⟦**ElseIf** *expression2*\
> *ElseIf-instruções*⟧ \
> ⟦**ELSE**\
> *else – instruções*⟧ \
> **ENDIF**

## <a name="remarks"></a>Comentários

As seguintes diretivas podem ser substituídas por [ElseIf](../../assembler/masm/elseif-masm.md): **ELSEIFB**, **ELSEIFDEF**, **ELSEIFDIF**, **ELSEIFDIFI**, **ElseIf**, **ELSEIFIDN**, **ELSEIFIDNI**, **ELSEIFNB**e **ELSEIFNDEF**. Opcionalmente, o monta *instruções ELSE* se a expressão anterior for false. Observe que as expressões são avaliadas no momento do assembly.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](directives-reference.md)
