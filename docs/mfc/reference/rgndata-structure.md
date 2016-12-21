---
title: "Estrutura RGNDATA | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "RGNDATA"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura RGNDATA"
ms.assetid: 72257c00-f440-4dca-979e-9b6b5b2d5f2f
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura RGNDATA
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

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
 Especifica um buffer de tamanho arbitrário que contém o [RECT](RECT%20Structure1.md) estruturas que compõem a região.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** wingdi  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CRgn::CreateFromData](../../mfc/reference/crgn-class.md#CreateFromData)   
 [CRgn::GetRegionData](../../mfc/reference/crgn-class.md#GetRegionData)

