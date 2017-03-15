---
title: "Enumeração cmfcimagepaintarea:: Image_edit_mode | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- IMAGE_EDIT_MODE Enumeration
- CMFCImagePaintArea::IMAGE_EDIT_MODE Enumeration
- CMFCImagePaintArea.IMAGE_EDIT_MODE Enumeration
dev_langs:
- C++
helpviewer_keywords:
- IMAGE_EDIT_MODE Enumeration method
ms.assetid: e51db66a-fa1c-4766-9dac-a25b595f871a
caps.latest.revision: 15
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 364b33568e2a21a4649923f4478b5b2456b23747
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcimagepaintareaimageeditmode-enumeration"></a>Enumeração CMFCImagePaintArea::IMAGE_EDIT_MODE
Especifica um modo de desenho que você pode usar para modificar uma imagem em uma caixa de diálogo do editor de imagem.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
enum IMAGE_EDIT_MODE  
{  
    IMAGE_EDIT_MODE_PEN = 0,  
    IMAGE_EDIT_MODE_FILL, 
    IMAGE_EDIT_MODE_LINE, 
    IMAGE_EDIT_MODE_RECT, 
    IMAGE_EDIT_MODE_ELLIPSE, 
    IMAGE_EDIT_MODE_COLOR 
};  
```  
  
## <a name="members"></a>Membros  
  
|||  
|-|-|  
|Nome|Descrição|  
|`IMAGE_EDIT_MODE_PEN`|Usado para desenhar pixels individuais.|  
|`IMAGE_EDIT_MODE_FILL`|Usada para preencher todas as áreas adjacentes que contêm a cor do local atual do cursor.|  
|`IMAGE_EDIT_MODE_LINE`|Usado para desenhar uma linha.|  
|`IMAGE_EDIT_MODE_RECT`|Usado para desenhar um retângulo.|  
|`IMAGE_EDIT_MODE_ELLIPSE`|Usado para desenhar uma elipse.|  
|`IMAGE_EDIT_MODE_COLOR`|Usado para definir a cor atual para a cor na posição atual do cursor.|  
  
### <a name="remarks"></a>Comentários  
 O `CMFCImagePaintArea` e `CMFCImageEditorDialog` classes usam essa enumeração para definir o modo de desenho atual. O modo de desenho e a cor atual são usadas para modificar a área de imagem em uma caixa de diálogo do editor de imagem. Para obter mais informações sobre `CMFCImagePaintArea` e `CMFCImageEditorDialog`, consulte [CMFCImagePaintArea classe](../../mfc/reference/cmfcimagepaintarea-class.md) e [CMFCImageEditorDialog classe](../../mfc/reference/cmfcimageeditordialog-class.md).  
  
 Quando você seleciona uma cor de uma imagem usando o `IMAGE_EDIT_MODE_COLOR` modo de desenho, a estrutura define o modo de desenho atual `IMAGE_EDIT_MODE_PEN`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afximagepaintarea.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCImagePaintArea](../../mfc/reference/cmfcimagepaintarea-class.md)   
 [Classe CMFCImageEditorDialog](../../mfc/reference/cmfcimageeditordialog-class.md)

