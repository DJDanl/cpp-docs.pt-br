---
title: Classe CMFCImagePaintArea | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCImagePaintArea
- AFXIMAGEPAINTAREA/CMFCImagePaintArea
- AFXIMAGEPAINTAREA/CMFCImagePaintArea::CMFCImagePaintArea
- AFXIMAGEPAINTAREA/CMFCImagePaintArea::GetMode
- AFXIMAGEPAINTAREA/CMFCImagePaintArea::SetBitmap
- AFXIMAGEPAINTAREA/CMFCImagePaintArea::SetColor
- AFXIMAGEPAINTAREA/CMFCImagePaintArea::SetMode
dev_langs:
- C++
helpviewer_keywords:
- CMFCImagePaintArea [MFC], CMFCImagePaintArea
- CMFCImagePaintArea [MFC], GetMode
- CMFCImagePaintArea [MFC], SetBitmap
- CMFCImagePaintArea [MFC], SetColor
- CMFCImagePaintArea [MFC], SetMode
ms.assetid: c59eec22-f15a-4e58-8c4d-4a18a41f4452
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8f4af09ad1da91e3d59f82736ae9b240812069eb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmfcimagepaintarea-class"></a>Classe CMFCImagePaintArea
Fornece a área da imagem que você pode usar para modificar uma imagem em uma caixa de diálogo do editor de imagem.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCImagePaintArea : public CButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCImagePaintArea::CMFCImagePaintArea](#cmfcimagepaintarea)|Constrói um objeto `CMFCImagePaintArea`.|  
|`CMFCImagePaintArea::~CMFCImagePaintArea`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCImagePaintArea::GetMode](#getmode)|Recupera o modo de desenho atual.|  
|[CMFCImagePaintArea::SetBitmap](#setbitmap)|Define a imagem de bitmap para a área de imagem.|  
|[CMFCImagePaintArea::SetColor](#setcolor)|Define a cor de desenho atual.|  
|[CMFCImagePaintArea::SetMode](#setmode)|Define o modo de desenho atual.|  
  
### <a name="remarks"></a>Comentários  
 Essa classe não se destina a ser usada diretamente do seu código.  
  
 A estrutura usa essa classe para exibir a área de imagem em uma caixa de diálogo do editor de imagem. Para obter mais informações sobre a caixa de diálogo do editor de imagem, consulte [CMFCImageEditorDialog classe](../../mfc/reference/cmfcimageeditordialog-class.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um objeto de `CMFCImagePaintArea` classe, defina a cor de desenho, defina o modo de desenho atual e definir a imagem de bitmap para a área de imagem atual.  
  
 [!code-cpp[NVC_MFC_RibbonApp#37](../../mfc/reference/codesnippet/cpp/cmfcimagepaintarea-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CButton](../../mfc/reference/cbutton-class.md)  
  
 [CMFCImagePaintArea](../../mfc/reference/cmfcimagepaintarea-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afximagepaintarea.h  
  
##  <a name="cmfcimagepaintarea"></a>CMFCImagePaintArea::CMFCImagePaintArea  
 Constrói um objeto `CMFCImagePaintArea`.  
  
```  
CMFCImagePaintArea(CMFCImageEditorDialog* pParentDlg);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `pParentDlg`|Um ponteiro para a caixa de diálogo que é o pai do editor de imagem.|  
  
##  <a name="getmode"></a>CMFCImagePaintArea::GetMode  
 Recupera o modo de desenho atual.  
  
```  
IMAGE_EDIT_MODE GetMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [IMAGE_EDIT_MODE](cmfcimagepaintarea-image-edit-mode-enumeration.md) valor que especifica o modo de desenho atual.  
  
##  <a name="setbitmap"></a>CMFCImagePaintArea::SetBitmap  
 Define a imagem de bitmap para a área de imagem.  
  
```  
void SetBitmap(CBitmap* pBitmap);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `pBitmap`|A nova imagem de bitmap para exibir.|  
  
### <a name="remarks"></a>Comentários  
 Se `pBitmap` é `NULL`, esse método define o tamanho da área de pintura modificável como zero. Caso contrário, ele define o tamanho da área de pintura pode ser modificado para o tamanho da imagem de bitmap fornecido.  
  
##  <a name="setcolor"></a>CMFCImagePaintArea::SetColor  
 Define a cor de desenho atual.  
  
```  
void SetColor(COLORREF color);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `color`|A nova cor de desenho.|  
  
### <a name="remarks"></a>Comentários  
 Quando você selecionar uma cor da barra de paleta do editor de imagem ou o seletor de cores, o framework chama esse método para atualizar a cor de desenho atual. A cor inicial do desenho é preta (um `COLORREF` valor 0).  
  
 A cor de desenho é usada pela caixa de diálogo do editor de imagem para todos os modos de desenho exceto para `IMAGE_EDIT_MODE_COLOR`. Para obter mais informações sobre modos de desenho, consulte [cmfcimagepaintarea:: Image_edit_mode enumeração](cmfcimagepaintarea-image-edit-mode-enumeration.md).  
  
##  <a name="setmode"></a>CMFCImagePaintArea::SetMode  
 Define o modo de desenho atual.  
  
```  
void SetMode(IMAGE_EDIT_MODE mode);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `mode`|Um [IMAGE_EDIT_MODE](cmfcimagepaintarea-image-edit-mode-enumeration.md) valor que especifica o modo de desenho atual.|  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCImageEditorDialog](../../mfc/reference/cmfcimageeditordialog-class.md)
