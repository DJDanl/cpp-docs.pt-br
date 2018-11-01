---
title: .DOSSEG
ms.date: 08/30/2018
f1_keywords:
- .DOSSEG
helpviewer_keywords:
- .DOSSEG directive
ms.assetid: 175ad470-0a2b-4e2b-b078-65e224fec040
ms.openlocfilehash: 28b3e351030ee83693c0fec5568aacf9b4b77c27
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50639433"
---
# <a name="dosseg"></a>.DOSSEG

Ordena os segmentos de acordo com a convenção de segmento do MS-DOS: código primeiro, segmentos, em seguida, não em DGROUP e, em seguida, de segmentos no DGROUP.

## <a name="syntax"></a>Sintaxe

> .DOSSEG

## <a name="remarks"></a>Comentários

Os segmentos no DGROUP siga esta ordem: segmentos não está no BSS ou pilha, segmentos BSS e, finalmente, segmentos de pilha. Usado principalmente para garantir o suporte de CodeView em programas autônomos do MASM. Mesmo que [DOSSEG](../../assembler/masm/dosseg.md).

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>