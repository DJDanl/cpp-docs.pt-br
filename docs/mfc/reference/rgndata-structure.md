---
title: Estrutura RGNDATA | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- RGNDATA
dev_langs:
- C++
helpviewer_keywords:
- RGNDATA structure
ms.assetid: 72257c00-f440-4dca-979e-9b6b5b2d5f2f
caps.latest.revision: 14
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
ms.openlocfilehash: 93a7c79f175e22dcb0b40cb39b157cfe21a98e93
ms.lasthandoff: 02/25/2017

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
 Especifica um [RGNDATAHEADER](http://msdn.microsoft.com/library/windows/desktop/dd162941) estrutura. (Para obter mais informações sobre essa estrutura, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].) Os membros dessa estrutura especificam o tipo de região (seja retangular ou trapezoidal), o número de retângulos que formam a região, o tamanho do buffer que contém as estruturas do retângulo, e assim por diante.  
  
 `Buffer`  
 Especifica um buffer de tamanho arbitrário que contém o [RECT](../../mfc/reference/rect-structure1.md) estruturas que compõem a região.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** wingdi  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CRgn::CreateFromData](../../mfc/reference/crgn-class.md#createfromdata)   
 [CRgn::GetRegionData](../../mfc/reference/crgn-class.md#getregiondata)


