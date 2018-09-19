---
title: Estrutura RECT 1 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- LPRECT
- RECT
dev_langs:
- C++
helpviewer_keywords:
- RECT structure [MFC]
- LPRECT structure [MFC]
ms.assetid: 1b3160de-64e9-40d1-89eb-af3e0fd6acf0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2e71459a1c22b9295c5c88ce29da9e494660fa26
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46046297"
---
# <a name="rect-structure1"></a>Estrutura RECT 1
O `RECT` estrutura define as coordenadas dos cantos superior esquerdo e inferior direito de um retângulo.  
  
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
`left`<br/>
Especifica a coordenada x do canto superior esquerdo de um retângulo.  
  
`top`<br/>
Especifica a coordenada y do canto superior esquerdo de um retângulo.  
  
`right`<br/>
Especifica a coordenada x do canto inferior direito de um retângulo.  
  
`bottom`<br/>
Especifica a coordenada y do canto inferior direito de um retângulo.  
  
## <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_Utilities#38](../../mfc/codesnippet/cpp/rect-structure1_1.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** windef.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Classe CRect](../../atl-mfc-shared/reference/crect-class.md)
