---
title: .PUSHFRAME
description: Descreve o. Diretiva PUSHFRAME MASM, usada para especificar como desenrolar uma função frame.
ms.date: 12/06/2019
f1_keywords:
- .PUSHFRAME
helpviewer_keywords:
- .PUSHFRAME directive
ms.assetid: 17b123d0-4c6d-4fd2-85eb-798e8ad0a73c
ms.openlocfilehash: 5f951396291ecb12dab500a364f176106c5daa8b
ms.sourcegitcommit: 2cac0150ab3bc8260f866451019b8e22c7e1ac11
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/09/2019
ms.locfileid: "74945846"
---
# <a name="pushframe"></a>.PUSHFRAME

Gera uma entrada de código de desenrolação `UWOP_PUSH_MACHFRAME`. Se a palavra-chave de **código** opcional for especificada, a entrada de código de liberação receberá um modificador de 1. Caso contrário, o modificador será 0.

## <a name="syntax"></a>Sintaxe

> **. PUSHFRAME** ⟦**Code**⟧;;

## <a name="remarks"></a>Comentários

. PUSHFRAME permite que os usuários de ml64. exe especifiquem como a função de quadro se desenrola. Ele só é permitido dentro do prólogo, que se estende da declaração de quadro [proc](../../assembler/masm/proc.md) para o [. Diretiva endprólogo](../../assembler/masm/dot-endprolog.md) . Essas diretivas não geram código; Eles geram apenas `.xdata` e `.pdata`. **. PUSHFRAME** deve ser precedido por instruções que realmente implementam as ações a serem rebobinadas. É uma boa prática encapsular as diretivas de desenrolamento e o código que elas devem desenrolar em uma macro para garantir o contrato.

Para obter mais informações, consulte [MASM para x64 (ml64. exe)](../../assembler/masm/masm-for-x64-ml64-exe.md).

## <a name="see-also"></a>Consulte também

[Referência de diretivas](directives-reference.md)
