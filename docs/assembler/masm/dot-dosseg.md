---
title: .DOSSEG
ms.date: 11/05/2019
f1_keywords:
- .DOSSEG
helpviewer_keywords:
- .DOSSEG directive
ms.assetid: 175ad470-0a2b-4e2b-b078-65e224fec040
ms.openlocfilehash: 8f0388c3df9804c0cdb105162a962a44fe207345
ms.sourcegitcommit: 45f1d889df633f0f7e4a8e813b46fa73c9858b81
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/06/2019
ms.locfileid: "73703312"
---
# <a name="dosseg-32-bit-masm"></a>. DOSSEG (MASM de 32 bits)

Ordena os segmentos de acordo com a Convenção de segmento do MS-DOS: CODE First, segmentos que não estão em DGROUP e, em seguida, Segments in DGROUP. (somente MASM de 32 bits.)

## <a name="syntax"></a>Sintaxe

> .DOSSEG

## <a name="remarks"></a>Comentários

Os segmentos em DGROUP seguem esta ordem: segmentos que não estão em BSS ou pilha, segmentos de BSS e, por fim, segmentos de pilha. Usado principalmente para garantir o suporte do CodeView em programas autônomos do MASM. O mesmo que [DOSSEG](../../assembler/masm/dosseg.md).

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>