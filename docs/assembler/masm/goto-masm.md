---
title: GOTO (MASM)
ms.date: 12/16/2019
f1_keywords:
- goto
helpviewer_keywords:
- GOTO directive
ms.assetid: 6a5f73e7-6784-4eae-ac52-4fc77a7f369f
ms.openlocfilehash: f198658f9a4b85e0b5ec9b7a0c122241e57286f6
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75317273"
---
# <a name="goto"></a>GOTO

Transfere o assembly para a linha marcada **:** _macrolabel_.

## <a name="syntax"></a>Sintaxe

> **Ir** para *macrolabel*

## <a name="remarks"></a>Comentários

**Goto** é permitido somente dentro de [macros](macro.md), [for](for-masm.md), [forçada](forc.md), [REPEAT](repeat.md)e [while](while-masm.md) Blocks. O destino *macrolabel* deve ser a única diretiva na linha e deve ser precedido por um dois-pontos à esquerda.

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
