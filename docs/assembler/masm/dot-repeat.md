---
title: .REPEAT
ms.date: 11/05/2019
f1_keywords:
- .REPEAT
helpviewer_keywords:
- .REPEAT directive
ms.assetid: cb8ad8c6-587b-42f9-a0ad-b5316a24918c
ms.openlocfilehash: f21f3f3cc4cb86b1ca2503d515dcd7fbcdffe622
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75318274"
---
# <a name="repeat-32-bit-masm"></a>. REPEAT (MASM-bit de 32 bits)

Gera um código que repete a execução do bloco de *instruções* até que a *condição* se torne verdadeira. [. UNTILCXZ](dot-untilcxz.md), que se torna verdadeiro quando o CX é zero, pode ser substituído por [. ATÉ](dot-until.md). A *condição* é opcional com **. UNTILCXZ**. (somente MASM de 32 bits.)

## <a name="syntax"></a>Sintaxe

> **. REPETIR**\
> *instruções*\
> **.**  *Condição* until

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
