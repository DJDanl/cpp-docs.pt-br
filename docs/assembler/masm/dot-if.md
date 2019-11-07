---
title: .IF
ms.date: 11/05/2019
f1_keywords:
- .IF
helpviewer_keywords:
- .IF directive
ms.assetid: dccc7615-8fc7-4829-9f39-0ee405f6c1e3
ms.openlocfilehash: 83c9ff588e2fe273e24e1d0b1c16517c5eee3365
ms.sourcegitcommit: 45f1d889df633f0f7e4a8e813b46fa73c9858b81
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/06/2019
ms.locfileid: "73703781"
---
# <a name="if-32-bit-masm"></a>. IF (32-bit MASM)

Gera código que testa `condition1` (por exemplo, AX > 7) e executa as *instruções* se essa condição for verdadeira. (somente MASM de 32 bits.)

## <a name="syntax"></a>Sintaxe

> . SE condição1<br/>
> instruções<br/>
> [[. Condição2 ELSEIF<br/>
> Statements]]<br/>
> [[. RESTANTE<br/>
> Statements]]<br/>
> .ENDIF

## <a name="remarks"></a>Comentários

Se a [. A seguir,](../../assembler/masm/dot-else.md) suas instruções serão executadas se a condição original for falsa. Observe que as condições são avaliadas em tempo de execução.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>