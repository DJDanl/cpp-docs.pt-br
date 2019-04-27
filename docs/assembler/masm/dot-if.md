---
title: .IF
ms.date: 08/30/2018
f1_keywords:
- .IF
helpviewer_keywords:
- .IF directive
ms.assetid: dccc7615-8fc7-4829-9f39-0ee405f6c1e3
ms.openlocfilehash: cf9c594d843c937dd2191bee2a7cebadbc615c82
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62185260"
---
# <a name="if"></a>.IF

Gera código que testa `condition1` (por exemplo, AX > 7) e executa o *instruções* se a condição for true.

## <a name="syntax"></a>Sintaxe

> . Se condition1<br/>
> instruções<br/>
> [[. Condição2 ELSEIF<br/>
> statements]]<br/>
> [[.ELSE<br/>
> statements]]<br/>
> .ENDIF

## <a name="remarks"></a>Comentários

Se um [. ELSE](../../assembler/masm/dot-else.md) segue, suas instruções é executadas se a condição original era falsa. Observe que as condições são avaliadas em tempo de execução.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>