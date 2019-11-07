---
title: .REPEAT
ms.date: 11/05/2019
f1_keywords:
- .REPEAT
helpviewer_keywords:
- .REPEAT directive
ms.assetid: cb8ad8c6-587b-42f9-a0ad-b5316a24918c
ms.openlocfilehash: 0533397c60c83f22b10c84ec72aa6eb65a71e4c0
ms.sourcegitcommit: 45f1d889df633f0f7e4a8e813b46fa73c9858b81
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/06/2019
ms.locfileid: "73703568"
---
# <a name="repeat-32-bit-masm"></a>. REPEAT (MASM-bit de 32 bits)

Gera um código que repete a execução do bloco de *instruções* até que `condition` se torne true. [. UNTILCXZ](../../assembler/masm/dot-untilcxz.md), que se torna verdadeiro quando o CX é zero, pode ser substituído por [. ATÉ](../../assembler/masm/dot-until.md). O `condition` é opcional com **. UNTILCXZ**. (somente MASM de 32 bits.)

## <a name="syntax"></a>Sintaxe

> .REPEAT<br/>
> instruções<br/>
> . Condição UNTIL

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>