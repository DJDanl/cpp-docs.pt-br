---
title: GOTO (MASM) | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- goto
dev_langs:
- C++
helpviewer_keywords:
- GOTO directive
ms.assetid: 6a5f73e7-6784-4eae-ac52-4fc77a7f369f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b0be678e2d39389cbc551c386c1890f799124b5b
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43694020"
---
# <a name="goto-masm"></a>GOTO (MASM)

Transfere o assembly para a linha marcada **:**_macrolabel_.

## <a name="syntax"></a>Sintaxe

> **GOTO** *macrolabel*

## <a name="remarks"></a>Comentários

**GOTO** é permitido apenas dentro [MACRO](macro.md), [para](for-masm.md), [FORC](forc.md), [REPITA](repeat.md), e [ENQUANTO](while-masm.md)blocos. O *macrolabel* deve ser a única diretiva na linha de destino e deve ser precedido por dois-pontos à esquerda.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>
