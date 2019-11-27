---
title: .DOSSEG
ms.date: 11/05/2019
f1_keywords:
- .DOSSEG
helpviewer_keywords:
- .DOSSEG directive
ms.assetid: 175ad470-0a2b-4e2b-b078-65e224fec040
ms.openlocfilehash: 17edea122afc03a8c3a2fdc86ee6c06c2ccf3c85
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74398482"
---
# <a name="dosseg-32-bit-masm"></a>. DOSSEG (MASM de 32 bits)

Ordena os segmentos de acordo com a Convenção de segmento do MS-DOS: CODE First, segmentos que não estão em DGROUP e, em seguida, Segments in DGROUP. (somente MASM de 32 bits.)

## <a name="syntax"></a>Sintaxe

> **.DOSSEG**

## <a name="remarks"></a>Comentários

Os segmentos em DGROUP seguem esta ordem: segmentos que não estão em BSS ou pilha, segmentos de BSS e, por fim, segmentos de pilha. Usado principalmente para garantir o suporte do CodeView em programas autônomos do MASM. O mesmo que [DOSSEG](../../assembler/masm/dosseg.md).

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)
