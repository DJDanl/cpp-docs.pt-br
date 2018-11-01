---
title: Estrutura RGNDATA
ms.date: 11/04/2016
f1_keywords:
- RGNDATA
helpviewer_keywords:
- RGNDATA structure [MFC]
ms.assetid: 72257c00-f440-4dca-979e-9b6b5b2d5f2f
ms.openlocfilehash: d6ee25b490aa5c7055b4e8ccf63939fbdd8dd4ac
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50638133"
---
# <a name="rgndata-structure"></a>Estrutura RGNDATA

O `RGNDATA` estrutura contém um cabeçalho e uma matriz de retângulos que formam uma região. Esses retângulos, classificados de cima para baixo à esquerda para a direita, não se sobrepõem.

## <a name="syntax"></a>Sintaxe

```
typedef struct _RGNDATA { /* rgnd */
    RGNDATAHEADER rdh;
    char Buffer[1];
} RGNDATA;
```

#### <a name="parameters"></a>Parâmetros

*rdh*<br/>
Especifica um [RGNDATAHEADER](/windows/desktop/api/wingdi/ns-wingdi-_rgndataheader) estrutura. (Para obter mais informações sobre essa estrutura, consulte o SDK do Windows). Os membros dessa estrutura especificam o tipo de região (se ele está retangular ou trapezoidal), o número de retângulos que formam a região, o tamanho do buffer que contém as estruturas do retângulo, e assim por diante.

*buffer*<br/>
Especifica um buffer de tamanho arbitrário que contém o [RECT](../../mfc/reference/rect-structure1.md) estruturas que compõem a região.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** wingdi

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CRgn::CreateFromData](../../mfc/reference/crgn-class.md#createfromdata)<br/>
[CRgn::GetRegionData](../../mfc/reference/crgn-class.md#getregiondata)

