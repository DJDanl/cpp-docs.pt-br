---
title: GOTO (MASM)
ms.date: 12/16/2019
helpviewer_keywords:
- GOTO directive
ms.assetid: 6a5f73e7-6784-4eae-ac52-4fc77a7f369f
ms.openlocfilehash: 18f286d8634202b57dea788aa6984755a5afb197
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79440801"
---
# <a name="goto"></a>GOTO

Transfere o assembly para a linha marcada **:** _macrolabel_.

## <a name="syntax"></a>Sintaxe

> **Ir** para *macrolabel*

## <a name="remarks"></a>Comentários

**Goto** é permitido somente dentro de [macros](macro.md), [for](for-masm.md), [forçada](forc.md), [REPEAT](repeat.md)e [while](while-masm.md) Blocks. O destino *macrolabel* deve ser a única diretiva na linha e deve ser precedido por um dois-pontos à esquerda.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
