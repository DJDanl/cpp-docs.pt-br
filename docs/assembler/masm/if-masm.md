---
title: IF (MASM)
ms.date: 12/17/2019
helpviewer_keywords:
- IF directive
ms.assetid: 82e43712-4f0c-4bf6-90ce-0663e81af707
ms.openlocfilehash: 6e63f5c8075b3c94370ad8863d224c097cf0ecdf
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79440754"
---
# <a name="if"></a>IF

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

As seguintes diretivas podem ser substituídas por [ElseIf](elseif-masm.md): **ELSEIFB**, **ELSEIFDEF**, **ELSEIFDIF**, **ELSEIFDIFI**, **ElseIf**, **ELSEIFIDN**, **ELSEIFIDNI**, **ELSEIFNB**e **ELSEIFNDEF**. Opcionalmente, o monta *instruções ELSE* se a expressão anterior for false. Observe que as expressões são avaliadas no momento do assembly.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
