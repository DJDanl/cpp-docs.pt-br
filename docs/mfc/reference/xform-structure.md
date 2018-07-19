---
title: Estrutura XFORM | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- XFORM
dev_langs:
- C++
helpviewer_keywords:
- XFORM structure [MFC]
ms.assetid: 4fb4ef5b-05d2-4884-82d1-1cb8f7be6302
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6084882bed6690269fbb926f394159491d22978a
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37885878"
---
# <a name="xform-structure"></a>Estrutura XFORM
O `XFORM` estrutura tem a seguinte forma:  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct  tagXFORM {  /* xfrm */  
    FLOAT eM11;  
    FLOAT eM12;  
    FLOAT eM21;  
    FLOAT eM22;  
    FLOAT eDx;  
    FLOAT eDy;  
} XFORM;  
```  
  
## <a name="remarks"></a>Comentários  
 O `XFORM` estrutura Especifica um espaço de mundo para transformação de espaço da página. O `eDx` e `eDy` membros especificam os componentes de translação horizontal e vertical, respectivamente. A tabela a seguir mostra como os outros membros são usados, dependendo da operação:  
  
|Operação|eM11|eM12|eM21|eM22|  
|---------------|----------|----------|----------|----------|  
|`Rotation`|Cosseno do ângulo de rotação|Seno do ângulo de rotação|Negativo seno do ângulo de rotação|Cosseno do ângulo de rotação|  
|`Scaling`|Componente de colocação em escala horizontal|nada|nada|Componente de colocação em escala vertical|  
|`Shear`|nada|Constante proporção horizontal|Constante proporção vertical|nada|  
|`Reflection`|Componente de reflexão horizontal|nada|nada|Componente de reflexão vertical|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** wingdi  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CRgn::CreateFromData](../../mfc/reference/crgn-class.md#createfromdata)

