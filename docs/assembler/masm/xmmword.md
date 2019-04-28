---
title: XMMWORD
ms.date: 08/30/2018
f1_keywords:
- XMMWORD
helpviewer_keywords:
- XMMWORD directive
ms.assetid: 18026d32-5cab-403e-ad7e-382fb41aa9b8
ms.openlocfilehash: 59d1ba71260ed08b761c332e887cf27517762303
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62210099"
---
# <a name="xmmword"></a>XMMWORD

Usado para operandos multimídia de 128 bits com instruções MMX e SSE (XMM).

## <a name="syntax"></a>Sintaxe

> XMMWORD

## <a name="remarks"></a>Comentários

`XMMWORD` destina-se para representar o mesmo tipo que [__m128](../../cpp/m128.md).

## <a name="example"></a>Exemplo

```asm
    movdqa   xmm0, xmmword ptr [ebx]
```