---
title: IF (MASM)
ms.date: 12/17/2019
f1_keywords:
- if
helpviewer_keywords:
- IF directive
ms.assetid: 82e43712-4f0c-4bf6-90ce-0663e81af707
ms.openlocfilehash: 38d366a3a41e7b08759594899cdcbb2cb84dfbfa
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75317286"
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

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
