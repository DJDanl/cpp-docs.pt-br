---
title: Estrutura ponto 1 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- POINT
- LPPOINT
dev_langs:
- C++
helpviewer_keywords:
- LPPOINT structure [MFC]
- POINT structure [MFC]
ms.assetid: 965736d8-4e53-41b6-9b8b-6961992dd21f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a31af23b336e5a911b62d23d0cce2795aa66f0f9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="point-structure1"></a>Estrutura ponto 1
O **ponto** estrutura define x*-* e coordenadas y de um ponto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct tagPOINT {  
    LONG x;  
    LONG y;  
} POINT;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *x*  
 Especifica a coordenada x do ponto.  
  
 *y*  
 Especifica a coordenada y de um ponto.  
  
## <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_Utilities#37](../../mfc/codesnippet/cpp/point-structure1_1.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** windef.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Classe CPoint](../../atl-mfc-shared/reference/cpoint-class.md)
