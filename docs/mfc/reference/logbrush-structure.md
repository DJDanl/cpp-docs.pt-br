---
title: Estrutura LOGBRUSH | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- LOGBRUSH
dev_langs:
- C++
helpviewer_keywords:
- LOGBRUSH structure
ms.assetid: 1bf96768-52c5-4444-9bb8-d41ba2e27e68
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: eea7caf6139fd43dd77163271701d170c7a744e2
ms.lasthandoff: 02/25/2017

---
# <a name="logbrush-structure"></a>Estrutura LOGBRUSH
O `LOGBRUSH` estrutura define o estilo, cor e padrão de um pincel físico. Ele é usado pelo Windows [CreateBrushIndirect](http://msdn.microsoft.com/library/windows/desktop/dd183487) e [ExtCreatePen](http://msdn.microsoft.com/library/windows/desktop/dd162705) funções.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct tag LOGBRUSH { /* lb */  
    UINT lbStyle;  
    COLORREF lbColor;  
    LONG lbHatch;  
} LOGBRUSH;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `lbStyle`  
 Especifica o estilo de pincel. O `lbStyle` membro deve ser um dos seguintes estilos:  
  
- **BS_DIBPATTERN** um pincel de padrão definido pela especificação de um bitmap independente de dispositivo (DIB). Se `lbStyle` é **BS_DIBPATTERN**, o **lbHatch** membro contém um identificador para um DIB compactada.  
  
- **BS_DIBPATTERNPT** um pincel de padrão definido pela especificação de um bitmap independente de dispositivo (DIB). Se `lbStyle` é **BS_DIBPATTERNPT**, o **lbHatch** membro contém um ponteiro para um DIB compactada.  
  
- **BS_HATCHED** Hatched pincel.  
  
- **BS_HOLLOW** vazado pincel.  
  
- **BS_NULL** igual **BS_HOLLOW**.  
  
- **BS_PATTERN** padrão pincel definido por um bitmap de memória.  
  
- **BS_SOLID** pincel sólido.  
  
 `lbColor`  
 Especifica a cor na qual o pincel for emitida. Se `lbStyle` é o **BS_HOLLOW** ou **BS_PATTERN** estilo, **lbColor** será ignorado. Se `lbStyle` é **BS_DIBPATTERN** ou **BS_DIBPATTERNBT**, a palavra de ordem inferior de **lbColor** Especifica se o **bmiColors** membros a [BITMAPINFO](../../mfc/reference/bitmapinfo-structure.md) estrutura contêm explícito vermelho, verde, azul (valores RGB) ou índices na paleta de lógica realizada no momento. O **lbColor** membro deve ser um dos seguintes valores:  
  
- **DIB_PAL_COLORS** a tabela de cores consiste em uma matriz de índices de 16 bits na paleta de lógica realizada no momento.  
  
- **DIB_RGB_COLORS** a tabela de cores contém valores literais de RGB.  
  
 *lbHatch*  
 Especifica um estilo de hachura. O significado depende do estilo de pincel definido pelo `lbStyle`. Se `lbStyle` é **BS_DIBPATTERN**, o **lbHatch** membro contém um identificador para um DIB compactada. Se `lbStyle` é **BS_DIBPATTERNPT**, o **lbHatch** membro contém um ponteiro para um DIB compactada. Se `lbStyle` é **BS_HATCHED**, o **lbHatch** membro Especifica a orientação das linhas usadas para criar a hachura. Ele pode ser um dos seguintes valores:  
  
- `HS_BDIAGONAL`Um compartimento de 45 graus para cima e da esquerda para direita  
  
- `HS_CROSS`Hachura horizontal e vertical  
  
- `HS_DIAGCROSS`Hachura de 45 graus  
  
- `HS_FDIAGONAL`Um compartimento de 45 graus para baixo, esquerda para a direita  
  
- `HS_HORIZONTAL`Hachura horizontal  
  
- `HS_VERTICAL`Hachura vertical  
  
 Se `lbStyle` é **BS_PATTERN**, **lbHatch** é um identificador para o bitmap que define o padrão. Se `lbStyle` é **BS_SOLID** ou **BS_HOLLOW**, **lbHatch** será ignorado.  
  
## <a name="remarks"></a>Comentários  
 Embora **lbColor** controla a cor de primeiro plano de um pincel de hachura de [CDC::SetBkMode](../../mfc/reference/cdc-class.md#setbkmode) e [CDC::SetBkColor](../../mfc/reference/cdc-class.md#setbkcolor) funções controlam a cor do plano de fundo.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** wingdi  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDC::GetCharABCWidths](../../mfc/reference/cdc-class.md#getcharabcwidths)


