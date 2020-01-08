---
title: .IF
ms.date: 11/05/2019
f1_keywords:
- .IF
helpviewer_keywords:
- .IF directive
ms.assetid: dccc7615-8fc7-4829-9f39-0ee405f6c1e3
ms.openlocfilehash: 6992ec8b151a83b3f9fa920997845c20caf0476d
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75317741"
---
# <a name="if-32-bit-masm"></a>. IF (32-bit MASM)

Gera um código que testa *condição1* (por exemplo, AX > 7) e executa as *instruções* se essa condição for verdadeira. (somente MASM de 32 bits.)

## <a name="syntax"></a>Sintaxe

> **. SE** *condição1*\
> *instruções*\
> ⟦ **. ELSEIF** *condição2*\
> *instruções*⟧
> ⟦ **. Caso contrário**\
> *instruções*⟧
> **.ENDIF**

## <a name="remarks"></a>Comentários

Se a [. A seguir,](dot-else.md) suas instruções serão executadas se a condição original for falsa. Observe que as condições são avaliadas em tempo de execução.

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
