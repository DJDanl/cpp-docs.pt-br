---
title: MMWORD
ms.date: 08/30/2018
f1_keywords:
- MMWORD
helpviewer_keywords:
- MMWORD directive
ms.assetid: b4c5a104-9078-4fb4-afc3-d1e63abe562a
ms.openlocfilehash: e4ebaa9d47a569bc9cf7d843d3ddb54ca5d713a0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62176857"
---
# <a name="mmword"></a>MMWORD

Usado para operandos multimídia de 64 bits com instruções MMX e SSE (XMM).

## <a name="syntax"></a>Sintaxe

> MMWORD

## <a name="remarks"></a>Comentários

`MMWORD` é um tipo.  Antes de MMWORD que está sendo adicionado para MASM, funcionalidade equivalente pode foi obtida com:

```asm
    mov mm0, qword ptr [ebx]
```

Embora as duas instruções funcionam em operandos de 64 bits `QWORD` é o tipo para inteiros sem sinal de 64 bits e `MMWORD` é o tipo para um valor de multimídia de 64 bits.

`MMWORD` destina-se para representar o mesmo tipo que [__m64](../../cpp/m64.md).

## <a name="example"></a>Exemplo

```asm
    movq     mm0, mmword ptr [ebx]
```