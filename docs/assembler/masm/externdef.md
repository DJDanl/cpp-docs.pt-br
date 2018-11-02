---
title: EXTERNDEF
ms.date: 08/30/2018
f1_keywords:
- EXTERNDEF
helpviewer_keywords:
- EXTERNDEF directive
ms.assetid: 95a10de6-c345-4428-a2f2-90f7d411dc86
ms.openlocfilehash: 23d34af470e825a8535de8cb28645a7bfb4c4d1b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50619759"
---
# <a name="externdef"></a>EXTERNDEF

Define uma ou mais variáveis externas, rótulos ou símbolos chamados *nome* cujo tipo é `type`.

## <a name="syntax"></a>Sintaxe

> Nome: tipo EXTERNDEF [[langtype]] [[, nome: tipo de [[langtype]]]]...

## <a name="remarks"></a>Comentários

Se *nome* é definido no módulo, ele será tratado como [público](../../assembler/masm/public-masm.md). Se *nome* é referenciada no módulo, ele será tratado como [EXTERN](../../assembler/masm/extern-masm.md). Se *nome* não é referenciado, ele será ignorado. O `type` pode ser [ABS](../../assembler/masm/operator-abs.md), que importa *nome* como uma constante. Normalmente usado em incluir arquivos.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>