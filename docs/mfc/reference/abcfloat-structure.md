---
title: Estrutura ABCFLOAT
ms.date: 11/04/2016
f1_keywords:
- ABCFLOAT
helpviewer_keywords:
- ABCFLOAT structure [MFC]
ms.assetid: 338e7e15-9d2c-42d0-aa80-273acfde5cc5
ms.openlocfilehash: b9e3923e8c70e38fe5efe959db8da43118cc6445
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50443648"
---
# <a name="abcfloat-structure"></a>Estrutura ABCFLOAT

O `ABCFLOAT` estrutura contém as larguras de A, B e C de um caractere de fonte.

## <a name="syntax"></a>Sintaxe

```
typedef struct _ABCFLOAT { /* abcf */
    FLOAT abcfA;
    FLOAT abcfB;
    FLOAT abcfC;
} ABCFLOAT;
```

#### <a name="parameters"></a>Parâmetros

*abcfA*<br/>
Especifica o espaçamento entre um caractere. O espaçamento de um é a distância para adicionar à posição atual antes de desenhar o glifo de caracteres.

*abcfB*<br/>
Especifica o espaçamento de B do caractere. O espaçamento de B é a largura da parte desenhado de glifo de caracteres.

*abcfC*<br/>
Especifica o espaçamento de C do caractere. O espaçamento de C é a distância para adicionar à posição atual para fornecer espaço em branco à direita do glifo de caracteres.

## <a name="remarks"></a>Comentários

As larguras de A, B e C são medidas ao longo da linha de base da fonte. O incremento de caractere (largura total) de um caractere é a soma dos espaços de A, B e C. O r ou o espaço de C pode ser negativo para indicar underhangs ou overhangs.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** wingdi

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CDC::GetCharABCWidths](../../mfc/reference/cdc-class.md#getcharabcwidths)

