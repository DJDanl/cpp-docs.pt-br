---
title: XMMWORD
ms.date: 12/17/2019
f1_keywords:
- XMMWORD
helpviewer_keywords:
- XMMWORD directive
ms.assetid: 18026d32-5cab-403e-ad7e-382fb41aa9b8
ms.openlocfilehash: 1116729883bf9b1b9342b30332bab5de6ba59015
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75319106"
---
# <a name="xmmword"></a>XMMWORD

Usado para operandos de multimídia de 128 bits com instruções MMX e SSE (XMM).

## <a name="syntax"></a>Sintaxe

> **XMMWORD**

## <a name="remarks"></a>Comentários

**XMMWORD** se destina a representar o mesmo tipo que [__m128](../../cpp/m128.md).

## <a name="example"></a>Exemplo

```asm
    movdqa   xmm0, xmmword ptr [ebx]
```

## <a name="see-also"></a>Veja também

[MASM BNF Grammar](masm-bnf-grammar.md)
