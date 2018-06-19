---
title: 'Enumeração cmfcimagepaintarea:: Image_edit_mode | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- IMAGE_EDIT_MODE Enumeration
dev_langs:
- C++
helpviewer_keywords:
- IMAGE_EDIT_MODE Enumeration method [MFC]
ms.assetid: e51db66a-fa1c-4766-9dac-a25b595f871a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ef036c1d619bf85e21edafbd20f20cc27c7c12d5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33369262"
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
|`IMAGE_EDIT_MODE_FILL`|Usado para preencher todas as áreas adjacentes que contêm a cor do local atual do cursor.|  
|`IMAGE_EDIT_MODE_LINE`|Usado para desenhar uma linha.|  
|`IMAGE_EDIT_MODE_RECT`|Usado para desenhar um retângulo.|  
|`IMAGE_EDIT_MODE_ELLIPSE`|Usado para desenhar uma elipse.|  
|`IMAGE_EDIT_MODE_COLOR`|Usado para definir a cor atual para a cor na posição do cursor atual.|  
  
### <a name="remarks"></a>Comentários  
 O `CMFCImagePaintArea` e `CMFCImageEditorDialog` classes usam esta enumeração para definir o modo de desenho atual. O modo de desenho e a cor atual são usadas para modificar a área de imagem em uma caixa de diálogo do editor de imagem. Para obter mais informações sobre `CMFCImagePaintArea` e `CMFCImageEditorDialog`, consulte [CMFCImagePaintArea classe](../../mfc/reference/cmfcimagepaintarea-class.md) e [CMFCImageEditorDialog classe](../../mfc/reference/cmfcimageeditordialog-class.md).  
  
 Quando você seleciona uma cor de uma imagem usando o `IMAGE_EDIT_MODE_COLOR` modo de desenho, a estrutura define o modo de desenho atual `IMAGE_EDIT_MODE_PEN`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afximagepaintarea.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCImagePaintArea](../../mfc/reference/cmfcimagepaintarea-class.md)   
 [Classe CMFCImageEditorDialog](../../mfc/reference/cmfcimageeditordialog-class.md)
