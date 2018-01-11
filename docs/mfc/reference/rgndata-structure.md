---
title: Estrutura RGNDATA | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: RGNDATA
dev_langs: C++
helpviewer_keywords: RGNDATA structure [MFC]
ms.assetid: 72257c00-f440-4dca-979e-9b6b5b2d5f2f
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d4170b3590cc841f3edc10d4767045a4fede9782
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="rgndata-structure"></a>Estrutura RGNDATA
O `RGNDATA` estrutura contém um cabeçalho e uma matriz de retângulos que compõem uma região. Esses retângulos, classificados de cima para baixo à esquerda para a direita, não se sobrepõem.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct _RGNDATA { /* rgnd */  
    RGNDATAHEADER rdh;  
    char Buffer[1];  
} RGNDATA;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *rdh*  
 Especifica um [RGNDATAHEADER](http://msdn.microsoft.com/library/windows/desktop/dd162941) estrutura. (Para obter mais informações sobre essa estrutura, consulte o SDK do Windows.) Os membros dessa estrutura especificam o tipo de região (se ele está retangular ou trapezoidal), o número de retângulos que compõem a região, o tamanho do buffer que contém as estruturas do retângulo, e assim por diante.  
  
 `Buffer`  
 Especifica um buffer de tamanho arbitrário que contém o [RECT](../../mfc/reference/rect-structure1.md) estruturas que compõem a região.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** wingdi  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CRgn::CreateFromData](../../mfc/reference/crgn-class.md#createfromdata)   
 [CRgn::GetRegionData](../../mfc/reference/crgn-class.md#getregiondata)

