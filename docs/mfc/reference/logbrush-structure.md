---
title: Estrutura LOGBRUSH | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- LOGBRUSH
dev_langs:
- C++
helpviewer_keywords:
- LOGBRUSH structure [MFC]
ms.assetid: 1bf96768-52c5-4444-9bb8-d41ba2e27e68
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8bef2c9b9219231b6a61bfad0a282b3af1b4e0c0
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46374769"
---
# <a name="logbrush-structure"></a>Estrutura LOGBRUSH

O `LOGBRUSH` estrutura define o estilo, cor e padrão de um pincel físico. Ele é usado pelo Windows [CreateBrushIndirect](/windows/desktop/api/wingdi/nf-wingdi-createbrushindirect) e [ExtCreatePen](/windows/desktop/api/wingdi/nf-wingdi-extcreatepen) funções.

## <a name="syntax"></a>Sintaxe

```
typedef struct tag LOGBRUSH { /* lb */
    UINT lbStyle;
    COLORREF lbColor;
    LONG lbHatch;
} LOGBRUSH;
```

#### <a name="parameters"></a>Parâmetros

*lbStyle*<br/>
Especifica o estilo de pincel. O `lbStyle` membro deve ser um dos seguintes estilos:

- Pincel de padrão BS_DIBPATTERN um definido por um bitmap independente de dispositivo especificação (DIB). Se *lbStyle* é BS_DIBPATTERN, o `lbHatch` membro contém um identificador para um DIB compactado.

- Pincel de padrão BS_DIBPATTERNPT um definido por um bitmap independente de dispositivo especificação (DIB). Se *lbStyle* é BS_DIBPATTERNPT, o `lbHatch` membro contém um ponteiro para um DIB compactado.

- Pincel BS_HATCHED Hatched.

- Pincel BS_HOLLOW vazado.

- BS_NULL mesmo que BS_HOLLOW.

- Pincel padrão BS_PATTERN definido por um bitmap de memória.

- Pincel BS_SOLID sólida.

*lbColor*<br/>
Especifica a cor em que o pincel deve ser desenhada. Se *lbStyle* é o estilo de BS_HOLLOW ou BS_PATTERN *lbColor* será ignorado. Se *lbStyle* é BS_DIBPATTERN ou BS_DIBPATTERNBT, a palavra de ordem baixa *lbColor* Especifica se o `bmiColors` membros do [BITMAPINFO](../../mfc/reference/bitmapinfo-structure.md) estrutura contêm explícito vermelho, verde, azul valores (RGB) ou índices para a paleta lógica realizada no momento. O `lbColor` membro deve ser um dos seguintes valores:

- DIB_PAL_COLORS a tabela de cores consiste em uma matriz de índices de 16 bits na paleta lógica realizada no momento.

- A tabela de cores DIB_RGB_COLORS contém valores RGB literais.

*lbHatch*<br/>
Especifica um estilo de hachura. O significado depende do estilo de pincel definido pela *lbStyle*. Se *lbStyle* é BS_DIBPATTERN, o `lbHatch` membro contém um identificador para um DIB compactado. Se *lbStyle* é BS_DIBPATTERNPT, o `lbHatch` membro contém um ponteiro para um DIB compactado. Se *lbStyle* é BS_HATCHED, o `lbHatch` membro Especifica a orientação das linhas usadas para criar a hachura. Ele pode ser um dos seguintes valores:

- Hachura de para cima e da esquerda para direita de 45 graus de um do HS_BDIAGONAL

- HS_CROSS Horizontal e vertical hachura

- Hachura de 45 graus HS_DIAGCROSS

- Hachura de para baixo, esquerda para a direita de 45 graus de um do HS_FDIAGONAL

- Hachura Horizontal HS_HORIZONTAL

- Hachura Vertical HS_VERTICAL

Se *lbStyle* é BS_PATTERN, *lbHatch* é um identificador para o bitmap que define o padrão. Se *lbStyle* é BS_SOLID ou BS_HOLLOW, *lbHatch* será ignorado.

## <a name="remarks"></a>Comentários

Embora *lbColor* controla a cor de primeiro plano de um pincel de hachura, o [CDC::SetBkMode](../../mfc/reference/cdc-class.md#setbkmode) e [CDC::SetBkColor](../../mfc/reference/cdc-class.md#setbkcolor) funções controlam a cor do plano de fundo.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** wingdi

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CDC::GetCharABCWidths](../../mfc/reference/cdc-class.md#getcharabcwidths)

