---
title: GOTO (MASM)
ms.date: 08/30/2018
f1_keywords:
- goto
helpviewer_keywords:
- GOTO directive
ms.assetid: 6a5f73e7-6784-4eae-ac52-4fc77a7f369f
ms.openlocfilehash: a03cbda5a8ff64f6c167766f416e7744a5382ad5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50654656"
---
# <a name="goto-masm"></a>GOTO (MASM)

Transfere o assembly para a linha marcada **:**_macrolabel_.

## <a name="syntax"></a>Sintaxe

> **GOTO** *macrolabel*

## <a name="remarks"></a>Comentários

**GOTO** é permitido apenas dentro [MACRO](macro.md), [para](for-masm.md), [FORC](forc.md), [REPITA](repeat.md), e [ENQUANTO](while-masm.md)blocos. O *macrolabel* deve ser a única diretiva na linha de destino e deve ser precedido por dois-pontos à esquerda.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>
