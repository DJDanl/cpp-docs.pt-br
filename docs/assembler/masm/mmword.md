---
title: MMWORD
ms.date: 12/17/2019
f1_keywords:
- MMWORD
helpviewer_keywords:
- MMWORD directive
ms.assetid: b4c5a104-9078-4fb4-afc3-d1e63abe562a
ms.openlocfilehash: fd3b9f40b7ff9fa4dae570e0ed906c13a9456424
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75311917"
---
# <a name="mmword"></a>MMWORD

Usado para operandos de multimídia de 64 bits com instruções MMX e SSE (XMM).

## <a name="syntax"></a>Sintaxe

> **MMWORD**

## <a name="remarks"></a>Comentários

**MMWORD** é um tipo.  Antes do **MMWORD** ser adicionado ao MASM, a funcionalidade equivalente poderia ter sido obtida com:

```asm
    mov mm0, qword ptr [ebx]
```

Embora ambas as instruções funcionem em operandos de 64 bits, **QWORD** é o tipo de inteiros sem sinal de 64 bits e **MMWORD** é o tipo de um valor de multimídia de 64 bits.

**MMWORD** se destina a representar o mesmo tipo que [__m64](../../cpp/m64.md).

## <a name="example"></a>Exemplo

```asm
    movq     mm0, mmword ptr [ebx]
```

## <a name="see-also"></a>Veja também

[MASM BNF Grammar](masm-bnf-grammar.md)
