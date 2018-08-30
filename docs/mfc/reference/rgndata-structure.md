---
title: Estrutura RGNDATA | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- RGNDATA
dev_langs:
- C++
helpviewer_keywords:
- RGNDATA structure [MFC]
ms.assetid: 72257c00-f440-4dca-979e-9b6b5b2d5f2f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2c539feaac9cac5bca3a41868cc03379a63bf6bb
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43204353"
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
 *rdh*  
 Especifica um [RGNDATAHEADER](/windows/desktop/api/wingdi/ns-wingdi-_rgndataheader) estrutura. (Para obter mais informações sobre essa estrutura, consulte o SDK do Windows). Os membros dessa estrutura especificam o tipo de região (se ele está retangular ou trapezoidal), o número de retângulos que formam a região, o tamanho do buffer que contém as estruturas do retângulo, e assim por diante.  
  
 *buffer*  
 Especifica um buffer de tamanho arbitrário que contém o [RECT](../../mfc/reference/rect-structure1.md) estruturas que compõem a região.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** wingdi  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CRgn::CreateFromData](../../mfc/reference/crgn-class.md#createfromdata)   
 [CRgn::GetRegionData](../../mfc/reference/crgn-class.md#getregiondata)

