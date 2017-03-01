---
title: Estrutura RECT&1; | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- LPRECT
- RECT
dev_langs:
- C++
helpviewer_keywords:
- RECT structure
- LPRECT structure
ms.assetid: 1b3160de-64e9-40d1-89eb-af3e0fd6acf0
caps.latest.revision: 13
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
ms.sourcegitcommit: 5187996fc377bca8633360082d07f7ec8a68ee57
ms.openlocfilehash: bc91b22f291f23ed396a054b0c929410718286a3
ms.lasthandoff: 02/25/2017

---
# <a name="rect-structure1"></a>Estrutura RECT&1;
O `RECT` estrutura define as coordenadas das extremidades superior esquerda e inferior direita de um retângulo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct tagRECT {  
    LONG left;  
    LONG top;  
    LONG right;  
    LONG bottom;  
} RECT;  
```  
  
## <a name="members"></a>Membros  
 `left`  
 Especifica a coordenada x do canto superior esquerdo de um retângulo.  
  
 `top`  
 Especifica a coordenada y do canto superior esquerdo de um retângulo.  
  
 `right`  
 Especifica a coordenada x do canto inferior direito de um retângulo.  
  
 `bottom`  
 Especifica a coordenada y do canto inferior direito de um retângulo.  
  
## <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_Utilities&38;](../../mfc/codesnippet/cpp/rect-structure1_1.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** windef.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Classe CRect](../../atl-mfc-shared/reference/crect-class.md)

