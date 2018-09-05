---
title: .IF | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- .IF
dev_langs:
- C++
helpviewer_keywords:
- .IF directive
ms.assetid: dccc7615-8fc7-4829-9f39-0ee405f6c1e3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f7bd5ba5821b4dcfb2d088e31816f50540445018
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43691538"
---
# <a name="if"></a>.IF

Gera código que testa `condition1` (por exemplo, AX > 7) e executa o *instruções* se a condição for true.

## <a name="syntax"></a>Sintaxe

> . Se condition1<br/>
> instruções<br/>
> [[. Condição2 ELSEIF<br/>
> instruções]]<br/>
> [[. ELSE<br/>
> instruções]]<br/>
> .ENDIF

## <a name="remarks"></a>Comentários

Se um [. ELSE](../../assembler/masm/dot-else.md) segue, suas instruções é executadas se a condição original era falsa. Observe que as condições são avaliadas em tempo de execução.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>