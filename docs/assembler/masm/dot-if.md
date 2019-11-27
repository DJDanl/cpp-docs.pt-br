---
title: .IF
ms.date: 11/05/2019
f1_keywords:
- .IF
helpviewer_keywords:
- .IF directive
ms.assetid: dccc7615-8fc7-4829-9f39-0ee405f6c1e3
ms.openlocfilehash: e8213052dce8d84d62f90d4bc2653435c2b31434
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74398231"
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

Se a [. A seguir,](../../assembler/masm/dot-else.md) suas instruções serão executadas se a condição original for falsa. Observe que as condições são avaliadas em tempo de execução.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](directives-reference.md)
