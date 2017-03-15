---
title: Estrutura XFORM | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- XFORM
dev_langs:
- C++
helpviewer_keywords:
- XFORM structure
ms.assetid: 4fb4ef5b-05d2-4884-82d1-1cb8f7be6302
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
ms.openlocfilehash: 2d23b3838f1e2dcabb2affb96fa6f18942581ff8
ms.lasthandoff: 02/25/2017

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
 O `XFORM` estrutura Especifica um espaço do mundo para transformação de espaço da página. O **eDx** e **eDy** membros especificam os componentes de tradução horizontal e vertical, respectivamente. A tabela a seguir mostra como os outros membros são usados, dependendo da operação:  
  
|Operação|eM11|eM12|eM21|eM22|  
|---------------|----------|----------|----------|----------|  
|`Rotation`|Cosseno do ângulo de rotação|Seno do ângulo de rotação|Negativo seno do ângulo de rotação|Cosseno do ângulo de rotação|  
|**Dimensionamento**|Componente de dimensionamento horizontal|nada|nada|Componente de dimensionamento vertical|  
|**Distorcer**|nada|Constante de proporção horizontal|Constante de proporção vertical|nada|  
|**Reflexão**|Componente de reflexão horizontal|nada|nada|Componente de reflexão vertical|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** wingdi  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CRgn::CreateFromData](../../mfc/reference/crgn-class.md#createfromdata)


