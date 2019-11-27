---
title: GOTO (MASM)
ms.date: 08/30/2018
f1_keywords:
- goto
helpviewer_keywords:
- GOTO directive
ms.assetid: 6a5f73e7-6784-4eae-ac52-4fc77a7f369f
ms.openlocfilehash: 424ff295fe37e7c5ff02897a01b99a7c75876f85
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74397489"
---
# <a name="goto-masm"></a>GOTO (MASM)

Transfere o assembly para a linha marcada **:** _macrolabel_.

## <a name="syntax"></a>Sintaxe

> **Ir** para *macrolabel*

## <a name="remarks"></a>Comentários

**Goto** é permitido somente dentro de [macros](macro.md), [for](for-masm.md), [forçada](forc.md), [REPEAT](repeat.md)e [while](while-masm.md) Blocks. O destino *macrolabel* deve ser a única diretiva na linha e deve ser precedido por um dois-pontos à esquerda.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](directives-reference.md)
