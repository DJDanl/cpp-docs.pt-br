---
title: .DOSSEG
ms.date: 11/05/2019
f1_keywords:
- .DOSSEG
helpviewer_keywords:
- .DOSSEG directive
ms.assetid: 175ad470-0a2b-4e2b-b078-65e224fec040
ms.openlocfilehash: e27b0ae185542c11ee29119575d5c8225501f71e
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75313841"
---
# <a name="dosseg-32-bit-masm"></a>. DOSSEG (MASM de 32 bits)

Ordena os segmentos de acordo com a Convenção de segmento do MS-DOS: CODE First, segmentos que não estão em DGROUP e, em seguida, Segments in DGROUP. (somente MASM de 32 bits.)

## <a name="syntax"></a>Sintaxe

> **.DOSSEG**

## <a name="remarks"></a>Comentários

Os segmentos em DGROUP seguem esta ordem: segmentos que não estão em BSS ou pilha, segmentos de BSS e, por fim, segmentos de pilha. Usado principalmente para garantir o suporte do CodeView em programas autônomos do MASM. O mesmo que [DOSSEG](dosseg.md).

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
