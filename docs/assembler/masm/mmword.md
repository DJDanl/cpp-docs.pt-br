---
title: MMWORD | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- MMWORD
dev_langs:
- C++
helpviewer_keywords:
- MMWORD directive
ms.assetid: b4c5a104-9078-4fb4-afc3-d1e63abe562a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7314c6d0861195e312c7f72481d2e195e041965d
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43679228"
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